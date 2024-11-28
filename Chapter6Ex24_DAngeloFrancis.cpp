/*
TITLE: Chapter 6 Exercise 24 - Rock, Paper, Scissors
FILE NAME: Chapter6Ex24_DAngeloFrancis.cpp
PROGRAMMER: D'Angelo Francis
DATE: November 2024
REQUIREMENTS: 
Write a program that lets the user play the game of Rock, Paper, Scissors against the computer. The program should work as follows:

1. When the program begins, a random number in the range of 1 through 3 is generated. 
  - If the number is 1, then the computer has chosen rock. 
  - If the number is 2, then the computer has chosen paper. 
  - If the number is 3, then the computer has chosen scissors. (Don’t display the computer’s choice yet.)

2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard. (You can use a menu if you prefer.)

3. The computer’s choice is displayed.

4. A winner is selected according to the following rules:

  - If one player chooses rock and the other player chooses scissors, then rock wins. (The rock smashes the scissors.)

  - If one player chooses scissors and the other player chooses paper, then scissors wins. (Scissors cuts paper.)

  - If one player chooses paper and the other player chooses rock, then paper wins. (Paper wraps rock.)

  - If both players make the same choice, the game must be played again to determine the winner.

Be sure to divide the program into functions that perform each major task.
*/

#include <iostream>
#include <random>
#include <string>
using namespace std;

// Function prototypes
int GetComputerChoice();
int ChoiceInput();
void ShowComputerChoice(int);
void DetermineWinner(int, int, string&);

int main() {
    string playAgain = "true"; 
    cout << "Rock, Paper, Scissors\n\n";

    while (playAgain == "true") { 
        int computerChoice = GetComputerChoice(); // Computer's choice
        int playerChoice = ChoiceInput();        // Player's choice
        ShowComputerChoice(computerChoice);      // Display computer's choice
        DetermineWinner(computerChoice, playerChoice, playAgain); // Determine result
    }

    return 0;
}
int GetComputerChoice() {
    random_device numberEngine;
    uniform_int_distribution<int> randomInt(1, 3);
    return randomInt(numberEngine);
}
int ChoiceInput() {
    int choice;

    cout << "\n1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n\n";

    do {
        cout << "Enter your choice (1-3): ";
        cin >> choice;
    } while (choice < 1 || choice > 3);

    return choice;
}
void ShowComputerChoice(int computerChoice) {
    if (computerChoice == 1)
        cout << "\nComputer chose Rock!";
    else if (computerChoice == 2)
        cout << "\nComputer chose Paper!";
    else if (computerChoice == 3)
        cout << "\nComputer chose Scissors!";
}
void DetermineWinner(int computerChoice, int playerChoice, string& playAgain) {
    cout << endl;
    if (playerChoice == computerChoice) {
        cout << "It's a tie! Play again.\n";
        return; 
    }

    if (playerChoice == 1) { // Player chose Rock
        if (computerChoice == 2)
            cout << "Paper wraps Rock. You lost.\n";
        else if (computerChoice == 3)
            cout << "Rock smashes Scissors. You won!\n";
    }
    else if (playerChoice == 2) { // Player chose Paper
        if (computerChoice == 1)
            cout << "Paper wraps Rock. You won!\n";
        else if (computerChoice == 3)
            cout << "Scissors cuts Paper. You lost.\n";
    }
    else if (playerChoice == 3) { // Player chose Scissors
        if (computerChoice == 1)
            cout << "Rock smashes Scissors. You lost.\n";
        else if (computerChoice == 2)
            cout << "Scissors cuts Paper. You won!\n";
    }

    // Ask if the player wants to play again
    char choice;
    do {
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> choice;
     
        if (choice == 'Y')
            playAgain = "true";
        else if (choice == 'N')
            playAgain = "false";
        else
            cout << "Invalid input. Please enter Y or N.\n";
    } while (choice != 'Y' && choice != 'N');
}
