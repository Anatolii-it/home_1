#include <iostream>
using namespace std;
#include <conio.h> // äëÿ getche()
int main()
{
	char dir = 'a';
	int x = 10, y = 10;
	cout << "Натисніть Enter для виходу...\n";
	while (dir != '\r ') // пока не нажата Enter
	{
		cout << "\nВаші координати: " << x << ", " << y;
		cout << "\nВиберіть направлення (n,s,e,w): ";
		dir = _getche(); 
		if (dir == 'n') // на север
			y--;
		else
			if (dir == 's') // на юг
				y++;
			else
				if (dir == 'e') // на восток
					x++;
				else
					if (dir == 'w')
					{
						x--;
	
					}
						
	} 
	cout << "ви заблукали" << endl;

	

	return 0;
}