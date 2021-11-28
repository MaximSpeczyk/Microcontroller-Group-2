#define Switch 2
#define Red 13
#define Yellow 12
#define Green 11
#define RedPedestrian 10
#define GreenPedestrian 9

volatile bool shift = true;
int up;
int down = 1;
int red = 1;

enum Status{stRed, stYellow, stGreen};

Status status = stYellow;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Switch), help, FALLING);
}

void mode_red()
  {
    digitalWrite(Red, HIGH);
  	digitalWrite(GreenPedestrian, HIGH);
    delay(5000);
    digitalWrite(Red, LOW);
  	digitalWrite(GreenPedestrian, LOW);
    status = stRed;
  }
  
void mode_yellow()
  {
    digitalWrite(Yellow, HIGH);
  	digitalWrite(RedPedestrian, HIGH);
    delay(1500);
    digitalWrite(Yellow, LOW);
  	digitalWrite(RedPedestrian, LOW);
    status = stYellow;
  }
  
void mode_green()
  {
    digitalWrite(Green, HIGH);
  	digitalWrite(RedPedestrian, HIGH);
    delay(5000);
    digitalWrite(Green, LOW);
  	digitalWrite(RedPedestrian, LOW);
    status = stGreen;
  }
void help()
{
	digitalWrite(Green, LOW);
  	up = 0;
	down = 1;
	red = 1;
  	mode_yellow();
  	status = stYellow;
}
  
void change()
  {
  if(shift)
  {
    switch(status)
    {
      case stRed:
      		if(up == 1 && red == 1 )
            {
              	up = 1;
      			down = 0;
      			red = 0;
              	mode_yellow();
            }
      break;
      
      case stYellow:
      		if(up == 1 && down == 0 && red == 0)
            {	
              	up = 0;
				down = 1;
      			mode_green();
            }
      		if(down == 1 && red == 1 && up == 0)
            {	
              	up = 1;
      			down = 0;
      			red = 1;
      			mode_red();
            }
      	break;
      
      case stGreen:
        	if(down == 1)
            {	
              	up = 0;
      			down = 1;
              	red = 1;
              	mode_yellow();
            }
      break;
    }
  }
}  
void loop()
{
change();
}


