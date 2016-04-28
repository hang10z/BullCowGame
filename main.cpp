/*This is the console executable that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all user
interaction.  For game logic see the FBullCowGame Class.
*/



#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


//declare fuctions
void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;				// instantiate class ( a new game)

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	FText Response = "";
	getline(std::cin, Response);

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
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	for (int32 count = 1; count <= MaxTries; count++)	//This will become a while loop.
	{
		FText guess = GetGuess();		//TODO: Make loop check for valid guesses

		//TODO: Submit Valid Guess To The Game
		//TODO: Print Number of Bulls and Cows

		std::cout << "Your guess was " << guess << std::endl;
		std::cout << std::endl; //put a space between each run in the loop
	}

	//TODO: Add game summary

}


void PrintIntro()
{
	//introduce the game
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?!\n";
	std::cout << std::endl;
	return;
}


FText GetGuess()
{
	// get a guess from the player
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText Guess = "";
	std::cout << "Try " << CurrentTry << ": Please type in your guess: ";
	getline(std::cin, Guess);
	return Guess;
}
