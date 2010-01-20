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

#ifndef _DIP_CALLS_H_
#define _DIP_CALLS_H_

#include "types.h"

/* Externs */
extern u8 dip_readctrl[2];


/* Debug */
#ifdef DEBUG
void DI_Printf(const char *fmt, ...);
#else
# define DI_Printf(fmt, ...)
#endif

/* Prototypes */
void *DI_Alloc(u32 size, u32 align);
void  DI_Free(void *mem);
void  DI_Memcpy(void *dst, const void *src, u32 size);
s32   DI_ReadHash(void); 

/* DIP handlers */
s32 DI_HandleIoctl(void *buffer, u32 fd);
s32 DI_HandleCmd(void *inbuf, const void *outbuf, u32 size);

#endif
