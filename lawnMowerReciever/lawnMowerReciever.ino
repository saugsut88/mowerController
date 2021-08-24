#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "functions.h"


RF24 radio(7, 8); // CE, CSN

struct package{
   int x = 512;
   int y = 512;
   int btnVal = 0; //set to 1 to start
 };

//set package data 
 typedef struct package Package;
 Package data;

//set radio connection port 
 const byte address[6] = "00001";
 //set motor pins
 const int OUT1 = 5;
 const int OUT2 = 6;
 const int OUT3 = 9;
 const int OUT4 = 10;
 //set motor speed variable
 int leftMotorSpeed = 0;
 int rightMotorSpeed = 0;
 //set led pin
 const int LED = 2;
 //struct variables

 int button1 = 0;
 // map joystick controlls




void setup() {
  
  Serial.begin(9600);
  
  delay(1500);
  radio.begin();

  //open connection address
  radio.openReadingPipe(0, address);

  //set power mode of NRF module to high (requires 
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();

  //check if reciever connected to transmitter
  bool result = radio.isChipConnected ();
  Serial.print("are coms avail: ");
  Serial.println (result);

  //set out puts to motor controller
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);

  //set speed variables
  pinMode(leftMotorSpeed, OUTPUT);
  pinMode(rightMotorSpeed, OUTPUT);

  //set values to 0, no movement
  analogWrite(OUT1, 0);
  analogWrite(OUT2, 0);
  analogWrite(OUT3, 0);
  analogWrite(OUT4, 0);
  analogWrite(leftMotorSpeed, 0);
  analogWrite(rightMotorSpeed, 0);
  digitalWrite(LED, LOW);
 
  
}//end set up


void loop() {

 
  if (radio.available()) {

    //Serial.println(text); //This will print out the received value  
    radio.read( &data, sizeof(data) );

    //set values from struct pack
    X = data.x;
    Y = data.y;
    button1 = data.btnVal;

    //serial check data tranmission
    dataCheck(X,Y,button1);

    //digital btn
    btnCall(button1);

    //mower moves
    moveMower(X, Y);
 
    
    }else{
      
      //stops mower if radio is lost
      stopMower();
      
    }//end if else radio available
    
} // end void loop



  

  
