const int buttonPin = 10;     
const int white =  1;
const int green = 2;
const int blue = 3;
const int red = 4;
const int yellow = 5; 

int buttonState = 0;
int change = 0;
int flag = 0;

void setup() {

  pinMode(white, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(buttonPin, INPUT);
}

void mode1(){
  digitalWrite(white, HIGH);
  delay(100);
  digitalWrite(white, LOW);
  delay(100);
}

void mode2(){
  digitalWrite(green, HIGH);
  delay(100);
  digitalWrite(green, LOW);
  delay(100);
}

void mode3(){
  digitalWrite(blue, HIGH);
  delay(100);
  digitalWrite(blue, LOW);
  delay(100);
}

void mode4(){
  digitalWrite(red, HIGH);
  delay(100);
  digitalWrite(red, LOW);
  delay(100);
}

void mode5(){
  digitalWrite(yellow, HIGH);
  delay(100);
  digitalWrite(yellow, LOW);
  delay(100);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && flag == 0) {
    change += 1;
    flag = 1;

    if(change == 5){
      change = 0;
    }
  } else if(buttonState == LOW){
    flag = 0;
  }
  
  if(change == 0){
    mode1();
  }

  else if(change == 1){
    mode2();
  }

  else if(change == 2){
    mode3();
  }

  else if(change == 3){
    mode4();
  }

  else if(change == 4){
    mode5();
  }
  
}
