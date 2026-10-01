#pragma once

#include "types.h"
#include "status_codes.h"

// Forward declarations

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;
typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// Data structure that precedes all of the standard EFI table types.
typedef struct {
    UINT64          Signature;
    UINT32          Revision;
    UINT32          HeaderSize;
    UINT32          CRC32;
    UINT32          Reserved;
} EFI_TABLE_HEADER;

// Resets the input device hardware
typedef EFI_STATUS (EFIAPI *EFI_INPUT_RESET) (
    IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL       *This,
    IN BOOLEAN                              ExtendedVerification
);

// A pointer to a buffer that is filled in with the keystroke information for the key that was pressed
typedef struct {
    UINT16      ScanCode;
    CHAR16      UnicodeChar;
} EFI_INPUT_KEY;

// Reads the next keystroke from the input device
typedef EFI_STATUS (EFIAPI *EFI_INPUT_READ_KEY) (
    IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL       *This,
    OUT EFI_INPUT_KEY                       *Key
);

// This protocol is used to obtain input from the ConsoleIn device
struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    EFI_INPUT_RESET         Reset;
    EFI_INPUT_READ_KEY      ReadKeyStroke;
    EFI_EVENT               WaitForKey;
};

// Resets the text output device hardware
typedef EFI_STATUS (EFIAPI *EFI_TEXT_RESET) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL      *This,
    IN BOOLEAN                              ExtendedVerification
);

// Writes a string to the output device
typedef EFI_STATUS (EFIAPI *EFI_TEXT_STRING) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL      *This,
    IN CHAR16                               *String
);

// Verifies that all characters in a string can be output to the target device
typedef EFI_STATUS (EFIAPI *EFI_TEXT_TEST_STRING) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL      *This,
    IN CHAR16                               *String
);

// Returns information for an available text mode that the output device(s) supports
typedef EFI_STATUS (EFIAPI *EFI_TEXT_QUERY_MODE) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL      *This,
    IN UINTN                                ModeNumber,
    OUT UINTN                               *Columns,
    OUT UINTN                               *Rows
);

// Sets the output device(s) to a specified mode
typedef EFI_STATUS (EFIAPI *EFI_TEXT_SET_MODE) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL      *This,
    IN UINTN                                ModeNumber
);

// Sets the background and foreground colors for the OutputString()
typedef EFI_STATUS (EFIAPI *EFI_TEXT_SET_ATTRIBUTE) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL      *This,
    IN UINTN                                Attribute
);

// Clears the output device(s) display to the currently selected background color
typedef EFI_STATUS (EFIAPI *EFI_TEXT_CLEAR_SCREEN) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL      *This
);

// Sets the current coordinates of the cursor position
typedef EFI_STATUS (EFIAPI *EFI_TEXT_SET_CURSOR_POSITION) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL      *This,
    IN UINTN                                Column,
    IN UINTN                                Row
);

// Makes the cursor visible or invisible
typedef EFI_STATUS (EFIAPI *EFI_TEXT_ENABLE_CURSOR) (
    IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL      *This,
    IN BOOLEAN                              Visible
);

/*
The following data values in the SIMPLE_TEXT_OUTPUT_MODE
interface are read-only and are changed by using the
appropriate interface functions
*/
typedef struct {
    INT32                   MaxMode;
    //current settings
    INT32                   Mode;
    INT32                   Attribute;
    INT32                   CursorColumn;
    INT32                   CursorRow;
    BOOLEAN                 CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

// This protocol is used to control text-based output devices
struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    EFI_TEXT_RESET                          Reset;
    EFI_TEXT_STRING                         OutputString;
    EFI_TEXT_TEST_STRING                    TestString;
    EFI_TEXT_QUERY_MODE                     QueryMode;
    EFI_TEXT_SET_MODE                       SetMode;
    EFI_TEXT_SET_ATTRIBUTE                  SetAttribute;
    EFI_TEXT_CLEAR_SCREEN                   ClearScreen;
    EFI_TEXT_SET_CURSOR_POSITION            SetCursorPosition;
    EFI_TEXT_ENABLE_CURSOR                  EnableCursor;
    SIMPLE_TEXT_OUTPUT_MODE                 *Mode;
};

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

// This is the main entry point for a UEFI Image
typedef EFI_STATUS (EFIAPI *EFI_IMAGE_ENTRY_POINT) (
    IN EFI_HANDLE ImageHandle,
    IN EFI_SYSTEM_TABLE *SystemTable
);







