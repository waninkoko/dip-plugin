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

#ifndef _FS_H_
#define _FS_H_

#include "types.h"

/* Constants */
#define ISFS_MAXPATH		64

/* IOCTL commands */
#define IOCTL_FS_FORMAT               1
#define IOCTL_FS_GETSTATS             2
#define IOCTL_FS_CREATEDIR            3
#define IOCTL_FS_READDIR              4
#define IOCTL_FS_SETATTR              5
#define IOCTL_FS_GETATTR              6
#define IOCTL_FS_DELETE               7
#define IOCTL_FS_RENAME               8
#define IOCTL_FS_CREATEFILE           9
#define IOCTL_FS_SETFILEVERCTRL       10
#define IOCTL_FS_GETFILESTATS         11
#define IOCTL_FS_GETUSAGE             12
#define IOCTL_FS_SHUTDOWN             13

#endif

