//Joonejälgimis Robi v1.0

//MOTORS VARIABLES
const int mot1f = 6;
const int mot1b = 5;
const int mot2f = 11;
const int mot2b = 10;
int mot_speed = 110; //motors speed
int brake_k = 4; //BRAKE

//LOGICS VARIABLES
int errorLED = 13;
int leftSensor = 2;
int rightSensor = 3;

int stateForward = 0;
int stateLeft = 1;
int stateRight = 2;

int state = stateForward;

void setup(){
  
    pinMode(mot1f, OUTPUT);
    pinMode(mot1b, OUTPUT);
    pinMode(mot2f, OUTPUT);
    pinMode(mot2f, OUTPUT);
    
    delay(2000);
    motors_forward();
  
}

void loop(){
  
    boolean left = digitalRead(leftSensor);
    boolean right = digitalRead(rightSensor);
    
    
    if (left == 0 & right == 0){ 
      
      motors_forward();
      
    }
    if (left == 1 & right == 0){
      
      motors_left();
      delay(20);
      
    }
    if (left == 0 & right == 1) {
      
      motors_right();
      delay(20);
      
    }
    if (left == 1 & right == 1) {
      
      motors_forward();
      
    } 
  
}


//==============MOTORS====================================
void motors_forward(){                    //MOTORS FORWARD FUNCTION
  analogWrite(mot1f, mot_speed);
  analogWrite(mot2f, mot_speed);
  digitalWrite(mot1b, 0);
  digitalWrite(mot2b, 0);
}
void motors_back(){                      //MOTORS BACK FUNCTION
  digitalWrite(mot1f, 0);
  digitalWrite(mot2f, 0);
  analogWrite(mot1b, mot_speed);
  analogWrite(mot2b, mot_speed);
}
void motors_stop() {                      //MOTORS STOP FUNCTION
  digitalWrite(mot1f, 1);
  digitalWrite(mot2f, 1);
  digitalWrite(mot1b, 1);
  digitalWrite(mot2b, 1);
}
void motors_left() {                     //MOTORS LEFT FUNCTION
  analogWrite(mot1f, mot_speed);
  digitalWrite(mot2f, 0);
  digitalWrite(mot1b, 0);
  analogWrite(mot2b, mot_speed);
}
void motors_right() {                    //MOTORS RIGHT FUNCTION
  digitalWrite(mot1f, 0);
  analogWrite(mot2f, mot_speed);
  analogWrite(mot1b, mot_speed);
  digitalWrite(mot2b, 0);
}
void motors_foward_left() {             //FORWARD LEFT FUNCTION
int k = mot_speed*0.8;
  analogWrite(mot1f, mot_speed);
  analogWrite(mot2f, k);
  digitalWrite(mot1b, 0);
  digitalWrite(mot2b, 0);
}
void motors_foward_right() {             //FORWARD RIGHT FUNCTION
int k = mot_speed*0.8;
  analogWrite(mot1f, k);
  analogWrite(mot2f, mot_speed);
  analogWrite(mot1b, 0);
  analogWrite(mot2b, 0);
}
void motors_back_left() {               //BACK LEFT FUNCTION
int k = mot_speed*0.8;
  digitalWrite(mot1f, 0);
  digitalWrite(mot2f, 0);
  analogWrite(mot1b, k);
  analogWrite(mot2b, mot_speed);
}
void motors_back_right() {               //BACK RIGHT FUNCTION
int k = mot_speed*0.8;
  digitalWrite(mot1f, 0);
  digitalWrite(mot2f, 0);
  analogWrite(mot1b, mot_speed);
  analogWrite(mot2b, k);
}
