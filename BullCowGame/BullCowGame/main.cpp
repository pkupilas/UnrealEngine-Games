/*
	This is console BullCowGame.
	All logic is gathered in FBullCowGame class.
*/

#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGameSummary();
bool AskToPlayAgain();
FString GetValidGuess();

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
	std::cout << "Can You guess the " << FBCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n\n";
}

void PlayGame()
{
	FBCGame.Reset();
	int32 NumberOfTurns = FBCGame.GetMaxTries();

	while(!FBCGame.IsGameWon() && FBCGame.GetCurrentTry()<=NumberOfTurns)
	{
		FString Guess = GetValidGuess();
		FBullCowCount BullCowCount = FBCGame.SubmitValidGuess(Guess);
		FBCGame.PrintBullCowCount(BullCowCount);
	}

	PrintGameSummary();
}

void PrintGameSummary()
{
	if(FBCGame.IsGameWon())
	{
		std::cout << "Congratz! You won!\n";
	}
	else
	{
		std::cout << "\nSorry, You lost.\n";
	}
}

bool IsGuessValid(FString Guess)
{
	EGuessStatus GuessStatus = FBCGame.GetGuessStatusValidity(Guess);
	bool IsValid = false;

	switch (GuessStatus)
	{
	case EGuessStatus::Not_Isogram:
		std::cout << "There must be only one letter of the same type in the word!\n\n";
		break;
	case EGuessStatus::Not_Lowercase:
		std::cout << "All letters must be lowercase!\n\n";
		break;
	case EGuessStatus::Wrong_Length:
		std::cout << "The word must have exacly " << FBCGame.GetHiddenWordLength() << " letters!\n\n";
		break;
	default:
		IsValid = true;
	}

	return IsValid;
}

FString GetValidGuess()
{
	FString Guess = "";
	int32 CurrentTry = FBCGame.GetCurrentTry();

	do
	{
		std::cout << "Try " << CurrentTry << " of " << FBCGame.GetMaxTries() << ". Enter Your guess: ";
		getline(std::cin, Guess);
	} while (!IsGuessValid(Guess));


	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do You want to play again? (yes/no)\nAnswer: ";
	FString Response = "";
	getline(std::cin, Response);

	return Response[0]=='y' || Response[0] == 'Y';
}
