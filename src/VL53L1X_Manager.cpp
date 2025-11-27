#include "VL53L1X_Manager.h"

VL53L1X_Manager::VL53L1X_Manager(VL53L1X *sensors, uint8_t *xshutPins, uint8_t count) {
  _sensors = sensors;
  _xshutPins = xshutPins;
  _count = count;
}

bool VL53L1X_Manager::begin() {
  // 1. Reset ALL sensors (pull XSHUT low)
  for (int i = 0; i < _count; i++) {
    pinMode(_xshutPins[i], OUTPUT);
    digitalWrite(_xshutPins[i], LOW);
  }
  delay(10); 

  // 2. Bring them up one by one
  for (int i = 0; i < _count; i++) {
    // Enable this sensor
    pinMode(_xshutPins[i], INPUT); 
    delay(10); 

    // Initialize (Calls our Mock init)
    if (!_sensors[i].init()) {
      return false;
    }

    // Change Address (Calls our Mock setAddress)
    _sensors[i].setAddress(START_ADDR + i);
    
    _sensors[i].startContinuous(50); 
  }
  return true;
}
