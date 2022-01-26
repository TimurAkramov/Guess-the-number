#include <iostream>
#include <cstdlib>
#include <ctime>


int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
 
bool playGame(int guesses, int number)
{
    for (int count = 1; count <= guesses; ++count)
    {
        std::cout << "Guess #" << count << ": ";
        int guess;
        std::cin >> guess;
 
        if (guess > number)
            std::cout << "Your guess is too high.\n";
        else if (guess < number)
            std::cout << "Your guess is too low.\n";
        else 
            return true;
    }
 
    return false;
}
 
bool askToPlayGame()
{
    char ch;
    do
    {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> ch;
    } while (ch != 'y' && ch != 'n');
 
    return (ch == 'y');
}
 
int main()
{
    srand(static_cast<unsigned int>(time(0))); 
    rand();
    const int guesses = 7; // change number of guesses here to get more tries
 
    do 
    {
        int number = getRandomNumber(1, 100); // change min and max to guess numbers higher or lower than present.

        std::cout << "Let's play a game.  I'm thinking of a number.  You have " << guesses << " tries to guess what it is.\n";
        bool won = playGame(guesses, number);
        if (won)
            std::cout << "Correct!  You win!\n";
        else
            std::cout << "Sorry, you lose.  The correct number was " << number << '\n';
    }
    while (askToPlayGame());
 
    std::cout << "Thank you for playing.\n";
    return 0;
}