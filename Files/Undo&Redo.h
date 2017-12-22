#ifndef UNDO&REDO_H_INCLUDED
#define UNDO&REDO_H_INCLUDED

#include <time.h>
#include "players.h"


extern int R,C,R1,C1; //R1&C1 ARE NUMBER OF DOTS HE NEEDS TO PLAY ON .... R,C ARE ROW AND COLOUMN OF THE PLAY GROUND.
extern char Size[100]; // ARRAY TO TAKE NUMBER OF ROWS AND COLOUMNS OF THE PLAYGROUND
extern int i,y; //COUNTERS FOR MOST LOOPS.
//extern int P; // PLAYER NUMBER.
extern int CruR,CruC; //WHERE THE CRUSUR ? .. ROW AND COLOUMN
extern int ClcdBtn,wchSign,WchSignCounter; // BUTTON THAT THE PLAYER CLICKED ON FROM THE KEYBOARD... AND WHICH SIGN WE WILL USE - OR |
extern int Arrow,ArrowVal,main_choice,esc_choice,player_mode,game_difficulty,ex,Save_Value,loadValue,Valid_Load;
extern int backKey;  // MAIN MENU VARIABLES --- ARROW AND ARROWVAL FOR THE MOVING ARROW IN THE MAIN MENU
extern char PlayerSign; // VARIABLE TO TAKE THE PLAYER SIGN 'A' OR 'B'
extern int turns,wchPlayer; // NUMBER OF TURNS DURING THE GAME .. AND PLAYER 1 OR 2
extern int After_Game; // GLOBAL VARIABLE TO KNOW WHAT DID THE PLAYER CHOOSE TO DO AFTER THE GAME END
extern char A[20][20]; // THE PLAY GROUND.
extern int  B[20][20],MiniMax[100][100]; // ARRAY OF 1 AND 0 FOR SOME CHECKS.
extern int  RemainingDots[20][20],NumRemainningDots; // ARRAY TO CALCULATE THE REMAINING DOTS.
extern int  undoC[300],undoR[300],undoCounter,undoTurns[300],Valid_Redo,Last_Redo;// ARRAYS TO SAVE EVERY MOVE'S ROW AND COLOUMN AND HOW PLAYED IT .. VARIABLES TO CHECK THE REDO AND UNDO
extern int sum; //sums up all the ones in the B array to know when the game ends.
extern int enter; //a key to continue.
extern time_t start,end; //To Calculate Time
extern int minute;
extern double dif; // VARIABLES TO CALCULATE TIME
extern int ValidRow,ValidColumn; // TO CHECK IF THE INPUT IS VALID OR NOT IN ADVANCED MODE
extern int PlayerVsComp;
extern char FileName[10];
extern int Played;
extern int language;
extern struct Players Player1;
extern struct Players Player2;
extern struct Players Player3;
extern struct Players Player4;
extern int Num_Of_Players;
void undo();
void redo();

#endif // UNDO&REDO_H_INCLUDED
