#include <iostream>
using namespace std;


int guessNumber(int target, int currentPlayer) {
    int guess;
    cout << "Player " << currentPlayer << ", enter your guess: ";
    cin >> guess;

   //Base case
    if (guess == target) {
        cout << "Player " << currentPlayer << " wins! The correct number was " << target << "." << endl;
        return 1; 
        //game will end here if user enter right target number
    }

    if (guess > target) {
        cout << "Too high!" << endl;
    } else {
        cout << "Too low!" << endl;
    }

    // Switch to the next player using if-else
    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }

    // Recursive call for the next turn
    return guessNumber(target, currentPlayer);
}

int main() {
    int target;
    cout << "Enter a number between 1 and 100 for players to guess: ";
    cin >> target; 

    // Start the game with Player 1
    guessNumber(target, 1);

    return 0;
}
