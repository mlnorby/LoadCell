#include "Arduino.h"
#include "HX711.h"

#define RST 4
#define DOUT  3					//Pin #A1
#define CLK  2					//Pin #A0

HX711 scale(DOUT, CLK);				//create LoadCell object

void setup() {
	Serial.begin(9600);			//38400
	scale.set_scale();
	scale.tare();  				//Reset the scale to 0
}

void loop() {
	scale.set_scale(360.3);			//Adjust to this calibration factor
	Serial.println("Reading weight");	//Read an average of X readings
	float weight = scale.get_units(10);
	Serial.print(weight);
	Serial.println(" g");
}
