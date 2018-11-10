//TODO Add License

#ifndef Photosensor_h
#define Photosensor_h

#define BRIGHT 1
#define DARK 0

#include "Arduino.h"

/**
* Represents a Light-Dependent Resistor (LDR) - Photoresistor.
* It gives usable both digital and analog information about the ambient luminosty.
* As well it saves and compares data from different readings to provide information about changes in ambient luminosity.
*
* One terminal of the sensor have to be connected on an analog pin.
* The other one can be connected on GND or 5V (through a resistor).
* This needs to be specified when calling the class constructor.
*/
class Photosensor {

public:
	Photosensor(byte sensorPin, int brightLevel, int darkLevel,
		bool LDRtoGround = true);
	int getLuminosity();
	bool getState();
	bool getLastState();
	void setBrightLevel(int brightLevel);
	void setDarkLevel(int darkLevel);

private:
	byte pin;
	bool LDRtoGround;
	int lum;
	bool lumState;
	bool lumLastState;
	int brightLevel;
	int darkLevel;
};

#endif
