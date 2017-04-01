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
	pinMode(ECHO, INPUT);
	
	// declaration des variables repetition, selection selcal civil ou militaire,poste HF et indicatif
	unsigned int pulseStart,pulseStop,pulseInterval,distance;

	digitalWrite(TRIG,LOW);
    

    int i=0;
    while(i<10){
    i++;
    digitalWrite(TRIG,HIGH);
    usleep(10);
    digitalWrite(TRIG,LOW);
    
	// initialisation de la librairie audio
    
	while(digitalRead(ECHO)==0){
        pulseStart=micros();
    }
    
    while(digitalRead(ECHO)==1){
        pulseStop=micros();
    }
    
    pulseInterval= pulseStart-pulseStop;
    distance = pulseInterval*0.170;
    cout << "pulsestart: "<< pulseStart << " mm"<<endl;
    cout << "pulsestop: "<< pulseStop << " mm"<<endl;
	cout << distance << " mm"<<endl;
	usleep(1000000);
    }
  }  // fin fonction main