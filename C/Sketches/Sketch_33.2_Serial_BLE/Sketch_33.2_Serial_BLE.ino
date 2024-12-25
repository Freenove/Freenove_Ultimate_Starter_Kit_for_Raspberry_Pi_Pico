#include <BTstackLib.h> 
#include <SPI.h>
#include "btstack.h"

#define MAX_LENGTH 256
static char characteristic_data[MAX_LENGTH] = "Pico W Bluetooth";

// Track subscription status
bool isSubscribed = false;

// The handle of the connection
hci_con_handle_t connection_handle = HCI_CON_HANDLE_INVALID;

// characteristic handle
uint16_t characteristic_handle = 0;

// Assuming the handle of CCCD is a characteristic handle+1
#define CCCD_HANDLE (characteristic_handle + 1)

void setupBLE(const char *BLEName){
  //Set callback function
  BTstack.setBLEDeviceConnectedCallback(deviceConnectedCallback);
  BTstack.setBLEDeviceDisconnectedCallback(deviceDisconnectedCallback);
  BTstack.setGATTCharacteristicRead(gattReadCallback);
  BTstack.setGATTCharacteristicWrite(gattWriteCallback);

  //Set GATT database
  BTstack.addGATTService(new UUID("B8E06067-62AD-41BA-9231-206AE80AB551"));
  characteristic_handle = BTstack.addGATTCharacteristicDynamic(
    new UUID("f897177b-aee8-4767-8ecc-cc694fd5fce0"),
    ATT_PROPERTY_READ | ATT_PROPERTY_WRITE | ATT_PROPERTY_NOTIFY,
    0
    );

  //Activate Bluetooth and broadcast
  BTstack.setup(BLEName);
  BTstack.startAdvertising();

  Serial.println("Waiting a client connection to notify...");
}

void setup(void) {
  Serial.begin(115200);
  delay(2000);

  setupBLE("PicoW_BLE");
}

void loop(void) {
  BTstack.loop();

  if (Serial.available() > 0) {                     // Check if there is serial data
    String input = Serial.readStringUntil('\n');
    input.trim();                                   // Remove front and back blank spaces

    size_t input_length = input.length();           // Get String length

    // Copy input to characteristic_data  and add line breaks
    memcpy(characteristic_data, input.c_str(), input_length);
    characteristic_data[input_length] = '\n';       // add linefeeds
    characteristic_data[input_length + 1] = '\0';   // End of string

    Serial.print("input data: ");
    Serial.print(characteristic_data);

    sendNotificationToSubscribers();                //Send notifications to subscribed devices
  }
  //Delay by 5ms to prevent data loss due to receiving too quickly
  delay(5);
}

void deviceConnectedCallback(BLEStatus status, BLEDevice *device) {
  if(status == BLE_STATUS_OK) {
    Serial.println("Device connected!");
    connection_handle = device->getHandle();          // Get connection handle
  }
}

void deviceDisconnectedCallback(BLEDevice * device) {
  (void) device;
  Serial.println("Disconnected.");
  connection_handle = HCI_CON_HANDLE_INVALID;
  isSubscribed = false;                               // Reset subscription status
}

// Callback function for reading data
uint16_t gattReadCallback(uint16_t value_handle, uint8_t * buffer, uint16_t buffer_size) {
  (void) value_handle;
  if (buffer && buffer_size > 0) {
    Serial.print("Read data: ");
    Serial.println(characteristic_data);

    size_t data_length = strlen(characteristic_data); // Get characteristic_data length
    if (data_length > buffer_size) {                  // Limit length
      data_length = buffer_size;
    }

    memcpy(buffer, characteristic_data, data_length); // Copy String
    return data_length;
  }
  return 0;
}

// Callback function for writing data
int gattWriteCallback(uint16_t value_handle, uint8_t *buffer, uint16_t size) {
  if (value_handle == CCCD_HANDLE) {                  // Processing CCCD writing
    if (size >= 2) {
      uint16_t cccd_value = buffer[0] | (buffer[1] << 8);
      isSubscribed = true;                            //Subscription status is true
    }
  } else { // Writing of processing feature data
    size_t copy_size = (size < (MAX_LENGTH - 1)) ? size : (MAX_LENGTH - 1);
    memcpy(characteristic_data, buffer, copy_size);   // Copy String
    characteristic_data[copy_size] = '\0';            // Ensure that the string ends

    Serial.print("Received data: ");
    Serial.println(characteristic_data);
  }

  return 0;
}

void sendNotificationToSubscribers() {
  if (isSubscribed && connection_handle != HCI_CON_HANDLE_INVALID) {
    // Send notifications
    att_server_notify(connection_handle, characteristic_handle, 
                      (uint8_t*)characteristic_data, strlen(characteristic_data));
  }
}
