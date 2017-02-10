#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
std::string GetGuess();


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

	std::cout << "Welcome to Bulls and Cows game.\n";
	std::cout << "Can You guess the " << WordLength << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
	int NumberOfTurns = 5;

	for (int i = 0; i<NumberOfTurns; i++)
	{
		std::string Guess = GetGuess();

		std::cout << "Your guess: " << Guess << std::endl << std::endl;
	}
}

std::string GetGuess()
{
	std::string Guess = "";

	std::cout << "Enter Your guess: ";
	getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do You want to play again? (yes/no)\nAnswer: ";
	std::string Response = "";
	getline(std::cin, Response);

	return Response[0]=='y' || Response[0] == 'Y';
}
