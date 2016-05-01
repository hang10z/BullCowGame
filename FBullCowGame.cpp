#include "FBullCowGame.h"
# include <map>
# define TMap std::map

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
	return bGameIsWon;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{	
	
	if (!IsIsogram(Guess))								//TODO: if the guess is not an isogram
	{
		return EGuessStatus::NOT_ISOGRAM;			
	}
	else if (!IsLowercase(Guess))										//TODO: If the guess is not in lower case
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
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isograms
	if (Word.length() <= 1)
	{
		return true;
	}

	//setup map
	TMap<char, bool> LetterSeen;

	//Ranged based for loop ":" means "in", auto will find the type for us, instead of putting "char" manually
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);			//convert all char to lowercase
		if (LetterSeen[Letter])				//if letter is in map
		{
			return false;					//we do not have isogram
		}
		else
		{
			LetterSeen[Letter] = true;		//add the letter to the map
		}

	}
	return true; 
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	if (Word.length() <= 1)
	{
		return true;
	}
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
}



