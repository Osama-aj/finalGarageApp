#pragma once
#include "Vehicle.h"
class Bicycle : public Vehicle
{
private:
	bool SupportWheels, Tandem;
public:
	Bicycle(string owner, string model, string regNum, string color, int  numOfWheels, bool supportWheels, bool tandem, chrono::system_clock::time_point start);

	void printVehicle()const override;
};

