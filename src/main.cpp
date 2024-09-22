#include <Arduino.h>
#include "HomeSpan.h"
#include "Radio.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  homeSpan.setPairingCode("11122333");
  homeSpan.setQRID("111-22-333");

  homeSpan.begin(Category::Other, "Radio");

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
    new RADIO(16); 
}

void loop() {
  homeSpan.poll();
}
