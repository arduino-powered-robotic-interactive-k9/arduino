#include <Servo.h>

// pin assignments
#define FRH_pin    23
#define FRK_pin    24
#define FLH_pin    26
#define FLK_pin    27

#define BRH_pin    29
#define BRK_pin    30
#define BLH_pin    32
#define BLK_pin    33

#define head_pin   22
#define neck_pin   25
#define tail_pin   31

// bluetooth Initation
char c;
String voice = "";

// servos
Servo FRH, FRK, FLH, FLK, BRH, BRK, BLH, BLK;
Servo head, neck, tail;
const int pingPin = 2; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 3; // Echo Pin of Ultrasonic Sensor
boolean t = false;

//default state 
void hey()
 {
  if (checkBluetooth()) return;
  
  alert();
  
  if (checkBluetooth()) return;
  
  delay(500);
  
  if (checkBluetooth()) return;
  
  sit();
  
  if (checkBluetooth()) return;
  
  head2();
  
  if (checkBluetooth()) return;
  
  delay(1000);
  
  if (checkBluetooth()) return;
  
  tail2();
  
  if (checkBluetooth()) return;
  
  delay(1000);
  
  if (checkBluetooth()) return;
  
  tail2();
  
  if (checkBluetooth()) return;
  
  delay(1000);
  
  if (checkBluetooth()) return;
  
  tail2();
  
  if (checkBluetooth()) return;
  
  delay(1000);
  
  if (checkBluetooth()) return;
  
  down();
  
  if (checkBluetooth()) return;
  
  delay(1000);
  
  if (checkBluetooth()) return;
  
  head2();

  delay(500);
 }

void tail2()
{
  for (int i = 0; i < 181; i++)
  {
  delay(4);
  tail.write(i);
  }
}

void head2()
{
  for(int i = 0; i <4; i++)
  {
    head.write(15);
    delay(150);
    neck.write(50);
    delay(150);
    
  }
  
  for(int i = 0; i <4; i++)
  {
    
    head.write(55);
    delay(150);
    neck.write(130);
    delay(150);
  }
    tail.write(120);
    head.write(40);
    neck.write(90);
    delay(3000); 
 }

void straight() 
{ //zerored values, can move either direction
  FRH.write(45); //if less than 45 then it goes back, if it is more than 45 it goes forward
  FRK.write(110); //if less than 110 then it goes forward, if it is more than 110 it goes back
  FLH.write(135); //if less than 135 then it goes forward, if it is more than 135 it goes back
  FLK.write(60); //if less than 60 then it goes back, if it is more than 60 it goes forward

  BRH.write(135); //if less than 135 then it goes backwards, if it is more than 135 it goes forward
  BRK.write(120); //if less than 125 then it goes forward, if it is more than 125 it goes backward
  BLH.write(45); //if less than 45 then it goes forward, if it is more than 45 it goes backward
  BLK.write(65); //if less than 60 then it goes backwards, if it is more than 60 it goes forward
}

void sit() 
{
  FRH.write(25); //if less than 45 then it goes back, if it is more than 45 it goes forward
  FRK.write(110); //if less than 110 then it goes forward, if it is more than 110 it goes back
  FLH.write(155); //if less than 135 then it goes forward, if it is more than 135 it goes back
  FLK.write(60); //if less than 60 then it goes back, if it is more than 60 it goes forward

  BRH.write(90); //if less than 135 then it goes backwards, if it is more than 135 it goes forward
  BRK.write(0); //if less than 125 then it goes forward, if it is more than 125 it goes backward
  BLH.write(90); //if less than 45 then it goes forward, if it is more than 45 it goes backward
  BLK.write(170); //if less than 60 then it goes backwards, if it is more than 60 it goes forward
}

void alert() 
{ //zerored values, can move either direction
  FRH.write(45-20); //if less than 45 then it goes back, if it is more than 45 it goes forward
  FRK.write(110-35); //if less than 110 then it goes forward, if it is more than 110 it goes back
  FLH.write(135+20); //if less than 135 then it goes forward, if it is more than 135 it goes back
  FLK.write(60+50); //if less than 60 then it goes back, if it is more than 60 it goes forward

  BRH.write(135-20); //if less than 135 then it goes backwards, if it is more than 135 it goes forward
  BRK.write(120-60); //if less than 125 then it goes forward, if it is more than 125 it goes backward
  BLH.write(45+20); //if less than 45 then it goes forward, if it is more than 45 it goes backward
  BLK.write(65+60); //if less than 60 then it goes backwards, if it is more than 60 it goes forward
}

void up() 
{
  BRK.write(120);
  BLK.write(65);

  delay(500);

  BRH.write(135);
  BLH.write(45);

  delay(500);

  FRK.write(110);
  FLK.write(60);

  delay(500);

  FRH.write(45);
  FLH.write(135);
}

void vow() 
{
  FRH.write(20); //if less than 45 then it goes back, if it is more than 45 it goes forward
  FRK.write(20); //if less than 110 then it goes forward, if it is more than 110 it goes back

  //delay(500);

  FLH.write(160); //if less than 135 then it goes forward, if it is more than 135 it goes back
  FLK.write(160); //if less than 60 then it goes back, if it is more than 60 it goes forward

  BRH.write(135); //if less than 135 then it goes backwards, if it is more than 135 it goes forward
  BRK.write(120); //if less than 125 then it goes forward, if it is more than 125 it goes backward

  BLH.write(45); //if less than 45 then it goes forward, if it is more than 45 it goes backward
  BLK.write(65); //if less than 60 then it goes backwards, if it is more than 60 it goes forward
  //tail.write(90-90);
}

void walk(int steps) 
{
  //up();
  delay(300);

  for (int i = 0; i < steps; i++) 
  {
    /* first part of walking animation */
    FRH.write(70); //if less than 45 then it goes back, if it is more than 45 it goes forward
    FRK.write(150); //if less than 110 then it goes forward, if it is more than 110 it goes back
  
    BRH.write(90); //if less than 135 then it goes backwards, if it is more than 135 it goes forward
    BRK.write(80); //if less than 125 then it goes forward, if it is more than 125 it goes backward
  
    BLH.write(15); //if less than 45 then it goes forward, if it is more than 45 it goes backward
    BLK.write(20); //if less than 60 then it goes backwards, if it is more than 60 it goes forward
  
    FLH.write(170); //if less than 135 then it goes forward, if it is more than 135 it goes back
    FLK.write(95); //if less than 60 then it goes back, if it is more than 60 it goes forward
  
    delay(300);
  
    /* second part of walking animation */
    FRH.write(15); //if less than 45 then it goes back, if it is more than 45 it goes forward
    FRK.write(90); //if less than 125 then it goes forward, if it is more than 125 it goes backward

    BRH.write(155); //if less than 135 then it goes backwards, if it is more than 135 it goes forward
    BRK.write(145);//if less than 125 then it goes forward, if it is more than 125 it goes backward
  
    BLH.write(80); //if less than 45 then it goes forward, if it is more than 45 it goes backward
    BLK.write(100); //if less than 60 then it goes backwards, if it is more than 60 it goes forward
  
    FLH.write(110); //if less than 135 then it goes forward, if it is more than 135 it goes back
    FLK.write(20); //if less than 60 then it goes back, if it is more than 60 it goes forward
  
    delay(300);
    
  }

  straight();

}

void down() 
{
  BRH.write(100); //if less than 135 then it goes backwards, if it is more than 135 it goes forward
  BRK.write(0); //if less than 125 then it goes forward, if it is more than 125 it goes backward

  BLH.write(80); //if less than 45 then it goes forward, if it is more than 45 it goes backward
  BLK.write(180); //if less than 60 then it goes backwards, if it is more than 60 it goes forward

  delay(500);

  FRH.write(10); //if less than 45 then it goes back, if it is more than 45 it goes forward
  FRK.write(10); //if less than 110 then it goes forward, if it is more than 110 it goes back

  FLH.write(170); //if less than 135 then it goes forward, if it is more than 135 it goes back
  FLK.write(160); //if less than 60 then it goes back, if it is more than 60 it goes forward
}


void handtailsensor()
{
  long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   if(inches < 6){
     for(int i = 0; i <3; i++)
    {
      tail.write(120);
      delay(150);
      tail.write(120+70);
      delay(150);
      head.write(15);
      delay(150);
      neck.write(50);
      delay(150);
      
    }
    
    for(int i = 0; i <3; i++)
    {
      tail.write(120-50);
      delay(150);
      tail.write(120+70);
      delay(150);
      head.write(55);
      delay(150);
      neck.write(130);
      delay(150);
    }
    tail.write(120);
    head.write(40);
    neck.write(90);
    delay(3000);
    
   }
   delay(1000);
}


long microsecondsToInches(long microseconds) 
{
 return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) 
{
 return microseconds / 29 / 2;
}

//Sets up the pin in the servos
void setup() 
{
  FRH.attach(FRH_pin);
  FRK.attach(FRK_pin);
  FLH.attach(FLH_pin);
  FLK.attach(FLK_pin);

  BRH.attach(BRH_pin);
  BRK.attach(BRK_pin);
  BLH.attach(BLH_pin);
  BLK.attach(BLK_pin);

  neck.attach(neck_pin);
  head.attach(head_pin);
  tail.attach(tail_pin);

  Serial.begin(9600);
}

//[Reference for the bluetooth module]
//white goes to 0
//brown goes to 1


void loop() {
  hey();
}

boolean checkBluetooth() {
  while (Serial.available()) 
  {
    delay(10);
  
    c = Serial.read();
    if (c == '#') break;
    voice += c;
  }

  if (voice.length() > 0) {
    Serial.println("voice: " + voice);
    
    if (voice == "sit") {
      sit();
    } else if (voice == "up" || voice == "stand") {
      up();
    } else if (voice == "bow" || voice == "vow") {
      vow();
    } else if (voice == "straight") {
      straight();
    } else if (voice == "down") {
      down();
    } else if (voice == "walk") {
      walk(8);
    }
    
    delay(5000);
    voice = "";

    return true;
  }
  
  return false;
}
