
#include <OneWire.h> 
#include <DallasTemperature.h>

// pin2
#define ONE_WIRE_BUS 2 

//OneWire reading all pins
OneWire oneWire(ONE_WIRE_BUS); 

// tell Dallas Temperature to read pins
DallasTemperature sensors(&oneWire);

void setup(void) 
{ 
 // start serial port 
 Serial.begin(9600); 
 // Start sensors 
 sensors.begin(); 
} 
void loop(void) 
{ 
 //get temperature readings 
 sensors.requestTemperatures();

 Serial.print("Temperature is:   1: "); 
 Serial.print(sensors.getTempFByIndex(0));
 Serial.print("     2: ");
 Serial.print(sensors.getTempFByIndex(1));
 Serial.println();
 delay(1000); 
} 
