#include "pch.h"
#include "listor.h"

enum options
{
	E_WrongInput = 666, E_AddVeh = 1, E_ShowGarage, E_showAllVehicle, E_showAllVehicleNEW, E_showVehicleBy/*, E_FindVeh*/, E_SearchRemovVec, E_Exit
};
enum anotherOrders
{
	E_color = 1, E_numOfWheels, E_typeOfVec, E_regNum
};
enum Mylistor
{
	E_MainList, E_AddVecList, E_ShowVecList
};
enum vehicleEnum
{
	E_Bicycle = 1, E_Motorcycle, E_Car, E_Bus, E_Truck, E_Submarine
};
enum Boolesk
{
	E_yes = 1, E_no
};


void listor::addTestVehicle()
{

	VehicleP = new Bicycle("1", "bmx1", "qQWE123", "white1", 2, true, false, chrono::system_clock::now());
	garageV[chooseGarage].addVehicle(VehicleP);
	VehicleP = new Bus("4", "bmx4", "QWE234", "white4", 4, 33, true, chrono::system_clock::now());
	garageV[chooseGarage].addVehicle(VehicleP);
	VehicleP = new Motorcycle("3", "bmx3", "QWE345", "white3", 4, false, false, chrono::system_clock::now());
	garageV[chooseGarage].addVehicle(VehicleP);
	VehicleP = new Bicycle("2", "bmx2", "QWE456", "white2", 2, false, true, chrono::system_clock::now());
	garageV[chooseGarage].addVehicle(VehicleP);
	VehicleP = new Bus("5", "bmx5", "QWE567", "white5", 6, 33, false, chrono::system_clock::now());
	garageV[chooseGarage].addVehicle(VehicleP);
	VehicleP = new Car("6", "bmx6", "QWE678", "white6", 6, 4, true, chrono::system_clock::now());
	garageV[chooseGarage].addVehicle(VehicleP);
	VehicleP = new Car("7", "bmx7", "QWE789", "white7", 6, 4, false, chrono::system_clock::now());
	garageV[chooseGarage].addVehicle(VehicleP);
	VehicleP = new Car("8", "bmx8", "QWE321", "white8", 6, 2, true, chrono::system_clock::now());
	garageV[chooseGarage].addVehicle(VehicleP);
}







void listor::managing()
{
	chooseGarage = 0;
	tempBool1 = true;
	while (tempBool1)
	{
		cout
			<< "1.Add garage\n"
			<< "2.Show all garage\n"
			<< "3.delete garage\n"
			<< "4.switch garage \n"
			<< "5.continue\n";

		getUserInput();
		switch (userInputInt)
		{
		case 1:
			creategarage();
			break;
		case 2:
			for (unsigned int i = 0; i < garageV.size(); i++)
			{
				cout << i + 1 << "- " << garageV[i].get_garageName() << endl;
			}
			break;
		case 3:
			for (unsigned int i = 0; i < garageV.size(); i++)
			{
				cout << i + 1 << "- " << garageV[i].get_garageName() << endl;
			}
			getUserInput();
			tempInt = garageV.size();
			if ((userInputInt > 0) && (userInputInt <= tempInt))
			{
				garageV[userInputInt - 1].cleanAGarage();
				garageV.erase(garageV.begin() + (userInputInt - 1));
			}
			userInputInt = E_MainList;
			break;
		case 4:
			for (unsigned int i = 0; i < garageV.size(); i++)
			{
				cout << i + 1 << "- " << garageV[i].get_garageName() << endl;
			}
			getUserInput();
			tempInt = garageV.size();
			if ((userInputInt > 0) && (userInputInt <= tempInt))
			{
				chooseGarage = userInputInt - 1;
			}
			break;
		case 5:
			tempBool1 = false;
			userInputInt = E_MainList;
			break;
		default:
			break;
		}
	}

}

void listor::creategarage()
{
	cout << "How many parking lots? ";
	while (!(cin >> sizeOfGarage))
	{
		cout << "wrong input, try again\n";
		cin.clear();
		cin.ignore();
	}
	cout << "what is the garage name : ";
	cin.clear();
	cin.ignore();
	getline(cin, garageName);
	//garageP=new Garage(sizeOfGarage, garageName);


	Garage garage(sizeOfGarage, garageName);
	garageV.push_back(garage);
	userInputInt = E_MainList;
}

void listor::init()
{

	managing();
	userInputInt = E_MainList;;
	while (whileToGo)
	{
		moveto();
		system("cls");
	}

	for (unsigned int i = 0; i < garageV.size(); i++)
	{
		garageV[i].cleanAGarage();
	}
	//vector<Garage>().swap(garageV); //this method or -> clear and shrink_to_fit //to clear the vector
	garageV.clear();
	garageV.shrink_to_fit();
}

void listor::getUserInput()
{

	accepted = false;
	try
	{
		cin >> userInputString;
		userInputInt = stoi(userInputString);
		accepted = true;
	}
	catch (const std::exception&)
	{
		cout << ("something went wrong,insert only numbers please\n\a");
		system("pause");
		accepted = false;
		userInputInt = E_WrongInput;
	}

}


//////////////////////////////////////
//////////////////////////////////////
///////////////Main Meny /////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
void listor::mainMeny()
{

	garageV[chooseGarage].numberOfPlacesLeft();
	cout << "-------------------------------------------------------------------\n"
		<< "Welcome to the " << garageV[chooseGarage].get_garageName() << ". What would you like to do?\n"
		<< "It cost 30 kronor per hour.\n"
		<< "1.Add vehicle\n"
		<< "2.Show garage(list vehicle)\n"
		<< "3.Show  all vehicles(ListTypeOfVehicles)\n"
		<< "4.Show  all vehicles(ListTypeOfVehicles)\"Enhanced way\"\n"
		<< "5.Show Vehicles by  ... \n"
		<< "6.Search/Remove vehicle\n"
		<< "8.managing garages\n"
		<< "7.Exit\n";

	getUserInput();
	switch (userInputInt)
	{
	case E_AddVeh:
		userInputInt = E_AddVecList;
		break;
	case E_ShowGarage:
		garageV[chooseGarage].listVehicles();
		system("pause");
		userInputInt = E_MainList;
		break;
	case E_showAllVehicle:
		garageV[chooseGarage].ListTypeOfVehicles();
		system("pause");
		userInputInt = E_MainList;
		break;
	case E_showAllVehicleNEW:
		garageV[chooseGarage].listTypeOfVecNEW();
		system("pause");
		userInputInt = E_MainList;
		break;
	case E_showVehicleBy:
		userInputInt = E_ShowVecList;
		break;
	case E_SearchRemovVec:
		searchAndRemove();
		userInputInt = E_MainList;
		break;
	case E_Exit:
		whileToGo = false;
		break;
	case E_WrongInput:
		userInputInt = E_MainList;
		break;
	case 8:
		managing();
		userInputInt = E_MainList;
		break;
	case 70:
		addTestVehicle();
		userInputInt = E_MainList;
		break;
	default:
		cout << "Wrong input, try again.\n";
		system("pause");
		userInputInt = E_MainList;
		break;
	}
}



//////////////////////////////////////
//////////////////////////////////////
//////// Add vehicle List ////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
void listor::addVecile()
{
	if (garageV[chooseGarage].isFull())
	{
		cout << "The garage is full, you cannot add more vehicles!\n";
		system("pause");
		userInputInt = E_MainList;
	}
	else
	{


		cout << "What type of vehicle do you want to add?\n"
			<< "1.Bicycle \n"
			<< "2.Motorcycle\n"
			<< "3.Car \n"
			<< "4.Bus\n"
			<< "5.Truck\n"
			<< "0.Main meny\n";

		getUserInput();
		switch (userInputInt)
		{
		case E_MainList:
			userInputInt = E_MainList;
			break;
		case E_Bicycle:
			addBicycle();
			userInputInt = E_MainList;
			break;
		case E_Motorcycle:
			addMotorcycle();
			userInputInt = E_MainList;
			break;
		case E_Car:
			addCar();
			userInputInt = E_MainList;
			break;
		case E_Bus:
			addBus();
			userInputInt = E_MainList;
			break;
		case E_Truck:
			addTruck();
			userInputInt = E_MainList;
			break;
		case E_WrongInput:
			userInputInt = E_AddVecList;
			break;
		default:
			cout << "Wrong input, try again.\n";
			system("pause");
			userInputInt = E_AddVecList;
			break;
		}

	}
}
///////////////////////////////////////////
//////////////add bicycle ////////////////
//////////////////////////////////////////
void listor::addBicycle()
{
	cout << "What is the registration number?  ";
	regnuml = regNumInput();
	if (!garageV[chooseGarage].findByRegNum(regnuml))
	{

		cout << "What is the owner's name?  ";
		cin.ignore();
		getline(cin, ownerl);
		cout << "What model is it?  ";
		cin.ignore();
		getline(cin, modell);

		cout << "What color is it?  ";
		cin.ignore();
		getline(cin, colorl);
		cout << "How many wheels does your vehicle has?  ";
		getUserInput();
		if (accepted)
		{
			if (userInputInt >= 1 && userInputInt <= 4)
				numOfwheelsl = userInputInt;
			else
			{
				cout << "You cannot be serious\n";
				cout << "Default -> \"2\".\n";
				numOfwheelsl = 2;
			}
		}
		else
		{
			cout << "Default -> \"2\".\n";
			numOfwheelsl = 2;
		}
		cout << "Does the bicycle have supporting wheels?\n1-yes\n2-no\n";
		getUserInput();
		if (userInputInt == 1)
			tempBool1 = true;
		else if (userInputInt == 2)
			tempBool1 = false;
		else
		{
			cout << "Default -> \"no\".\n";
			tempBool1 = false;
		}
		cout << "Is the bicycle tandem?\n1-yes\n2-no\n";
		getUserInput();
		if (userInputInt == 1)
			tempBool2 = true;
		else if (userInputInt == 2)
			tempBool2 = false;
		else
		{
			cout << "Default -> \"no\".\n";
			tempBool2 = false;
		}
		VehicleP = new Bicycle(ownerl, modell, regnuml, colorl, numOfwheelsl, tempBool1, tempBool2, chrono::system_clock::now());
		garageV[chooseGarage].addVehicle(VehicleP);
	}
	else
		cout << "the vehicle is already in the garage!\n";

	system("pause");

}
///////////////////////////////////////////
//////////////add motorcycle///////////////
//////////////////////////////////////////
void listor::addMotorcycle()
{
	cout << "What is the registration number?  ";
	regnuml = regNumInput();
	if (!garageV[chooseGarage].findByRegNum(regnuml))
	{


		cout << "What is the owner's name?  ";
		cin.ignore();
		getline(cin, ownerl);

		cout << "What model is it?  ";
		cin.ignore();
		getline(cin, modell);
		cout << "What color is it?  ";
		cin.ignore();
		getline(cin, colorl);
		cout << "How many wheels does your vehicle have?  ";
		getUserInput();
		if (accepted)
		{
			if (userInputInt >= 2 && userInputInt <= 3)
				numOfwheelsl = userInputInt;
			else
			{
				cout << "You cannot be serious\n";
				cout << "Default -> \"2\".\n";
				numOfwheelsl = 2;
			}
		}
		else
		{
			cout << "Default -> \"2\".\n";
			numOfwheelsl = 2;
		}
		cout << "Is there a sidecar?\n1-yes\n2-no\n";
		getUserInput();
		if (userInputInt == 1)
			tempBool1 = true;
		else if (userInputInt == 2)
			tempBool1 = false;
		else
		{
			cout << "Default -> \"no\".\n";
			tempBool1 = false;
		}
		cout << "Is there a windshield?\n1-yes\n2-no\n";
		getUserInput();
		if (userInputInt == 1)
			tempBool2 = true;
		else if (userInputInt == 2)
			tempBool2 = false;
		else
		{
			cout << "Default -> \"no\".\n";
			tempBool2 = false;
		}
		VehicleP = new Motorcycle(ownerl, modell, regnuml, colorl, numOfwheelsl, tempBool1, tempBool2, chrono::system_clock::now());
		garageV[chooseGarage].addVehicle(VehicleP);
	}
	else
		cout << "the vehicle is already in the garage!\n";

	system("pause");
}
//////////////////////////////////////
///////////add car////////////////////
/////////////////////////////////////
void listor::addCar()
{

	cout << "What is the registration number?  ";
	regnuml = regNumInput();
	if (!garageV[chooseGarage].findByRegNum(regnuml))
	{


		cout << "What is the owner's name?  ";
		cin.ignore();
		getline(cin, ownerl);

		cout << "What model is it?  ";
		cin.ignore();
		getline(cin, modell);
		cout << "What color is it?  ";
		cin.ignore();
		getline(cin, colorl);
		cout << "How many wheels does your vehicle have?  ";
		getUserInput();
		if (accepted)
		{
			if (userInputInt >= 3 && userInputInt <= 4)
				numOfwheelsl = userInputInt;
			else
			{
				cout << "You cannot be serious\n";
				cout << "Default -> \"4\".\n";
				numOfwheelsl = 4;
			}
		}
		else
		{
			cout << "Default -> \"4\".\n";
			numOfwheelsl = 4;
		}

		cout << "How many doors does your vehicle have?  ";
		getUserInput();
		if (accepted)
		{
			if (userInputInt >= 2 && userInputInt <= 4)
				numofdoorsl = userInputInt;
			else
			{
				cout << "You cannot be serious\n";
				cout << "Default -> \"4\".\n";
				numofdoorsl = 4;
			}
		}
		else
		{
			cout << "Default -> \"4\".\n";
			numofdoorsl = 4;
		}

		cout << "Does your car have a GPS?\n1-yes\n2-no\n";
		getUserInput();
		if (userInputInt == 1)
			tempBool1 = true;
		else if (userInputInt == 2)
			tempBool1 = false;
		else
		{
			cout << "Default -> \"no\".\n";
			tempBool1 = false;
		}

		VehicleP = new Car(ownerl, modell, regnuml, colorl, numOfwheelsl, numofdoorsl, tempBool1, chrono::system_clock::now());
		garageV[chooseGarage].addVehicle(VehicleP);
	}
	else
		cout << "the vehicle is already in the garage!\n";

	system("pause");
}

///////////////////////////////////
////////////addbus/////////////////
///////////////////////////////////

void listor::addBus()
{

	cout << "What is the registration number?  ";
	regnuml = regNumInput();
	if (!garageV[chooseGarage].findByRegNum(regnuml))
	{


		cout << "What is the owner's name?  ";
		cin.ignore();
		getline(cin, ownerl);

		cout << "What model is it?  ";
		cin.ignore();
		getline(cin, modell);
		cout << "What color is it?  ";
		cin.ignore();
		getline(cin, colorl);
		cout << "How many wheels does your vehicle have?  ";
		getUserInput();
		if (accepted)
		{
			if (userInputInt >= 4 && userInputInt <= 20)
				numOfwheelsl = userInputInt;
			else
			{
				cout << "You cannot be serious\n";
				cout << "Default -> \"6\".\n";
				numOfwheelsl = 6;
			}
		}
		else
		{
			cout << "Default -> \"6\".\n";
			numOfwheelsl = 6;
		}
		cout << "How many seats does your vehicle have?  ";
		getUserInput();
		if (accepted)
		{
			if (userInputInt >= 8 && userInputInt <= 89)
				numofseatsl = userInputInt;
			else
			{
				cout << "You cannot be serious\n";
				cout << "Default -> \"56\".\n";
				numofseatsl = 56;
			}
		}
		else
		{
			cout << "Default -> \"56 \".\n";
			numofseatsl = 56;
		}

		cout << "Is the bus double-decker?\n1-yes\n2-no\n";
		getUserInput();
		if (userInputInt == 1)
			tempBool1 = true;
		else if (userInputInt == 2)
			tempBool1 = false;
		else
		{
			cout << "Default -> \"no\".\n";
			tempBool1 = false;
		}

		VehicleP = new Bus(ownerl, modell, regnuml, colorl, numOfwheelsl, numofseatsl, tempBool1, chrono::system_clock::now());
		garageV[chooseGarage].addVehicle(VehicleP);
	}
	else
		cout << "the vehicle is already in the garage!\n";

	system("pause");
}
//////////////////////////////////////
//////////////addtruck////////////////
//////////////////////////////////////
void listor::addTruck()
{

	cout << "What is the registration number?  ";
	regnuml = regNumInput();
	if (!garageV[chooseGarage].findByRegNum(regnuml))
	{


		cout << "What is the owner's name?  ";
		cin.ignore();
		getline(cin, ownerl);

		cout << "What model is it?  ";
		cin.ignore();
		getline(cin, modell);
		cout << "What color is it?  ";
		cin.ignore();
		getline(cin, colorl);
		cout << "How many wheels do your vehicle has?  ";
		getUserInput();
		if (accepted)
		{
			if (userInputInt >= 8 && userInputInt <= 98)
				numOfwheelsl = userInputInt;
			else
			{
				cout << "You cannot be serious\n";
				cout << "Default -> \"18\".\n";
				numOfwheelsl = 18;
			}
		}
		else
		{
			cout << "Default -> \"18\".\n";
			numOfwheelsl = 18;
		}


		cout << "Is the truck loaded?\n1-yes\n2-no\n";
		getUserInput();
		if (userInputInt == 1)
			tempBool1 = true;
		else if (userInputInt == 2)
			tempBool1 = false;
		else
		{
			cout << "Default -> \"no\".\n";
			tempBool1 = false;
		}
		cout << "Does it have a crane?\n1-yes\n2-no\n";
		getUserInput();
		if (userInputInt == 1)
			tempBool2 = true;
		else if (userInputInt == 2)
			tempBool2 = false;
		else
		{
			cout << "Default -> \"no\".\n";
			tempBool2 = false;
		}
		VehicleP = new Truck(ownerl, modell, regnuml, colorl, numOfwheelsl, tempBool1, tempBool2, chrono::system_clock::now());
		garageV[chooseGarage].addVehicle(VehicleP);
	}
	else
		cout << "the vehicle is already in the garage!\n";

	system("pause");
}
//////////////////////////////////////
//////////////////////////////////////
///////////////find by////////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
void listor::showVecBy()
{


	cout << "Show by ...?\n"
		<< "1.color \n"
		<< "2.num of whells\n"
		<< "3.type of vehicle\n"
		<< "4.Reg number\n"
		<< "0.main meny\n";

	getUserInput();
	switch (userInputInt)
	{
	case E_MainList:
		userInputInt = E_MainList;
		break;
	case E_color:
		cout << "What color are you looking for?\n";
		cin >> MyTempString;
		garageV[chooseGarage].listVehicles(E_color, MyTempString);
		system("pause");
		userInputInt = E_MainList;
		break;
	case E_numOfWheels:
		cout << "How many wheels are you looking for?\n";
		getUserInput();
		if (accepted)
		{
			garageV[chooseGarage].listVehicles(E_numOfWheels, userInputInt);
			system("pause");
		}
		userInputInt = E_MainList;
		break;
	case E_typeOfVec:
		cout << "what type are you looking for?\n"
			<< "1.Bicycle \n"
			<< "2.Motorcycle\n"
			<< "3.Car \n"
			<< "4.Bus\n"
			<< "5.Truck\n";
		getUserInput();
		if (accepted)
		{
			garageV[chooseGarage].listVehicles(userInputInt);
			system("pause");
		}
		userInputInt = E_MainList;
		break;
	case E_regNum:
		cout << "Type the reg number?\n";
		MyTempString = regNumInput();

		garageV[chooseGarage].listVehicles(E_regNum, MyTempString);
		system("pause");
		userInputInt = E_MainList;
		break;
	case E_WrongInput:
		userInputInt = E_ShowVecList;
		break;
	default:
		cout << "Wrong input, try again.\n";
		system("pause");
		userInputInt = E_ShowVecList;
		break;
	}
}


//////////////////////////////////////
//////////////////////////////////////
/////////Search and remove////////////
//////////////////////////////////////
//////////////////////////////////////
void listor::searchAndRemove()
{

	cout << "type the reg number you want to search\n";
	MyTempString = regNumInput();
	if (garageV[chooseGarage].findByRegNum(MyTempString))
	{
		cout << "your vehicle has been found!\n";
		cout << "Would you like to remove your vehicle?\n1-yes\n2-no \n";
		getUserInput();
		switch (userInputInt)
		{
		case E_yes:
			garageV[chooseGarage].RemoveVehicle(MyTempString);
			userInputInt = E_MainList;
			break;
		case E_no:
			userInputInt = E_MainList;
			break;
		case E_WrongInput:
			searchAndRemove();
			break;
		default:
			cout << "Wrong input, try again.\n";
			searchAndRemove();
			break;

		}
	}
	else
	{
		cout << "The vehicle is not found!\n";
		cout << "shoud be system line\n";
	}
	system("pause");

}

void listor::moveto()
{

	switch (userInputInt)
	{
	case E_MainList:
		mainMeny();
		break;
	case E_AddVecList:
		addVecile();
		break;
	case E_ShowVecList:
		showVecBy();
		break;
	default:
		cout << "Wrong in moveto method \n\n";
		break;
	}

}

string listor::regNumInput()
{
	do
	{
		accepted = false;

		cin.clear();
		cin.ignore();

		cin >> regnumlchar;
		for (int i = 0; i < 6; i++)
		{
			if (i <= 2)
			{
				if (!isalpha(regnumlchar[i]))
				{
					//cout << "wrong input ... i = " << i << endl;
					accepted = true;
				}
				else
				{
					regnumlchar[i] = toupper(regnumlchar[i]);
				}
			}

			else if (i >= 3)
			{
				if (!isdigit(regnumlchar[i]))
				{
					//cout << "wrong input ... i = " << i << endl;
					accepted = true;
				}
			}
			else
			{
				cout << "WHAT\n";
			}
		}
		if (accepted)
			cout << "wrong input, ->AAA000<-\n\a";
	} while (accepted);
	regnumlchar[6] = '\0';
	cout << "vehicles reg number is : " << regnumlchar << endl;
	return regnumlchar;
}
