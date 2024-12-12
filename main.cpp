#include <iostream>
using namespace std;


int main()
{
	int* pAge = new int[10];
	pAge[0] = 10;
	pAge[1] = 25;
	cout << "Веедіть значення для pAge[9]" << endl;
	cin >> pAge[9];

	for (int i = 0; i < 10; i++) {
		cout << "Значення і - " << i << "  Значення pAge[i] - " << pAge[i] <<"Адреса - "<<pAge +i << endl;
	}



	delete pAge;
	

	cin.ignore();                               // очистка буфера вводу
	cin.get();
	return 0;
}