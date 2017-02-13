#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	OK,
	Not_Isogram,
	Too_Short,
	Too_Long,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	int32 GetHiddenWordLength() const;

	void Reset();
	EWordStatus CheckGuessValidity(FString);
	void PrintBullCowCount(FBullCowCount);

	FBullCowCount SubmitGuess(FString);
	
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

};