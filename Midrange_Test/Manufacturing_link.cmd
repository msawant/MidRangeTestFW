/* C6x Elf symbols */
--symbol_map __TI_STACK_SIZE=__STACK_SIZE
--symbol_map __TI_STACK_BASE=__stack
--symbol_map _stack=__stack




--args 0x200
-heap  0x30000
-stack 0x30000

MEMORY
{
    IRAM (RWX) : org = 0xffff0000, len = 0x2000
    L3_CBA_RAM (RWX) : org = 0x80000000, len = 0x20000
    DDR : org = 0xc3000000, len = 0x1000000
}


SECTIONS
{
    .cio: load >> L3_CBA_RAM
    GROUP: load > L3_CBA_RAM
    {
        .bss:
        .neardata:
        .rodata:
    }
    .text: load >> DDR
    .far: load >> L3_CBA_RAM
    .sysmem: load > DDR
    .pinit: load > L3_CBA_RAM
    .cinit: load > L3_CBA_RAM
    .vectorTable: load > 0xffff0040
    .args: load > L3_CBA_RAM align = 0x4, fill = 0 {_argsize = 0x200; }
    .switch: load >> L3_CBA_RAM
    .data: load >> L3_CBA_RAM
    .stack: load > L3_CBA_RAM
    .vecs: load > 0xffff0000
    .fardata: load >> L3_CBA_RAM
    .const: load >> L3_CBA_RAM
}
