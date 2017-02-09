#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

int main() {

	int NUMBER_OF_TURNS = 5;

	PrintIntro();

	for (int i=0;i<NUMBER_OF_TURNS;i++)
	{
		GetGuessAndPrintBack();
		cout << endl;
	}

	return 0;
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	
	cout << "Welcome to Bulls and Cows game.\n";
	cout << "Can You guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

string GetGuessAndPrintBack()
{
	string guess = "";
	cout << "Enter Your guess: ";
	getline(cin, guess);
	cout << "Your guess: " << guess << endl;

	return guess;
}