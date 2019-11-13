#pragma once
#include <string>
#include "Person.h"
class Car
{
private:
	std::string model;
	std::string registration;
	Person owner;
	int year;	// ������ �� ������������
public:
	Car();	//default constructor
	Car(std::string, std::string, std::string, std::string, int, int);
	~Car();	//destructor
	void Show();
};

