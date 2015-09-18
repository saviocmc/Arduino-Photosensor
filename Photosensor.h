#ifndef Photosensor_h
#define Photosensor_h

#define BRIGHT 1
#define DARK 0

#define PHOTOSENSOR_GND
//#define PHOTOSENSOR_5V 

/*One terminal of the sensor have to be connected on an analog pin.
The other one can be connected on GND or 5v.
Leave the correct #define depending on how did you connected the sensor on your circuit.*/

#include "Arduino.h"

class Photosensor{
	byte pin;
	int lum;
	bool lumState;
	bool lumLastState;
	int brightLevel;
	int darkLevel;
public:
	Photosensor(byte sensorPin, int brightLevel=300, int darkLevel=400);
	int getLuminosity();
	bool getState();
	bool getLastState();
	void setBrightLevel(int brightLevel);
	void setDarkLevel(int darkLevel);
};

#endif