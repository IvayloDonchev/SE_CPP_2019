#include "Car.h"
#include <iostream>

Car::Car() : model(""), registration(""), owner(), year(0)
{}

Car::Car(std::string model, std::string registration, 
	     std::string owner_name, std::string owner_address, int owner_year,
	     int year):
	model(model), registration(registration),
	owner(owner_name, owner_address, owner_year),
	year(year)
{}

Car::~Car(){
	std::cout << "Car destruction...\n";
}

void Car::Show(){
	std::cout << "Model: " << model << std::endl;
	std::cout << "Reg. number: " << registration << std::endl;
	std::cout << "Year: " << year << std::endl;
	std::cout << "Owner: ";
	owner.Show();	//Person::Show()
}



