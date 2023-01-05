// CowsAndBulls.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "FCowAndBulls.h"
using FText = std::string;
using int32 = int;
void PrintIntro();
FText GetValidGuess();
void Playgame();
bool AskToPlayAgain();

FCowAndBulls BCGame;


int main()
{
 
    bool bplaygame = false;
    do {
        PrintIntro();
        Playgame();
        bplaygame = AskToPlayAgain();
    } while (bplaygame);
    return 0;
}




void Playgame()
{
    BCGame.reset();
    int32 maxtries=BCGame.GetMaxTries();
    //std::cout << maxtries<<" ";
    //std::cout << BCGame.GetHiddenWordLength() << std::endl;

    while(!BCGame.IsGameWon() && BCGame.GetCurrTry()<=BCGame.GetMaxTries())
    {
        FText guess = GetValidGuess();
        std::cout << std::endl;
        std::cout << std::endl;
        
        BullCowCount CBCount = BCGame.SubmitGuess(guess);
        
            std::cout << "Bull " << CBCount.bulls;
            std::cout << "  cow " << CBCount.cow << std::endl;
    }
    std::cout << std::endl;
    BCGame.PrintGameSumary();
    std::cout << std::endl;
    
}




bool AskToPlayAgain()
{
    std::cout << "Do you want to play again with the same hidden word (y/n)? ";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}






FText GetValidGuess()
{
    EWordCheck Status = EWordCheck::InValidStatus;
    FText guess = "";

    do {
        int32 CurrentTry = BCGame.GetCurrTry();
        std::cout << "Try : " << CurrentTry << " Type your guess : ";
        std::getline(std::cin, guess);
        Status = BCGame.CheckValidGuess(guess);
        std::cout << std::endl;
        switch (Status)
        {
        case EWordCheck::Not_Isogram:
            std::cout << "Not an Isogram\n";
            break;
        case EWordCheck::wrong_length:
            std::cout << "wrong word length\n";
            break;
        case EWordCheck::Not_uppercase:
            std::cout << "enter lowercase letters\n";
            break;
        default:
            return guess;
        }
    } while (Status!=EWordCheck::Ok);
    std::cout << std::endl;

    return guess;
}






void PrintIntro()
{
    std::cout << std::endl;
    std::cout << "          }   {         ___ " << std::endl;
    std::cout << "          (o o)        (o o) " << std::endl;
    std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
    std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
    std::cout << " *  |-,--- |              |------|  * " << std::endl;
    std::cout << "    ^      ^              ^      ^ " << std::endl;
    constexpr int32 WORD_LENGTH = 5;
    std::cout << "\n\nWelcome to Bulls and Cows\n";
    std::cout << "can u guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram i am thinking of :\n";
    //std::cout << std::endl;
    return;
}
