#include <stdio.h>
#include "Computer.h"

struct MiniMaxS
{
    int R;
    int C;
    int Sc;
};
struct MiniMaxS MiniMaxA[100];
void PlayTop(int i,int y)
{
    wchSign=5;
    A[i][y]='-';
    CruR=i;
    CruC=y;
    SaveMoves(i,y);
    Valid_Redo=0;
    B[i][y]=0;
    sum--;
    Check_Box(i,y);
    Change_In_Player_Info(i,y);
    Player2.Played_Moves++;
    wchPlayerMove(Num_Of_Players);
    Calculate_Remainning_Dots(i,y);
}
void PlayBottom(int i,int y)
{
    wchSign=5;
    A[i+2][y]='-';
    CruR=i+2;
    CruC=y;
    SaveMoves(i+2,y);
    Valid_Redo=0;
    B[i+2][y]=0;
    sum--;
    Check_Box(i+2,y);
    Change_In_Player_Info(i+2,y);
    Player2.Played_Moves++;
    wchPlayerMove(Num_Of_Players);
    Calculate_Remainning_Dots(i+2,y);
}
void Playleft(int i,int y)
{
    wchSign=4;
    A[i+1][y-1]='|';
    CruR=i+1;
    CruC=y-1;
    SaveMoves(i+1,y-1);
    Valid_Redo=0;
    B[i+1][y-1]=0;
    sum--;
    Check_Box(i+1,y-1);
    Change_In_Player_Info(i+1,y-1);
    Player2.Played_Moves++;
    wchPlayerMove(Num_Of_Players);
    Calculate_Remainning_Dots(i+1,y-1);
}
void PlayRight(int i,int y)
{
    wchSign=4;
    A[i+1][y+1]='|';
    CruR=i+1;
    CruC=y+1;
    SaveMoves(i+1,y+1);
    Valid_Redo=0;
    B[i+1][y+1]=0;
    sum--;
    Check_Box(i+1,y+1);
    Change_In_Player_Info(i+1,y+1);
    Player2.Played_Moves++;
    wchPlayerMove(Num_Of_Players);
    Calculate_Remainning_Dots(i+1,y+1);
}
void PlayTop1(int i,int y)
{
    wchSign=4;
    A[i][y]='|';
    CruR=i;
    CruC=y;
    SaveMoves(i,y);
    Valid_Redo=0;
    B[i][y]=0;
    sum--;
    Check_Box(i,y);
    Change_In_Player_Info(i,y);
    Player2.Played_Moves++;
    wchPlayerMove(Num_Of_Players);
    Calculate_Remainning_Dots(i,y);
}
void PlayBottom1(int i,int y)
{
    wchSign=4;
    A[i][y+2]='|';
    CruR=i;
    CruC=y+2;
    SaveMoves(i,y+2);
    Valid_Redo=0;
    B[i][y+2]=0;
    sum--;
    Check_Box(i,y+2);
    Change_In_Player_Info(i,y+2);
    Player2.Played_Moves++;
    wchPlayerMove(Num_Of_Players);
    Calculate_Remainning_Dots(i,y+2);
}
void Playleft1(int i,int y)
{
    wchSign=5;
    A[i-1][y+1]='-';
    CruR=i-1;
    CruC=y+1;
    SaveMoves(i-1,y+1);
    Valid_Redo=0;
    B[i-1][y+1]=0;
    sum--;
    Check_Box(i-1,y+1);
    Change_In_Player_Info(i-1,y+1);
    Player2.Played_Moves++;
    wchPlayerMove(Num_Of_Players);
    Calculate_Remainning_Dots(i-1,y+1);
}
void PlayRight1(int i,int y)
{
    wchSign=5;
    A[i+1][y+1]='-';
    CruR=i+1;
    CruC=y+1;
    SaveMoves(i+1,y+1);
    Valid_Redo=0;
    B[i+1][y+1]=0;
    sum--;
    Check_Box(i+1,y+1);
    Change_In_Player_Info(i+1,y+1);
    Player2.Played_Moves++;
    wchPlayerMove(Num_Of_Players);
    Calculate_Remainning_Dots(i+1,y+1);
}
void computerRandom()
{
    srand(time(NULL));
    int CompR,CompC,x=1;
    while(x==1)
    {
        CompR=rand()%R;
        CompC=rand()%C;
        if(CompR%2==0&&CompC%2==1)
        {
            wchSign=5;
            WchSignCounter=2;
            if(B[CompR][CompC]==1)
            {
                x=0;
                A[CompR][CompC]='-';
                CruR=CompR;
                CruC=CompC;
                SaveMoves(CruR,CruC);
                Valid_Redo=0;
                B[CruR][CruC]=0;
                sum--;
                Check_Box(CruR,CruC);
                Change_In_Player_Info(CruR,CruC);
                Player2.Played_Moves++;
                wchPlayerMove(Num_Of_Players);
                Calculate_Remainning_Dots(CruR,CruC);
            }
            else
            {
                x=1;
            }

        }

        else if(CompR%2==1&&CompC%2==0)
        {
            wchSign=4;
            WchSignCounter=1;

            if(B[CompR][CompC]==1)
            {
                x=0;
                A[CompR][CompC]='|';
                CruR=CompR;
                CruC=CompC;

                SaveMoves(CruR,CruC);
                Valid_Redo=0;
                B[CruR][CruC]=0;
                sum--;
                Check_Box(CruR,CruC);
                Change_In_Player_Info(CruR,CruC);
                Player2.Played_Moves++;
                wchPlayerMove(Num_Of_Players);
                Calculate_Remainning_Dots(CruR,CruC);

            }
            else
            {
                x=1;
            }

        }
    }
}
void computerGreedy()
{
    int i,y,x=0;
// Check if there is only one side left of a box
    for(i=0; i<R-2; i+=2)
    {
        // i<R-2 so it can check for all rows except the last one caause its looking for the beneath box
        for(y=1; y<C; y+=2)
        {
            if (B[i][y]+B[i+2][y]+B[i+1][y+1]+B[i+1][y-1]==1)
            {
                if(B[i][y]==1)
                {
                    PlayTop(i,y);
                    x=1;
                    break;
                }
                else if(B[i+2][y]==1)
                {
                    PlayBottom(i,y);
                    x=1;
                    break;
                }
                else if(B[i+1][y+1]==1)
                {
                    PlayRight(i,y);
                    x=1;
                    break;
                }
                else if(B[i+1][y-1]==1)
                {
                    Playleft(i,y);
                    x=1;
                    break;
                }
            }
        }
        if(x==1)
        {
            break;
        }
    }



// Check if there is 3 or 4 sides left of a box
    int randd = rand()%2;
    if (x==0&&randd==1) // search horizontally for a box with 3 or 4 sides left
    {
        for(i=0; i<R-2; i+=2)
        {
            for(y=1; y<C; y+=2)
            {
                //If the bottom box has 3 or 4 empty places
                if (B[i][y]+B[i+2][y]+B[i+1][y+1]+B[i+1][y-1]==3||B[i][y]+B[i+2][y]+B[i+1][y+1]+B[i+1][y-1]==4)
                {
                    //if the current place is empty
                    if(B[i][y]==1)
                    {
                        //first row...put line in the current place
                        if(i==0)
                        {
                            PlayTop(i,y);
                            x=1;
                            break;
                        }
                        else
                        {
                            //check above the current place if the box with sum 3 or 4
                            if (B[i-2][y]+B[i-1][y-1]+B[i-1][y+1]+B[i][y]==3||B[i-2][y]+B[i-1][y-1]+B[i-1][y+1]+B[i][y]==4)
                            {
                                PlayTop(i,y);
                                x=1;
                                break;
                            }

                        }
                    }
                    //in the row before the last one...put line in the bottom
                    if (i==R-3)
                    {
                        if(B[i+2][y]==1)
                        {
                            PlayBottom(i,y);
                            x=1;
                            break;
                        }
                    }

                    if (y==1) //in the left column
                    {
                        if(B[i+1][y-1]==1)
                        {
                            Playleft(i,y);
                            x=1;
                            break;
                        }

                    }
                    if (y==C-2) //in the right column
                    {
                        if(B[i+1][y+1]==1)
                        {
                            PlayRight(i,y);
                            x=1;
                            break;
                        }
                    }

                    if (B[i+1][y+1]==1) //if the right side is empty
                    {
                        int i1=(i+1),y1=(y+1);
                        if (B[i1][y1]+B[i1][y1+2]+B[i1-1][y1+1]+B[i1+1][y1+1]==3||B[i1][y1]+B[i1][y1+2]+B[i1-1][y1+1]+B[i1+1][y1+1]==4)
                        {
                            PlayRight(i,y);
                            x=1;
                            break;
                        }
                    }


                }
            }
            if(x==1)
            {
                break;
            }
        }
    }





    if (x==0&&randd==0) // search Vertically for a box with 3 or 4 sides left
    {
        for(i=1; i<R; i+=2)
        {
            for(y=0; y<C-2; y+=2)
            {
                if (B[i][y]+B[i][y+2]+B[i+1][y+1]+B[i-1][y+1]==3||B[i][y]+B[i][y+2]+B[i+1][y+1]+B[i-1][y+1]==4)
                {
                    if(B[i][y]==1)
                    {
                        if(y==0)
                        {
                            PlayTop1(i,y);
                            x=1;
                            break;
                        }
                        else
                        {
                            if (B[i][y-2]+B[i-1][y-1]+B[i+1][y-1]+B[i][y]==3||B[i][y-2]+B[i-1][y-1]+B[i+1][y-1]+B[i][y]==4)
                            {
                                PlayTop1(i,y);
                                x=1;
                                break;
                            }

                        }
                    }
                    if (y==C-3)
                    {
                        if(B[i][y+2]==1)
                        {
                            PlayBottom1(i,y);
                            x=1;
                            break;
                        }
                    }

                    if (i==1)
                    {
                        if(B[i-1][y+1]==1)
                        {
                            Playleft1(i,y);
                            x=1;
                            break;
                        }

                    }
                    if (i==R-2)
                    {
                        if(B[i+1][y+1]==1)
                        {
                            PlayRight1(i,y);
                            x=1;
                            break;
                        }
                    }

                    if (B[i+1][y+1]==1)
                    {
                        int i1=(i+1),y1=(y+1);
                        if (B[i1][y1]+B[i1+2][y1]+B[i1+1][y1-1]+B[i1+1][y1+1]==3||B[i1][y1]+B[i1+2][y1]+B[i1+1][y1-1]+B[i1+1][y1+1]==4)
                        {
                            PlayRight1(i,y);
                            x=1;
                            break;
                        }
                    }


                }
            }
            if(x==1)
            {
                break;
            }
        }
    }


    if (x==0) // if there are only 2 sides left of EVERY box in the game
    {
        int MiniMaxCounter=0,d,f;
        for( d=0; d<R; d+=2)
        {
            for( f=1; f<C; f+=2)
            {
                if (B[d][f]==1)
                {
                    int w,e;
                    for (w=0; w<R; w++)
                    {
                        for (e=0; e<C; e++)
                        {

                            MiniMax[w][e]=B[w][e];
                        }
                    }
                    MiniMax[d][f]=0;
                    MiniMaxA[MiniMaxCounter].R=d;
                    MiniMaxA[MiniMaxCounter].C=f;
                    MiniMaxA[MiniMaxCounter].Sc=0;
                    minimax(MiniMaxCounter);
                    x=1;
                    MiniMaxCounter++;
                }
            }
        }
        if (x==1)
        {
            int BestMove=0,i;

            //search for the least score for the opponent and play in that place
            for ( i=0; i<MiniMaxCounter; i++)
            {
                if (MiniMaxA[BestMove].Sc>MiniMaxA[i].Sc)
                {
                    BestMove=i;
                }
            }
            PlayTop(MiniMaxA[BestMove].R,MiniMaxA[BestMove].C);
            x=1;

        }
    }
    if (x==0)
    {
        computerRandom();
    }
}
int minimax(int MiniMaxCounter)
{

    int i,y,x=0;
    for(i=0; i<R-2; i+=2)
    {
        for(y=1; y<C; y+=2)
        {
            if (MiniMax[i][y]+MiniMax[i+2][y]+MiniMax[i+1][y+1]+MiniMax[i+1][y-1]==1)
            {
                if(MiniMax[i][y]==1)
                {
                    MiniMax[i][y]=0;
                    x=1;
                    MiniMaxA[MiniMaxCounter].Sc++;
                    break;
                }
                else if(MiniMax[i+2][y]==1)
                {
                    MiniMax[i+2][y]=0;
                    x=1;
                    MiniMaxA[MiniMaxCounter].Sc++;
                    break;
                }
                else if(MiniMax[i+1][y+1]==1)
                {
                    MiniMax[i+1][y+1]=0;
                    x=1;
                    MiniMaxA[MiniMaxCounter].Sc++;
                    break;
                }
                else if(MiniMax[i+1][y-1]==1)
                {
                    MiniMax[i+1][y-1]=0;
                    x=1;
                    MiniMaxA[MiniMaxCounter].Sc++;
                    break;
                }
            }
        }
        if(x==1)
        {
            break;
        }
    }
    if (x==0)
    {
        return;
    }
    else if (x==1)
    {
        minimax(MiniMaxCounter);
        return;
    }

}
