#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

unsigned long count;
byte check = 0;
static const uint8_t PIN_MP3_TX = 11;
static const uint8_t PIN_MP3_RX = 10;
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);


DFRobotDFPlayerMini player;

void setup() {

  Serial.begin(9600);

  softwareSerial.begin(9600);

  if (player.begin(softwareSerial)) {
    Serial.println("OK");

    player.volume(15);

player.play(1);

  } else {
    Serial.println("Hiba");
  }
}

void loop() {
  
 if((player.readState())==512){
  if (check==0){
    check=1;
  count=millis();
 }

}
}
