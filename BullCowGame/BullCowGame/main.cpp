#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
string GetGuess();


int main() {

	PrintIntro();
	PlayGame();
	cout << "Result: " << AskToPlayAgain() << endl;

	return 0;
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	
	cout << "Welcome to Bulls and Cows game.\n";
	cout << "Can You guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
	int NUMBER_OF_TURNS = 5;

	for (int i = 0; i<NUMBER_OF_TURNS; i++)
	{
		string guess = GetGuess();

		cout << "Your guess: " << guess << endl;
		cout << endl;
	}
}

string GetGuess()
{
	string guess = "";

	cout << "Enter Your guess: ";
	getline(cin, guess);

	return guess;
}

bool AskToPlayAgain()
{
	cout << "Do You want to play again? (yes/no)\n" << "Answer: ";
	string response = "";
	getline(cin, response);

	return response[0]=='y' || response[0] == 'Y';
}
