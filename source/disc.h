
#ifndef _DISC_H_
#define _DISC_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define WII_MAGIC            0x5D1C9EA3
#define GC_MAGIC            0xC2339F3D

/* Disc header structure */
struct discHdr
{
    /* Game ID */
    u8 id[6];

    /* Game version */
    u16 version;

    /* Audio streaming */
    u8 streaming;
    u8 bufsize;

    /* Padding */
    u64 chantitle; // Used for channels

    /* Sorting */
    u16 index;
    u8 esrb;
    u8 controllers;
    u8 players;
    u8 wifi;

    /* Wii Magic word */
    u32 magic;

    /* GC Magic word */
    u32 gc_magic;

    /* Game title */
    char title[64];

    /* Encryption/Hashing */
    u8 encryption;
    u8 h3_verify;

    /* Padding */
    u32 casecolor;
    u8 unused3[26];
} ATTRIBUTE_PACKED;

struct gc_discHdr
{
    /* Game ID */
    u8 id[6];

    /* Game version */
    u16 version;

    /* Audio streaming */
    u8 streaming;
    u8 bufsize;

    /* Padding */
    u8 unused1[18];

    /* Magic word */
    u32 magic;

    /* Game title */
    char title[64];

    /* Padding */
    u8 unused2[64];
} ATTRIBUTE_PACKED;

s32 Disc_Open();
void Disc_Boot();
s32 Disc_FindPartition(u32 *outbuf);
void Disc_SetLowMemPre();
void Disc_SetLowMem(u32 IOS);
void Disc_SetLowMemChan();
void Disc_SetTime();

GXRModeObj *Disc_SelectVMode(u32 *rmode_reg);
void Disc_SetVMode(GXRModeObj *rmode, u32 rmode_reg);

s32 Disc_IsWii(void);
s32 Disc_IsGC(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
