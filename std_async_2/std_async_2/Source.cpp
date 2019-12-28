#include <future>
#include <iostream>

using namespace std;

int main()
{
	auto fut1 = async([] {
		for(int i=1; i<=100; i++)
			cout << "1 ";
		});
	auto fut2 = async([] {
		for(int i=1; i<=100; i++)
			cout << "2 ";
		});
	cout << '\n';
}

