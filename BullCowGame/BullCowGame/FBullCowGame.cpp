#include "FBullCowGame.h"
#include <iostream>

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

void FBullCowGame::Reset()
{
	constexpr int32 MaxTries = 8;
	const FString HiddenWord = "planets";

	MyMaxTries = MaxTries;
	MyCurrentTry = 1;
	MyHiddenWord = HiddenWord;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	return EWordStatus::OK;
}

void FBullCowGame::PrintBullCowCount(FBullCowCount BullCowCount)
{
	std::cout << "Bulls= " << BullCowCount.Bulls << ", Cows= " <<  BullCowCount.Cows << std::endl;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	for(int32 i = 0; i < MyHiddenWord.length(); i++)
	{
		for (int32 j = 0; j < Guess.length(); j++)
		{
			if (MyHiddenWord[i] == Guess[j])
			{
				if(i==j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}

