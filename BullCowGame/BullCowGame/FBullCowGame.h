#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); // TODO: Make it
	int GetMaxTries();
	void GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;
};