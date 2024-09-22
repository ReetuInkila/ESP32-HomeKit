struct RADIO : Service::LightBulb {

  int buzzerPin;
  SpanCharacteristic *power;
  
  RADIO(int buzzerPin) : Service::LightBulb(){

    power=new Characteristic::On();
    this->buzzerPin=buzzerPin;
    pinMode(buzzerPin,OUTPUT);
    
  }

  boolean update(){ 
    noTone(buzzerPin);
    if(power->getNewVal()){                      
      tone(buzzerPin, 800);
    }
    return(true); 
  } 
};