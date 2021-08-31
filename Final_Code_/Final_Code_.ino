/*
Hinge 1          Driver(2)
        ena - 4
        in1 - 33
        in2 - 34
Hinge 2
        enb - 3
        in3 -35
        in4 - 36
Hinge 3 
        ena - 2  Driver (3)
        in1 - 37
        in2 - 38
*/



#define BLYNK_USE_DIRECT_CONNECT
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(19, 18); // RX, TX
#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleSerialBLE.h>
char auth[] = "sBVEAogcssGh0CdZfLV2rPOQmaNsqzcP";
#define PWM 255
#define X 50                        // The minimum distance between bot and wall 
const int trigPin1 = 23;            // Pin 1 is for front sensor
const int echoPin1 = 11; //pwm
const int trigPin2 = 25;            // Pin 2 is for right sensor
const int echoPin2 = 10; //pwm
const int trigPin3 = 24;            // Pin 3 is for left sensor
const int echoPin3 = 12; //pwm
const int in1 = 29;                                               // left in
const int in2 = 30;                                               // left out
const int in3 = 31;                                               // right in
const int in4 = 32;                                               // right out
const int enA = 6; //pwm      
const int enB = 5; //pwm
void setup() 
{
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 pinMode(trigPin3, OUTPUT);
 pinMode(echoPin3, INPUT);
 pinMode (in1, OUTPUT);
 pinMode (in2, OUTPUT);
 pinMode (in3, OUTPUT);
 pinMode (in4, OUTPUT);
 pinMode (enA, OUTPUT);
 pinMode (enB, OUTPUT);
}
void loop()
{ 

   Blynk.run();
 if ( FrontSensor() < X && RightSensor() < X && LeftSensor()< X) // obstacle infront of all 3 sides
 {
        turn_right(); 
        delay(3000);
//then reverse
 }

 else if (FrontSensor() < X && RightSensor() < X && LeftSensor()> X) // obstacle on right and front sides
 {
 turn_left(); 
// turn left side
 }
 else if (FrontSensor() < X && RightSensor() > X && LeftSensor()< X) // obstacle on left and front sides
    {
 turn_right(); 
// turn right side
 }
 else if (FrontSensor() < X && RightSensor() > X && LeftSensor()> X) // obstacle on front sides
 {
 turn_right(); 
// then turn right
 }
 else if (FrontSensor() > X && RightSensor() > X && LeftSensor()< X) // obstacle on left sides
 {
 turn_right(); 
// then turn right and then forward
 delay(180);
 forward();
 }
 else if (FrontSensor() > X && RightSensor() < X && LeftSensor()> X) // obstacle on right sides
 {
 turn_left(); 
// then turn left and then right
 delay(180);
 forward();
 }
 else 
 {
 forward();
 }
}

void forward ()

{
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 analogWrite(enA, PWM); 
 analogWrite(enB, PWM);
}

void turn_left () 

{
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
 analogWrite(enA, PWM); 
 analogWrite(enB, PWM);
}
void turn_right () 
{
 digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}

void reverse ()
{
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
 analogWrite(enA, PWM);
 analogWrite(enB, PWM);
}
void stop()
{
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
 analogWrite(enA, LOW);
 analogWrite(enB, LOW);
}

long FrontSensor ()
{
long dur;
 digitalWrite(trigPin1, LOW); 
 delayMicroseconds(5); 
 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin1, LOW);
 dur = pulseIn(echoPin1, HIGH);
 return (dur/58);// convert the distance to centimeters.
}

long RightSensor () 
{
long dur;
 digitalWrite(trigPin2, LOW);
 delayMicroseconds(5); 
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin2, LOW);
 dur = pulseIn(echoPin2, HIGH);
 return (dur/58);// convert the distance to centimeters.
}

long LeftSensor ()    
{
long dur;
 digitalWrite(trigPin3, LOW); 
 delayMicroseconds(5); 
 digitalWrite(trigPin3, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin3, LOW);
 dur = pulseIn(echoPin3, HIGH);
 return (dur/58);// convert the distance to centimeters.
}
