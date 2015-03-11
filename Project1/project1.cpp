/* 
 * File:   project1.cpp
 * Author: Doug Keller
 * Email:  dwk24@zips.uakron.edu
 */


#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    cout << "##########################################\n"
            "##                                      ##\n"
            "##           TWENTY-ONE PICKUP          ##\n"
            "##                                      ##\n"
            "##              HOW TO PLAY:            ##\n"
            "##    1. Select who goes first          ##\n"
            "##    2. Take 1-3 stones each turn      ##\n"
            "##    3. Take the last stones to win!   ##\n"
            "##                                      ##\n"
            "##########################################\n" << endl;

    int playthroughs;
    char input;
    while (input != 'q') {
        cout << "\n::: Enter 'p' to play or 'q' to quit :::     ";
        cin >> input;
        if (input != 'q') {
            playthroughs++;

            cout << "::: Enter 'h' to go first or 'c' to let the computer go first :::     ";

            cin >> input;
            if (input == 'h') {
                Game game(0);
                game.play();
            } else {
                Game game(1);
                game.play();
            }
        }
    }
    cout << "You played " << playthroughs << " times. Goodbye!\n";
}