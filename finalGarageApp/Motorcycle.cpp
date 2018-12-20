#include "pch.h"

#include "Motorcycle.h"


Motorcycle::Motorcycle(string owner, string model, string regNum, string color, int numOfWheels, bool sidecar, bool windshield, chrono::system_clock::time_point start)
	: Vehicle(owner, model, regNum, color, numOfWheels, 2, start), Sidecar(sidecar), Windshield(windshield) {}


void Motorcycle::printVehicle()const
{
	cout << "Motorcycle owner: " << Owner << ", Model: " << Model << ", Reg number: " << RegNum
		<< ", Color: " << Color << ", wheels: " << NumOfWheels << "\n"
		<< ((Sidecar) ? "   It has a sidecar" : "   It doesn't have a sidecar")
		<< (((Sidecar && Windshield) || (!Sidecar && !Windshield)) ? " and " : " but ")
		<< ((Windshield) ? "has windshield.\n" : "doesn't have windshield.\n") << endl;
};


