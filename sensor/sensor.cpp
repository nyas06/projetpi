#include <string>
#include <iostream>
#include <wiringPi.h>
#include <unistd.h>

#define 	TRIG		4  //port GPIO relais HF1
#define		ECHO		5  //port GPIO relais HF2

using namespace std;
 
 int main(int argc, char *argv[]){ 
 
	// verification si le programme est lance avec les droits root
	if(getuid()) {

		cerr << "Le droit root est obligatoire" << endl;
		return -1;
	}

    // initialisation de la librairie GPIO
	if(wiringPiSetup() == -1) {cout << "--> Erreur WiringPI " << endl;return -1;}
	// activation des ports GPIO
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INTPUT);
	
	// declaration des variables repetition, selection selcal civil ou militaire,poste HF et indicatif
	unsigned int pulseStart,pulseStop,pulseInterval,distance;

	digitalWrite(TRIG,LOW);


    digitalWrite(TRIG,HIGH);
    usleep(10);
    digitalWrite(TRIG,LOW);
	// initialisation de la librairie audio
	usleep(10000);

	while(digitalRead(ECHO)==0){
        pulseStart=micros();
    }

    while(digitalRead(ECHO)==1){
        pulseStop=micros();
    }
    
    pulseInterval=pulseStart-pulseStop;
    distance = pulseInterval*0.170;
	cout << distance << endl;
	
	
  }  // fin fonction main