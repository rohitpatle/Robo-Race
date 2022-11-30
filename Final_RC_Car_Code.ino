char command;

const int IN1 = 6;
const int IN2 = 7;
const int IN3 = 8;
const int IN4 = 9;
const int EN12 = 3;
const int EN34 = 5;
const int Speed = 255;
const int Lspeed = 100;

void setup() 
{
 pinMode(IN1,OUTPUT);   //left motor front
 pinMode(IN2,OUTPUT);   //left motor back
 pinMode(IN3,OUTPUT);   //right motor front
 pinMode(IN4,OUTPUT);   //right motor back  
 pinMode(EN12,OUTPUT);  //both left motors
 pinMode(EN34,OUTPUT);  //both right motors
 Serial.begin(9600);
}

void loop(){
 if(Serial.available() > 0){ 
   command = Serial.read(); 
   switch(command){
   case 'F':    //forward
     Forward();
     break;
   case 'B':    //back
      Back();
     break;
   case 'L':    //immediate left 
     Left(); 
     break;
   case 'R':    //immediate right
     Right();
     break;
   default:  //stop
     Stop();
     break;
   }
    Serial.println(command);

 }
}

void Forward()
{
 digitalWrite(IN1,HIGH);    //motor direction
 digitalWrite(IN3,HIGH);    //motor direction
 analogWrite(EN12,Speed);   //motor speed
 analogWrite(EN34,Speed);   //motor speed
}


void Back()
{
 digitalWrite(IN2,HIGH);    //motor direction
 digitalWrite(IN4,HIGH);    //motor direction
 analogWrite(EN12,Speed);   //motor speed
 analogWrite(EN34,Speed);   //motor speed
}

void Left()
{
 digitalWrite(IN2,HIGH);    //motor direction
 digitalWrite(IN3,HIGH);    //motor direction
 analogWrite(EN12,Speed);   //motor speed
 analogWrite(EN34,Speed);   //motor speed
}

void Right()
{
 digitalWrite(IN1,HIGH);    //motor direction
 digitalWrite(IN4,HIGH);    //motor direction
 analogWrite(EN12,Speed);   //motor speed
 analogWrite(EN34,Speed);   //motor speed
}

void Stop()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
