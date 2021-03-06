#include <iostream>
using namespace std;

class Horse
{
public:
	Horse() : age(0) {
		cout << "Horse constructor...\n";
	}
	virtual ~Horse() {
		cout << "Horse destructor...\n";
	}
	virtual void Whinny() const {
		cout << "Whinny!...\n";
	}
private:
	int age;
};

class Bird
{
public:
	Bird() : weight(0) {
		cout << "Bird constructor...\n";
	}
	virtual ~Bird() {
		cout << "Bird destructor...\n";
	}
	virtual void Chirp() const {
		cout << "Chirp...\n";
	}
	virtual void Fly() const{
		cout << "I can fly!\n";
	}
private:
	int weight;
};

class Pegasus : public Horse, public Bird
{
public:
	void Chirp() const {
		Whinny();
	}
	Pegasus() {
		cout << "Pegasus constructor...\n";
	}
	~Pegasus() {
		cout << "Pegasus destructor...\n";
	}
};

int main()
{
	const int n = 3;
	Horse* Ranch[n];
	Bird* Aviary[n];
	Horse* pHorse;
	Bird* pBird;
	int choice, i;
	for (i = 0; i < n; i++)
	{
		cout << "\n(1) Horse   (2) Pegasus: ";
		cin >> choice;
		if (choice == 2)
			pHorse = new Pegasus;
		else
			pHorse = new Horse;
		Ranch[i] = pHorse;
	}
	for (i = 0; i < n; i++)
	{
		cout << "Ranch[" << i << "]: ";
		Ranch[i]->Whinny();
		delete Ranch[i];
	}
	for (i = 0; i < n; i++)
	{
		cout << "\n(1) Bird   (2) Pegasus: ";
		cin >> choice;
		if (choice == 2)
			pBird = new Pegasus;
		else
			pBird= new Bird;
		Aviary[i] = pBird;
	}
	for (i = 0; i < n; i++)
	{
		cout << "Aviary[" << i << "]: ";
		Aviary[i]->Chirp();
		delete Aviary[i];
	}
}