#include "pch.h"
#include "Car.h"


Car::Car(string owner, string model, string regNum, string color, int numOfWheels, int numOfDoors, bool gps, chrono::system_clock::time_point start)
	: Vehicle(owner, model, regNum, color, numOfWheels, 3, start), NumOfDoors(numOfDoors), Gps(gps) {}


void Car::printVehicle()const
{
	cout << "Car owner: " << Owner << ", Model: " << Model << ", Reg number: " << RegNum
		<< ", Color: " << Color << ", wheels: " << NumOfWheels << "\n"
		<< "   It has " << NumOfDoors << " doors"
		<< ((Gps) ? " and has Gps.\n" : " and doesn't have Gps.\n") << endl;
};

