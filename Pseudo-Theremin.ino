/*  Arduino Pseduo-Theramin ECE 110 AB8

    Original Code by:
      Nathan McGovern (nathanm3)
      Daniel Gros (gros2)

    Completed: April 24th, 2018

*/

#include <NewPing.h>
#include <toneAC.h>
#include <pitches.h>

#define triggerPin1 12
#define echoPin1 13
#define maxDistance 400

#define triggerPin2 7
#define echoPin2 8

//Notes and Warnings
//If you want to play different pitches on multiple pins, you need to call noNewTone() on one pin before calling Newtone() on the next pin (assuming the NewTone Library).
//Lets consider the toneAC library, as it is more recently updated than NewTone and allows for a variable volume output

NewPing sonar1(triggerPin1, echoPin1, maxDistance);
NewPing sonar2(triggerPin2, echoPin2, maxDistance);


double distancex;
// in centimeters
double distancey;
// in centimeters
double freq;            // in Hertz

void setup() {

  Serial.begin(9600);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);  //sonar2 = volume output

  distancex = 0;
  distancey = 0;

  delay(1000);

}

void loop() {

  distancex = sonar1.ping_cm();
  distancey = sonar2.ping_cm();

  Serial.print("Ping1: ");    //Debugging tool
  Serial.print(distancex);
  Serial.println(" cm");
  Serial.print("Ping2: ");
  Serial.print(distancey);
  Serial.println(" cm");

  if (distancex <= 10.0)
    freq = NOTE_C5;  //High C
  else if (distancex > 10.5 && distancex <= 20.0)
    freq = NOTE_B4; //B
  else  if (distancex > 20.5 && distancex <= 30.0)
    freq = NOTE_A4;  //Concert A Pitch
  else if (distancex > 30.5 && distancex <= 40.0)
    freq = NOTE_G4; //G
  else  if (distancex > 40.5 && distancex <= 50.0)        //Represents a change in frequency due to a change in distance from ultrasonic sensor
    freq = NOTE_F4; //F
  else  if (distancex > 50.5 && distancex <= 60.0)
    freq = NOTE_E4; //E
  else  if (distancex > 60.5 && distancex <= 70.0)
    freq = NOTE_D4;  //D
  else  if (distancex > 70.5)
    freq = NOTE_C4; //C


  //Below you will find code to potentially allow an ultrasonic sensor be used as a volume control
  //pins used = 9,10
  //VOLUME 0-9 ONLY, 10 sounds distored in comaprison


  if (distancey <= 5.0) { //Minimum Volume
    toneAC(freq, 0);
  }

  else if (distancey > 5.6 && distancey <= 10.0) {
    toneAC(freq, 1);
  }

  else if (distancey > 10.6 && distancey <= 15.0) {
    toneAC(freq, 2);
  }

  else if (distancey > 15.6 && distancey <= 20.0) {
    toneAC(freq, 3);
  }

  else if (distancey > 20.6 && distancey <= 25.0) {
    toneAC(freq, 4);
  }

  else if (distancey > 25.6 && distancey <= 30.0) { 
    toneAC(freq, 5);
  }

  else if (distancey > 30.6 && distancey <= 35.0) {
    toneAC(freq, 6);
  }

  else if (distancey > 35.6 && distancey <= 40.0) {
    toneAC(freq, 7);
  }

  else if (distancey > 40.6 && distancey <= 45.0) {
    toneAC(freq, 8);
  }

  else if (distancey > 45.6) { //Maximum Volume
    toneAC(freq, 9);
  }
  
  else
    toneAC(freq, 0);

  delay(300);
}

/*
 * 
  Credit:
    NewPing Library: Tim Eckel
    NewTone Library: Tim Eckel
    toneAC  Library: Tim Eckel
    pitches Library: mikeputnam
 
 */


