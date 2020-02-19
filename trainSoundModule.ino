//#include <IRremote.h>
//#include <IRremoteInt.h>

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


float voltage = 0;
unsigned long count;
byte check = 0;
static const uint8_t PIN_MP3_TX = 11;
static const uint8_t PIN_MP3_RX = 10;
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);


DFRobotDFPlayerMini player;

void setup() {

Serial.begin(115200);

  softwareSerial.begin(9600);

  if (player.begin(softwareSerial)) {
    //Serial.println("OK");

    player.volume(5);

    

  } else {
    Serial.println("Hiba");
  }
}

void loop() {

  if ((analogRead(A1))== HIGH){
    player.play(2);  //kürt
  }
  
voltage = (((analogRead(A0)) * (5.0 / 1023.0))*5.0);
Serial.println(voltage);
//if ((player.readState()) == 512) {
    /*if (check == 0) {
      check = 1;
      count = millis();
    }*/
   if(voltage>4.00){
delay(map(voltage, 4.00, 14.00, 1500, 300));

player.play(1);
Serial.println(map(voltage, 4.00, 14.00, 1500, 300));
 // }
  }
  
}
