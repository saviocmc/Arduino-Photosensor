//TODO Add License

#ifndef Photosensor_h
#define Photosensor_h

#define BRIGHT 1
#define DARK 0

/**
* One terminal of the sensor have to be connected on an analog pin.
* The other one can be connected on GND or 5V (through a resistor).
* Leave the correct #define below depending on how did you connect the sensor on your circuit.
*/

#define PHOTOSENSOR_TO_GND
//#define PHOTOSENSOR_TO_5V

#include "Arduino.h"

/**
* Represents a Light-Dependent Resistor (LDR) - Photoresistor.
* It gives usable both digital and analog information about the ambient luminosty.
* As well it saves and compares data from different readings to provide information about changes in ambient luminosity.
*/
class Photosensor{
	byte pin;
	int lum;
	bool lumState;
	bool lumLastState;
	int brightLevel;
	int darkLevel;
	
public:
	Photosensor(byte sensorPin, int brightLevel, int darkLevel);
	int getLuminosity();
	bool getState();
	bool getLastState();
	void setBrightLevel(int brightLevel);
	void setDarkLevel(int darkLevel);

	//TODO: Need Implementation
	bool hadStateChange();
	bool hadBrightToDarkChange();
	bool hadDarkToBrightChange();
};

#endif
