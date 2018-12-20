#pragma once

#include "Vehicle.h"
class Motorcycle : public Vehicle
{
private:
	bool Sidecar, Windshield;
public:
	Motorcycle(string owner, string model, string regNum, string color, int numOfWheels, bool sidecar, bool windshield, chrono::system_clock::time_point start);

	void printVehicle()const override;
};

