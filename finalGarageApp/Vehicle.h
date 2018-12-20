#pragma once

class Vehicle
{
protected:
	string Owner, Model, RegNum, Color;
	int NumOfWheels, TypeOfV;
	chrono::system_clock::time_point Start;
public:
	Vehicle(string owner, string model, string regNum, string color, int numOfWheels, int typeOfV, chrono::system_clock::time_point start);

	inline 	~Vehicle() { cout << "Vehicle decon\n"; };

	virtual void printVehicle()const = 0;
	inline int  get_typeOfV()const { return this->TypeOfV; };
	inline int get_numOfWheels()const { return this->NumOfWheels; };
	inline string get_regNum()const { return this->RegNum; };
	inline string get_color()const { return this->Color; };
	inline chrono::system_clock::time_point get_StartTime()const { return this->Start; };
	//void set_tov() { TypeOfV = 9; };
};