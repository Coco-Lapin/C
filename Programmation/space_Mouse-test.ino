/*Programme permettant d'indiquer dans le port serie 
la valeur des axes X et Y d'un joystcik*/

//importation de la librairie
#include <Mouse.h>

//declaration et initialisation des variables
int xAxe = A1;
int yAxe = A2;
bool button = 2;

int xValue = 0;
int mappedX;
int yValue = 0;
int mappedY;
bool buttonValue;


void setup() {

  //déclaration des pin
  pinMode(xAxe,INPUT);
  pinMode(yAxe,INPUT);
  pinMode(button,INPUT_PULLUP);
  delay(2000);
  //initiation du port serie pour l'impression des valeurs de X Y et bouton
  Serial.begin(9600);

  //impression mise en forme
  Serial.println(" X    Y    Bouton");

  //initialisation de l'état du bouton
  buttonValue = false;

  //start de la librairie
  Mouse.begin();

}

void loop() {

  //lecture des valeurs des axes x y et de l'etat du bouton
  xValue = analogRead(xAxe);
  yValue = analogRead(yAxe);
  buttonValue = !digitalRead(button);

  //mapping des valeurs pour permettre de réduire leurs plages 
  mappedX = map(xValue,0,1023,-20,20);
  mappedY = map(yValue,0,1023,-20,20);

  //appel des fonctions
  retournerValeurBase(xValue,yValue,buttonValue);
  delay(100);
  retournerValeurMapper(mappedX,mappedY,buttonValue);
  delay(300);
}

//methode permettant d'imprimer les valeurs de X Y et bouton à l'écran
void retournerValeurBase(int x,int y,bool b){
  //impression des valeurs
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(b);
  Serial.println(" ");
}

//methode permettant d'imprimer les valeurs mapper de X Y et bouton à l'écran
void retournerValeurMapper(int x,int y,bool b){
  //impression des valeurs
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(b);
  Serial.println(" ");
}