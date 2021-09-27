#define PWM 255
#define X 25 // The minimum distance between bot and wall 
const int trigPin1 = 14;            // Pin 1 is for front sensor
const int echoPin1 = 2; //pwm
const int trigPin2 = 15;            // Pin 2 is for right sensor
const int echoPin2 = 3; //pwm
const int trigPin3 = 16;            // Pin 3 is for left sensor
const int echoPin3 = 4; //pwm
const int in1 = 17;                                               // left in
const int in2 = 18;                                               // left out
const int in3 = 19;                                               // right in
const int in4 = 20;                                               // right out
const int enA = 5; //pwm      
const int enB = 6; //pwm
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
 return (dur/62);// convert the distance to centimeters.
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
 return (dur/62);// convert the distance to centimeters.
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
 return (dur/62);// convert the distance to centimeters.
}
