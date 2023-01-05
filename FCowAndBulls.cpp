#pragma once
#include "FCowAndBulls.h"
#include <iostream>
#include <map>
#define TMap std::map

std::string Guess = "";

FCowAndBulls::FCowAndBulls()
{
	reset();
}



void FCowAndBulls::reset()
{
	MyCurrentTry = 1;
	bIsGameWon = false;
	const FString HiddenWord = "slice";
	MyHiddenWord = HiddenWord;
	constexpr int32 maxtries = 8;
	MyMaxTries = maxtries;
}




int32 FCowAndBulls::GetMaxTries() const
{
	return MyMaxTries;
}




int32 FCowAndBulls::GetCurrTry() const
{
	return MyCurrentTry;
}




int32 FCowAndBulls::GetHiddenWordLength() const
{

	return MyHiddenWord.length();
}




bool FCowAndBulls::IsvalidGuess(FString guess)
{
	if (GetHiddenWordLength() != guess.length())
		return false;
	else
		return true;
}





EWordCheck FCowAndBulls::CheckValidGuess(FString guess) const
{
	if (!IsIsogram(guess))
		return EWordCheck::Not_Isogram;
	else if (GetHiddenWordLength()!=guess.length())
		return EWordCheck::wrong_length;
	else if (false)
		return EWordCheck::Not_uppercase;
	else
		return EWordCheck::Ok;
}






BullCowCount FCowAndBulls::SubmitGuess(FString guess)
{
	MyCurrentTry++;
	BullCowCount BullCowCount;
	int32 hiidenwordlength = MyHiddenWord.length();
	for (int32 i = 0; i < hiidenwordlength; i++)
	{
		
		for (int32 j = 0; j < hiidenwordlength; j++)
		{
			if (guess[i] == MyHiddenWord[i])
			{
				if(i==j)
				BullCowCount.bulls += 1;
			}
			else if(guess[i]==MyHiddenWord[j])
			{
				BullCowCount.cow += 1;
			}
		}
	}
	if (BullCowCount.bulls == hiidenwordlength)
	{
		bIsGameWon = true;
	}
	else
		bIsGameWon = false;
	return BullCowCount;
}






bool FCowAndBulls::IsGameWon()

{
		return bIsGameWon;
}










void FCowAndBulls::PrintGameSumary()
{
	if (IsGameWon())
	{
		std::cout << "well done u win\n";
	}
	else
	{
		std::cout << "better luck next time\n";
	}
}




bool FCowAndBulls::IsIsogram(FString Word) const
{	
	if (Word.length() <= 1)
	{
		return true;
	}
	TMap<char,bool> letterseen;
	for (auto letter : Word)
	{
		letter = tolower(letter);
		if (letterseen[letter])
		{
			return false;
		}
		else
		{
			letterseen[letter]= true;
		}
	}
	return true;
}

