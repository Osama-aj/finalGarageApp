#include "pch.h"
#include "Truck.h"


Truck::Truck(string owner, string model, string regNum, string color, int numOfWheels, bool isLoaded, bool withCrane, chrono::system_clock::time_point start)
	: Vehicle(owner, model, regNum, color, numOfWheels, 5, start), IsLoaded(isLoaded), WithCrane(withCrane) {}


void Truck::printVehicle()const
{
	cout << "Truck owner: " << Owner << ", Model: " << Model << ", Reg number: " << RegNum
		<< ", Color: " << Color << ", wheels: " << NumOfWheels << "\n"
		<< ((WithCrane) ? "   It has a crane" : "   It doesn't have a crane")
		<< (((WithCrane && IsLoaded) || (!WithCrane && !IsLoaded)) ? " and " : " but ")
		<< ((IsLoaded) ? "is loaded.\n" : "is not loaded.\n") << endl;
};


