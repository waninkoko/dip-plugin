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

#ifndef _IPC_H_
#define _IPC_H_

#include "types.h"

/* Error codes */
#define IPC_EINVAL		 -1
#define IPC_ENOENT		 -6
#define IPC_ENOMEM		-22
#define IPC_EIO			  2
#define IPC_EINCMD		128


/* IOCTL vector */
typedef struct {
	void *data;
	u32   len;
} ioctlv;

/* IOCTL structure */
typedef struct {
	u32 command;

	u32 *inbuf;
	u32  inlen;
	u32 *iobuf;
	u32  iolen;
} ioctl;

#endif
