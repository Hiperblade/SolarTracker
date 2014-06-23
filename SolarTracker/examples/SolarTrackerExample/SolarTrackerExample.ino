//
//  Solar Traker Sensor Library example
//
// -------------------------------------------
//  Release: 1.0 - 19/06/2014
// -------------------------------------------
//  Code:    Giorgio Amadei
// -------------------------------------------

#include <SolarTracker.h>

// Example of SolarTrackerAxis on Analog pin A0 and A1
SolarTracker sensor(A0, A1, 50);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  SolarTracker::Data data = sensor.track();
  Serial.print("Sensor value - horizontal: " + data.horizontalDirection);
  Serial.println(" vertical: " + data.verticalDirection);
  delay(100);
}