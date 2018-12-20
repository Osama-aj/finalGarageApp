#include "pch.h"
#include "Vehicle.h"


Vehicle::Vehicle(string owner, string model, string regNum, string color, int numOfWheels, int typeOfV, chrono::system_clock::time_point start)
	: Owner(owner), Model(model), RegNum(regNum), Color(color), NumOfWheels(numOfWheels), TypeOfV(typeOfV), Start(start) {};


