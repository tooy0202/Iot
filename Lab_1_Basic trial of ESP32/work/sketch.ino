const int buttonPin = 4; 
int buttonState = 0;
void setup() {
  Serial.begin(115200); 
  pinMode(buttonPin, INPUT);
  for(int i =16 ; i<=19; i++){
    pinMode(i,OUTPUT);
  }
}
void off_led(){
  for(int i =16 ; i<=19; i++){
    digitalWrite(i,LOW);
  }
}
void loop() {
  int delay_led = 0;
  buttonState = digitalRead(buttonPin);
  while(buttonState == HIGH){
    delay(1000);
    delay_led +=1000;
    Serial.println(delay_led);
    buttonState = digitalRead(buttonPin);
    if (buttonState == LOW){
      switch (delay_led) {
      case 1000:
          digitalWrite(16,HIGH);
          break;
      case 2000:
          digitalWrite(17,HIGH);
          break;
      case 3000:
          digitalWrite(18,HIGH);
          break;
      case 4000:
          digitalWrite(19,HIGH);
          break;
      default:
          break;
      }
    }
  }
  delay(1000);
  off_led();
}
