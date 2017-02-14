#pragma once
#include <string>
#include <map>
#define TMap = std::map

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus GetGuessStatusValidity(FString);
	FBullCowCount SubmitValidGuess(FString);
	void Reset();
	void PrintBullCowCount(FBullCowCount);
	
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsAllLowercase(FString) const;
	bool IsProperLength(FString) const;

};