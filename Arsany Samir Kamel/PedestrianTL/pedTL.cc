#define RequestRed 13
#define RequestGreen 12
#define Red 11
#define Yellow 10
#define Green 9
#define Request 2
#define time 5000

int path = 1;

enum Color{redC, yellowC, greenC};
Color current = redC;

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
  attachInterrupt(digitalPinToInterrupt(Request), pedestreian, FALLING);
}

void redL()
{
    digitalWrite(Red, HIGH);
    delay(time);
    digitalWrite(Red, LOW);
    current = yellowC;
}
  
void yellowL()
{	
    digitalWrite(Yellow, HIGH);
    delay(time/2);
    digitalWrite(Yellow, LOW);
}
  
void greenL()
{
  	digitalWrite(Green, HIGH);
    delay(time);
    digitalWrite(Green, LOW);
    current = yellowC;
}

void pdRedL(){
  
  digitalWrite(RequestGreen, LOW);
  digitalWrite(RequestRed, HIGH);
}

void pdGreenL(){
  
  digitalWrite(RequestGreen, HIGH);
  digitalWrite(RequestRed, LOW);

}

void loop()
{
  switch(current)
  {
    case redC:
    	pdGreenL();
      	redL();
      
    break;
      
    case yellowC:
    	pdRedL();
    	yellowL();
    	
      	if(path == 1)
        {
          	path = 0;
      		current = greenC;
        }
      	else if(path == 0)
        {	
            path = 1;
      		current = redC;
        }
    break;
      
    case greenC:
        greenL();
    	pdRedL();
    break;
  }
} 
