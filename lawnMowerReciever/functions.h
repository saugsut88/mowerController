
//Functions

 int X = 0;
 int Y = 0;
 
 int rightSpeed = map(X,516,1024,0,255);
 int leftSpeed = map(X,484,0,0,255);
 int backwardSpeed = map(Y,524,1024,0,255);
 int fowardSpeed = map(Y,475,0,0,255);

 
//digital button high low function
  int btnCall(int btnValue){
    int btnVal;
    btnVal = btnValue;
     if(btnVal == 0 ){
      digitalWrite(2, HIGH);
    }else{
      digitalWrite(2, LOW);
    }
  
  }//end digital button function



  void dataCheck(int Xdata, int Ydata, int btnData){
    
    int X = Xdata;
    int Y = Ydata;
    int btnVal = btnData;

    Serial.print("X:");
    Serial.print(X);
    Serial.print("      Y");
    Serial.println(Y);
    Serial.print("button: ");
    Serial.println(btnVal);
    
  }


void stopMower(){

    const int OUT1 = 5;
    const int OUT2 = 6;
    const int OUT3 = 9;
    const int OUT4 = 10;
    const int LED = 2;
    
    pinMode(OUT1, OUTPUT);
    pinMode(OUT2, OUTPUT);
    pinMode(OUT3, OUTPUT);
    pinMode(OUT4, OUTPUT);
    pinMode(LED, OUTPUT);
    
    analogWrite(OUT1, 0);
    analogWrite(OUT2, 0);
    analogWrite(OUT3, 0);
    analogWrite(OUT4, 0);
    digitalWrite(LED, LOW);
  
}


void moveMower(int Xdata, int Ydata){
   
   /*range on joysticks
   y 490 to 0 = forward
   y 490 to 1023 = reverse
   x 500 to 0 = left
   x 500 to 1023 = right
   pins on left side of joy stick  
   */
  
    int X = Xdata;
    int Y = Ydata;
    
    const int OUT1 = 5;
    const int OUT2 = 6;
    const int OUT3 = 9;
    const int OUT4 = 10;
    
    
    pinMode(OUT1, OUTPUT);
    pinMode(OUT2, OUTPUT);
    pinMode(OUT3, OUTPUT);
    pinMode(OUT4, OUTPUT);

    if(Y > 505 && X < 515 && X > 485){
      //reverse
      analogWrite(OUT1, backwardSpeed);
      analogWrite(OUT2, 0);
      analogWrite(OUT3, 0);
      analogWrite(OUT4, backwardSpeed);

    }else if(Y < 480 && X < 515 && X > 485){
     //forward
      analogWrite(OUT1, 0);
      analogWrite(OUT2, fowardSpeed);
      analogWrite(OUT3, fowardSpeed);
      analogWrite(OUT4, 0);
    
    }else if (Y < 504 && Y > 481 && X < 515 && X > 485){
      //Stand Still
      analogWrite(OUT1, 0);
      analogWrite(OUT2, 0);
      analogWrite(OUT3, 0);
      analogWrite(OUT4, 0);
      
    }else if (Y < 504 && Y > 481 && X < 484){
      //turn left
      analogWrite(OUT1, leftSpeed);
      analogWrite(OUT2, 0);
      analogWrite(OUT3, leftSpeed);
      analogWrite(OUT4, 0);
    }else if (Y < 504 && Y > 481 && X > 516){
      //turn left
      analogWrite(OUT1, 0);
      analogWrite(OUT2, rightSpeed);
      analogWrite(OUT3, 0);
      analogWrite(OUT4, rightSpeed);
    }

  
}
