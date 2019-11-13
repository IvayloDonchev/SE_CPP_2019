#include <iostream>
#include <cstring>
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
	~Person();
	void Show();
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

Person::~Person() {
	if (name) delete[] name;
	if (address) delete[] address;
}

void Person::Show()
{
	std::cout << name << ", " << address << ", " << year << std::endl;
}

int main()
{
	Person person("Ivan Petrov", "Sofia", 2000);
	person.Show();

}