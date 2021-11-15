// C++ code
//
#define StronglyTaken 100

#define StronglyNotTaken 200
 
#define TakenEvent 0
#define NotTakenEvent 0
 
int state = StronglyNotTaken;  
int event = TakenEvent;  
 
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if(buttonTakenPressed)
     event = TakenEvent;
  else(buttonNotTakenPressed)
     event = NotTakenEvent;
 
  stateMachine();
 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

 void stateMachine(){  
  switch(state){
    case stronglyTaken;
        if(event == NotTakenEvent)
          state = weaklyTaken;
          digitalWrite(weaklyTakenLED, HIGH);
        break;
   
    case weaklyTaken;
        if(event == NotTakenEvent)
          //switchState
        else
          //switchState
        ....
}  
         
//ISR
  void takeEven(){
    TakenEvent = 1;
    NotTakenEvent = 0;
}
 set event  
