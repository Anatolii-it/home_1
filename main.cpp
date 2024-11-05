#include <iostream>
using namespace std;

struct Car
{
	char model[10];
	char kpp[10];
	char color[8];
	int v; 
	int r;
};

int main() {
	Car vaz = { "vaz 2101","5ст фіат","Біла",1.5,14};
	cout << "    база машин   \n\n";
	cout << "Марка           " << vaz.model <<"\n";
	cout << "коробка         " << vaz.kpp << "\n";
	cout << "Об'єм двигуна   " << vaz.v << "\n";
	cout << "Колір           " << vaz.color << "\n";
	cout << "Колеса          " << vaz.r<< "\n";


	


	return 0;
}