/**
 * This file defines the flags that will be used to enable and disable
 * encryption in the OpenThread source code.
 *
 * The files that utilizes these flags are as follows:
 *  - `src/port/esp_openthread_radio.c`
 *  - `openthread/src/core/mac/mac_frame.cpp`
 *
 * The function definitions for this file are in
 *  - `src/port/cse299a_encryption_debug.c`
 *  - `openthread/src/core/mac/mac_frame_cse299a_debug.cpp`
 *  - `openthread/src/core/thread/mle_cse299a_debug.cpp`
*/
#ifndef CSE299A_ENCRYPT_FLAGS_H_
#define CSE299A_ENCRYPT_FLAGS_H_

/**
 * Need "sdkconfig.h" in order to use Kconfig macros defined by
 * the user in `idf.py menuconfig`.
 * https://www.esp32.com/viewtopic.php?t=19098#p70667
*/
#include <sdkconfig.h>
#include <stdbool.h>
#include <openthread/logging.h>

/**
 * I was using enums to define the below 3 macros before.
 * The Stack Overflow post:
 * https://stackoverflow.com/questions/65652161/pre-processor-directives-if-and-endif-not-working-in-c
 *
 * Helped me realize that enums operate after compile time, and thus,
 * will lead to buggy behavior when used with preprocessor directives.
*/
#define CIPHER_SUITE CONFIG_CSE299A_CIPHER_SUITE

#define AES 0
#define NONE 1

#define ASCON_ENABLED (CIPHER_SUITE >= 2)
#define ASCON_128A_ESP32 (CIPHER_SUITE == 2)
#define ASCON_128A_REF (CIPHER_SUITE == 3)

#define AES_DATA_ENCRYPT (CIPHER_SUITE == AES)
#define AES_DATA_DECRYPT (CIPHER_SUITE == AES)
#define AES_MLE_ENCRYPT (CIPHER_SUITE == AES)
#define AES_MLE_DECRYPT (CIPHER_SUITE == AES)

#define ASCON_DATA_ENCRYPT ASCON_ENABLED
#define ASCON_DATA_DECRYPT ASCON_ENABLED
#define ASCON_MLE_ENCRYPT ASCON_ENABLED
#define ASCON_MLE_DECRYPT ASCON_ENABLED

#define NO_ENCRYPT_DECRYPT (CIPHER_SUITE == NONE)

#define CSE299A_ENCRYPT_DEBUG CONFIG_CSE299A_DEBUG_ENABLED

void dataEncryptPrintTransmitted();
void dataDecryptPrintReceived();
void mleEncryptPrintTransmitted();
void mleDecryptPrintReceived();

#endif // CSE299A_ENCRYPT_FLAGS_H_