//
//  Solar Traker Sensor Library example
//
// -------------------------------------------
//  Release: 1.0 - 19/06/2014
// -------------------------------------------
//  Code:    Giorgio Amadei
// -------------------------------------------

#include <SolarTracker.h>

// Example of SolarTrackerAxis on Analog pin A0
SolarTracker::Axis sensor(A0, 50);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Sensor value: " + String(sensor.track()));
  delay(100);
}
