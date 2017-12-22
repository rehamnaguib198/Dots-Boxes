#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED
#include <time.h>
#include "players.h"


extern int R,C,R1,C1; //R1&C1 ARE NUMBER OF DOTS HE NEEDS TO PLAY ON .... R,C ARE ROW AND COLOUMN OF THE PLAY GROUND.
extern int i,y; //COUNTERS FOR MOST LOOPS.
extern int CruR,CruC; //WHERE THE CRUSUR ? .. ROW AND COLOUMN
extern int ClcdBtn,wchSign,WchSignCounter; // BUTTON THAT THE PLAYER CLICKED ON FROM THE KEYBOARD... AND WHICH SIGN WE WILL USE - OR |
extern int turns,wchPlayer; // NUMBER OF TURNS DURING THE GAME .. AND PLAYER 1 OR 2
extern char A[20][20]; // THE PLAY GROUND.
extern int  B[20][20],MiniMax[100][100]; // ARRAY OF 1 AND 0 FOR SOME CHECKS.
extern int sum; //sums up all the ones in the B array to know when the game ends.
extern time_t start,end; //To Calculate Time
extern int minute;
extern double dif; // VARIABLES TO CALCULATE TIME
extern int ValidPlace;
extern int undoCounter;
extern int Valid_Redo;
extern struct Players Player1;
extern struct Players Player2;
extern struct Players Player3;
extern struct Players Player4;
extern int Num_Of_Players;
extern int language;
void Print();

#endif // PRINT_H_INCLUDED
