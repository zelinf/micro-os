#pragma once

// Address of the first page frame.
// And this is where the meta info is stored
#define PMM_BEGIN 0x100000u

#define PAGE_SIZE 4096u
#define PAGE_SHIFT 12u
#define PAGE_DIR_SHIFT 22u

#define KERNEL_STACK_BASE 0x7FFFF

#define PT_VADDR 0x800000

#define PT_SIZE 0x400000

#define MiB 0x100000u

#define KERNEL_GLOBAL_DATA (16 * MiB)

#define PROC_BEGIN (128u * MiB)

#define PROC_STACK_BASE (512u * MiB)

#define PROC_STACK_SIZE (2u * MiB)
