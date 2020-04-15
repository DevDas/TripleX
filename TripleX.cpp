#include <iostream>
#include<ctime>

void PrintIntroduction(int Difficulty)
{
// print welcome messeges to the terminal
    std::cout << "\n\n  +  you are a hacker! \n";
    std::cout << "  +  breaking into a secure server room at level : " << Difficulty;
    std::cout << "\n  +  you need to enter the correct codes to continue...\n\n";
}    

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC; 

    // Print sum and product to the terminal
    std::cout << "  +  there are 3 numbers in the code \n";
    std::cout << "  +  the numbers add ups to : " << CodeSum <<std::endl;
    std::cout << "  +  the product of these numbers is : " << CodeProduct <<std::endl;

    //Store Player Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA>> GuessB >> GuessC;
    
    std::cout<< "  +  You Entered : " << GuessA << GuessB << GuessC;
    std::cout << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check if the player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "  +  You Win!!!!! \n ";
        return true;
    }
    else 
    {
        std::cout << "  +   You lost the server!!!!! \n ";
        return false;
    }
}

int main()
{
   srand(time(NULL)); //creates new random sequence based on time of day

   int LevelDifficulty = 1;
   const int MaxDifficulty = 5;
  
   while (LevelDifficulty <= MaxDifficulty) //loop game until all levels completed
   {
    bool bLevelComplete = PlayGame(LevelDifficulty);

    std::cin.clear(); // Clears the errors
    std::cin.ignore(); // Dicards the buffer
    
    if (bLevelComplete)
    {
        ++LevelDifficulty;
    }
   
   }
std::cout<< " +  you are Master Hacker! Join Our Group :) ";
return 0;
} 