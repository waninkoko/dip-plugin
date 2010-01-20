OUTPUT_FORMAT("elf32-bigarm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_emulateIoctl)
 
/* Sections area */ 
MEMORY {
	ios_info_table		: ORIGIN = 0x0, LENGTH = 0x4000
	exe(rwx)		: ORIGIN = 0x20208200, LENGTH = 0xe00
	ram(rwx)		: ORIGIN = 0x20208140, LENGTH = 0xc0
	ios_exe(rwx)		: ORIGIN = 0x20200000, LENGTH = 0x7d74
	bss(rwx)		: ORIGIN = 0x20234dc4, LENGTH = 0x23c
}

__exe_start_virt__		= 0x20208200;
__exe_start_phys__		= 0x139b8200;
__ram_start_virt__		= 0x20208140;
__ram_start_phys__		= 0x139b8140;
__bss_start_virt__		= 0x20234dc4;

/* DIP addresses */
dip_readctrl			= 0x2022cdac;
dip_handle_ioctl		= 0x202003c4;
dip_handle_cmd			= 0x20200d38;

 
SECTIONS
{
	.debug_aranges 0 : {
		*(.debug_aranges)
	}
	.debug_pubnames 0 : {
		*(.debug_pubnames)
	}
	.debug_info 0 : {
		*(.debug_info)
	}
	.debug_abbrev 0 : {
		*(.debug_abbrev)
	}
	.debug_line 0 : {
		*(.debug_line)
	}
	.debug_frame 0 : {
		*(.debug_frame)
	}
	.debug_str 0 : {
		*(.debug_str)
	}
	.debug_loc 0 : {
		*(.debug_loc)
	}
	.debug_macinfo 0 : {
		*(.debug_macinfo)
	}
	.note.arm.ident 0 : {
		KEEP (*(.note.arm.ident))
	}

	/*
	 * DIP functions
	 */

	.dip_printf 0x2020365c : {
		*(.dip_printf)
	} > ios_exe

	.dip_alloc 0x202008c4 : {
		*(.dip_alloc)
	} > ios_exe

	.dip_free 0x20200898 : {
		*(.dip_free)
	} > ios_exe

	.dip_memcpy 0x20205b80 : {
		*(.dip_memcpy)
	} > ios_exe

	.dip_read_hash 0x20202874 : {
		*(.dip_read_hash)
	} > ios_exe

	/*
	 * End of DIP functions
	 */

	.init __exe_start_virt__ : AT (__exe_start_phys__) {
		. = .; KEEP (*(.init))
	} > exe

	.text ALIGN (0x4) : { 
		*(.text.entry)
		*(.text*)
		*(.gnu.warning) 
		*(.gnu.linkonce.t.*) 
		*(.glue_7) 
		*(.glue_7t)
		*(.rodata*) 
	} > exe

	.data __ram_start_virt__ : AT (__ram_start_phys__) {
		*(.data*)
		*(.data1)
		*(.gnu.linkonce.d.*)
		. = ALIGN (4);
		__CTOR_LIST__ = ABSOLUTE (.);
		KEEP (*(SORT (.ctors*)))
		__CTOR_END__  = ABSOLUTE (.);
		__DTOR_LIST__ = ABSOLUTE (.);
		KEEP (*(SORT (.dtors*)))
		__DTOR_END__  = ABSOLUTE (.);
		*(.dynamic)
		*(.sdata*)
		*(.gnu.linkonce.s.*)
		. = ALIGN (4);
		*(.2ram.*)
	} > ram 

	.fini : {
		. = .;
		*(.fini)
	} > ram

	.rodata ALIGN (0x4) : { 
		. = .; 
		*(.gnu.linkonce.r.*)
	} > ram

	.rodata1 ALIGN (0x4) : {
		. = .;
		*(.rodata1)
	} > ram

	.fixup ALIGN (0x4) : {
		. = .;
		*(.fixup)
	} > ram

	.gcc_except_table ALIGN (0x4) : {
		. = .;
		*(.gcc_except_table)
	} > ram

	.got ALIGN (0x4) : {
		*(.got.plt)
		*(.got)
	} > ram

	.bss __bss_start_virt__ : {
		*(.scommon)
		*(.dynsbss)
		*(.sbss*)
		*(.gnu.linkonce.sb.*)
		*(.dynbss)
		*(.bss*)
		*(.gnu.linkonce.b.*)
		*(COMMON)
	} > bss

	. = ALIGN(4);
}
