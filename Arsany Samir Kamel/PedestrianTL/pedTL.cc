#define RequestRed 13
#define RequestGreen 12
#define Red 11
#define Yellow 10
#define Green 9
#define Request 2

int path = 0;

enum Color{redC, yellowC, greenC};
Color current = yellowC;

void pedestreian()
{
  path=0;
}

void setup()
{
  pinMode(RequestRed, OUTPUT);
  pinMode(RequestGreen, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Request, INPUT);
  attachInterrupt(digitalPinToInterrupt(Request), pedestreian, FALLING);
}

void redL()
{
    digitalWrite(Red, HIGH);
  	digitalWrite(RequestGreen, HIGH);
    delay(5000);
  	digitalWrite(RequestGreen, LOW);
    digitalWrite(Red, LOW);
    current = redC;
}
  
void yellowL()
{	
    digitalWrite(Yellow, HIGH);
  	digitalWrite(RequestRed, HIGH);
    delay(2500);
 	digitalWrite(RequestRed, LOW);
    digitalWrite(Yellow, LOW);
    current = yellowC;
}
  
void greenL()
{
  	digitalWrite(Green, HIGH);
  	digitalWrite(RequestRed, HIGH);
    delay(5000);
  	digitalWrite(RequestRed, LOW);
    digitalWrite(Green, LOW);
    current = greenC;
}


void loop()
{
  switch(current)
  {
    case redC:
      yellowL();
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
        yellowL();
    break;
  }
} 
