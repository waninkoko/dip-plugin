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

#ifndef _PLUGIN_H_
#define _PLUGIN_H_

#include "tools.h"
#include "types.h"

/* Return codes */
#define DIP_EIO			0xA000

/* Disc lengths */
#define DVD5_LENGTH     	0x46090000
#define DVD9_LENGTH     	0x7ED30000

/* Error codes */
#define ERROR_BLOCK_RANGE	0x52100
#define ERROR_WRONG_DISC	0x53100

/* Mode codes */
#define MODE_DVDROM		0x01
#define MODE_CRYPT		0x02
#define MODE_WBFS		0x04
#define MODE_FAT		0x08

/* Macros */
#define DI_SetMode(bit)		BIT_SET(config.mode, (bit))
#define DI_DelMode(bit)		BIT_DEL(config.mode, (bit))
#define DI_ChkMode(bit)		BIT_CHK(config.mode, (bit))

/* Disc types */
enum {
	DISC_UNKNOWN = 0,
	DISC_DVD5,
	DISC_DVD9,
};


/* Config structure */
struct dipConfig {
	/* Modes */
	u32 mode;

	/* Type */
	u32 type;

	/* Offsets */
	u32 offset[2];

	/* WBFS */
	s32 wbfs_dev;
	u8  wbfs_id[6];

	/* Last error */
	u32 error;

	/* Misc variables */
	u32 cover;
	u32 noreset;
};

/* Extern */
extern struct dipConfig config;

#endif
