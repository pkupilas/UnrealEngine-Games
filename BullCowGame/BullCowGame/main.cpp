#include <iostream>
#include <string>

using namespace std;

int main() {

	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows game.\n";
	cout << "Can You guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";

	cout << "Enter Your guess: ";
	string Guess = "";
	cin >> Guess;

	cout << "Your guess: " << Guess << endl;

	return 0;
}