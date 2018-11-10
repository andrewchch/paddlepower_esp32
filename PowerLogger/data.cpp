#include <BLEUtils.h>
#include <math.h>
#include <Arduino.h>
#include "data.h"

inline int min(int a, int b) { return ((a)<(b) ? (a) : (b)); }

void sendData (uint8_t data[], int size, BLECharacteristic* pCharacteristic) {
  int index = 0;
  int tx_index = 0;
  uint8_t tx_buffer[BLE_MAX_BYTES];

  // TODO: need to add current time (millis) and length of packet to buffer
  
  while (index < size) {
    // Transfer a chunk of data to the tx_buffer
    tx_index = 0;
    for (int i=index; i<min(index + BLE_MAX_BYTES,size); i++) {
      tx_buffer[tx_index] = data[index];
      tx_index++;
    }

    // Send the buffer
    pCharacteristic->setValue(tx_buffer, BLE_MAX_BYTES);
    pCharacteristic->indicate();

    // Increment the readings buffer index 
    index += BLE_MAX_BYTES;
    
    delay(20); // bluetooth stack will go into congestion, if too many packets are sent
  }
}
