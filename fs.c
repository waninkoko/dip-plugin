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

#include <string.h>

#include "dip_calls.h"
#include "fs.h"
#include "syscalls.h"


/* FS structure */
typedef struct {
	char filepath[ISFS_MAXPATH];

	union {
		struct {
			char oldpath[ISFS_MAXPATH];
			char newpatn[ISFS_MAXPATH];
		} rename;

		struct {
			u32  owner;
			u16  group;
			char filepath[ISFS_MAXPATH];
			u8   ownerperm;
			u8   groupperm;
			u8   otherperm;
			u8   attributes;
			u8   pad0[2];
		} attr;

		struct {
			ioctlv vector[4];
			u32    entries;
		} dir;

		struct {
			ioctlv vector[4];
			u32    usage1;
			u8     pad0[28];
			u32    usage2;
		} usage;
	};
} ATTRIBUTE_PACKED fsBuf;

/* Variables */
static s32    fsFd  = -1;
static fsBuf *iobuf = NULL;


s32 FS_Init(void)
{
	/* Already open */
	if (fsFd >= 0)
		return 0;

	/* Allocate buffer */
	if (!iobuf) {
		iobuf = DI_Alloc(sizeof(*iobuf), 32);
		if (!iobuf)
			return IPC_ENOMEM;
	}

	/* Open filesystem */
	fsFd = os_open("/dev/fs", 0);
	if (fsFd < 0)
		return fsFd;

	return 0;
}

void FS_Close(void)
{
	/* Close filesystem */
	if (fsFd >= 0)
		os_close(fsFd);

	/* Reset descriptor */
	fsFd = -1;
}

s32 FS_CreateFile(const char *filepath, u8 attributes, u8 owner, u8 group, u8 other)
{
	/* Set filepath */
	strcpy(iobuf->attr.filepath, filepath);

	/* Setup buffer */
	iobuf->attr.attributes = attributes;
	iobuf->attr.ownerperm  = owner;
	iobuf->attr.groupperm  = group;
	iobuf->attr.otherperm  = other;

	/* Create file */
	return os_ioctl(fsFd, IOCTL_FS_CREATEFILE, &iobuf->attr, sizeof(iobuf->attr), NULL, 0);
}
