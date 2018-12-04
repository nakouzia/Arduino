int MOT_R = 6;
int MOT_L = 5;
int HEATER = 7;
// LOW means ON

void setup(){
  pinMode(MOT_R, OUTPUT);
  pinMode(MOT_L, OUTPUT);
  pinMode(HEATER, OUTPUT);
}

void loop(){      
  Heat_On();
  Turn_Right();
  Stop();
  Heat_On();
  Turn_Left();
  Stop();
}

void Heat_On(){
  digitalWrite(MOT_R, HIGH);
  digitalWrite(MOT_L, HIGH);
  digitalWrite(HEATER, LOW);
  delay(15000);
}

void Turn_Right(){
  digitalWrite(MOT_R, LOW);
  digitalWrite(MOT_L, HIGH);
  digitalWrite(HEATER, LOW);
  delay(40000);
}

void Turn_Left(){
  digitalWrite(MOT_R, HIGH);
  digitalWrite(MOT_L, LOW);
  digitalWrite(HEATER, LOW);
  delay(40000);
}

void Stop(){
  digitalWrite(MOT_R, HIGH);
  digitalWrite(MOT_L, HIGH);
  digitalWrite(HEATER, HIGH);
  delay(10000);
}
void Cool(){
  digitalWrite(MOT_R, LOW);
  digitalWrite(MOT_L, HIGH);
  digitalWrite(HEATER, HIGH);
  delay(30000);
  digitalWrite(MOT_R, HIGH);
  digitalWrite(MOT_L, LOW);
  digitalWrite(HEATER, HIGH);
  delay(30000);
}
