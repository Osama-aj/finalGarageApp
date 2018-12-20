#pragma once
#include "Vehicle.h"
class Bus :
	public Vehicle
{
private:
	int NumOfChairs;
	bool DoubleDecker;
public:
	Bus(string owner, string model, string regNum, string color, int numOfWheels, int numOfChairs, bool doubleDecker, chrono::system_clock::time_point start);

	void printVehicle()const override;
};

