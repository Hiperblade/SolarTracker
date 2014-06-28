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
  Serial.println("Sensor value - horizontal: " + String(data.horizontalDirection) + " vertical: " + String(data.verticalDirection));
  delay(100);
}
