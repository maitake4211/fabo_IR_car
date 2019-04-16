#include <IRremote.h>
#include <Wire.h>
#include <CarController.h>

int input_pin = 13; //set D10 as input signal pin
IRrecv irrecv(input_pin);
decode_results signals;

#define ADR_DRV_L      0x64
#define ADR_DRV_R      0x63
CarController Car = CarController(ADR_DRV_R, ADR_DRV_L);

void setup() {
  Wire.begin();
  Serial.begin(9600);
  irrecv.enableIRIn(); // enable input from IR receiver
  Car.InitialCar();
}

void loop() {
  double i = signals.value;
  double beferSignal = 0;

  if (irrecv.decode(&signals)) {
    Serial.println(i);
    if (i > 17000000.00 ) {   //ovfを検知
      i = beferSignal;
    } else if (i == 16718055.00) {
      Car.Forward();
      beferSignal = i;
    } else if (i == 16730805.00) {
      Car.Reverse();
      beferSignal = i;
    } else if (i == 16734885.00) {
      Car.TurnRight();
      beferSignal = i;
    } else if (i == 16716015.00) {
      Car.TurnLeft();
      beferSignal = i;
    }else if(i == 16726215.00){
      Car.Stop();
      beferSignal = i;
    }
    delay(100);
    irrecv.resume();
  }
}
