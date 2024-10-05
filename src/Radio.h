#include <TEA5767N.h>  // Include your TEA5767N radio library

TEA5767N radio = TEA5767N();  // Initialize the radio

struct RADIO : Service::LightBulb {

  SpanCharacteristic *power;
  
  RADIO() : Service::LightBulb() {
    power = new Characteristic::On();  // Create power characteristic
    
    radio.setMonoReception();  // Radio setup: mono reception
    radio.setStereoNoiseCancellingOn();  // Enable noise cancellation
  }

  boolean update() { 
    if (power->getNewVal()) {  // If power is ON
      radio.setStandByOff();   // Turn radio ON
      radio.selectFrequency(96.0);  // Start the radio at 96.0 MHz
    } else {
      radio.setStandByOn();  // Stop the radio (put it in standby mode)
    }
    return true; 
  } 
};
