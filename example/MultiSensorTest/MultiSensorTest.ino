#define UNIT_TEST
#include "MockVL53L1X.h"
#include "VL53L1X_Manager.h"

// Define test configuration
const uint8_t SENSOR_COUNT = 3;
uint8_t xshutPins[SENSOR_COUNT] = {4, 5, 6}; // We don't need real wires, just valid pin numbers

VL53L1X mySensors[SENSOR_COUNT];
VL53L1X_Manager manager(mySensors, xshutPins, SENSOR_COUNT);

void setup() {
  Serial.begin(9600);
  Serial.println("--- STARTING UNIT TEST ---");

  // Step 1: Run the Manager
  Serial.println("Running manager.begin()...");
  bool success = manager.begin();

  // Step 2: Validate Results
  if (success) {
    Serial.println("[ PASS ] Manager returned Success.");
  } else {
    Serial.println("[ FAIL ] Manager returned Error.");
  }

  // Step 3: Check if addresses were actually changed in memory
  // We expect: Sensor 0 -> 0x30 (48), Sensor 1 -> 0x31 (49), Sensor 2 -> 0x32 (50)
  for (int i = 0; i < SENSOR_COUNT; i++) {
    Serial.print("Sensor "); Serial.print(i);
    Serial.print(" Address: 0x"); Serial.print(mySensors[i].address, HEX);
    
    uint8_t expected = 0x30 + i;
    if (mySensors[i].address == expected) {
       Serial.println(" [ PASS ]");
    } else {
       Serial.print(" [ FAIL ] - Expected 0x"); Serial.println(expected, HEX);
    }
  }
}

void loop() {}
