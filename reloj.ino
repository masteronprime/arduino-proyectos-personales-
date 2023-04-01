                                                                                       
#include <MaxMatrix.h>//libreria para poder usar el modulo MAX7219
#include "RTClib.h" //libreria para poder usar el modulo RTC DS1307
#include <Keypad.h> //libreria para poder usar el teclado de 4 x 4
#include <avr/pgmspace.h>

RTC_DS1307 rtc; 
const byte ROWS = 4; //cuatro filas
const byte COLS = 4; //cuatro columnas 
char keys[ROWS][COLS] = {     
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 10, 11, 12}; //conectamos los pines de la fila del teclado 
byte colPins[COLS] = {5, 6, 7, 8}; //conectamos los pines de la columna del teclado 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //selecciona los valores que les dimos  a los pines de las columans ,filas ,lee la matriz char keys
PROGMEM const unsigned char CH[] = //Se definen todos los caracteres posibles y se cargan en la memoria del programa para la matriz CH 
{  
3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, // espacio
1, 8, B01011111, B00000000, B00000000, B00000000, B00000000, // !
3, 8, B00000011, B00000000, B00000011, B00000000, B00000000, // "
5, 8, B00010100, B00111110, B00010100, B00111110, B00010100, // #
4, 8, B00100100, B01101010, B00101011, B00010010, B00000000, // $
5, 8, B01100011, B00010011, B00001000, B01100100, B01100011, // %
5, 8, B00110110, B01001001, B01010110, B00100000, B01010000, // &
1, 8, B00000011, B00000000, B00000000, B00000000, B00000000, // '
3, 8, B00011100, B00100010, B01000001, B00000000, B00000000, // (
3, 8, B01000001, B00100010, B00011100, B00000000, B00000000, // )
5, 8, B00101000, B00011000, B00001110, B00011000, B00101000, // *
5, 8, B00001000, B00001000, B00111110, B00001000, B00001000, // +
2, 8, B10110000, B01110000, B00000000, B00000000, B00000000, // ,
4, 8, B00001000, B00001000, B00001000, B00001000, B00000000, // -
2, 8, B01100000, B01100000, B00000000, B00000000, B00000000, // .
4, 8, B01100000, B00011000, B00000110, B00000001, B00000000, // /
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // 0
3, 8, B01000010, B01111111, B01000000, B00000000, B00000000, // 1
4, 8, B01100010, B01010001, B01001001, B01000110, B00000000, // 2
4, 8, B00100010, B01000001, B01001001, B00110110, B00000000, // 3
4, 8, B00011000, B00010100, B00010010, B01111111, B00000000, // 4
4, 8, B00100111, B01000101, B01000101, B00111001, B00000000, // 5
4, 8, B00111110, B01001001, B01001001, B00110000, B00000000, // 6
4, 8, B01100001, B00010001, B00001001, B00000111, B00000000, // 7
4, 8, B00110110, B01001001, B01001001, B00110110, B00000000, // 8
4, 8, B00000110, B01001001, B01001001, B00111110, B00000000, // 9
2, 8, B01010000, B00000000, B00000000, B00000000, B00000000, // :
2, 8, B10000000, B01010000, B00000000, B00000000, B00000000, // ;
3, 8, B00010000, B00101000, B01000100, B00000000, B00000000, // <
3, 8, B00010100, B00010100, B00010100, B00000000, B00000000, // =
3, 8, B01000100, B00101000, B00010000, B00000000, B00000000, // >
4, 8, B00000010, B01011001, B00001001, B00000110, B00000000, // ?
5, 8, B00111110, B01001001, B01010101, B01011101, B00001110, // @
4, 8, B01111110, B00010001, B00010001, B01111110, B00000000, // A
4, 8, B01111111, B01001001, B01001001, B00110110, B00000000, // B
4, 8, B00111110, B01000001, B01000001, B00100010, B00000000, // C
4, 8, B01111111, B01000001, B01000001, B00111110, B00000000, // D
4, 8, B01111111, B01001001, B01001001, B01000001, B00000000, // E
4, 8, B01111111, B00001001, B00001001, B00000001, B00000000, // F
4, 8, B00111110, B01000001, B01001001, B01111010, B00000000, // G
3, 8, B01000001, B01111111, B01000001, B00000000, B00000000, //I
4, 8, B01111111, B00001000, B00001000, B01111111, B00000000, // H
4, 8, B00110000, B01000000, B01000001, B00111111, B00000000, // J
4, 8, B01111111, B00001000, B00010100, B01100011, B00000000, // K
4, 8, B01111111, B01000000, B01000000, B01000000, B00000000, // L
5, 8, B01111111, B00000010, B00001100, B00000010, B01111111, // M
5, 8, B01111111, B00000100, B00001000, B00010000, B01111111, // N
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // O
4, 8, B01111111, B00001001, B00001001, B00000110, B00000000, // P
4, 8, B00111110, B01000001, B01000001, B10111110, B00000000, // Q
4, 8, B01111111, B00001001, B00001001, B01110110, B00000000, // R
4, 8, B01000110, B01001001, B01001001, B00110010, B00000000, // S
5, 8, B00000001, B00000001, B01111111, B00000001, B00000001, // T
4, 8, B00111111, B01000000, B01000000, B00111111, B00000000, // U
5, 8, B00001111, B00110000, B01000000, B00110000, B00001111, // V
5, 8, B00111111, B01000000, B00111000, B01000000, B00111111, // W
5, 8, B01100011, B00010100, B00001000, B00010100, B01100011, // X
5, 8, B00000111, B00001000, B01110000, B00001000, B00000111, // Y
4, 8, B01100001, B01010001, B01001001, B01000111, B00000000, // Z
2, 8, B01111111, B01000001, B00000000, B00000000, B00000000, // [
4, 8, B00000001, B00000110, B00011000, B01100000, B00000000, // \ 
2, 8, B01000001, B01111111, B00000000, B00000000, B00000000, // ]
3, 8, B00000010, B00000001, B00000010, B00000000, B00000000, // acento 
4, 8, B01000000, B01000000, B01000000, B01000000, B00000000, // _
2, 8, B00000001, B00000010, B00000000, B00000000, B00000000, // `
4, 8, B00100000, B01010100, B01010100, B01111000, B00000000, // a
4, 8, B01111111, B01000100, B01000100, B00111000, B00000000, // b
4, 8, B00111000, B01000100, B01000100, B00101000, B00000000, // c
4, 8, B00111000, B01000100, B01000100, B01111111, B00000000, // d
4, 8, B00111000, B01010100, B01010100, B00011000, B00000000, // e
3, 8, B00000100, B01111110, B00000101, B00000000, B00000000, // f
4, 8, B10011000, B10100100, B10100100, B01111000, B00000000, // g
4, 8, B01111111, B00000100, B00000100, B01111000, B00000000, // h
3, 8, B01000100, B01111101, B01000000, B00000000, B00000000, // i
4, 8, B01000000, B10000000, B10000100, B01111101, B00000000, // j
4, 8, B01111111, B00010000, B00101000, B01000100, B00000000, // k
3, 8, B01000001, B01111111, B01000000, B00000000, B00000000, // l
5, 8, B01111100, B00000100, B01111100, B00000100, B01111000, // m
4, 8, B01111100, B00000100, B00000100, B01111000, B00000000, // n
4, 8, B00111000, B01000100, B01000100, B00111000, B00000000, // o
4, 8, B11111100, B00100100, B00100100, B00011000, B00000000, // p
4, 8, B00011000, B00100100, B00100100, B11111100, B00000000, // q
4, 8, B01111100, B00001000, B00000100, B00000100, B00000000, // r
4, 8, B01001000, B01010100, B01010100, B00100100, B00000000, // s
3, 8, B00000100, B00111111, B01000100, B00000000, B00000000, // t
4, 8, B00111100, B01000000, B01000000, B01111100, B00000000, // u
5, 8, B00011100, B00100000, B01000000, B00100000, B00011100, // v
5, 8, B00111100, B01000000, B00111100, B01000000, B00111100, // w
5, 8, B01000100, B00101000, B00010000, B00101000, B01000100, // x
4, 8, B10011100, B10100000, B10100000, B01111100, B00000000, // y
3, 8, B01100100, B01010100, B01001100, B00000000, B00000000, // z
3, 8, B00001000, B00110110, B01000001, B00000000, B00000000, // {
1, 8, B01111111, B00000000, B00000000, B00000000, B00000000, // |
3, 8, B01000001, B00110110, B00001000, B00000000, B00000000, // }
4, 8, B00001000, B00000100, B00001000, B00000100, B00000000, // ~
};


// Definimos los pines del arduino
int data1 = 3;    // Pin DIN del módulo MAX7219
int load = 2;    // Pin CS del módulo MAX7219
int clockc = 4;  // Pin CLK del módulo MAX7219

//
int maxuse = 4 ; //Definimos cuantas matrices usaremos. En este caso solo se usará 5


MaxMatrix m(data1, load, clockc, maxuse); // Definimos la funcion de cada pin
char string1[] = "Ingenieria Informatica" ; // Texto que aparecerá en la matriz 

byte buffer[10];

 
void setup() //modulo que se ejecuta 1 vez
{
  m.init();          // Se inicializa el modulo
  m.setIntensity(10); // Se define la intensidad de los LED´s (0-15)
    Serial.begin(9600); // muestra los valores en el monitor serial del arduino 

  if (! rtc.begin()) {
    Serial.println("no se encontro un rtc");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC no esta corriendo ,¡ vamos a cambiar la hora!"); // cuando necesitamos usar el rtc despues de que lo apagamos , si no reconoce nada imprime RTC no esta corriendo

   rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // esta linea actualiza el rtc con la hora de la computadora
}
}
void loop() //modulo que se ejecuta varias veces
{
  char key = keypad.getKey(); 
  if (key) {
    Serial.println(key);
  }

  DateTime now = rtc.now(); // le damos un nombre a el tiempo el cual sera rtc.now()
  char timeString[9]; // convertira los valores de la lista en un caracter 
   if (now.hour()>24 ){ // si la hora del rtc exede a las 24 horas este se actualiza a 00:00:00
    snprintf(timeString,sizeof(timeString),"%02d:%02d:%02d",now.hour()-24 ,now.minute(),now.second()); // linea que realiza lo que se dice arriba 
   } else ; {
    snprintf(timeString,sizeof(timeString),"%02d:%02d:%02d",now.hour(),now.minute(),now.second());//ordena los valores del rtc 
    Serial.println(timeString);//imprime los valores del rtc 
    printString(timeString); //llama a la funcion imprimir para despues convertirlo en valores puntuales en la matriz 
   }
  if (key=='1'){ 
  byte c;
  delay(1000);  // Pausa entre movimientos
  m.shiftLeft(false, true);
  printStringWithShift(string1, 100);  // Se envia el texto al modulo
  }
  if (key=='2'){
   char diassemana[10];
   snprintf(diassemana,sizeof(diassemana),now.day());
   Serial.println(diassemana);
   printString(diassemana);
    
  }
}
  
  
void printString(char*s) // modulo que se encarga de imprimir en la matriz , convierte en caracteres los numeros que nos bota el rtc
 {
  int col=0;//inicia una variable en 0 
  while(*s !=0) // mientras la cantidad de valores sea diferente de 0 
  {
    if (*s < 32)continue; // si los valores del rtc es menor a 32 se ejecuta 
    char c=*s-32; 
    memcpy_P(buffer,CH+7*c,7);//inicidaliza los valores de la matriz CH
    m.writeSprite(col,0,buffer);//ubica los valores de la matriz CH
    m.setColumn(col + buffer[0],0);
    col +=buffer[0]+1;
    s++;//aumenta la variable de 1 en 1 
  }
 }
 
void printCharWithShift(char c, int shift_speed) // Funciones para mostrar el texto en el display.
{
  if (c <= 32) return;
  c -= 33;
  memcpy_P(buffer, CH + 7*c, 7);
  m.writeSprite(maxuse*8, 0, buffer);
  m.setColumn(maxuse*8 + buffer[0], 0);
  
  for (int i=0; i<buffer[0]+1; i++) 
  {
    delay(shift_speed);
    m.shiftLeft(false, false);
  }
}
 
void printStringWithShift(char* s, int shift_speed)
{
  while (*s != 0)
  {
    printCharWithShift(*s, shift_speed);
    s++;
  }
}
 
