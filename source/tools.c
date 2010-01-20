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

#include "types.h"


void DI_Memset(void *buf, u8 val, u32 len)
{
	u32 cnt;

	/* Clean buffer */
	for (cnt = 0; cnt < len; cnt++)
		((u8 *)buf)[cnt] = val;
}

s32 DI_Memcmp(const void *a, const void *b, u32 len)
{
	u8 *p = (u8 *)a, *q = (u8 *)b;
	u32 cnt;

	/* Compare bytes */
	for (cnt = 0; cnt < len; cnt++)
		if (p[cnt] != q[cnt])
			return -1;

	return 0;
}
