#include<iostream>
#include<string>
#include "Person.h"
#include "Car.h"
using namespace std;

int main()
{
	//Person p1;	// default constructor
	//Person p2("Ivan", "Veliko Turnovo", 1995);
	//p2.Show();

	//Person* p;
	//p = &p2;
	//p->Show();

	//p = new Person("Georgi", "Varna", 1999);
	//p->Show();
	//delete p;

	Car car("Opel Corsa", "BT 1234 TB", "Ivan Ivanov", "Veliko Turnovo", 1995, 1993);
	car.Show();
	Car myCar{ car };
	myCar.Show();

	Car* p;
	p = new Car("Opel Astra", "BT 4321 TB", "Ivan Ivanov", "Veliko Turnovo", 1993, 2000);
	p->Show();
	delete p;

}