int led_green=0; //we use variables naming the digital outputs/inputs
int led_yellow=1;
int led_red=2;
int led_pedestrian_green=3;
int led_pedestrian_red=4;
int button_pedestrian=5;
int lag=2000; //we use a variable for the delay 2 seconds
int status=0;

void setup() //declaration of digital outputs
{
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_pedestrian_green, OUTPUT);
  pinMode(led_pedestrian_red, OUTPUT);
  pinMode(button_pedestrian, INPUT);
}

void loop()
{
  digitalWrite(led_green, 1);
  digitalWrite(led_pedestrian_red, 1);
  status = digitalRead(button_pedestrian);
  if(status == HIGH){ //only if button is pressed, cars will be stopped
    delay(lag);
    digitalWrite(led_green,0);
    for (int i = 0; i<=3; i++) //three times yellow blinked
     {
      digitalWrite(led_yellow, 1);
      delay(lag/2);
      digitalWrite(led_yellow, 0);
      delay(lag/4);
     }
    digitalWrite(led_red,1);
    delay(lag/2); //safety delay for pedestrians before green
    digitalWrite(led_pedestrian_red, 0);
    digitalWrite(led_pedestrian_green, 1);
    delay(lag*2);
    for (int i = 0; i<=3; i++) //three times green pedestrian blinked
     {
      digitalWrite(led_pedestrian_green, 0);
      delay(lag/4);
      digitalWrite(led_pedestrian_green, 1);
      delay(lag/2);
  	 }
    digitalWrite(led_pedestrian_green, 0);
    digitalWrite(led_pedestrian_red, 1);
    delay(lag); //safety delay for pedestrians before green to cars
    digitalWrite(led_red,0);
   }
  else{ //if the button is not pressed no stop to cars and the loop starts again
  }
}
