#include <Wire.h>
#define Switch 2
#define Red 13
#define Yellow 12
#define Green 11
#define RedPedestrian 10
#define GreenPedestrian 9

volatile bool shift = true;
int up;
int time = 5000;
int x = 0;
int event = 1;
int pinbutton = 1;

enum Status{stRed, stYellow, stGreen};
enum StatusPedestrain{stRedPedestrian,stGreenPedestrian};

Status status = stRed;

void mode_red()
  {
    digitalWrite(Red, HIGH);
    delay(time);
    digitalWrite(Red, LOW);
  	status = stYellow;
  }
  
void mode_yellow()
  {
    digitalWrite(Yellow, HIGH);
    delay(time/2);
    digitalWrite(Yellow, LOW);
  }
  
void mode_green()
  {
    digitalWrite(Green, HIGH);
    delay(time);
    digitalWrite(Green, LOW);
  	status = stYellow;
  }

void mode_pedestrian_red()
{
  digitalWrite(RedPedestrian, HIGH);
  digitalWrite(GreenPedestrian, LOW);
}

void mode_pedestrian_green()
{
  digitalWrite(GreenPedestrian, HIGH);
  digitalWrite(RedPedestrian, LOW);
  delay(time);
}

void setup()
{
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Switch),button,FALLING);
}

void receiveEvent(int event)
{
  event = Wire.read();
}

void button()
{
	pinbutton = 0;
}

void change_traffic()
{
  if(shift)
  {
    receiveEvent(event);
    
   if(pinbutton == 0)
    {
      if(status == stRed)
      {
        x = 1;
        mode_red();
        x = 0;
      }
      if(status == stYellow)
      {
        up = 0;
      }
    }
    else {
	
      if(status == stRed && event == 1)
      {
        up = 1;
        mode_red();
      }
      if(status == stYellow && event == 2||3)
      {
        mode_yellow();
              
        if(up == 1)
      {
       	status = stGreen;
      }
      
      if(up == 0)
      {
        status = stRed;
      }
      }
      if(status == stGreen )
      {
        up = 0;
        mode_green();
      }
    }
  }
}

void pedestrian ()
{
  if(x == 0)
  {
    mode_pedestrian_red();
  }
  
  if(x == 1)
  {
    mode_pedestrian_green();
    x = 0;
  }
}
void loop()
{
	change_traffic();
  	pedestrian();
}