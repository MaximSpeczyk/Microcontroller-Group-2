#define Red 4
#define Yellow 3
#define Green 2

int path = 0;

enum Color{redC, yellowC, greenC};
Color current = yellowC;

void setup()
{
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
}

void redL()
{
    digitalWrite(Red, HIGH);
    delay(5000);
    digitalWrite(Red, LOW);
    current = redC;
}
  
void yellowL()
{	
    digitalWrite(Yellow, HIGH);
    delay(1500);
    digitalWrite(Yellow, LOW);
    current = yellowC;
}
  
void greenL()
{
  	digitalWrite(Green, HIGH);
    delay(5000);
    digitalWrite(Green, LOW);
    current = greenC;
}


void loop()
{
  switch(current)
  {
    case redC:
      	if(path == 1)
      	{   yellowL();}
    break;
      
    case yellowC:
      	if(path == 1)
        {
          	path = 0;
      		greenL();
        }
      	else if(path == 0)
        {	
            path = 1;
      		redL();
        }
    break;
      
    case greenC:
        if(path==0)
        {	yellowL();}
    break;
  }
} 
