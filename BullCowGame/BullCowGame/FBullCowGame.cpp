#pragma once
#include "FBullCowGame.h"
#include <iostream>
#include <map>

// to make sytax Unreal friendly
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {1,2},{2,3},{3,5},{4,10},{5,15},{6,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()]; // posibility of no element in map
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	if (Guess.length() <= 1)
	{
		return true;
	}

	TMap<char, bool> LetterSeen;
	for(auto Letter : Guess)
	{
		Letter = tolower(Letter);
		if(LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
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
	const FString HiddenWord = "planet";

	MyCurrentTry = 1;
	MyHiddenWord = HiddenWord;
	bGameIsWon = false;
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
	std::cout << "Bulls= " << BullCowCount.Bulls << ", Cows= " <<  BullCowCount.Cows << std::endl << std::endl;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
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

	bGameIsWon = (BullCowCount.Bulls == MyHiddenWord.length()) ? true : false;

	return BullCowCount;
}
