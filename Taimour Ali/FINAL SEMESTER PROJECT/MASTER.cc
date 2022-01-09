//MASTER 
#define rled 2 //Red LED 
#define yled 3 //Yellow LED
#define gled 4 //Green LED
#define button 7 //Push button 
#define prled 5 //Red pedestrian light
#define pgled 6 //Green pedestrian light
int t1=5000,t2=2500; //T1=Green,Red, and T2=Yellow
int bstate=0; //If button is not pressed 
//1 = green, 2= yellow, 3= red
void setup()
{
  Serial.begin(9600); //Call serial communication 
  pinMode(rled, OUTPUT);
  pinMode(yled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(prled, OUTPUT);
  pinMode(pgled, OUTPUT);
  pinMode(button, INPUT);
  
  digitalWrite(prled,1);
  digitalWrite(pgled,0);
  RedEventState();
  Serial.write(3);//turn on red - Slave
  delay(t1);
  bstat(); //Checking button state
  Serial.write(2);//turn on yellow - Slave
  delay(t2);
  bstat(); //Checking button state
  Serial.write(1);//turn on green - Slave
  delay(t1);
  bstat(); //Checking button state
  YellowEventState();
  Serial.write(2);
  delay(t2);
  bstat();//Checking button state
}

void loop() //Function for button pressed 
{
  bstat();
  syn();
}
void bstat() //If the button is not pressed 
{
  bstate=digitalRead(button);
  if(bstate==1) // If the button is pressed 
  {
    psyn(); //For synchoronization we make this function 
  }
}
void psyn() //If the button is pressed whatever the state of the traffic light will be, it will go directly to yellow
{
  YellowEventState();//Jump to yellow 
  delay(t2); 
  RedEventState();//Jump to red 
  digitalWrite(prled,0);// Red will be 0 
  digitalWrite(pgled,1);//Green will be 1 
  delay(t1);
  digitalWrite(prled,1);
  digitalWrite(pgled,0);
  YellowEventState();
  delay(t2);
}
void syn()
{
  GreenEventState();//Jump to green
  Serial.write(3);//3=red
  delay(t1);
  bstat();
  YellowEventState();//Jump to yellow 
  Serial.write(2);//2=yellow
  delay(t2);
  bstat();
  RedEventState();//Jump to red
  Serial.write(1);
  delay(t1);
  bstat();
  YellowEventState();//Jump to yellow 
  Serial.write(2);
  delay(t2);
  bstat();
}
void RedEventState()//Function for RedEventState
{
  digitalWrite(rled,1);//Red will turn on
  digitalWrite(yled,0);
  digitalWrite(gled,0);
}
void YellowEventState()//Function for YellowEventState
{
  digitalWrite(rled,0);
  digitalWrite(yled,1);//Yellow will turn on 
  digitalWrite(gled,0);
}
void GreenEventState()//Function for GreenEventState
{
  digitalWrite(rled,0);
  digitalWrite(yled,0);
  digitalWrite(gled,1);//Green will turn on 
}
