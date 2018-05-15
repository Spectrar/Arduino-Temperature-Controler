// credit to Miles Burton for the libraries in use
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
  String temps;
 //get temperature readings 
 sensors.requestTemperatures();

for (int i=0; i <= sensors.getDeviceCount()-1; i++){
  temps.concat((String)sensors.getTempFByIndex(i) + " ");
}
Serial.println(temps);
 delay(1000); 
} 

