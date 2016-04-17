#include <iostream>
#include <string>

//namespaces
using namespace std;

//declare fuctions
void PrintIntro();
string GetGuess();



//Entry point for our application
int main()
{
	PrintIntro();
	string guess1 = GetGuess();
	cout << "Your guess was " << guess1 << endl;
	string guess2 = GetGuess();
	cout << "Your guess was " << guess2 << endl;
	return 0;

}

void PrintIntro()
{
	//introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows!\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?!\n";
	cout << endl;
	return;
}

string GetGuess()
{
	// get a guess from the player
	string Guess = "";
	cout << "Please type in your guess: ";
	getline(cin, Guess);
	return Guess;
	
}