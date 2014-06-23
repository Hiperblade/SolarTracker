//
//  Solar Traker Sensor Library
//
// -------------------------------------------
//  Release: 1.0 - 19/06/2014
// -------------------------------------------
//  Code:    Giorgio Amadei
// -------------------------------------------

#include "Arduino.h"
#include "SolarTracker.h"

// Costruttore il pin analogico a cui è collegato il sensore e la soglia di tolleranza
SolarTracker::Axis::Axis(int pinSensor, int threshold)
{
  this->pinSensor = pinSensor;
  this->threshold = threshold;
}

// Lettura del sensore [-512..0..512]
int SolarTracker::Axis::getShift()
{
  return (512 - analogRead(this->pinSensor));
}

// Restituisce lo scostamento della fonte di luce
//    1 = sopra o destra
//    0 = nessuno
//   -1 = sotto o sinistra
int SolarTracker::Axis::track()
{
  int shift = getShift();
  int newDirection = 0;
  if(shift > 0)
  {
	newDirection = 1;
  }
  else if(shift < 0)
  {
	newDirection = -1;
  }
  
  if(this->lastDirection == newDirection)
  {
    // spostamento nella stessa direzione
    return this->lastDirection;
  }
  else
  {
    // gestione soglia
    if(abs(shift) >= this->threshold)
    {
      this->lastDirection = newDirection;
      return this->lastDirection;
    }
	else
	{
	  return 0;
	}
  }
}

// Costruttore i due pin analogici a cui è collegato il sensore e la soglia di tolleranza
SolarTracker::SolarTracker(int pinSensorHorizontal, int pinSensorVertical, int threshold)
{
  this->horizontalAxis = new SolarTracker::Axis::Axis(pinSensorHorizontal, threshold);
  this->verticalAxis = new SolarTracker::Axis::Axis(pinSensorVertical, threshold);
}

// Restituisce lo scostamento della fonte di luce
SolarTracker::Data SolarTracker::track()
{
	SolarTracker::Data ret = SolarTracker::Data();
	ret.horizontalDirection = this->horizontalAxis->track();
	ret.verticalDirection = this->verticalAxis->track();
	return ret;
}