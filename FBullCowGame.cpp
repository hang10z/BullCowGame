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

int32 FBullCowGame::GetHiddenWordLength() const
{

	return MyHiddenWord.length();
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

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{	
	
	if (false)											//if the guess is not an isogram
	{
		return EGuessStatus::NOT_ISOGRAM;			
	}
	else if (false)										//If the guess is not in lower case
	{
		return EGuessStatus::NOT_LOWERCASE;			
	}
	else if (GetHiddenWordLength() != Guess.length() )	//If the guess is the wrong length
	{
		return EGuessStatus::WRONG_LENGTH;
	}
	else 
	{
		return EGuessStatus::OK;
	}
		 
}

//recieves valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)		//"Guess" gives the passed string a variable name to use in the function
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();
	
	//loop through all letters in hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{
		//compare letters against guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
		{
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{
				//if they are in the same place
				if (MHWChar == GChar) 
				{
					//increment bulls
					BullCowCount.Bulls++;
				}
				else {
					//increment cows
 					BullCowCount.Cows++;
				}
			}
		}
			
	}
		
	return BullCowCount;
}


