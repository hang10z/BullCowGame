#include "FBullCowGame.h"


//Constructor
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

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	
	return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

//TODO: provide a method for couting bulls and cows, and incrementing try number. Assumes Valid Guess
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	//Increment Turn
	MyCurrentTry++;

	//Setup Return variable
	FBullCowCount BullCowCount;

	//loop through all letters in guess

	//Each letter compare against hidden word

	return BullCowCount;
}


