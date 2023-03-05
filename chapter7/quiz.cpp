#include <iostream>
#include <cassert>
#include <random>

#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen{ myConstants::gravity * seconds * seconds / 2 };
    double heightNow{ initialHeight - distanceFallen };

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void calculateAndPrintHeight(double initialHeight, int time)
{
    std::cout << "At " << time << " seconds, the ball is at height: " << calculateHeight(initialHeight, time) << "\n";
}

void ballFall()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight{};
    std::cin >> initialHeight;
    double height{ initialHeight };

    for (int seconds{ 0 }; height > 0.0; ++seconds) {
        calculateAndPrintHeight(initialHeight, seconds);
        height = calculateHeight(initialHeight, seconds);
    }
}

bool isPrime(int x)
{
    int n{ 2 };
    for (; n < x; ++n) {
        if (x % n == 0) return false;
    }
    if (x==0 || x==1) return false;
    else return true;
}

void isPrimeCheck()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";
}

void hilo() {

    std::random_device randomGenerator{};
    std::uniform_int_distribution dist{ 1,100 };

    int nTries{ 7 };

    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have "
        << nTries << " tries to guess what it is.\n";

game:
    int number{ dist(randomGenerator) };
    int nTry{ 1 };
    while (true) {
        std::cout << "Guess #" << nTry << ": ";
        int guess{};
        std::cin >> guess;
        if (guess > number) {
            std::cout << "Your guess is too high.\n";
        }
        else if (guess < number) {
            std::cout << "Your guess is too low.\n";
        }
        else {
            std::cout << "Correct! You win!\n";
            break;
        }
        ++nTry;
        if (nTry > nTries) {
            std::cout << "Sorry, you lose. The correct number was " << number << " \n";
            break;
        }
    }
    char ch{};
    do {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> ch;
    } while (ch != 'y' && ch != 'n');
    if (ch == 'y') goto game;
    
    std::cout << "Thank you for playing.";
}