
#ifndef _DEFINE_H_
#define _DEFINE_H_

// ======== Title ID's ======== //
#define HBC_LULZ            0x000100014c554c5aULL
#define HBC_108                0x00010001af1bf516ULL
#define HBC_JODI            0x0001000148415858ULL
#define HBC_HAXX            0x000100014a4f4449ULL
#define RETURN_CHANNEL        0x0001000857494948ULL
#define SYSTEM_MENU            0x0000000100000002ULL
#define GC_BC                0x0000000100000100ULL

#define KB_SIZE                1024.0
#define MB_SIZE                1048576.0
#define GB_SIZE                1073741824.0

#define MAX_FAT_PATH        1024

#define round_up(x,n)        (-(-(x) & -(n)))

#define ALIGN(n, x)            (((x) + (n - 1)) & ~(n - 1))
#define ALIGN32(x)            (((x) + 31) & ~31)

#define TITLE_ID(x,y)        (((u64)(x) << 32) | (y))
#define TITLE_UPPER(x)        ((u32)((x) >> 32))
#define TITLE_LOWER(x)        ((u32)(x) & 0xFFFFFFFF)

#define Write8(addr, val)    *(u8 *)addr = val; DCFlushRange((void *)addr, sizeof(u8));
#define Write16(addr, val)    *(u16 *)addr = val; DCFlushRange((void *)addr, sizeof(u16));
#define Write32(addr, val)    *(u32 *)addr = val; DCFlushRange((void *)addr, sizeof(u32));

#endif
