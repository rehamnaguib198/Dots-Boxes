#include "Undo&Redo.h"

void SaveMoves(int r,int c)
{
    undoCounter++;
    Last_Redo=undoCounter;
    undoR[undoCounter]=r;
    undoC[undoCounter]=c;
    undoTurns[undoCounter]=wchPlayer;

}

void undo()
{


    if(undoCounter>=0)
    {
        Valid_Redo=1;
        if(undoTurns[undoCounter]==1)
        {
            wchPlayer=1;
        }
        else if(undoTurns[undoCounter]==2)
        {
            wchPlayer=2;
        }
        else if(undoTurns[undoCounter]==3)
        {
            wchPlayer=3;
        }
        else if(undoTurns[undoCounter]==4)
        {
            wchPlayer=4;
        }
        int r=undoR[undoCounter];
        int c=undoC[undoCounter];
        A[r][c]=' ';
        B[r][c]=1;
        Player1.Player_Info[r][c]=0;
        Player2.Player_Info[r][c]=0;
        Player3.Player_Info[r][c]=0;
        Player4.Player_Info[r][c]=0;
        if(r%2==0) //if its horizontal place
        {
            int a=0;
            if(A[r+1][c]==' '&&r<R-1) //if the middle place in the box beneath is empty "so he didnt finished a box in this turn"
            {
            }
            else if (r<R-1)// the middle place in the box isn't empty . so he closed the box in this turn
            {
                A[r+1][c]=' ';
                if(Player1.Player_Info[r+1][c]==2) //if player1 closed this box .. decrease his score
                {
                    Player1.Score--;
                    Player1.Player_Info[r+1][c]=0;
                    turns++;
                    a=1;
                }
                else if(Player2.Player_Info[r+1][c]==2) //if player2 closed this box .. decrease his score
                {
                    Player2.Score--;
                    Player2.Player_Info[r+1][c]=0;
                    turns++;
                    a=1;
                }
                else if(Player3.Player_Info[r+1][c]==2) //if player3 closed this box .. decrease his score
                {
                    Player3.Score--;
                    Player3.Player_Info[r+1][c]=0;
                    turns++;
                    a=1;
                }
                else if(Player4.Player_Info[r+1][c]==2) //if player4 closed this box .. decrease his score
                {
                    Player4.Score--;
                    Player4.Player_Info[r+1][c]=0;
                    turns++;
                    a=1;
                }
            }
            if(A[r-1][c]==' '&&r>0) //if the middle place in the upper box is empty "so he didnt finished a box in this turn"
            {
            }
            else if (r>0)
            {
                A[r-1][c]=' ';
                if(Player1.Player_Info[r-1][c]==2) //if player1 closed this box .. decrease his score
                {
                    Player1.Score--;
                    Player1.Player_Info[r-1][c]=0;
                    if(a==0)
                    {
                        turns++;
                    }
                }
                else if(Player2.Player_Info[r-1][c]==2) //if player2 closed this box .. decrease his score
                {
                    Player2.Score--;
                    Player2.Player_Info[r-1][c]=0;
                    if(a==0)
                    {
                        turns++;
                    }
                }
                else if(Player3.Player_Info[r-1][c]==2) //if player3 closed this box .. decrease his score
                {
                    Player3.Score--;
                    Player3.Player_Info[r-1][c]=0;
                    if(a==0)
                    {
                        turns++;
                    }
                }
                else if(Player4.Player_Info[r-1][c]==2) //if player4 closed this box .. decrease his score
                {
                    Player4.Score--;
                    Player4.Player_Info[r-1][c]=0;
                    if(a==0)
                    {
                        turns++;
                    }
                }
            }
        }
        else if(r%2==1)
        {
            int b=0;
            if(A[r][c+1]==' '&&c<C-1)
            {
            }
            else if (c<C-1)
            {
                A[r][c+1]=' ';
                if(Player1.Player_Info[r][c+1]==2)
                {
                    Player1.Score--;
                    Player1.Player_Info[r][c+1]=0;
                    turns++;
                    b=1;
                }
                else if(Player2.Player_Info[r][c+1]==2)
                {
                    Player2.Score--;
                    Player2.Player_Info[r][c+1]=0;
                    turns++;
                    b=1;
                }
                else if(Player3.Player_Info[r][c+1]==2)
                {
                    Player3.Score--;
                    Player3.Player_Info[r][c+1]=0;
                    turns++;
                    b=1;
                }
                else if(Player4.Player_Info[r][c+1]==2)
                {
                    Player4.Score--;
                    Player4.Player_Info[r][c+1]=0;
                    turns++;
                    b=1;
                }
            }
            if(A[r][c-1]==' '&&r>0)
            {
            }
            else if (r>0)
            {
                A[r][c-1]=' ';
                if(Player1.Player_Info[r][c-1]==2)
                {
                    Player1.Score--;
                    Player1.Player_Info[r][c-1]=0;
                    if(b==0)
                    {
                        turns++;
                    }
                }
                else if(Player2.Player_Info[r][c-1]==2)
                {
                    Player2.Score--;
                    Player2.Player_Info[r][c-1]=0;
                    if(b==0)
                    {
                        turns++;
                    }
                }
                else if(Player3.Player_Info[r][c-1]==2)
                {
                    Player3.Score--;
                    Player3.Player_Info[r][c-1]=0;
                    if(b==0)
                    {
                        turns++;
                    }
                }
                else if(Player4.Player_Info[r][c-1]==2)
                {
                    Player4.Score--;
                    Player4.Player_Info[r][c-1]=0;
                    if(b==0)
                    {
                        turns++;
                    }
                }
            }
        }

        if(undoTurns[undoCounter]==1)
        {
            Player1.Played_Moves--;
        }
        else if (undoTurns[undoCounter]==2)
        {
            Player2.Played_Moves--;
        }
        else if (undoTurns[undoCounter]==3)
        {
            Player3.Played_Moves--;
        }
        else if (undoTurns[undoCounter]==4)
        {
            Player4.Played_Moves--;
        }


        endgame(&sum);
        turns--;
        undoCounter--;
    }
}



void redo()
{
    if(Valid_Redo==1)
    {

        if(undoCounter>=-1&&undoCounter<Last_Redo)
        {
            undoCounter++;
            if(undoTurns[undoCounter]==1)
            {
                wchPlayer=1;
                PlayerSign='A';
                Player1.Played_Moves++;
            }
            else if(undoTurns[undoCounter]==2)
            {
                wchPlayer=2;
                PlayerSign='B';
                Player2.Played_Moves++;
            }
            else if(undoTurns[undoCounter]==3)
            {
                wchPlayer=3;
                PlayerSign='C';
                Player3.Played_Moves++;
            }
            else if(undoTurns[undoCounter]==4)
            {
                wchPlayer=4;
                PlayerSign='D';
                Player4.Played_Moves++;
            }
            int r=undoR[undoCounter];
            int c=undoC[undoCounter];
            if (r%2==0&&c%2==1)
            {
                A[r][c]='-';
                wchSign=5;
            }
            else if (r%2==1&&c%2==0)
            {
                A[r][c]='|';
                wchSign=4;
            }
            B[r][c]=0;
            if(wchPlayer==1)
            {
                Player1.Player_Info[r][c]=1;
            }
            else if (wchPlayer==2)
            {
                Player2.Player_Info[r][c]=1;

            }
            else if (wchPlayer==3)
            {
                Player3.Player_Info[r][c]=1;

            }
            else if (wchPlayer==4)
            {
                Player4.Player_Info[r][c]=1;

            }

            Check_Box(r,c);
            endgame(&sum);
            wchPlayerMove(Num_Of_Players);
        }

    }
}
