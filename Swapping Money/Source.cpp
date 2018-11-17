#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <cctype>


using namespace std;

void decisionTree();
void balanceCheck();
void goAgain();
void hackedTransfer(int& x, int& y);
void normalTransfer(int x, int y);
int userAmount();
string userChoice();
string usersChoice;
bool checkAgain = false;
bool checkAgain1 = false;
bool playAgain = true;

int preJoe = 0; //needed for comparison
int averageJoe = 0; //needed for comparison
int preExec = 0; //needed for comparison
int execAmount = 0; //needed for comparison
int temp1 = 0; //for adding onto existing values of averageJoe and execAmount
int counter = 0; //for determining welcome message


void balanceCheck()
{
	cout << "Do you want to check your balance then? Y/N: ";
	userChoice();

	if (execAmount == 0 && usersChoice == "Y" || execAmount == 0 && usersChoice == "YES") //only activates if execAmount actually equals zero
	{
		execAmount = 0;
		cout << "\n\nYou have " << execAmount << " in your account\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "You might want to add money before your account is closed\n\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		checkAgain = false;
		checkAgain1 = true;
		system("pause");
	}

	else if (execAmount > 0 && usersChoice == "Y" || execAmount > 0 && usersChoice == "YES")
		//should hit this first and never hit again (unless program restart obviously)
	{
		
		cout << "You have " << execAmount << " in your account\n\n";
		hackedTransfer(averageJoe, execAmount);
		checkAgain = false;
		checkAgain1 = true;
		playAgain = true;
		system("pause");
	}

	else if (usersChoice == "N" || usersChoice == "NO") //leaves program
	{
		cout << "\nAll right. Have a good day and thanks for doing business with E-Corp!\n\n";
		checkAgain = false;
		checkAgain1 = false;
		playAgain = true;
	}
	else //informs user that their choice was invalid
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //sets color for text to red
		cout << "I am sorry I do not understand your command" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //resets to green
		system("pause");
		checkAgain = true;
	}
}

void decisionTree()
{
	do
	{
		if (counter == 0)
		{
			system("cls");
			cout << "Welcome to E-Corp Banking\nWould you like to transfer funds? Y/N: "; //welcome message
		}

		else if (counter > 0)
		{
			system("cls");
			cout << "Welcome to E-Corp Banking\nWould you care to transfer more funds? Y/N: "; //Query whether to transfer more or not
		}

		userChoice();

		if (averageJoe > 0 && usersChoice == "Y" || averageJoe > 0 && usersChoice == "YES") 
			//should apply after first balanceCheck
			//also deceptive to the end user by giving false values and making them think it was weird glitch.
		{
			cout << "How much would you like to transfer: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //sets color for text only to aqua
			cin >> temp1; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			averageJoe = temp1 + averageJoe;
			cout << "Your account balance is at " << averageJoe << "\n\n";
			checkAgain1 = true;
			system("pause");
		}

		else if (execAmount == 0 && usersChoice == "Y" || execAmount == 0 && usersChoice == "YES") //always hits this first
		{
			cout << "How much would you like to transfer: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //sets color for text only to aqua
			cin >> execAmount; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << "Your account balance is now at " << execAmount << "\n\n";
			++counter;
			checkAgain1 = true;
			system("pause");
		}

		else if (execAmount > 0 && usersChoice == "Y" || execAmount > 0 && usersChoice == "YES") //immediately hits this after putting in initial amount
		{
			cout << "How much would you like to transfer: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //sets color for text only to aqua
			cin >> temp1; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			execAmount = execAmount + temp1;
			preExec = execAmount;
			cout << "Your account balance is now at " << execAmount << "\n\n"; //for debugging
			
			checkAgain1 = true;
			system("pause");
		}

		else if (usersChoice == "N" || usersChoice == "NO")
		{
			do
			{
				balanceCheck();
			} while (checkAgain);
		}
		/*
		else //informs user that their choice was invalid
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //sets color for text to red
			cout << "\nI am sorry I do not understand your command" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //resets to green
			system("pause");
			checkAgain = true;
		} couldn't get this error catch to work properly
		*/
	} while (checkAgain1);
}

void goAgain() // Replay Loop Confirmation
{
	if (playAgain == true) //triggers this if playAgain is true when reaching the loop
	{
		do
		{
			cout << "\n\nWant to initialize another simulation? Y/N: ";
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
		cout << "\n\nThanks for using E-Corp Banking.\n\n";
		system("pause");
	}
}


void hackedTransfer(int& x, int& y) //Actually going to a normal citizen.
{
	int temp = x;
	x = y;
	y = temp;
}

void normalTransfer(int x, int y) //What they are transferring and for their eyes initially
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



int main()
{
	system("color 02");
	do
	{
		//resets values
		preJoe = 0; 
		averageJoe = 0;
		preExec = 0;
		execAmount = 0;
		temp1 = 0; //for adding onto existing values
		counter = 0; //for determining display message

		decisionTree();
		goAgain(); //function run for confirmation on playing again

	} while (playAgain);
	/*
	//next bit is for picture purposes
	cout << "End Results\n";
	cout << "Before Swap Executive Amount: " << preExec << endl; //amount before the swap
	cout << "After Swap Executive Amount: " << execAmount << endl; //amount after the swap
	cout << "Before Swap Normal Citizen: " << preJoe << endl; //amount before the swap
	cout << "After Swap Normal Citizen: " << preExec << endl; //essentially the same amount after swap with executive
	cout << "After Swap and attempted transfer Normal Citizen: " << averageJoe << "\n\n"; //amount after swap and attempted transfers
	system("pause");
	*/
	return 0;
}