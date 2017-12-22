#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED
struct Top{
char Name[50];
int Score;
};
struct COORD {
int x;
int y;
};
struct Players{
    int Score;
    int Played_Moves;
    char Player_Sign;
    int Player_Color;
    int Player_Info[100][100];
    char Name[100];

};
struct Players Player1 ={
.Score=0,
.Played_Moves=0,
.Player_Sign='A',
.Player_Color=14
 };

 struct Players Player2 ={
.Score=0,
.Played_Moves=0,
.Player_Sign='B',
.Player_Color=11
 };


#endif // PLAYERS_H_INCLUDED

