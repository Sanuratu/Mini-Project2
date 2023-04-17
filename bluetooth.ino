#include <AFMotor.h>
#include<SoftwareSerial.h>
#define ENA 5
#define ENB 6
#define IN1 3 //3
#define IN2 4
#define IN3 2 //2
#define IN4 7

//SoftwareSerial mySerial(2, 3); // RX, TX


String data;
int btVal;

void setup() 
{  
  //mySerial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  // digitalWrite(IN1, LOW);
  // digitalWrite(IN2, LOW);
  // digitalWrite(IN3, LOW);
  // digitalWrite(IN4, LOW);
  // analogWrite(EN1,63);
  // analogWrite(EN2,63);
  Serial.begin(9600);
}

void loop()
{
//  while (mySerial.available())
//  {  
//   {  
//       data = mySerial.readStringUntil('\n');
//       //Serial.print(str);             
//   } 
    
//     btVal = (data.toInt());
//     //Serial.print("BlueToothe ");
//     //Serial.println(btVal);    



//   switch (btVal) 
//    {
//       case 1:                                
//         //Serial.println("Forward");
//         forward();
//         break;

//       case 2:                 
//        //Serial.println("Reverse");
//         reverse();
//         break;

//       case 3:         
//        //Serial.println("Left");
//         left();
//         break;
        
//       case 4:                     
//         //Serial.println("Right");
//         right();
//         break;
        
//       case 5:                                            
//         //Serial.println("Stop");
//         stoprobot();
//         break;      

//   }

//  } 
 
                                                              
//    if (mySerial.available() < 0)                              
//     {
//      //Serial.println("No Bluetooth Data ");          
//     }
  
  // mIT App
  if (Serial.available())
  {
    String Direction = Serial.readString();
    Serial.println(Direction);
    if (Direction == "F")
    {
      //forward
      forward();
    }

    else if (Direction == "B")
    {
      reverse();
    }

    else if (Direction == "L")
    {
      left();
    }

    else if (Direction == "R")
    {
      right();
    }

    else if (Direction == "S")
    {
      stoprobot();
    }
  }
}

void forward()
{
  analogWrite(ENA, 220);
  analogWrite(ENB, 220);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverse()
{
  analogWrite(ENA, 220);
  analogWrite(ENB, 220);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left()
{
  analogWrite(ENA, 220);
  analogWrite(ENB, 220);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  analogWrite(ENA, 220);
  analogWrite(ENB, 220);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stoprobot()
{
  analogWrite(ENA, LOW);
  analogWrite(ENB, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}