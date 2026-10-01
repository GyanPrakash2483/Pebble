#pragma once

typedef signed char INT8;               // 1-byte signed value
typedef signed short INT16;             // 2-byte signed value
typedef signed int INT32;               // 4-byte signed value
typedef signed long long INT64;         // 8-byte signed value

typedef unsigned char UINT8;            // 1-byte unsigned value
typedef unsigned short UINT16;          // 2-byte unsigned value
typedef unsigned int UINT32;            // 4-byte unsigned value
typedef unsigned long long UINT64;      // 8-byte unsigned value

typedef char CHAR8;                     // 1-byte character
typedef UINT16 CHAR16;                  // 2-byte character

typedef void VOID;                      // Undeclared type
typedef UINT8 BOOLEAN;                  // Logical Boolean. 1-byte value containing a 0 for FALSE or a 1 for TRUE.

#define TRUE 1
#define FALSE 0
#define true 1
#define false 0

#define NULL ((VOID *)0)

typedef INT64 INTN;                     // Signed value of native width (8 bytes on supported 64-bit processor instructions)
typedef UINT64 UINTN;                   // Unsigned value of native width (8 bytes on supported 64-bit processor instructions)

// 128-bit buffer containing a unique identifier value. Unless otherwise specified, aligned on a 64-bit boundary.
typedef struct __attribute__((aligned(8))) {
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];                     
} EFI_GUID;

typedef UINTN EFI_STATUS;               // Status code (Type UINTN)

typedef VOID *EFI_HANDLE;               // A collection of related interfaces (Type VOID *)
typedef VOID *EFI_EVENT;                // Handle to an event structure (Type VOID *)

typedef UINT64 EFI_LBA;                 // Logical block address (Type UINT64)
typedef UINTN EFI_TPL;                  // Task priority level (Type UINTN)

// 32-byte buffer containing a network Media Access Control address
typedef struct {
    UINT8 Addr[32];
} EFI_MAC_ADDRESS;

// An IPv4 internet protocol address (4-byte buffer)
typedef struct {
    UINT8 Addr[4];
} EFI_IPv4_ADDRESS;

// An IPv6 internet protocol address (16-byte buffer)
typedef struct {
    UINT8 Addr[16];
} EFI_IPv6_ADDRESS;

// 16-byte buffer aligned on a 4-byte boundary. An IPv4 or IPv6 internet protocol address.
typedef union __attribute__((aligned(4))) {
    UINT32 Addr[4];
    EFI_IPv4_ADDRESS v4;
    EFI_IPv6_ADDRESS v6;
} EFI_IP_ADDRESS;


// Modifiers for Common UEFI Data Types
#define IN
#define OUT
#define OPTIONAL
#define CONST const
#define EFIAPI __attribute__((ms_abi))


/* ---------- Primitive type sizes ---------- */
_Static_assert(sizeof(INT8)    == 1, "INT8 must be 1 byte");
_Static_assert(sizeof(UINT8)   == 1, "UINT8 must be 1 byte");
_Static_assert(sizeof(INT16)   == 2, "INT16 must be 2 bytes");
_Static_assert(sizeof(UINT16)  == 2, "UINT16 must be 2 bytes");
_Static_assert(sizeof(INT32)   == 4, "INT32 must be 4 bytes");
_Static_assert(sizeof(UINT32)  == 4, "UINT32 must be 4 bytes");
_Static_assert(sizeof(INT64)   == 8, "INT64 must be 8 bytes");
_Static_assert(sizeof(UINT64)  == 8, "UINT64 must be 8 bytes");

_Static_assert(sizeof(BOOLEAN) == 1, "BOOLEAN must be 1 byte");
_Static_assert(sizeof(CHAR8)   == 1, "CHAR8 must be 1 byte");
_Static_assert(sizeof(CHAR16)  == 2, "CHAR16 must be 2 bytes");

/* ---------- Signedness ---------- */
_Static_assert((INT8)-1  < 0, "INT8 must be signed");
_Static_assert((INT16)-1 < 0, "INT16 must be signed");
_Static_assert((INT32)-1 < 0, "INT32 must be signed");
_Static_assert((INT64)-1 < 0, "INT64 must be signed");
_Static_assert((UINT8)-1  > 0, "UINT8 must be unsigned");
_Static_assert((UINT16)-1 > 0, "UINT16 must be unsigned");
_Static_assert((UINT32)-1 > 0, "UINT32 must be unsigned");
_Static_assert((UINT64)-1 > 0, "UINT64 must be unsigned");

/* ---------- Native width (x86_64) ---------- */
_Static_assert(sizeof(VOID *) == 8, "expected 64-bit pointers");
_Static_assert(sizeof(INTN)  == sizeof(VOID *), "INTN must be pointer-sized");
_Static_assert(sizeof(UINTN) == sizeof(VOID *), "UINTN must be pointer-sized");

/* ---------- Handles and aliases ---------- */
_Static_assert(sizeof(EFI_STATUS) == sizeof(UINTN), "EFI_STATUS is UINTN");
_Static_assert(sizeof(EFI_HANDLE) == 8, "EFI_HANDLE is a pointer");
_Static_assert(sizeof(EFI_EVENT)  == 8, "EFI_EVENT is a pointer");
_Static_assert(sizeof(EFI_LBA)    == 8, "EFI_LBA is 64-bit");
_Static_assert(sizeof(EFI_TPL)    == sizeof(UINTN), "EFI_TPL is UINTN");

/* ---------- EFI_GUID ---------- */
_Static_assert(sizeof(EFI_GUID)            == 16, "EFI_GUID size");
_Static_assert(_Alignof(EFI_GUID)          == 8,  "EFI_GUID alignment");
_Static_assert(__builtin_offsetof(EFI_GUID, Data1) == 0,  "Data1 offset");
_Static_assert(__builtin_offsetof(EFI_GUID, Data2) == 4,  "Data2 offset");
_Static_assert(__builtin_offsetof(EFI_GUID, Data3) == 6,  "Data3 offset");
_Static_assert(__builtin_offsetof(EFI_GUID, Data4) == 8,  "Data4 offset");

/* ---------- Network addresses ---------- */
_Static_assert(sizeof(EFI_MAC_ADDRESS)  == 32, "EFI_MAC_ADDRESS size");
_Static_assert(sizeof(EFI_IPv4_ADDRESS) == 4,  "EFI_IPv4_ADDRESS size");
_Static_assert(sizeof(EFI_IPv6_ADDRESS) == 16, "EFI_IPv6_ADDRESS size");
_Static_assert(sizeof(EFI_IP_ADDRESS)   == 16, "EFI_IP_ADDRESS size");
_Static_assert(_Alignof(EFI_IP_ADDRESS) == 4,  "EFI_IP_ADDRESS alignment");

