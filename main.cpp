#include <iostream>
#include <string>

//namespaces
using namespace std;

//declare fuctions
void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();


bool AskToPlayAgain()
{
	cout << "Do you want to play again? ";
	string Response = "";
	getline(cin, Response);

	//get the first character entered, is it y?
	if (Response[0] == 'y' || Response[0] == 'Y')
	{
		return true;
	}
	return false;
}

//Entry point for our application
int main()
{
	do
	{
		PrintIntro();
		PlayGame();

	} while (AskToPlayAgain() == true);

	//exit game
	return 0;
}


void PlayGame()
{
	for (int count = 1; count <= 5; count++)
	{
		string guess = GetGuess();
		cout << "Your guess was " << guess << endl;
		cout << endl; //put a space between each run in the loop
	}
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
