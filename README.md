# VL53L1X Multi-Sensor Manager

A lightweight C++ wrapper for the [Pololu VL53L1X Library](https://github.com/pololu/vl53l1x-arduino) that simplifies managing multiple Time-of-Flight sensors on the same I2C bus.

## 🚀 Features
* **Automatic Addressing:** Handles the complex `XSHUT` reset sequence to assign unique I2C addresses dynamically.
* **Scalable:** Initialize 2, 5, or 10 sensors with a single array.
* **Mock Unit Testing:** Includes a "Hardware-less" test mode (`#define UNIT_TEST`) to verify logic in CI/CD environments without physical sensors.

## 🛠️ Wiring & Setup
The VL53L1X defaults to address `0x29`. To use multiple sensors, we must control their `XSHUT` pins individually.

| Component | Arduino Pin |
|-----------|-------------|
| **SDA** | A4 (Shared) |
| **SCL** | A5 (Shared) |
| **Sensor 1 XSHUT** | Digital 4 |
| **Sensor 2 XSHUT** | Digital 5 |
| **Sensor 3 XSHUT** | Digital 6 |

## 📦 Usage
```cpp
#include "VL53L1X_Manager.h"

// 1. Define your setup
const uint8_t COUNT = 2;
uint8_t xshutPins[COUNT] = {4, 5};
VL53L1X sensors[COUNT];

// 2. Initialize the Manager
VL53L1X_Manager manager(sensors, xshutPins, COUNT);

void setup() {
  Wire.begin();
  
  // 3. One-line initialization
  if (manager.begin()) {
    Serial.println("All sensors addressed and ready!");
  }
}
