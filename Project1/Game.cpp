/* 
 * File:   Game.cpp
 * Author: Doug Keller
 * Email:  dwk24@zips.uakron.edu
 */

#include <iostream>
#include "Game.h"
using namespace std;

enum Player {
    HUMAN, COMPUTER
};

Player lastTurn; // tracks the 

Game::Game(int h) { // 0 = human, 1 = computer
    lastTurn = (h == 0) ? HUMAN : COMPUTER;
    stones = 21;
}

void Game::play() {
    if (lastTurn == COMPUTER) {
        cpuTurn();
        printRemaining();
    }
    while (stones > 0) {
        humanTurn();
        if(stones > 0)
                cpuTurn();
        printRemaining();
    }
    endGame();
}

void Game::printRemaining() {
    string s = (stones == 1) ? " stone remains." : " stones remain.";
    cout << "\t\t\t\t\t" << stones << s << endl;
}

void Game::cpuTurn() {
    int toTake = stones % 4;
    if (toTake == 0)
        toTake = 1;

    stones -= toTake;

    string s = (toTake == 1) ? " stone" : " stones";
    cout << "\tThe computer takes " << toTake << s << "." << endl;

    lastTurn = COMPUTER;
}

void Game::humanTurn() {
    int toTake = getInput();

    stones -= toTake;

    string s = (toTake == 1) ? " stone" : " stones";
    cout << "\tYou take " << toTake << s << "." << endl;

    lastTurn = HUMAN;
}

int Game::getInput() {
    int input = 0;
    while (input < 1 || input > 3) {
        cout << "\nEnter how many stones to take: ";
        cin >> input;

        if (input < 1 || input > 3)
            cout << "Invalid number. Input must be between 1-3." << endl;
    }
    return input;
}

void Game::endGame() {
    if (lastTurn == HUMAN)
        cout << "\nWOW you took the final stones! A winner is you!" << endl;
    else
        cout << "\nYou let a machine beat you. You are a failure!" << endl;

}

