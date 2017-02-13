#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FString GetGuess();

FBullCowGame FBCGame;

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
	std::cout << "Welcome to Bulls and Cows game.\n";
	std::cout << "Can You guess the " << FBCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
	FBCGame.Reset();
	int32 NumberOfTurns = FBCGame.GetMaxTries();

	for (int32 i = 0; i<NumberOfTurns; i++)
	{
		FString Guess = GetGuess();
		FBullCowCount BullCowCount = FBCGame.SubmitGuess(Guess);
		FBCGame.PrintBullCowCount(BullCowCount);
	}
}

FString GetGuess()
{
	FString Guess = "";
	int32 CurrentTry = FBCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter Your guess: ";
	getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do You want to play again? (yes/no)\nAnswer: ";
	FString Response = "";
	getline(std::cin, Response);

	return Response[0]=='y' || Response[0] == 'Y';
}
