#pragma once
#include<string>
class Person
{
private:
	std::string name;
	std::string address;
	int year;
public:
	Person();
	Person(std::string, std::string, int);		
	~Person();
	void Show();
};