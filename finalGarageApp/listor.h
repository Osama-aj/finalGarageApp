#pragma once
#include"Garage.h"
#include"Vehicle.h"
#include"Bicycle.h"
#include"Motorcycle.h"
#include"Car.h"
#include"Bus.h"
#include"Truck.h"





class listor
{
private:
	//Garage garage;
	vector<Garage> garageV;
	Vehicle * VehicleP;
	string userInputString;
	int userInputInt, sizeOfGarage, chooseGarage, tempInt;
	string MyTempString;
	bool accepted;
	bool whileToGo = true;    // to make the program running or not    
	////////temp variabel
	string  ownerl, colorl, modell, regnuml, garageName;
	char regnumlchar[7];
	int numOfwheelsl, numofseatsl, numofdoorsl;
	bool tempBool1, tempBool2;
public:
	//listor() ;
	void managing();
	void creategarage();
	void addTestVehicle();//bara f�r att prova programmet, anv�ns inte i release l�ge
	void init();
	void getUserInput();
	void mainMeny();
	void addVecile();
	void addBicycle();
	void addMotorcycle();
	void addCar();
	void addBus();
	void addTruck();
	void showVecBy();
	void searchAndRemove();
	void moveto();
	string regNumInput();
};

