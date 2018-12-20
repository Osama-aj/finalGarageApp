#pragma once
#include"Vehicle.h"





class Garage
{
private:
	void calcMoney(int timeBySecond, int kronorPerHour);
protected:

	bool match;
	int Vehiclecounter = 0;
	int TempCounter[6] = { 0,0,0,0,0,0 };
	/*
	static const int GarageCapacity = 12;
	bool Places[GarageCapacity];
	Vehicle * vecP[GarageCapacity];
	*/
	bool *Places;
	Vehicle **vecP;
	int userSize;
	string garageName;
	string tempString;
	int tempInt, tempInt2;

	chrono::duration<long double> diff;

public:

	//Garage();
	Garage(int size, string name);
	~Garage();
	void cleanAGarage();
	void set_userSize(int usersize);
	void numberOfPlacesLeft();
	void addVehicle(Vehicle * newVehicle);
	void listVehicles(int x = 0);
	void listVehicles(int x, string wordToLook);
	void listVehicles(int x, int numToLook);
	void ListTypeOfVehicles();
	void listTypeOfVecNEW();
	bool findByRegNum(string regnumToFind);
	void RemoveVehicle(string regNumToRemove);
	bool isFull();
	inline void set_garageName(string newName) { garageName = newName; };
	inline string get_garageName()const { return garageName; };
};

