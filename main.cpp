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
	Car vaz = { "vaz 2101","5�� ����","����",1.5,14};
	cout << "    ���� �����   \n\n";
	cout << "�����           " << vaz.model <<"\n";
	cout << "�������         " << vaz.kpp << "\n";
	cout << "��'�� �������   " << vaz.v << "\n";
	cout << "����           " << vaz.color << "\n";
	cout << "������          " << vaz.r<< "\n";


	


	return 0;
}