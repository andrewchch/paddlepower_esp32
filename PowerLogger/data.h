

#ifndef HEADER_DATA
#define HEADER_DATA

#define BLE_DATA_LENGTH 2
#define BLE_MAX_BYTES 20
#define MIN_READINGS 50
#define MAX_READINGS 100
   
//Prototype for data helper functions found in data.cpp
void sendData (uint8_t data[], int size, BLECharacteristic* pCharacteristic);
   
#endif
