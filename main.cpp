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
	for (int count = 1; count <= 5; count++)
	{
		string guess = GetGuess();
		cout << "Your guess was " << guess << endl;
	}
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