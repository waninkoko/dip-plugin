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


/*
 * DIP functions
 */
	.section .dip_alloc, "x"

	.code 16
	.thumb_func

	.global DI_Alloc
DI_Alloc:
	bx lr


	.section .dip_read_hash, "x"

	.code 16
	.thumb_func

	.global DI_ReadHash
DI_ReadHash:
	bx lr


	.section .dip_free, "x"

	.code 16
	.thumb_func

	.global DI_Free
DI_Free:
	bx lr


	.section .dip_memcpy, "x"

	.code 16
	.thumb_func

	.global DI_Memcpy
DI_Memcpy:
	bx lr


	.section .dip_printf, "x"

	.code 16
	.thumb_func

	.global DI_Printf
DI_Printf:
	bx lr



/*
 * DIP handlers
 */
	.text
	.align 4

	.code 32

	.thumb_func
	.global DI_HandleIoctl
DI_HandleIoctl:
	push	{r4-r7, lr}
	mov	r7, r10
	mov	r6, r8
	push	{r6, r7}
	ldr	r5, [r0]
	mov	r10, r1

	ldr	r3, =dip_handle_ioctl + 1
	bx	r3

	.thumb_func
	.global DI_HandleCmd
DI_HandleCmd:
	push	{r4-r7, lr}
	mov	r7, r11
	mov	r6, r10
	mov	r5, r9
	mov	r4, r8
	push	{r4-r7}

	ldr	r3, =dip_handle_cmd + 1
	bx	r3
