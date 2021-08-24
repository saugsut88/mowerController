 #include <SPI.h>
 #include "nRF24L01.h"
 #include "RF24.h"

 RF24 radio(7, 8); // CE, CSN
 int text = 1;
 const byte address[6] = "00001";

//button
int btn = 2;

//variable
int btnVal = 0;

struct package{
  int x = 1; 
  int y = 1;
  int btnVal = 0;
};


typedef struct package Package;

Package data;


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();

  bool result = radio.isChipConnected ();

  Serial.println (result);

  //define btn
  pinMode(btn, INPUT_PULLUP);

  
  
}


void loop() {
  //const char text[] = "Hello World";

  data.x = analogRead(A0);
  data.y = analogRead(A1);
  btnVal = digitalRead(btn);
  data.btnVal = btnVal;
  
  
  
  radio.write(&data, sizeof(data)); 
  //Serial.println("Sending Data");

  Serial.print("X:");
  Serial.print(data.x);
  Serial.print("    Y");
  Serial.println(data.y);
  Serial.println("btn");
  Serial.print(data.btnVal);

  //Serial.print(btnVal);

  delay(100);
  
  
 }
