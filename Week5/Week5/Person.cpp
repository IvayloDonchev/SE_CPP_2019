#include "Person.h"
#include <iostream>

Person::Person() : name(""), address(""), year(0){
	std::cout << "Person default construction...\n";
}

Person::Person(std::string name, std::string address, int year) :
	name(name),
	address(address),
	year(year)
{}

Person::~Person(){
	std::cout << "Person destruction...\n";
}

void Person::Show()
{
	std::cout << name << ", " << address << ", " << year << std::endl;
}
