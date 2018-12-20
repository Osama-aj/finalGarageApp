#pragma once
#include "Vehicle.h"
class Car :
	public Vehicle
{
private:
	int NumOfDoors;
	bool Gps;
public:
	Car(string owner, string model, string regNum, string color, int numOfWheels, int numOfDoors, bool gps, chrono::system_clock::time_point start);

	void printVehicle()const override;

};

