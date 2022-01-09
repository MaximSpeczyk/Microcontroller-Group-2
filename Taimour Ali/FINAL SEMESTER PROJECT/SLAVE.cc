//SLAVE
#define rled 2
#define yled 3
#define gled 4
#define button 7
#define prled 5
#define pgled 6
int incomingByte=0;
int bstate=0;
int t1=5000,t2=2500; //T1=Green,Red, and T2=Yellow

void setup()
{
  Serial.begin(9600);//Call serial communication 
  pinMode(rled, OUTPUT);
  pinMode(yled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(prled, OUTPUT);  
  pinMode(pgled, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(prled,1);
  digitalWrite(pgled,0);
}

void loop()
{
  checkstate();//Function for checking the state --- Line 67 to 73, I made a separation function to check the state 
  bstat();
  if(incomingByte==1) //If incomingByte is 1, we will call green 
  {
    GreenEventState();
  }
  else if(incomingByte==2)//If incomingByte is 1, we will call yellow
  {
    YellowEventState();
  }
  else if(incomingByte==3)//If incomingByte is 1, we will call red
  {
    RedEventState();
  }
  else //Otherwise all states will be zero 
  {
    digitalWrite(rled,0);
    digitalWrite(yled,0);
    digitalWrite(gled,0);
   }
  bstat();
  
}
void bstat()
{
  bstate=digitalRead(button);
  if(bstate==1)//If the button is pressed 
  {
    YellowEventState();//Jump to Yellow State 
    delay(t2);
    RedEventState();//Jump to Red State 
    digitalWrite(prled,0);
    digitalWrite(pgled,1);
    delay(t1);
    digitalWrite(prled,1);
    digitalWrite(pgled,0);
    YellowEventState();
    delay(t2);
  }
}
void checkstate()//Checking state function 
{
  if (Serial.available() > 0) { //If Serial.available is greater than zero in the serial 
    incomingByte = Serial.read();//It will read as Serial.read and save in IncomingByte 
    Serial.print("Received State: ");//and it will print the Received State
    Serial.println(incomingByte, DEC);
  }
}
void RedEventState()//Function for RedEventState
{
  digitalWrite(rled,1);
  digitalWrite(yled,0);
  digitalWrite(gled,0);
}
void YellowEventState()//Function for YellowEventState
{
  digitalWrite(rled,0);
  digitalWrite(yled,1);
  digitalWrite(gled,0);
}
void GreenEventState()//Function for GreenEventState
{
  digitalWrite(rled,0);
  digitalWrite(yled,0);
  digitalWrite(gled,1);
}
