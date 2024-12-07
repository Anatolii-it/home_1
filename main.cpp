#include <iostream>
using namespace std;
float lbstokg(float);

int main()
{
	float lbs, kgs;
	cout << "\nВведіть вес в фунтах - ";
	cin >> lbs;
	kgs = lbstokg(lbs);
	cout << "Вага в кілограмах равна - " << kgs << endl;

	return 0;
}

float lbstokg(float pounds) {
	float kilograms = 0.45392 * pounds;
	return kilograms;
}
