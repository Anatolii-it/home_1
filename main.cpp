#include <iostream>
using namespace std;


int main() {
	const int c = 10;
	int arr[3][3];
	int x;
	// x - ���������� ������� ������ ����� ������ ����� �� ������ ����� ���� ������ ������
	(x = sizeof(arr) / sizeof(arr[0]));
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = (1+i)*(1+j);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "������� ������ - " << x << endl;

	


	return 0;
}