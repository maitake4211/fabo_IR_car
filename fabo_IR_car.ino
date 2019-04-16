#include <IRremote.h>
#include <Wire.h>
#include "CarController.h"

int input_pin = 13; //set D10 as input signal pin
IRrecv irrecv(input_pin);
decode_results signals;
#define ADR_DRV_L      0x64
#define ADR_DRV_R      0x63

void setup() {
  Wire.begin();
  Serial.begin(9600);
  irrecv.enableIRIn(); // enable input from IR receiver
  Car.InitialCar();
}

void loop() {
  double i = signals.value;
 
  if (irrecv.decode(&signals)) {
    Serial.println(i);
    if(i > 17000000.00 ){     //ovfを検知
      Serial.println("ovf");
    }
    delay(100);
    else if(i == 16750695.00){
      Car.Forward();
    }
    else if(i == ){
      Car.Reverse();
    }
    else if(i == ){
       Car.TurnRight();
    }
    else if(i == ){
      Car.TurnLeft();
    }
    else if(i == ){
      Car.Stop();
    }
  }
}
