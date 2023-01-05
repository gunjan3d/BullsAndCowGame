#pragma once
#include <string>
using FString = std::string;
using int32 = int;
struct BullCowCount
{
	int32 bulls = 0;
	int32 cow = 0;
};
enum class EWordCheck
{
	Ok,
	Not_Isogram,
	wrong_length,
	Not_uppercase,
	InValidStatus
};
class FCowAndBulls
{
public:
	FCowAndBulls();
	void reset();
	int32 GetMaxTries()const;
	int32 GetCurrTry()const;
	int32 GetHiddenWordLength()const;
	bool IsvalidGuess(FString);
	EWordCheck CheckValidGuess(FString)const;
	BullCowCount SubmitGuess(FString guess);
	bool IsGameWon();
	void PrintGameSumary();

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bIsGameWon;
	bool IsIsogram(FString) const;
	
};