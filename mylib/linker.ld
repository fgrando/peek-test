SECTIONS
{
    .text : {
        *(.text)
    }
    .data : {
        __MYLIB_start_data = .;
        *(.data)
        __MYLIB_end_data = .;
    }
    .bss : {
        __MYLIB_start_bss = .;
        *(.bss)
        *(COMMON)
        __MYLIB_end_bss = .;
    }
}
