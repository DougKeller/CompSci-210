/* 
 * File:   Game.h
 * Author: Doug Keller
 * Email:  dwk24@zips.uakron.edu
 */

#ifndef GAME_H
#define	GAME_H

class Game {
private:
    int stones;
    int getInput(); //returns a valid number between 1-3, based on user input
public:
    Game(int); // 0 = human, 1 = computer
    void humanTurn(); 
    void cpuTurn(); //calculates the best number of stones to take
    void endGame(); //outputs the winner
    void play(); //main game loop
    void printRemaining();
};


#endif	/* GAME_H */

