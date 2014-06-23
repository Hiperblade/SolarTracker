//
//  Solar Traker Sensor Library
//
// -------------------------------------------
//  Release: 1.0 - 19/06/2014
// -------------------------------------------
//  Code:    Giorgio Amadei
// -------------------------------------------

#include "Arduino.h"

#ifndef SolarTracker_h
#define SolarTracker_h

class SolarTracker
{
  public:
	class Axis
	{
	  private:
		int pinSensor;
		int threshold;
		int lastDirection;
		// Lettura del sensore [-512..0..512]
		int getShift();
	  
	  public:
		// Costruttore il pin analogico a cui è collegato il sensore e la soglia di tolleranza
		Axis(int pinSensor, int threshold);
		// Restituisce lo scostamento della fonte di luce
		//    1 = sopra o destra
		//    0 = nessuno
		//   -1 = sotto o sinistra
		int track();
	};
	
	struct Data
	{
	  public:
		int horizontalDirection;
		int verticalDirection;
	};
	
  private:
    SolarTracker::Axis *horizontalAxis;
    SolarTracker::Axis *verticalAxis;
  
  public:
	// Costruttore i due pin analogici a cui è collegato il sensore e la soglia di tolleranza
    SolarTracker(int pinSensorHorizontal, int pinSensorVertical, int threshold);
	// Restituisce lo scostamento della fonte di luce
    SolarTracker::Data track();
};

#endif