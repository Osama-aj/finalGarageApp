#include "pch.h"
#include "Bicycle.h"




Bicycle::Bicycle(string owner, string model, string regNum, string color, int  numOfWheels, bool supportWheels, bool tandem, chrono::system_clock::time_point start)
	: Vehicle(owner, model, regNum, color, numOfWheels, 1, start), SupportWheels(supportWheels), Tandem(tandem) {}
void  Bicycle::printVehicle()const
{
	cout << "Bicycle owner: " << Owner << ", Model: " << Model << ", Reg number: " << RegNum
		<< ", Color: " << Color << ", wheels: " << NumOfWheels << "\n"
		<< ((SupportWheels) ? "   It has supporting wheels" : "   It doesn't have supporting wheel")
		<< (((SupportWheels && Tandem) || (!SupportWheels && !Tandem)) ? " and " : " but ")
		<< ((Tandem) ? "is tandem.\n" : "is not tandem.\n") << endl;
};