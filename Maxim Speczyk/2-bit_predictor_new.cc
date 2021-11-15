#define NotTaken 2
#define Taken 3
#define green 13		
#define orange 12
volatile bool shift;
volatile bool up;
volatile bool down;
//green is the bit that changes the output to Taken or NotTaken
//orange is the bit that changes the output to Strongly or Weakly

enum Status{st00, st01, st10, st11};
//st00 = StronglyNotTaken
//st01 = WeaklyNotTaken
//st10 = WeaklyTaken
//st11 = StronglyTaken

Status status = st00; 
//sets the status in the beginning to st00

void not_taken(){
  shift = true;
  down = true;
}
//when NotTaken sets shift and down to true

void taken(){
  shift = true;
  up = true;
}
//when Taken sets shift and up to true

void setup()
{
  pinMode(NotTaken, INPUT);
  pinMode(Taken, INPUT);
  pinMode(green, OUTPUT);
  pinMode(orange, OUTPUT);  
  attachInterrupt(digitalPinToInterrupt(NotTaken), not_taken, RISING);
  //button 1 sets NotTaken to rising
  //that means for example shifts the status from st10 to st01
  attachInterrupt(digitalPinToInterrupt(Taken), taken, RISING);
  //button 2 sets Taken to rising
  //that means for example shits the status from st10 to st11
}

void loop()
{
  if(shift){
    switch(status){
      case st00:		//StronglyNotTaken
      if(up)
        mode_01();			//up to st01
      break;
      case st01:		//WeaklyNotTaken
      if(up)
        mode_10();			//up to st10
      if(down)
        mode_00();			//down to st00
      break;
      case st10:		//WeaklyTaken
      if(up)
        mode_11();			//up to st11
      if(down)
        mode_01();			//down to st01
      break;
      case st11:		//StronglyTaken
      if(down)
        mode_10();			//down to st10
      break;
      default:
      break;
    }
    up = false;
    down = false;
    shift = false;
  }
}
void mode_11(){
  digitalWrite(green, HIGH);
  digitalWrite(orange, HIGH);
  status = st11;
  //StronglyTaken
  //both LEDs are on
}

void mode_10(){
  digitalWrite(green, HIGH);
  digitalWrite(orange, LOW);
  status = st10;
  //WeaklyTaken
  //orange is off green is on
}

void mode_01(){
  digitalWrite(green, LOW);
  digitalWrite(orange, HIGH);
  status = st01;
  //WeaklyNotTaken
  //orange is on green is off
}

void mode_00(){
  digitalWrite(green, LOW);
  digitalWrite(orange, LOW);
  status = st00;
  //StronglyNotTaken
  //both LEDs are off
}