#define wrong 2 //right or wrong path
#define right 3
#define red 13		
#define blue 12

int current = 0; 

enum State{snt, wnt, wt, st};
//Strongly not taken, Weakly not taken,
//Weakly taken, Strongly taken
State state = snt; 

void notTaken(){
  if (current>0)
    current -= 1;
}

void taken(){
  if (current<3)
    current += 1;
}

void setup()
{
  pinMode(wrong, INPUT);
  pinMode(right, INPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);  
  attachInterrupt(digitalPinToInterrupt(wrong), notTaken, RISING);
  //if the decesion was wrong then current is decremented
  attachInterrupt(digitalPinToInterrupt(right), taken, RISING);
  //if the decesion was right then current is incremented
}

void loop()
{
   
    switch(state){
      case snt:		
      if(current == 1)
        one();
      //toggle to wnt
      break;
      case wnt:		
      if(current == 2)
        two();			
      //toggle to wt
      else if(current == 0)
        zero();			
      //toggle to snt
      break;
      case wt:		
      if(current == 3)
        three();			
      //toggle to st
      else if(current == 1)
        one();			
      //toggle to wnt
      break;
      case st:		
      if(current==2)
        two();			
      //toggle to st10
      break;
    }
    
}

//strongly not taken
void zero(){
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  state = snt;
}
//weakly not taken
void one(){
  digitalWrite(red, LOW);
  digitalWrite(blue, HIGH);
  state = wnt; 
}
//weakly taken
void two(){
  digitalWrite(red, HIGH);
  digitalWrite(blue, LOW);
  state = wt;
}
//strongly taken
void three(){
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  state = st;
 
}
