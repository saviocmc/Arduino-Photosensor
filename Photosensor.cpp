#include "Photosensor.h"

//Public Methods

Photosensor::Photosensor(byte sensorPin, int brightLevel, int darkLevel){
	pin = sensorPin;
	this->brightLevel = brightLevel;
	this->darkLevel = darkLevel;
	lumState = getState();
}

bool Photosensor::getLastState(){
	return lumLastState;
}

#ifdef PHOTOSENSOR_TO_GND

int Photosensor::getLuminosity(){
	return (1024 - analogRead(pin));
}

bool Photosensor::getState(){
	lumLastState = lumState;
	lum = analogRead(pin);
	if(lum < brightLevel) lumState = 1;
	else if(lum > darkLevel) lumState = 0;
	return lumState;
}

#endif

#ifdef PHOTOSENSOR_TO_5V

int Photosensor::getLuminosity(){
	return analogRead(pin);
}

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
