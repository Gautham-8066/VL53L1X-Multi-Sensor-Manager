#ifndef MOCK_VL53L1X_H
#define MOCK_VL53L1X_H

#include <Arduino.h>

// This class mimics the real Pololu VL53L1X library interface
class VL53L1X {
  public:
    uint8_t address;
    bool isInit;

    VL53L1X() {
      address = 0x29; // The default address of the real sensor
      isInit = false;
    }

    // Mock init: always return true
    bool init() {
      isInit = true;
      return true; 
    }

    // Mock setAddress: just save the variable so we can check it later
    void setAddress(uint8_t newAddr) {
      address = newAddr;
    }

    // Mock other functions to prevent crash
    void setTimeout(uint16_t timeout) {}
    void startContinuous(uint32_t period) {}
    
    // Return a fake distance so we see "something" happening
    uint16_t read() { return 888; }
};

#endif
