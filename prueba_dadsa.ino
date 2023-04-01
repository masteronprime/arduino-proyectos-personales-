#include <Keypad.h>
#include <LiquidCrystal_I2C.h> 
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int screenWidth = 16;
int screenHeigth = 16;
int stringStart, stringStop = 0;
int scrollCursor = screenWidth;
const int coinpin = 2;
const int ledpin = 4; 
const int ledpin1 = 3;
const int ledpin2 = 13;
const int ledpin3 = 12;
unsigned long startTime1;
unsigned long startTime2;
unsigned long startTime3;
unsigned long startTime4;
static long cont1 = 0;
static long cont2 = 0;
static long cont3 = 0;
static long cont4 = 0;
volatile int pulse = 0;
boolean bInserted = false;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {9, 10, 11};
byte colPins[COLS] = { 6, 7, 8};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  attachInterrupt(digitalPinToInterrupt(coinpin), coinInterrupt ,RISING);
  pinMode(coinpin, INPUT_PULLUP);
  pinMode(ledpin, OUTPUT);
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  digitalWrite(ledpin, LOW);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
  String line1 ="RAY" ;
  String line2 ="ELECTRONICS" ;
  lcd.setCursor(5,0);
  lcd.print(line1);
  lcd.setCursor(2,1);
  lcd.print(line2);
  delay(10000);
  lcd.clear();
  String line3 ="CONTACTENOS:" ;
  String line4 ="946188720" ;
  lcd.setCursor(1,0);
  lcd.print(line3);
  lcd.setCursor(2,1);
  lcd.print(line4);
  delay(10000);
  lcd.clear();
  
}
void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
    }
  if ( key == '1') {
    bInserted = false;
    digitalWrite(ledpin, HIGH);
    startTime1 = millis();
    Serial.println("Interruptor 1 encendido");
    Serial.println("Contador: " + String(cont1));
    Serial.println(millis() - startTime1);
    Serial.println("coin");
    
    }
  if ( key == '2') {
    bInserted = false;
    digitalWrite(ledpin1, HIGH);
    startTime2 = millis();
    cont2 = cont2 + 1;
    Serial.println("Interruptor 2 encendido");
    Serial.println("Contador: " + String(cont2));
    Serial.println(millis() - startTime2);
  }
  if (bInserted & key == '3') {
    bInserted = false;
    digitalWrite(ledpin2, HIGH);
    startTime3 = millis();
    cont3 = cont3 + 1;
    Serial.println("Interruptor 3 encendido");
    Serial.println("Contador: " + String(cont3));
    Serial.println(millis() - startTime3);
    }
   if (bInserted & key == '4') {
    bInserted = false;
    digitalWrite(ledpin3, HIGH);
    startTime3 = millis();
    cont4 = cont4 + 1;
    Serial.println("Interruptor 4 encendido");
    Serial.println("Contador: " + String(cont4));
    Serial.println(millis() - startTime4);
    }
  if (millis() - startTime1 >= 20000) {
    digitalWrite(ledpin, LOW);
    
  }
  if (millis() - startTime2 >= 20000) {
    digitalWrite(ledpin1, LOW);
  }
  if (millis() - startTime3 >= 20000) {
    digitalWrite(ledpin2, LOW);
  }
  millis()==0;

 
  String m =String((millis() - startTime1)/1000);
  String line1 ="1:" + m + " " +  String(((millis() - startTime2)/1000)/60) ;
  String line2 = String(((millis() - startTime2)/1000)/60);
  lcd.setCursor(0,0);
  lcd.print(line1);

  lcd.setCursor(0,1);
  lcd.print(line2);

  delay(200);
  lcd.clear();
}
void coinInterrupt(){ // es una funcion aparte
  pulse++; //hace que los pulsos se sumen de 1 en 1 
  bInserted = true;
  if (pulse==1){
     Serial.println("usted inserto:" +  String( pulse ) + "moneda"  ); 
    
  }
  else{
    Serial.println("usted inserto:" +  String( pulse ) + "monedas"  ); // digita la cantidad de pulse
  }
}
