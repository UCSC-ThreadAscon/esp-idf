#include "cse299a_encryption_flags.h"

void dataEncryptPrintTransmitted() {
  if (AES_DATA_ENCRYPT) {
    otLogNotePlat("(Data Encrypt ON) Transmit Frame.");
  } else if (ASCON_DATA_ENCRYPT) {
    otLogNotePlat("(Data Encrypt ASCON) Transmit Frame.");
  } else {
    otLogNotePlat("(Data Encrypt OFF) Transmit Frame.");
  }
  return;
}