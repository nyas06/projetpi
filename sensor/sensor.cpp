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
    cout << "debut programme" << endl;
    // initialisation de la librairie GPIO
	if(wiringPiSetup() == -1) {cout << "--> Erreur WiringPI " << endl;return -1;}
	// activation des ports GPIO
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	cout << "fin init" << endl;
	// declaration des variables repetition, selection selcal civil ou militaire,poste HF et indicatif
	unsigned int pulseStart,pulseStop,pulseInterval,distance;

	digitalWrite(TRIG,LOW);
    cout << "trig low" << endl;

    digitalWrite(TRIG,HIGH);
    usleep(10);
    digitalWrite(TRIG,LOW);
    cout << "trig envoyer" << endl;
	// initialisation de la librairie audio
    cout << "trig low" << endl;
	while(digitalRead(ECHO)==0){
        pulseStart=micros();
    }
    cout << "echo a 1" << endl;
    while(digitalRead(ECHO)==1){
        pulseStop=micros();
    }
    cout << "echo a 0" << endl;
    pulseInterval=pulseStart-pulseStop;
    distance = pulseInterval*0.170;
	cout << distance << endl;
	
	
  }  // fin fonction main