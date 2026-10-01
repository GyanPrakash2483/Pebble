#pragma once

#include "types.h"

// Data structure that precedes all of the standard EFI table types.
typedef struct {
    UINT64          Signature;
    UINT32          Revision;
    UINT32          HeaderSize;
    UINT32          CRC32;
    UINT32          Reserved;
} EFI_TABLE_HEADER;

// Contains pointers to the runtime and boot services tables.
typedef struct {
    EFI_TABLE_HEADER                    Hdr;
    CHAR16                              *FirmwareVendor;
    UINT32                              FirmwareRevision;
    EFI_HANDLE                          ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL      *ConIn;
    EFI_HANDLE                          ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL     *ConOut;
    EFI_HANDLE                          StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL     *StdErr;
    EFI_RUNTIME_SERVICES                *RuntimeServices;
    EFI_BOOT_SERVICES                   *BootServices;
    UINTN                               NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE             *ConfigurationTable;
} EFI_SYSTEM_TABLE;