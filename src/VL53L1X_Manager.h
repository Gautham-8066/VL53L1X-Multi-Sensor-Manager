#ifndef VL53L1X_MANAGER_H
#define VL53L1X_MANAGER_H

//#define UNIT_TEST 

#include <Arduino.h>

#ifdef UNIT_TEST
  #include "MockVL53L1X.h"
#else
  #include <VL53L1X.h>     
#endif

class VL53L1X_Manager {
  public:
    VL53L1X_Manager(VL53L1X *sensors, uint8_t *xshutPins, uint8_t count);
    bool begin();

  private:
    VL53L1X *_sensors;
    uint8_t *_xshutPins;
    uint8_t _count;
    const uint8_t START_ADDR = 0x30;
};

#endif
