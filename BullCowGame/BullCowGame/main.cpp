#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
string GetGuess();


int main() {

	bool bPlayAgain = false;

	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}

void PrintIntro()
{
	constexpr int WordLength = 5;
	
	cout << "Welcome to Bulls and Cows game.\n";
	cout << "Can You guess the " << WordLength << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
	int NumberOfTurns = 5;

	for (int i = 0; i<NumberOfTurns; i++)
	{
		string Guess = GetGuess();

		cout << "Your guess: " << Guess << endl << endl;
	}
}

string GetGuess()
{
	string Guess = "";

	cout << "Enter Your guess: ";
	getline(cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do You want to play again? (yes/no)\nAnswer: ";
	string Response = "";
	getline(cin, Response);

	return Response[0]=='y' || Response[0] == 'Y';
}
