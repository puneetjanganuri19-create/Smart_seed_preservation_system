int BUZZER1 =  8; 
int RELAY1 =  5;
int RELAY2 =  6;
int RELAY3 =  7;

int RELAY5 =  12;
int RELAY6 =  13;
const int led1 =  A0; 
const int led2 =  A1;
const int led3 =  A2; 
const int led4 =  A3; 
const int led5 =  1; 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

//(1)
int buttonpin11 = 11, buttonpin10 = 10, buttonpin9 = 9, buttonpin4 = 4, buttonpin2 = 2 ;
int buttonState11 = 0, buttonState10 = 0, buttonState9 = 0, buttonState4 = 0, buttonState2 = 0  ;

void setup() {
   lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd. setCursor(0, 0);
  lcd.print(" PROJECT  TITEL ");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   FOOD GRAIN   ");
  lcd.setCursor(0, 1);
  lcd.print("PRESERVATION SYS");
  delay(3000);
  lcd.clear();
 
  

  pinMode(BUZZER1, OUTPUT);
  pinMode(RELAY1, OUTPUT);
   pinMode(RELAY2, OUTPUT);
    pinMode(RELAY3, OUTPUT);
   
   pinMode(RELAY5, OUTPUT);
    pinMode(RELAY6, OUTPUT);
    pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  buttonState2 = digitalRead(buttonpin2);
  
  buttonState4 = digitalRead(buttonpin4);
  buttonState9 = digitalRead(buttonpin9);
  buttonState10 = digitalRead(buttonpin10);
  buttonState11 = digitalRead(buttonpin11);
  
  digitalWrite(BUZZER1, LOW);
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
 
  digitalWrite(RELAY5, HIGH);
  digitalWrite(RELAY6, HIGH);
   digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);

  
  if (buttonState11 == LOW) {
    digitalWrite(RELAY1, LOW);
    lcd.setCursor(0, 0);
    lcd.print(" WHEAT MOISTURE ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED    ");
    lcd.clear();
    digitalWrite(led1, LOW);
    digitalWrite(BUZZER1, HIGH);
    digitalWrite(BUZZER1, LOW);
    
   
    
  }
  else if (buttonState10 == LOW) {
   digitalWrite(RELAY2, LOW);
    lcd.setCursor(0, 0);
    lcd.print(" RICE  MOISTURE ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED    ");
    lcd.clear();
    digitalWrite(led2, LOW);
    digitalWrite(BUZZER1, HIGH);
    digitalWrite(BUZZER1, LOW);
   
 
  }

  // (5)
  else if (buttonState9 == LOW) {
   digitalWrite(RELAY3, LOW);
    lcd.setCursor(0, 0);
    lcd.print(" CORN  MOISTURE ");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED    ");
    lcd.clear();
     digitalWrite(led3, LOW);
    digitalWrite(BUZZER1, HIGH);
    digitalWrite(BUZZER1, LOW);
    
 
  
  } 

// (6)
  else if (buttonState4 == LOW) {
    digitalWrite(RELAY5, LOW);
    lcd.setCursor(0, 0);
    lcd.print("SOYABEAN MOISTURE");
    lcd.setCursor(0, 1);
    lcd.print("    DETECTED    ");
    lcd.clear();
    digitalWrite(led4, LOW);
    digitalWrite(BUZZER1, HIGH); 
    digitalWrite(BUZZER1, LOW);
    
  }



  // (7)
  else if (buttonState2 == LOW) {
    digitalWrite(RELAY6, LOW);
    lcd.setCursor(0, 0);
    lcd.print(" FIRE  DETECTED ");
    lcd.setCursor(0, 1);
    lcd.print("  PLZ TAKE CARE ");
    lcd.clear();
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
    digitalWrite(BUZZER1, HIGH); 
    digitalWrite(BUZZER1, LOW);
    

    
    
  }