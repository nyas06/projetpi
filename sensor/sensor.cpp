#include <string>
#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
#include <ctime>

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
	pinMode(ECHO, OUTPUT);
	
	// declaration des variables repetition, selection selcal civil ou militaire,poste HF et indicatif
	string chaineRepetition,chaineTypeSelcal, chainePosteHf, chaineIndicatif;
	int nombreDeRepetition = 0,typeDeSecal=0, selectHF = 0;

	digitalWrite(TRIG,LOW);


    digitalWrite(TRIG,HIGH);

	// initialisation de la librairie audio
	usleep(10000);
	
		//retour à l'état repos des relais
		digitalWrite(EM1,HIGH);
		digitalWrite(EM2,HIGH);
		digitalWrite(EM3,HIGH);
	
	
  }  // fin fonction main