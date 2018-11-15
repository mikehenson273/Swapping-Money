#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void nowSwapping(int& x, int& y);
 
int main()
{
	int myScore = 150;
	int yourScore = 1000;

	cout << "Original values\n\n";
	cout << "My score: " << myScore << "\n";
	cout << "Your score: " << yourScore << "\n";

	cout << "\nCalling Swap\n\n";

	nowSwapping(myScore, yourScore);

	cout << "swapped scores\n\n";
	cout << "My score: " << myScore << "\n";
	cout << "Your score: " << yourScore << "\n";

	system("pause");
	return 0;
}

void nowSwapping(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}