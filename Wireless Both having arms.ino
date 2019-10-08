#include<SoftwareSerial.h>
#include<Servo.h>

int motorA1 = 6; //Pin 2 of L293
int motorA2 = 5; //Pin 7 of L293
int motorB1 = 10; //Pin 10 of L293
int motorB2 = 8; //Pin 15 of L293
int motorC1 = 13; // Pin 2 of L293
int motorC2 = 11; // Pin 7 of L293
int motorD1 = 12; //Pin 10 of L293
int motorD2 = 4; //Pin 15 of L293

char state = '0'; //Initialise Motors

SoftwareSerial BT(0,1);
Servo servo_test;
Servo servo_test1;  

void setup() {
  BT.begin(9600);// Initialize serial communication at 9600 bits per second
  //Set pins as outputs
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorC1, OUTPUT);
  pinMode(motorC2, OUTPUT);
  pinMode(motorD1, OUTPUT);
  pinMode(motorD2, OUTPUT);

 servo_test.attach(3);      // attach the signal pin of servo to pin3 of arduino
 servo_test1.attach(9);     // attach the signal pin of servo to pin9 of arduino
  
}

void loop()
{
  if (BT.available())
  { // Reads from bluetooth and stores its value
    state = BT.read();
    BT.print(state);
  }
  if (state == 'F')
  { //Forward

    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    digitalWrite(motorC1, HIGH);
    digitalWrite(motorC2, LOW);
    digitalWrite(motorD1, HIGH);
    digitalWrite(motorD2, LOW);

  }
  else if (state == 'B') { // Reverse
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
    digitalWrite(motorC1, LOW);
    digitalWrite(motorC2, HIGH);
    digitalWrite(motorD1, LOW);
    digitalWrite(motorD2, HIGH);
  }
  else if (state == 'L') { // Left
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    digitalWrite(motorC1, LOW);
    digitalWrite(motorC2, LOW);
    digitalWrite(motorD1, HIGH);
    digitalWrite(motorD2, LOW);

  }
  else if (state == 'R') { // Right
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
    digitalWrite(motorC1, HIGH);
    digitalWrite(motorC2, LOW);
    digitalWrite(motorD1, LOW);
    digitalWrite(motorD2, LOW);
  }
  else if (state!='F' && state!='B' && state!='L' && state!='R' || state=='O') { // Stop
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
    digitalWrite(motorC1, LOW);
    digitalWrite(motorC2, LOW);
    digitalWrite(motorD1, LOW);
    digitalWrite(motorD2, LOW);

  }
  else if(state =='X'){
     servo_test.write(35);
   }

  else if(state=='Y')
  {

    servo_test.write(0);
  }
  else if(state=='A')
  {
   servo_test1.write(180);
  }
  else if(state=='C')
  {
   servo_test1.write(0); 
  }
} 





