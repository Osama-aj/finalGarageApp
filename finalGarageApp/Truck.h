#pragma once
#include "Vehicle.h"
class Truck :
	public Vehicle
{
private:
	bool IsLoaded, WithCrane;

public:
	Truck(string owner, string model, string regNum, string color, int numOfWheels, bool isLoaded, bool withCrane, chrono::system_clock::time_point start);

	void printVehicle()const override;
};

