#include "pch.h"
#include "Bus.h"


Bus::Bus(string owner, string model, string regNum, string color, int numOfWheels, int numOfChairs, bool doubleDecker, chrono::system_clock::time_point start)
	: Vehicle(owner, model, regNum, color, numOfWheels, 4, start), NumOfChairs(numOfChairs), DoubleDecker(doubleDecker) {}

void Bus::printVehicle()const
{
	cout << "Bus owner: " << Owner << ", Model: " << Model << ", Reg number: " << RegNum
		<< ", Color: " << Color << ", wheels: " << NumOfWheels << "\n"
		<< "   It has " << NumOfChairs << " chairs"
		<< ((DoubleDecker) ? " and is double-decker.\n" : " and is not double-decker.\n") << endl;
};


