#include "fun.h"

char d;
float a=5, b=2, result;
int main()
{
label:
	
	cout << "Виберіть дію над двома числами ";
	//cin.ignore();
	cin >> d;
	if (d == '-') {
		cin.ignore();
		cout << "Введіть перше число - " << endl;
		cin >> a;
		cout << "Введіть друге число - " << endl;
		cin.ignore();
		cin >> b;
		result = otnim(a, b);
		cout << a << d << b <<" = " << result << endl;
		cout << "----------------------" << endl;
	}
	else if (d == '+') {
		cin.ignore();
		cout << "Введіть перше число - " << endl;
		cin >> a;
		cout << "Введіть друге число - " << endl;
		cin.ignore();
		cin >> b;
		result = summa(a, b);
		cout << a << d << b << " = " << result << endl;
		cout << "----------------------" << endl;
	}
	else if (d == '*') {
		cin.ignore();
		cout << "Введіть перше число - " << endl;
		cin >> a;
		cout << "Введіть друге число - " << endl;
		cin.ignore();
		cin >> b;
		result = umnoj(a, b);
		cout << a << d << b << " = " << result << endl;
		cout << "----------------------" << endl;
	}
	else if (d == '/') {
		cin.ignore();
		cout << "Введіть перше число - " << endl;
		cin >> a;
		cout << "Введіть друге число - " << endl;
		cin.ignore();
		cin >> b;
		result = podtl(a, b);
		cout << a << d << b << " = " << result << endl;
		cout << "----------------------" << endl;
	}
	else {
		cout << " ----------------------" << endl;
		cout << "#     До побачення     #"  << endl;
		cout << " ----------------------" << endl;
		return(0);
	}
	cout << "Для виходу замісь дії нажміть любу букву" << endl;
	cout  << endl;
	goto label;
	cin.ignore();
	cin.get();

	return 0;
}

float summa(float a, float b) {
	cout << "----------------------" << endl;
	result = a + b;
	return result;
}
float otnim(float a, float b) {
	cout << "----------------------" << endl;
	result = a - b;
	return result;
}
float umnoj(float a, float b) {
	cout << "----------------------" << endl;
	result = a * b;
	return result;
}
float podtl(float a, float b) {
	cout << "----------------------" << endl;
	result = a / b;
	return result;
}
