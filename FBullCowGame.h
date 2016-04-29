#pragma once
#include <string>

using FString = std::string;
using int32 = int;


struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	INVALID,
	OK,
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE

};

class FBullCowGame
{
public:
	
	//Constructor
	FBullCowGame();

	//List of public methods, that can be used by other classes
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;	

	void Reset();	//TODO:Make a more rich return value
	FBullCowCount SubmitValidGuess(FString);


private:

	//private variables and methods, or members
	//See Constructor for Initilization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	
	


};
