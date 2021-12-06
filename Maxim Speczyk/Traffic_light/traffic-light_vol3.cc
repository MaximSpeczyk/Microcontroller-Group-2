#define Switch 2
#define Red 13
#define Yellow 12
#define Green 11
#define RedPedestrian 10
#define GreenPedestrian 9

volatile bool shift = true;
int up;
int time;

enum Status{stRed, stYellow, stGreen};
enum StatusPedestrain{stRedPedestrian,stGreenPedestrian};

Status status = stGreen;

void mode_red()
  {
    digitalWrite(Red, HIGH);
    delay(time);
    digitalWrite(Red, LOW);
  	status = stYellow;
  	time = 5000;
  }
  
void mode_yellow()
  {
    digitalWrite(Yellow, HIGH);
    delay(time/2);
    digitalWrite(Yellow, LOW);
  	time = 5000;
  }
  
void mode_green()
  {
    digitalWrite(Green, HIGH);
    delay(time);
    digitalWrite(Green, LOW);
  	status = stYellow;
  	time = 5000;
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
}

void change_pedestrian()
{
    if(status == stGreen || status == stYellow)
    {
      mode_pedestrian_red();
    }
    if(status == stRed)
    {
      mode_pedestrian_green();
    }
}

void change_time()
{
status = stYellow;
  up = 0;
  
}

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Switch),change_time,FALLING);
}

void change_traffic()
{
  if(shift)
  {
    switch(status)
    {
      case stRed:

      up = 1;
      mode_red();
      break;
  
      case stYellow:
      mode_yellow();
      
      if(up == 1)
      {
       	status = stGreen;
      }
      
      if(up == 0)
      {
        status = stRed;
      }
      break;
      
      case stGreen:
      up = 0;
      mode_green();
      break;
    }
  }
  change_pedestrian();
}

void loop()
{
change_traffic();
}