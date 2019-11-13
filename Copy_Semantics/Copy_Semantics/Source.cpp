#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;


class Person
{
private:
	char* name;
	char* address;
	int year;
public:
	Person() : name(nullptr), address(nullptr), year(0) {}
	Person(const char[], const char[], int);
	Person(const Person&);				// copy constructor
	Person& operator=(const Person&);	// copy assignment
	~Person();
	void Show() const;
	int Age() const;
};

Person::Person(const char n[], const char a[], int y)
{
	size_t len = strlen(n) + 1;
	name = new char[len];
	strcpy_s(name, len, n);
	len = strlen(a) + 1;
	address = new char[len];
	strcpy_s(address, len, a);
	year = y;
}

Person::Person(const Person& other)
{
	size_t n = strlen(other.name) + 1;
	this->name = new char[n];
	strcpy_s(name, n, other.name);
	n = strlen(other.address) + 1;
	this->address = new char[n];
	strcpy_s(address, n, other.address);
	this->year = other.year;
}

Person::~Person() {
	if (name) delete[] name;
	if (address) delete[] address;
}

Person& Person::operator=(const Person& other)
{
	if (this == &other)			// self assignment
		return *this;
	size_t n = strlen(other.name) + 1;
	if (name != nullptr) delete[] name;
	name = new char[n];
	strcpy_s(name, n, other.name);
	if (address != nullptr) delete[] address;
	n = strlen(other.address) + 1;
	address = new char[n];
	strcpy_s(address, n, other.address);
	year = other.year;
	return *this;
}
void Person::Show() const
{
	std::cout << name << ", " << address << ", born " << year 
		      << " (" << Age() << " years old)\n";
}

int Person::Age() const
{
	time_t now = std::time(0);   // времето в секунди от 01.01.1970 насам
	tm pt;	// Structure containing a calendar date and time broken down into its components.
	localtime_s(&pt,&now);	// Convert time_t to tm as local time
	int this_year = pt.tm_year + 1900;
	return this_year - year;
}

class Car
{
private:
	char* model;
	char* registration;
	int year;
	Person owner;
public:
	Car() :model(nullptr), registration(nullptr), year(0), owner() {}
	Car(const char[], const char[], int, const char[], const char[], int);
	~Car();
	Car(const Car&);			// copy constructor
	Car& operator=(const Car&);
	void Show() const;
};

Car::Car(const char mod[], const char reg[], int yc, 
	     const char nam[], const char adr[], int yo) : owner(nam, adr, yo)
{
	size_t n = strlen(mod) + 1;
	model = new char[n];
	strcpy_s(model, n, mod);
	n = strlen(reg) + 1;
	registration = new char[n];
	strcpy_s(registration, n, reg);
	year = yc;
}

Car::~Car()
{
	if (model) delete[] model;
	if (registration) delete[] registration;
}

Car::Car(const Car& other) : owner(other.owner)
{
	size_t n = strlen(other.model) + 1;
	model = new char[n];
	strcpy_s(model, n, other.model);
 	n = strlen(other.registration) + 1;
	registration = new char[n];
	strcpy_s(registration, n, other.registration);
	year = other.year;
}

Car& Car::operator=(const Car& other)
{
	if (this == &other) return *this;
	if (model) delete[] model; 
	size_t n = strlen(other.model) + 1;
	model = new char[n];
	strcpy_s(model, n, other.model);
	if (registration) delete[] registration;
	n = strlen(other.registration) + 1;
	registration = new char[n];
	strcpy_s(registration, n, other.registration);
	year = other.year;
	owner = other.owner;
	return *this;
}

void Car::Show() const
{
	cout << "Car model: " << model << endl;
	cout << "Reg. number: " << registration << endl;
	cout << "Year: " << year << endl;
	cout << "Owner: ";
	owner.Show();
}

int main()
{
	Person Ivaylo{ "Ivaylo Donchev", "V.T.", 1971 };
	Ivaylo.Show();
	cout << endl;

	Car c("Opel Corsa", "BT 1234 TB", 1993, "Ivan Ivanov", "V.T.", 2000);
	c.Show();

	Car c2{ c };	// copy construction
	c2.Show();

	Car c3;			// default constructor
	c3 = c;			// copy assignment
	c3.Show();

}