#define STEP 4 // definimos la variable "STER" el cual es el giro del motor
#define DIR 5 // definimos la variable "DIR" el cual es el sentido de giro del motor
const int coinpin = 2; // se define como el pin digital del monedero insertado
const int pull=7; // se define como el pin del pulsador para activar el motor y haga el giro predeterminado 
int estado=0; // se define como el estado en el que comienza el interruptor "como apagado"
const int ledpin = 13; // sirve para los releas no tiene que ver con las pokebolas
const int ledpin1 = 4; // sirve para los releas no tiene nada que ver con las pokebolas
volatile int pulse= 0; // se usa como una variable para iniciar los pulsos que da el monedero 
boolean bInserted = false; // sirve como una suposicion de falsedad que da el monedero 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // inicia la pantalla del monitoreo 
  attachInterrupt(digitalPinToInterrupt(coinpin), coinInterrupt ,RISING); // definido como el interruptor de ataque como indica en ingles es una variable que ahce funcionar al monedero de forma eficaz
  pinMode(coinpin, INPUT_PULLUP);// sirve para poder detectar los pulsos del monedero 
  pinMode(pull, INPUT_PULLUP); // sirve para detectar los pulsos del interruptor 
  pinMode(ledpin,OUTPUT); // sirve para definir como salida el dicho del pin del releas pero no tiene nada que ver con el proyecto 
  pinMode(STEP,OUTPUT); //definido como la varibale que sirve para definir el giro del motor 
  pinMode(DIR,OUTPUT); // define la variable del motor determina la cantidad de giros de dicho motor 
}

void loop() {
  digitalWrite(DIR,LOW);// el motor giro del motor tendra sentido horario 
  // put your main code here, to run repeatedly
  estado=digitalRead(pull); // dice que estado "variable de iniciacion" como un pin digital el cual es pull
 if(estado==LOW and bInserted ){ // es una condicional usada para poder realzar la operacion del monedero 
   bInserted = false; // sirve como variable de incializacion para poder definir al monedero como una falsedad 
   Serial.println("pulse"); // escrib en el tablero  si se activa dicha condicion con la palabra coin 
   for(int i=0;i<60;i++){ // es una variable de incializacion de rango for i in range se usa para ciertos tipos de trabajos este es uno de esosn
    digitalWrite(STEP,HIGH); // define al motor para que pueda seguir dichos pasas de ejeccucion
    delay(4);//determina una cantidad de tiempo para que pueda realizar una vuelta de  90 *
    digitalWrite(STEP,LOW); // hace que el motor gire en sentido antihorario 
    delay(0);//determina una cantidad de tiempo para que pueda realizar una vuelta de  90 *
   }
  
  }
}
void coinInterrupt(){ // es una funcion aparte
  pulse++; //hace que los pulsos se sumen de 1 en 1 
  bInserted = true;
  Serial.println(pulse); // digita la cantidad de pulsos
}
