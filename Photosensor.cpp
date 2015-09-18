#include "Photosensor.h"

//Public Methods

Photosensor::Photosensor(byte sensorPin, int brightLevel, int darkLevel){
	pin = sensorPin;
	this->brightLevel = brightLevel;
	this->darkLevel = darkLevel;
	lumState = getState();
}

int Photosensor::getLuminosity(){
	return analogRead(pin);
}

bool Photosensor::getLastState(){
	return lumLastState;
}

#ifdef PHOTOSENSOR_GND

bool Photosensor::getState(){
	lumLastState = lumState;
	lum = analogRead(pin);
	if(lum < brightLevel) lumState = 1;
	else if(lum > darkLevel) lumState = 0;
	return lumState;
}

#endif

#ifdef PHOTOSENSOR_5V

bool Photosensor::getState(){
	lumLastState = lumState;
	lum = analogRead(pin);
	if(lum > brightLevel) lumState = 1;
	else if(lum < darkLevel) lumState = 0;
	return lumState;
}

#endif

void Photosensor::setBrightLevel(int brightLevel){
	this->brightLevel = brightLevel;
}

void Photosensor::setDarkLevel(int darkLevel){
	this->darkLevel = darkLevel;
}