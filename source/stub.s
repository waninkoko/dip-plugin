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

	.section .init, "x"

	.code 32
	.thumb_func

	.global _emulateIoctl
_emulateIoctl:
	ldr	r3, =DI_EmulateIoctl + 1
	bx	r3

	.global _emulateCmd
_emulateCmd:
	ldr	r3, =DI_EmulateCmd + 1
	bx	r3

