#define Red 13
#define Yellow 12
#define Green 11

volatile bool shift = true;
int up;
int down = 1;
int red = 1;
int green;

enum Status{stRed, stYellow, stGreen};

Status status = stYellow;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}

void mode_red()
  {
    digitalWrite(Red, HIGH);
    delay(5000);
    digitalWrite(Red, LOW);
    status = stRed;
  }
  
void mode_yellow()
  {
    digitalWrite(Yellow, HIGH);
    delay(1500);
    digitalWrite(Yellow, LOW);
    status = stYellow;
  }
  
void mode_green()
  {
    digitalWrite(Green, HIGH);
    delay(5000);
    digitalWrite(Green, LOW);
    status = stGreen;
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
      			green = 1;
      			red = 0;
              	mode_yellow();
            }
      break;
      
      case stYellow:
      		if(up == 1 && green == 1 && down == 0 && red == 0)
            {	
              	up = 0;
				down = 1;
      			green = 1;
      			red = 0;
      			mode_green();
            }
      		if(down == 1 && red == 1 && up == 0 && green == 0)
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
      			green = 0;
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
