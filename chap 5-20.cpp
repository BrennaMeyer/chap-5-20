// chap 5-20.cpp : This file contains the 'main' function. Program execution begins and ends there.
////Programmer:Brenna Meyer
// Date: March 20th,2025
// Requirements: Random Number Guessing Game Write a program that generates a random number and asks the user to guess what 
// the number is. If the user’s guess is higher than the random number, the program should display “Too high, try again.” 
// If the user’s guess is lower than the random number, the program should display “Too low, try again.” 
// The program should use a loop that repeats until the user correctly guesses the random number.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Prototype
int generateRandomNumber(int minValue, int maxValue);
int getUserGuess(int minValue, int maxValue);
void displayHint(int userNum, int randomNum);
void displayResults(int randomNum, int userNum);

int main()
{

    const int minValue = 1,
        maxValue = 10;

    // Generate a random number
    int randomNum = generateRandomNumber(minValue, maxValue);

    // Get the user's guess
    int userNum = getUserGuess(minValue, maxValue);

    // Check the guess and provide hints
    while (userNum != randomNum) {
        displayHint(userNum, randomNum);
        userNum = getUserGuess(minValue, maxValue);
    }

    // Display the final results
    displayResults(randomNum, userNum);
    return 0;
}

// Generates a random number between minValue and maxValue
int generateRandomNumber(int minValue, int maxValue) {
    unsigned seed = time(0);
    srand(seed);
    return (rand() % (maxValue - minValue + 1)) + minValue;
}

// Prompts the user to enter a guess and ensures it's within the valid range
int getUserGuess(int minValue, int maxValue) {
    int userNum;
    while (true) {
        cout << "Guess a number between 1 and 10:";
        cin >> userNum;
        if (userNum >= minValue && userNum <= maxValue) {
            return userNum;
        }
        else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
}
void displayHint(int userNum, int randomNum) {
    if (userNum > randomNum) {
        cout << "Too high try again" << endl;
    }
    else if (userNum < randomNum) {
        cout << "Too low try again" << endl;
    }
    else {
        cout << "Correct" << endl;
    }
}

// Displays the final results
void displayResults(int randomNum, int userNum) {
    cout << "Random number = " << randomNum << endl;
    cout << "Your guess = " << userNum << endl;
}