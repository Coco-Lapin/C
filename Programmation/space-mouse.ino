/*Programme permettant a l'aide d'un arduino nano ayant une puce 32u4 de connecter 
un joystick a la place d'une souris afin de créer une space mouse pour gérer les
zooms et mouvement autour d'une pièce 3D faite avec le logiciel de modelisation 3D FUSION 360*/

//inclusion bibliotheque keyboard
#include "Keyboard.h"

//inclusion bibliotheque Mouse
#include "Mouse.h"

//initialisation et declaration variable pour joystick

const char axeX = 0;      //axeX    -- valeur de l'axe X du joystick
const char axeY = 1;      //axeY    -- valeur de l'axe Y du joystick
const char bouton = 9;    //bouton  -- bouton du joystick
const char ledStatu = 2;  //led     -- indicateur permettant de savoir si l'on va zommer ou bouger la piece en

char stateBouton;

unsigned int valeurX = 0;
unsigned int valeurY = 0;

void setup() {

  //declaration des différentes variables en sortie (OUTPUT) ou en entree (INPUT) pour le joystick
  pinMode(axeX, INPUT);
  pinMode(axeY, INPUT);
  
  stateBouton = HIGH;

  //demarrage du port serie
  Serial.begin(9600);

  Mouse.begin();
  Keyboard.begin();
}

void loop() {

  valeurX = analogRead(axeX);  //lecture de la valeur de la variable axeX et ecriture dans la variable valeurX
  valeurY = analogRead(axeY);  //lecture de la valeur de la variable axeY et ecriture dans la variable valeurY

  //la valeur de X au repos vaut 500 et la valeur de Y au repos vaut 519
  //condition permettant d'allumer ou eteindre une led indiquant le mode de la souris

  //mouse.move(X,Y,Roll)
  while (valeurX >= 600) {
    Mouse.click(MOUSE_LEFT);  //bouton gauche souris presse
    Mouse.move(5, 0, 0);     //bouge de 20 unites sur axe X vers gauche
    delay(100);
  }
  while (valeurX <= 400) {
      Mouse.click(MOUSE_LEFT);  //bouton gauche souris presse
      Mouse.move(-5, 0, 0);    //bouge de 20 unites sur axe X vers droite
      delay(100);
  }
  while (valeurY >= 600) {
      Mouse.click(MOUSE_LEFT);  //bouton gauche souris presse
      Mouse.move(0, 5, 0);    //bouge de 20 unites sur axe Y vers haut
      delay(100);
  }
  while (valeurY <= 400) {
      Mouse.click(MOUSE_LEFT);  //bouton gauche souris presse
      Mouse.move(0, -5, 0);      //bouge de 20 unites sur axe Y vers bas
      delay(100);     
  }
  Mouse.release(MOUSE_LEFT);  //relachement du bouton gauche soursi

  if (stateBouton == true) {
    while (valeurX >= 600) {
      Mouse.move(0, 0, 0);
      delay(100);
    }
    while (valeurX <= 400) {
      Mouse.move(0, 0, 0);
      delay(100);
    }
  }
  Mouse.end();
  Keyboard.end();
}