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
FText GetValidGuess();
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
		FText Guess = GetValidGuess();

		
		//TODO: Submit Valid Guess To The Game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl;
		std::cout << "Your guess was " << Guess << std::endl;
		std::cout << std::endl; 
	}

	//TODO: Add game summary

}


void PrintIntro()
{
	//introduce the game
	
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?!\n";
	std::cout << std::endl;
	return;
}


FText GetValidGuess() 
{
	EGuessStatus Status = EGuessStatus::INVALID;
	FText Guess = "";
	do
	{
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ": Please type in your guess: ";
		getline(std::cin, Guess);

		//Check Guess Validity
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::WRONG_LENGTH:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "Please enter a isogram (A word without repeating letters) and try again\n";
			break;
		case EGuessStatus::NOT_LOWERCASE:
			std::cout << "Please enter guess in all lowercase and try again/n";
			break;
		default:
			//assume guess is valid, we exhausted checks
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);  //keep looping until we get no errors
	return Guess;
}
