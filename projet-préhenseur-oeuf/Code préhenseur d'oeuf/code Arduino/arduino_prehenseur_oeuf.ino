// Nous ne pouvons pas nous passer d'arduino dans ce projet car le capteur de distance (ultrasons) nécessite une fréquence
// d'alimentation qui est supérieure a la fréquence d'ouverture et de fermeture du relais de sortie du PLC.
// Ce code a pour but de mesurer la distance qui sépare la structure du piston de la boite d'oeufs a l'aide
// d'un capteur ultrason, et envoie ensuite l'information au PLC. Il a aussi pour but de tourner le tourniquet quand il 
// en recoit l'ordre de la part du PLC.


#include <Stepper.h>
int stepsPerRevolution = 2048;
int motSpeed = 12;
int Trig_X=2;
int Echo_X=3;
int Trig_Y=4;
int Echo_Y=5;
int input_motor=6;
int tiempo_X;
int tiempo_Y;
int salida_X=12;
int salida_Y=13;
int X_map;
int Y_map;

Stepper myStepper(stepsPerRevolution,8,10,9,11);



void setup() {
  pinMode(salida_X,OUTPUT);
  pinMode(salida_Y,OUTPUT);
  pinMode(Trig_X,OUTPUT);
  digitalWrite(Trig_X,LOW);
  pinMode(Echo_X,INPUT);
  pinMode(input_motor,INPUT);
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
  pinMode(Trig_Y,OUTPUT);
  digitalWrite(Trig_Y,LOW);
  pinMode(Echo_Y,INPUT);
}
  
   
//725 x mini
//1660 x maxi
// 420 min Y
// 1230 max Y



void loop() {
  digitalWrite(Trig_X,HIGH);
  delay(1);
  digitalWrite(Trig_X, LOW);
  tiempo_X=pulseIn(Echo_X,HIGH);
  digitalWrite(Trig_Y,HIGH);
  delay(1);
  digitalWrite(Trig_Y, LOW);
  tiempo_Y=pulseIn(Echo_Y,HIGH);
  Serial.println(tiempo_X);
  delay(50);
  X_map=map(tiempo_X,725,1660,0,255);
  Y_map=map(tiempo_Y,420,1230,0,255);
  analogWrite(salida_X,X_map);
  analogWrite(salida_Y,Y_map);

 if (digitalRead(input_motor==HIGH)){
  myStepper.step(-512);
  delay(500);
 }
}
 
