#include "Photosensor.h"

//Public Methods

Photosensor::Photosensor(byte sensorPin, int brightLevel, int darkLevel,
	bool LDRtoGround)
{
	pin = sensorPin;
	this->brightLevel = brightLevel;
	this->darkLevel = darkLevel;
	this->LDRtoGround = LDRtoGround;
	lumState = getState();
}

bool Photosensor::getLastState(){
	return lumLastState;
}

int Photosensor::getLuminosity(){
	if (LDRtoGround) {
		return (1024 - analogRead(pin));
	} else {
		return analogRead(pin);
	}
}

bool Photosensor::getState(){
	lumLastState = lumState;
	lum = analogRead(pin);
	if (LDRtoGround) {
		if(lum < brightLevel) lumState = BRIGHT;
		else if(lum > darkLevel) lumState = DARK;
	} else {
		if(lum > brightLevel) lumState = BRIGHT;
		else if(lum < darkLevel) lumState = DARK;
	}
	return lumState;
}

void Photosensor::setBrightLevel(int brightLevel){
	this->brightLevel = brightLevel;
}

void Photosensor::setDarkLevel(int darkLevel){
	this->darkLevel = darkLevel;
}
