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

bool FBullCowGame::IsIsogram(FString Guess) const
{
	for (int32 i = 0; i < Guess.length()-1; i++)
	{
		for(int32 j = i+1;j<Guess.length();j++)
		{
			if(Guess[i]==Guess[j])
			{
				return false;
			}
		}
	}

	return true;
}

bool FBullCowGame::IsAllLowercase(FString Guess) const
{
	for (int32 i = 0; i < Guess.length(); i++)
	{
		if(isupper(Guess[i]))
		{
			return false;
		}
	}

	return true;
}

bool FBullCowGame::IsProperLength(FString Guess) const
{
	return Guess.length()==GetHiddenWordLength();
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

EGuessStatus FBullCowGame::GetGuessStatusValidity(FString Guess)
{
	if(!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if(!IsAllLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if(!IsProperLength(Guess))
	{
		return EGuessStatus::Wrong_Length;
	}
	
	return EGuessStatus::OK;
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

