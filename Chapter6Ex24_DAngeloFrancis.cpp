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
using namespace std;

string GetComputerChoice();
int ChoiceInput();
void ShowComputerChoice(string);

int main() {
	cout << "Rock, Paper, Scissors\n\n";
	
	int playerChoice = ChoiceInput(); //player choice

	string computerChoice = GetComputerChoice(); //computer choice

	showComputerChoice(computerChoice); //show computer choice
}
string GetComputerChoice() {
	random_device numberEngine;
	uniform_int_distribution<int> randomInt(1, 3);
	int randNumber = randomInt(numberEngine);

	if (randNumber == 1)
	{
		return "Rock";
	}
	else if (randNumber == 2)
	{
		return "Paper";
	}
	else if (randNumber == 3)
	{
		return "Scissors";
	}
}
int ChoiceInput() {
	int choice;
	
	cout << "\n1. Rock\n";
	cout << "2. Paper\n";
	cout << "3. Scissors\n\n";
	
	do {
		cout << "Enter your choice (1-3):";
		cin >> choice;
	} while (choice < 1 || choice > 3);

	return choice;
}
void ShowComputerChoice(string computerChoice) {
	cout << "The computer chose " << computerChoice << ".";
}