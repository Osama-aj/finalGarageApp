#include "pch.h"
#include "Garage.h"



enum vehicleEnum
{
	E_Bicycle = 1, E_Motorcycle, E_Car, E_Bus, E_Truck, E_Submarine
};
enum anotherOrders
{
	E_color = 1, E_numOfWheels, E_typeOfVec, E_regNum
};




//Garage::Garage()
//{
//	match = true;
//	do
//	{
//		cout << "How many parking lots? ";
//		while (!(cin >> userSize))
//		{
//			cout << "wrong input, try again\n";
//			cin.clear();
//			cin.ignore();
//		}
//
//		if (userSize > 0 && userSize <= 100)
//			match = false;
//		else
//			cout << "out of range, try again\n";
//
//
//
//	} while (match);
//
//
//
//	vecP = new (nothrow) Vehicle *[userSize];
//	for (int i = 0; i < userSize; i++)
//	{
//		vecP[i] = 0;
//	}
//
//	Places = new (nothrow) bool[userSize];
//	for (int i = 0; i < userSize; i++)
//	{
//		Places[i] = false;
//	}
//
//}

Garage::Garage(int size, string name)
{
	userSize = size;
	vecP = new (nothrow) Vehicle *[userSize];
	for (int i = 0; i < userSize; i++)
	{
		vecP[i] = 0;
	}

	Places = new (nothrow) bool[userSize];
	for (int i = 0; i < userSize; i++)
	{
		Places[i] = false;
	}
	garageName = name;
};

Garage::~Garage()
{
	cout << "garage deco\n";
	/*for (int i = 0; i < userSize; i++)
	{
		if (Places[i])
			delete vecP[i];
	}

	delete[] Places;
	delete[] vecP;*/

};


void Garage::cleanAGarage()
{
	cout << "Delete all\n";
	for (int i = 0; i < userSize; i++)
	{
		if (Places[i])
			delete vecP[i];
	}

	delete[] Places;
	delete[] vecP;
}

void Garage::set_userSize(int usersize)
{
	userSize = usersize;
};


void Garage::numberOfPlacesLeft()
{
	if (Vehiclecounter == 0)
		cout << "The garage is empty\n";
	else
		printf(((userSize - Vehiclecounter == 1) ? "there is %i place left\n" : "there are %i places left\n"), userSize - Vehiclecounter);
}
void Garage::addVehicle(Vehicle * newVehicle)
{

	if (Vehiclecounter < userSize)
	{
		match = false;

		for (int i = 0; i < userSize; i++)
		{
			if (Places[i])
			{
				if (vecP[i]->get_regNum() == newVehicle->get_regNum())
				{

					cout << "The vehicle is already in the garage.\n";
					match = true;
				}
			}
		}
		if (!match)
		{
			tempInt2 = -1;
			//using do while to avoid break in for-loop;
			while (Places[++tempInt2]) {};

			/*for (int i = 0; i < userSize; i++)
			{
				if (!Places[i])
				{
					j = i;
					break;
				}

			}*/
			Places[tempInt2] = true;
			vecP[tempInt2] = newVehicle;
			cout << "\nThe vehicle was successfully added.\n";
			/*vecP[Vehiclecounter]->printVehicle();*/
			Vehiclecounter++;
		}
	}
	else
		cout << "\tThe garage is full, sorry \n\n";
}

void Garage::listVehicles(int x)
{
	////varje nummer till nåt ... antal dörrar eller nåt annan
	if (Vehiclecounter > 0)
	{
		match = false;

		switch (x)
		{
		case 0:
			for (int i = 0; i < userSize; i++)
			{
				if (Places[i])
				{
					cout << i + 1 << "- ";
					vecP[i]->printVehicle();
				}

			}
			break;
		case E_Bicycle:
			for (int i = 0; i < userSize; i++)
			{
				if (Places[i])
				{
					if (vecP[i]->get_typeOfV() == E_Bicycle) {
						vecP[i]->printVehicle();
						match = true;
					}
				}

			}
			if (!match)
				cout << "There are no bikes in the garage!!\n";
			break;
		case E_Motorcycle:
			for (int i = 0; i < userSize; i++)
			{
				if (Places[i])
				{
					if (vecP[i]->get_typeOfV() == E_Motorcycle) {
						vecP[i]->printVehicle();
						match = true;
					}
				}

			}
			if (!match)
				cout << "There are no motorcycle in the garage!!\n";
			break;
		case E_Car:
			for (int i = 0; i < userSize; i++)
			{
				if (Places[i])
				{
					if (vecP[i]->get_typeOfV() == E_Car) {
						vecP[i]->printVehicle();
						match = true;
					}
				}

			}
			if (!match)
				cout << "There are no cars in the garage!!\n";
			break;
		case E_Bus:
			for (int i = 0; i < userSize; i++)
			{
				if (Places[i])
				{
					if (vecP[i]->get_typeOfV() == E_Bus) {
						vecP[i]->printVehicle();
						match = true;
					}
				}

			}
			if (!match)
				cout << "There are no busses in the garage!!\n";
			break;
		case E_Truck:
			for (int i = 0; i < userSize; i++)
			{
				if (Places[i])
				{
					if (vecP[i]->get_typeOfV() == E_Truck) {
						vecP[i]->printVehicle();
						match = true;
					}
				}

			}
			if (!match)
				cout << "There are no trucks in the garage!!\n";
			break;
		case E_Submarine:
			for (int i = 0; i < userSize; i++)
			{
				if (Places[i])
				{
					if (vecP[i]->get_typeOfV() == E_Submarine) {
						vecP[i]->printVehicle();
						match = true;
					}
				}

			}
			if (!match)
				cout << "There are no submarines in the garage!!\n";
			break;

		default:
			cout << "wrong input\n\n";
			break;
		}
	}
	else
		cout << "The garage is empty!!\n";

}

void Garage::listVehicles(int x, string wordToLook)
{



	if (Vehiclecounter > 0)
	{
		if (x == E_color)
		{
			match = false;

			for (int i = 0; i < userSize; i++)
			{
				if (Places[i])
				{

					if (vecP[i]->get_color() == wordToLook) {
						vecP[i]->printVehicle();
						match = true;
					}
				}
			}
			if (!match)
				cout << "There are no " << wordToLook << " vehicles in the garage!!\n";

		}
		else if (E_regNum)
		{
			match = false;

			for (int i = 0; i < userSize; i++)
			{
				if (Places[i])
				{

					if (vecP[i]->get_regNum() == wordToLook) {
						vecP[i]->printVehicle();
						match = true;
					}
				}
			}
			if (!match)
				cout << "The vehicle has not been found!\n";
		}
		else
			cout << "You are using this funktion in the wrong way\n\n";
	}
	else
		cout << "The garage is empty!!\n";


}

void Garage::listVehicles(int x, int numToLook)
{

	if (x == E_numOfWheels)
	{

		if (Vehiclecounter > 0)
		{
			match = false;

			for (int i = 0; i < userSize; i++)
			{
				if (Places[i])
				{

					if (vecP[i]->get_numOfWheels() == numToLook)
					{
						vecP[i]->printVehicle();
						match = true;
					}
				}
			}
			if (!match)
				cout << "There are no vehicles with " << numToLook << " wheels in the garage!!\n";
		}
		else
			cout << "The garage is empty!!\n";
	}
	else
		cout << "you are using this function in wrong way\n\n";
}

void Garage::ListTypeOfVehicles()
{

	if (Vehiclecounter > 0)
	{
		for (int i = 0; i < 6; i++)
		{
			TempCounter[i] = 0;
			for (int ii = 0; ii < userSize; ii++)
			{
				if (Places[ii])
				{

					if (vecP[ii]->get_typeOfV() == i + 1)
					{
						TempCounter[i]++;
					}
				}
			}
		}
		if (TempCounter[0] != 0)
			printf(((TempCounter[0] == 1) ? "There is %i bike\n" : "There are %i bikes\n"), TempCounter[0]);
		if (TempCounter[1] != 0)
			printf(((TempCounter[1] == 1) ? "There is %i motorcyle\n" : "There are %i motorcyles\n"), TempCounter[1]);
		if (TempCounter[2] != 0)
			printf(((TempCounter[2] == 1) ? "There is %i car\n" : "There are %i cars\n"), TempCounter[2]);
		if (TempCounter[3] != 0)
			printf(((TempCounter[3] == 1) ? "There is %i buse\n" : "There are %i buses\n"), TempCounter[3]);
		if (TempCounter[4] != 0)
			printf(((TempCounter[4] == 1) ? "There is %i truck\n" : "There are %i trucks\n"), TempCounter[4]);
		if (TempCounter[5] != 0)
			printf(((TempCounter[5] == 1) ? "There is %i submarine\n\n" : "There are %i submarines\n\n"), TempCounter[5]);
		printf(((userSize - Vehiclecounter == 1) ? "there is %i place left\n" : "there are %i places left\n"), userSize - Vehiclecounter);
	}
	else
		cout << "The garage is empty!!\n";
}

void Garage::listTypeOfVecNEW()
{

	if (Vehiclecounter > 0)
	{
		for (int i = 0; i < 6; i++)
			TempCounter[i] = 0;

		for (int i = 0; i < userSize; i++)
		{

			if (Places[i])
			{
				cout << i + 1 << "-";
				switch (vecP[i]->get_typeOfV())
				{
				case 1:
					cout << " Bicycle, Reg Number: " << vecP[i]->get_regNum() << endl;
					break;
				case 2:
					cout << " MotorCycle, Reg Number: " << vecP[i]->get_regNum() << endl;
					break;
				case 3:
					cout << " Car, Reg Number: " << vecP[i]->get_regNum() << endl;
					break;
				case 4:
					cout << " Bus, Reg Number: " << vecP[i]->get_regNum() << endl;
					break;
				case 5:
					cout << " Truck, Reg Number: " << vecP[i]->get_regNum() << endl;
					break;

				default:
					break;
				};
			}
			else
			{
				cout << i + 1 << "-";
				cout << " Empty\n";
			}
		}

	}
	else
		cout << "The garage is empty!!\n";
}

bool Garage::findByRegNum(string regnumToFind)
{


	if (Vehiclecounter > 0)
	{
		match = false;

		for (int i = 0; i < userSize; i++)
		{
			if (Places[i])
			{

				if (vecP[i]->get_regNum() == regnumToFind) {
					//vecP[i]->printVehicle();
					//cout << "Your vehicle has been found in the garage.\n";
					match = true;
					return true;
				}
			}
		}
		if (!match)
		{
			//cout << "There are no vehicles with regnumber  \"" << regnumToFind << "\" \n";
			return false;
		}

	}
	else
	{
		//cout << "The garage is empty!!\n";
		return false;
	}
	return false;
}

void Garage::RemoveVehicle(string regNumToRemove)
{


	if (Vehiclecounter > 0)
	{
		match = false;

		for (int i = 0; i < userSize; i++)
		{
			if (Places[i])
			{
				if (vecP[i]->get_regNum() == regNumToRemove)
				{
					diff = chrono::system_clock::now() - vecP[i]->get_StartTime();
					//cout << "your car stayed in the garage : " << (long long int)round(diff.count()) << " seconds." << endl;
					calcMoney(diff.count(), 30);
					delete vecP[i];
					Places[i] = false;
					Vehiclecounter--;
					match = true;
					cout << "The vehicle has been removed.\n";
				}
			}

		}
		if (!match)
		{
			cout << "There are no vehicles with regnumber  \"" << regNumToRemove << "\" \n";
		}

	}
	else
		cout << "The garage is empty!!\n";
}

bool Garage::isFull()
{
	if (Vehiclecounter == userSize)
	{
		return true;
	}
	else
		return false;
}



void Garage::calcMoney(int timeBySecond, int kronorPerHour)
{
	bool finished{ false };
	int sec = timeBySecond;
	int days{ 0 }, hours{ 0 }, minute{ 0 }, tempHour{ 0 };

	do
	{
		finished = false;
		if (sec >= 60)
		{
			sec -= 60;
			minute++;
			finished = true;
		}

	} while (finished);
	do
	{
		finished = false;
		if (minute >= 60)
		{
			minute -= 60;
			hours++;
			finished = true;
		}

	} while (finished);
	tempHour = hours;
	do
	{
		finished = false;
		if (hours >= 24)
		{
			hours -= 24;
			days++;
			finished = true;
		}

	} while (finished);
	(days > 0) ? printf("2- you stayed here for %i days %i hours and %i minutes\n", days, hours, minute) :
		((hours > 0) ? printf("you stayed here for %i hours and %i minutes\n", hours, minute) : printf("you stayed here for %i minutes\n", minute));

	(minute == 0 && tempHour == 0) ? printf("you need to pay for half an hour ... and it is %i:-\n\n", kronorPerHour / 2)
		: (minute == 0) ? printf("you need to pay for %i hours... and it is %i:-\n\n", tempHour, ((tempHour)* kronorPerHour))
		: (((minute <= 30) ? printf("you need to pay for %i hours and a half ... and it is %i:-\n\n", tempHour, ((tempHour)* kronorPerHour) + (kronorPerHour / 2))
			: printf("you need to pay for %i hours ... and it is %i:-\n\n", tempHour + 1, (tempHour + 1) * kronorPerHour)));
}

