#include "FBullCowGame.h"

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

void FBullCowGame::Reset()
{
	constexpr int32 MaxTries = 8;
	const FString HiddenWord = "planet";

	MyMaxTries = MaxTries;
	MyCurrentTry = 1;
	MyHiddenWord = HiddenWord;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString Guess)
{
	return false;
}

BullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	BullCowCount BullCowCount;

	for(int32 i = 0; i < MyHiddenWord.length(); i++)
	{
		//compare between word and guess
	}

	return BullCowCount;
}
