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
#include <fstream>
#include <vector>
using namespace std;

// Prototypes 
int generateRandomNumber(int min, int max);
int getUserGuess(int min, int max);
void playGame(int minVal, int maxVal, string playerName);  // Added semicolon here
void showSessions();
void clearSessions();
void showMenu();

// main
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <limits>  
using namespace std;

// Prototypes 
int generateRandomNumber(int min, int max);
int getUserGuess(int min, int max);
void playGame(int minVal, int maxVal, string playerName);
void showSessions();
void clearSessions();
void showMenu();

// main
int main() {
    const int min = 1, max = 10;

    while (true) {
        showMenu();
        int choice;
        cin >> choice;

        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 4) {
            cout << "Goodbye.\n";
            break;
        }

        switch (choice) {
        case 1:
            showSessions();
            break;

        case 2: {
            string name;
            cout << "Enter your name: ";
            getline(cin, name);  
            playGame(min, max, name);
            break;
        }

        case 3:
            clearSessions();
            break;

        default:
            cout << "Invalid choice.\n";
        }

        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}

// Game functions
int generateRandomNumber(int min, int max) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    return min + rand() % (max - min + 1);
}

int getUserGuess(int min, int max) {
    int guess;
    while (true) {
        cout << "Guess (" << min << "-" << max << "): ";
        cin >> guess;
        if (guess >= min && guess <= max) return guess;
        cout << "Invalid. Try again.\n";
    }
}

void playGame(int minVal, int maxVal, string playerName) {
    int randomNum = generateRandomNumber(minVal, maxVal);
    int attempts = 0;
    int guess;

    cout << "New Game \n";
    do {
        guess = getUserGuess(minVal, maxVal);
        attempts++;

        if (guess > randomNum) cout << "Too high.\n";
        else if (guess < randomNum) cout << "Too low.\n";
    } while (guess != randomNum);

    cout << "Correct. Attempts: " << attempts << "\n";

    // Save session
    ofstream file("sessions.txt", ios::app);
    if (file) {
        file << playerName << " " << attempts << " " << randomNum << "\n";
    }
}

// Session functions
void showSessions() {
    ifstream file("sessions.txt");
    cout << "Past Sessions \n";

    if (!file) {
        cout << "No sessions found.\n";
        return;
    }

    string name;
    int attempts, number;
    while (file >> name >> attempts >> number) {
        cout << name << ": Guessed " << number
            << " in " << attempts << " attempts\n";
    }
}

void clearSessions() {
    ofstream file("sessions.txt", ios::trunc);
    cout << "All sessions cleared!\n";
}

// Menu function
void showMenu() {
    cout << "Math Game\n"
        << "1. View Past Sessions\n"
        << "2. Play New Game\n"
        << "3. Clear Sessions\n"
        << "4. Exit\n"
        << "Choose (1-4): ";
}