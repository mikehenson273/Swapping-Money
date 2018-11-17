#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <cctype>


using namespace std;

void decisionTree();
void goAgain();
void hackedTransfer(int& x, int& y);
void normalTransfer(int x, int y);
int userAmount();
string userChoice();
string usersChoice;
bool checkAgain = false;
bool playAgain = true;

int checkAmount = 0;
int joesAmount = 0;
int terrorAmount = 0;

void goAgain() // Replay Loop Confirmation
{
	if (playAgain == true) //triggers this if playAgain is true when reaching the loop
	{
		do
		{
			cout << "\n\nWant to go Again Y/N: ";
			userChoice();

			if (usersChoice == "YES" || usersChoice == "Y")
			{
				playAgain = true; //replay program
				checkAgain = false; //leave current loop
				system("cls"); //clears console for new playthrough
			}
			else if (usersChoice == "NO" || usersChoice == "N")
			{
				cout << "\n\nThanks for playing. Please come again.\n\n";
				playAgain = false; //leave program altogether
				checkAgain = false; //leaves this loop
				system("pause");
			}
			else //error catcher
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //sets color for text to red
				cout << "\nInvalid response. Please enter a valid response.\n";
				checkAgain = true; //resets current loop for proper guess
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //sets color for text back to green
			}
		} while (checkAgain); //boolean for this do while loop
	}

	else if (playAgain == false) //triggered if playAgain is false when reaching this loop
	{
		cout << "\n\nThanks for playing.\n\n";
		system("pause");
	}
}


void hackedTransfer(int& x, int& y) //Actually going to Joe's Coffee Shop.
{
	int temp = x;
	x = y;
	y = temp;
}

void normalTransfer(int x, int y) //What they are transferring and for their eyes
{
	int temp = x;
	x = y;
	y = temp;
}

string userChoice() //small function for user input
{
	usersChoice; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //sets color for text only to aqua
	getline(cin, usersChoice); //gets input from user
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //sets color for text back to green
	for (int i = 0; usersChoice[i] != '\0'; i++) //this loop capitalizes input for decisions.
	{
		usersChoice[i] = toupper(usersChoice[i]);
	}
	return usersChoice;
}

void decisionTree()
{
	do
	{
		system("cls");
		cout << "Welcome would you like to transfer funds Y/N: ";
		userChoice();

		if (usersChoice == "Y" || usersChoice == "YES")
		{
			cout << "How much would you like to transfer: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //sets color for text only to aqua
			cin >> terrorAmount; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);			
			cout << terrorAmount << "\n\n";
			checkAgain = true;
			system("pause");
		}

		else if (usersChoice == "N" || usersChoice == "NO")
		{
			do
			{	
				cout << "Do you want to check your balance then? Y/N: ";
				userChoice();

				if (usersChoice == "Y" || usersChoice == "YES" & checkAmount > 0)
				{
					hackedTransfer(joesAmount, terrorAmount);
					cout << "You have " << terrorAmount << " in your account\n";
					cout << "You might want to add money before your account is closed\n\n";
					checkAgain = true;
					system("pause");
				}
				
				else if (usersChoice == "Y" || usersChoice == "YES" & checkAmount == 0)
				{
					normalTransfer(joesAmount, terrorAmount);
					cout << "You have " << terrorAmount << " in your account\n";
					++checkAmount;
					checkAgain = true;
					cout << checkAmount;
					system("pause");
				}

				else if (usersChoice == "N" || usersChoice == "NO")
				{
					cout << "\nAll right. Have a good day!\n\n";
					checkAgain = false;
					system("pause");
				}
				else //informs user that their choice was invalid
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //sets color for text to red
					cout << "I am sorry I do not understand your command" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //resets to green
					system("pause");
					checkAgain = true;
				}
			} while (checkAgain);
		}

		else //informs user that their choice was invalid
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //sets color for text to red
			cout << "\nI am sorry I do not understand your command" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //resets to green
			system("pause");
			checkAgain = true;
		}
	} while (checkAgain);
}
int main()
{
	system("color 02");
	do
	{

		decisionTree();

		goAgain(); //function run for confirmation on playing again
	} while (playAgain);
	return 0;
}