#pragma once

#include "types.h"

#define EFI_SUCCESS                   ((EFI_STATUS)0)         // The operation completed successfully

#define EFI_ERROR_BIT                 (((EFI_STATUS)1) << (sizeof(EFI_STATUS) * 8 - 1))
#define ENCODE_ERROR(e)               ((EFI_STATUS)(EFI_ERROR_BIT | (e)))
#define ENCODE_WARNING(w)             ((EFI_STATUS)(w))


// EFI_STATUS Error Codes (High Bit Set)

#define EFI_LOAD_ERROR                      ENCODE_ERROR(1)      // The image failed to load
#define EFI_INVALID_PARAMETER               ENCODE_ERROR(2)      // A parameter was incorrect
#define EFI_UNSUPPORTED                     ENCODE_ERROR(3)      // The operation is not supported
#define EFI_BAD_BUFFER_SIZE                 ENCODE_ERROR(4)      // The buffer was not the proper size for the request
#define EFI_BUFFER_TOO_SMALL                ENCODE_ERROR(5)      // The buffer is not large enough to hold the requested data
#define EFI_NOT_READY                       ENCODE_ERROR(6)      // There is no data pending upon return
#define EFI_DEVICE_ERROR                    ENCODE_ERROR(7)      // The physical device reported an error while attempting the operation
#define EFI_WRITE_PROTECTED                 ENCODE_ERROR(8)      // The device cannot be written to
#define EFI_OUT_OF_RESOURCES                ENCODE_ERROR(9)      // A resource has run out
#define EFI_VOLUME_CORRUPTED                ENCODE_ERROR(10)     // An inconstancy was detected on the file system causing the operating to fail
#define EFI_VOLUME_FULL                     ENCODE_ERROR(11)     // There is no more space on the file system
#define EFI_NO_MEDIA                        ENCODE_ERROR(12)     // The device does not contain any medium to perform the operation
#define EFI_MEDIA_CHANGED                   ENCODE_ERROR(13)     // The medium in the device has changed since the last access
#define EFI_NOT_FOUND                       ENCODE_ERROR(14)     // The item was not found
#define EFI_ACCESS_DENIED                   ENCODE_ERROR(15)     // Access was denied
#define EFI_NO_RESPONSE                     ENCODE_ERROR(16)     // The server was not found or did not respond to the request
#define EFI_NO_MAPPING                      ENCODE_ERROR(17)     // A mapping to a device does not exist
#define EFI_TIMEOUT                         ENCODE_ERROR(18)     // The timeout time expired
#define EFI_NOT_STARTED                     ENCODE_ERROR(19)     // The protocol has not been started
#define EFI_ALREADY_STARTED                 ENCODE_ERROR(20)     // The protocol has already been started
#define EFI_ABORTED                         ENCODE_ERROR(21)     // The operation was aborted
#define EFI_ICMP_ERROR                      ENCODE_ERROR(22)     // An ICMP error occurred during the network operation
#define EFI_TFTP_ERROR                      ENCODE_ERROR(23)     // A TFTP error occurred during the network operation
#define EFI_PROTOCOL_ERROR                  ENCODE_ERROR(24)     // A protocol error occurred during the network operation
#define EFI_INCOMPATIBLE_VERSION            ENCODE_ERROR(25)     // The function encountered an internal version that was incompatible with a version requested by the caller
#define EFI_SECURITY_VIOLATION              ENCODE_ERROR(26)     // The function was not performed due to a security violation
#define EFI_CRC_ERROR                       ENCODE_ERROR(27)     // A CRC error was detected
#define EFI_END_OF_MEDIA                    ENCODE_ERROR(28)     // Beginning or end of media was reached
#define EFI_EC29_UNSPECIFIED                ENCODE_ERROR(29)     // Not specified
#define EFI_EC30_UNSPECIFIED                ENCODE_ERROR(30)     // Not specified
#define EFI_END_OF_FILE                     ENCODE_ERROR(31)     // The end of the file was reached
#define EFI_INVALID_LANGUAGE                ENCODE_ERROR(32)     // The language specified was invalid
#define EFI_COMPROMISED_DATA                ENCODE_ERROR(33)     // The security status of the data is unknown or compromised and the data must be updated or replaced to restore a valid security status
#define EFI_IP_ADDRESS_CONFLICT             ENCODE_ERROR(34)     // There is an address conflict address allocation
#define EFI_HTTP_ERROR                      ENCODE_ERROR(35)     // A HTTP error occurred during the network operation


// EFI_STATUS Warning Codes (High Bit Clear)

#define EFI_WARN_UNKNOWN_GLYPH              ENCODE_WARNING(1)    // The string contained one or more characters that the device could not render and were skipped
#define EFI_WARN_DELETE_FAILURE             ENCODE_WARNING(2)    // The handle was closed, but the file was not deleted
#define EFI_WARN_WRITE_FAILURE              ENCODE_WARNING(3)    // The handle was closed, but the data to the file was not flushed properly
#define EFI_WARN_BUFFER_TOO_SMALL           ENCODE_WARNING(4)    // The resulting buffer was too small, and the data was truncated to the buffer size
#define EFI_WARN_STALE_DATA                 ENCODE_WARNING(5)    // The data has not been updated within the timeframe set by local policy for this type of data
#define EFI_WARN_FILE_SYSTEM                ENCODE_WARNING(6)    // The resulting buffer contains UEFI-compliant file system
#define EFI_WARN_RESET_REQUIRED             ENCODE_WARNING(7)    // The operation will be processed across a system reset


#define EFI_ERROR(c)            ((BOOLEAN)(((INTN)(c)) < 0))
#define EFI_WARNING(c)          ((BOOLEAN)(((INTN)(c)) > 0))