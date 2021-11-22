const byte led_G = 1;
const byte led_Y = 7;
const byte led_R = 13;


enum vtlStates {AMBER, RED, RA, GREEN}; 
vtlStates tlState;  

const int timings[] = {1000, 1000, 1000, 1000}; 
unsigned long timeStart, timeElapsed ; 

void setup() {
  pinMode(led_G, OUTPUT);
  pinMode(led_Y, OUTPUT);
  pinMode(led_R, OUTPUT);
  tlState = AMBER; 
  timeStart = millis();
}

void loop() {
  switch (tlState) {
    case AMBER : {
       
        digitalWrite(led_R, LOW);
        digitalWrite(led_Y, HIGH);
        digitalWrite(led_G, LOW);
        
        timeElapsed = millis() - timeStart;
        if (timeElapsed > timings[AMBER]) {
          
          timeStart = millis();
          tlState = RED;
        }
      }
      break;

    case RED: {
        digitalWrite(led_R, HIGH);
        digitalWrite(led_Y, LOW);
        digitalWrite(led_G, LOW);
        
        timeElapsed = millis() - timeStart;
        if (timeElapsed > timings[RED]) {
          
          timeStart = millis();
          tlState = RA;
        }
      }
      break;

    case RA: {
        digitalWrite(led_R, HIGH);
        digitalWrite(led_Y, HIGH);
        digitalWrite(led_G, LOW);
        
        timeElapsed = millis() - timeStart;
        if (timeElapsed > timings[RA]) {
          
          timeStart = millis();
          tlState = GREEN;
        }
      }
      break;

    case GREEN: {
        digitalWrite(led_R, LOW);
        digitalWrite(led_Y, LOW);
        digitalWrite(led_G, HIGH);
        
        timeElapsed = millis() - timeStart;
        if (timeElapsed > timings[GREEN]) {
          
          timeStart = millis();
          tlState = AMBER;
        }
      }
      break;
  }
}
