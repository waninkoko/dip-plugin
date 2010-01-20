/*
 * DIP plugin for Custom IOS.
 *
 * Copyright (C) 2008-2010 Waninkoko, WiiGator.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "dip_calls.h"
#include "ioctl.h"
#include "plugin.h"
#include "syscalls.h"
#include "tools.h"
#include "wbfs.h"

/* Constants */
#define WBFS_BASE		(('W'<<24) | ('F'<<16) | ('S'<<8))

/* IOCTL commands */
#define IOCTL_WBFS_OPEN_DISC	(WBFS_BASE + 0x1)
#define IOCTL_WBFS_READ_DISC	(WBFS_BASE + 0x2)

/* Variables */
static char *fs[] = { "/dev/usb/ehc", "/dev/sdio/sdhc" };
static s32   fd   = -1;


/* I/O buffer */
static struct {
	/* IOCTL vector */
	ioctlv vector[4];

	/* IOCTL buffer */
	u32 buffer[9];
} *iobuf = NULL;


s32 WBFS_Init(s32 device, u8 *discid)
{
	/* Wrong device */
	if (device < 0)
		return IPC_EINVAL;

	/* Allocate memory */
	if (!iobuf) {
		iobuf = DI_Alloc(sizeof(*iobuf), 32);
		if (!iobuf)
			return IPC_ENOMEM;
	}

	/* Close device */
	WBFS_Close();

	/* Open device */
	fd = os_open(fs[device], 1);
	if (fd < 0)
		return fd;

	/* Copy disc ID */
	DI_Memcpy(iobuf->buffer, discid, 6);

	/* Setup vector */
	iobuf->vector[0].data = iobuf->buffer;
	iobuf->vector[0].len  = 6;

	/* Open disc */
	return os_ioctlv(fd, IOCTL_WBFS_OPEN_DISC, 1, 0, iobuf->vector);
}

void WBFS_Close(void)
{
	/* Device opened */
	if (fd >= 0) {
		/* Close device */
		os_close(fd);
	}

	/* Clear descriptor */
	fd = -1;
}

s32 WBFS_Read(void *outbuf, u32 len, u32 offset)
{
	s32 ret;

	/* Set buffers */
	iobuf->buffer[0] = offset;
	iobuf->buffer[8] = len;

	/* Setup vector */
	iobuf->vector[0].data = &iobuf->buffer[0];
	iobuf->vector[0].len  = 4;
	iobuf->vector[1].data = &iobuf->buffer[8];
	iobuf->vector[1].len  = 4;
	iobuf->vector[2].data = outbuf;
	iobuf->vector[2].len  = len;

	/* Flush cache */
	os_sync_after_write(iobuf, sizeof(*iobuf));

	/* Read data */
	ret = os_ioctlv(fd, IOCTL_WBFS_READ_DISC, 2, 1, iobuf->vector);

	/* Read error */
	if (ret) {
		/* Block out of range */
		config.error = ERROR_BLOCK_RANGE;

		/* I/O error */
		return DIP_EIO;
	}
		
	/* Invalidate range */
	os_sync_before_read(outbuf, len);

	return 0;
}
