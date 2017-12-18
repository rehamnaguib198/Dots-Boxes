#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED

struct Players{
    int Score;
    int Played_Moves;
    char Player_Sign;
    int Player_Color;
    int Player_Info[100][100];

};
struct Players Player1 ={
.Score=0,
.Played_Moves=0,
.Player_Sign='A',
.Player_Color=4
 };

 struct Players Player2 ={
.Score=0,
.Played_Moves=0,
.Player_Sign='B',
.Player_Color=9
 };

#endif // PLAYERS_H_INCLUDED

