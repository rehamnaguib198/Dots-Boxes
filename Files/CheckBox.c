#include "CheckBox.h"

//---------------------------FUNCTION THAT CHECK WHEN THE PLAYER MAKE HIS MOVE IF ANY BOX WAS COMPLETED ----------------------------------

void Check_Box(int r,int c)
{
    if(wchSign==5)  //IF THE SIGN WAS --- .
    {
        if(r==0)  // LIMITS FOR THE BOARDERS HE CAN CALCULATE BOXES IN WJEN THE CRUSUR IN 1ST ROW
        {
            if(B[r+2][c]==0 && B[r+1][c-1]==0 && B[r+1][c+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[r+1][c]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1.Score+=1;
                    Player1.Player_Info[r+1][c]=2;
                    sound();
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2.Score+=1;
                    Player2.Player_Info[r+1][c]=2;
                    sound();
                }
                else if (PlayerSign=='C')  // IF PLAYER 3 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player3.Score+=1;
                    Player3.Player_Info[r+1][c]=2;
                    sound();
                }
                else if (PlayerSign=='D')  // IF PLAYER 4 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player4.Score+=1;
                    Player4.Player_Info[r+1][c]=2;
                    sound();
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN

            }
        }
        else if(r==R-1)  // LIMITS FOR THE BOARDERS HE CAN CALCULATE BOXES IN WJEN THE CRUSUR IN LAST ROW
        {
            if(B[r-2][c]==0 && B[r-1][c-1]==0 && B[r-1][c+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[r-1][c]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1.Score+=1;
                    Player1.Player_Info[r-1][c]=2;
                    sound();
                }
                else if (PlayerSign=='B') // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2.Score+=1;
                    Player2.Player_Info[r-1][c]=2;
                    sound();
                }
                else if (PlayerSign=='C') // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player3.Score+=1;
                    Player3.Player_Info[r-1][c]=2;
                    sound();
                }
                else if (PlayerSign=='D') // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player4.Score+=1;
                    Player4.Player_Info[r-1][c]=2;
                    sound();
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
        }

        else
        {
            // IF THESE PLACES WERE ZEROS SO THESE TWO BOXES ARE COMPLETE
            if(B[r+2][c]==0 && B[r+1][c-1]==0 && B[r+1][c+1]==0 && B[r-2][c]==0 && B[r-1][c-1]==0 && B[r-1][c+1]==0)
            {
                A[r+1][c]=PlayerSign; // PRINT A OR B DEPENDS ON WHICH PLAYER'S MOVE
                A[r-1][c]=PlayerSign; // PRINT A OR B DEPENDS ON WHICH PLAYER'S MOVE
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                    Player1.Score+=2;
                    Player1.Player_Info[r+1][c]=2;
                    Player1.Player_Info[r-1][c]=2;
                    sound();
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                    Player2.Score+=2;
                    Player2.Player_Info[r+1][c]=2;
                    Player2.Player_Info[r-1][c]=2;
                    sound();
                }
                else if (PlayerSign=='C')  // IF PLAYER 2 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                    Player3.Score+=2;
                    Player3.Player_Info[r+1][c]=2;
                    Player3.Player_Info[r-1][c]=2;
                    sound();
                }
                else if (PlayerSign=='D')  // IF PLAYER 2 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                    Player4.Score+=2;
                    Player4.Player_Info[r+1][c]=2;
                    Player4.Player_Info[r-1][c]=2;
                    sound();
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN

            }
            else if(B[r-2][c]==0 && B[r-1][c-1]==0 && B[r-1][c+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[r-1][c]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1.Score+=1;
                    Player1.Player_Info[r-1][c]=2;
                    sound();
                }
                else if (PlayerSign=='B') // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2.Score+=1;
                    Player2.Player_Info[r-1][c]=2;
                    sound();
                }
                else if (PlayerSign=='C') // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player3.Score+=1;
                    Player3.Player_Info[r-1][c]=2;
                    sound();
                }
                else if (PlayerSign=='D') // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player4.Score+=1;
                    Player4.Player_Info[r-1][c]=2;
                    sound();
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
            else if(B[r+2][c]==0 && B[r+1][c-1]==0 && B[r+1][c+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[r+1][c]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1.Score+=1;
                    Player1.Player_Info[r+1][c]=2;
                    sound();
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2.Score+=1;
                    Player2.Player_Info[r+1][c]=2;
                    sound();
                }
                else if (PlayerSign=='C')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player3.Score+=1;
                    Player3.Player_Info[r+1][c]=2;
                    sound();
                }
                else if (PlayerSign=='D')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player4.Score+=1;
                    Player4.Player_Info[r+1][c]=2;
                    sound();
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN

            }

        }
    }

    else if(wchSign==4)  // IF THE SIGN WAS | .
    {
        if(c==0)
        {
            if(B[r][c+2]==0 && B[r-1][c+1]==0 && B[r+1][c+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[r][c+1]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1.Score+=1;
                    Player1.Player_Info[r][c+1]=2;
                    sound();
                }
                else if (PlayerSign=='B')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2.Score+=1;
                    Player2.Player_Info[r][c+1]=2;
                    sound();
                }
                else if (PlayerSign=='C')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player3.Score+=1;
                    Player3.Player_Info[r][c+1]=2;
                    sound();
                }
                else if (PlayerSign=='D')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player4.Score+=1;
                    Player4.Player_Info[r][c+1]=2;
                    sound();
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
        }
        else if(c==C-1)
        {
            if(B[r][c-2]==0 && B[r-1][c-1]==0 && B[r+1][c-1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[r][c-1]=PlayerSign;

                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1.Score+=1;
                    Player1.Player_Info[r][c-1]=2;
                    sound();
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2.Score+=1;
                    Player2.Player_Info[r][c-1]=2;
                    sound();
                }
                else if (PlayerSign=='C')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player3.Score+=1;
                    Player3.Player_Info[r][c-1]=2;
                    sound();
                }
                else if (PlayerSign=='D')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player4.Score+=1;
                    Player4.Player_Info[r][c-1]=2;
                    sound();
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
        }
        else
        {
            // IF THIS PLACES WERE ZEROS SO THESE TWO BOXES ARE COMPLETED
            if(B[r][c+2]==0 && B[r-1][c+1]==0 && B[r+1][c+1]==0 && B[r][c-2]==0 && B[r-1][c-1]==0 && B[r+1][c-1]==0)
            {
                A[r][c+1]=PlayerSign;
                A[r][c-1]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                    Player1.Score+=2;
                    Player1.Player_Info[r][c+1]=2;
                    Player1.Player_Info[r][c-1]=2;
                    sound();
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                    Player2.Score+=2;
                    Player2.Player_Info[r][c+1]=2;
                    Player2.Player_Info[r][c-1]=2;
                    sound();
                }
                else if (PlayerSign=='C')  // IF PLAYER 2 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                    Player3.Score+=2;
                    Player3.Player_Info[r][c+1]=2;
                    Player3.Player_Info[r][c-1]=2;
                    sound();
                }
                else if (PlayerSign=='D')  // IF PLAYER 2 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                    Player4.Score+=2;
                    Player4.Player_Info[r][c+1]=2;
                    Player4.Player_Info[r][c-1]=2;
                    sound();
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
            else if(B[r][c-2]==0 && B[r-1][c-1]==0 && B[r+1][c-1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[r][c-1]=PlayerSign;


                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1.Score+=1;
                    Player1.Player_Info[r][c-1]=2;
                    sound();
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2.Score+=1;
                    Player2.Player_Info[r][c-1]=2;
                    sound();
                }
                else if (PlayerSign=='C')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player3.Score+=1;
                    Player3.Player_Info[r][c-1]=2;
                    sound();
                }
                else if (PlayerSign=='D')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player4.Score+=1;
                    Player4.Player_Info[r][c-1]=2;
                    sound();
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
            else if(B[r][c+2]==0 && B[r-1][c+1]==0 && B[r+1][c+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[r][c+1]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1.Score+=1;
                    Player1.Player_Info[r][c+1]=2;
                    sound();
                }
                else if (PlayerSign=='B')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2.Score+=1;
                    Player2.Player_Info[r][c+1]=2;
                    sound();
                }
                else if (PlayerSign=='C')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player3.Score+=1;
                    Player3.Player_Info[r][c+1]=2;
                    sound();
                }
                else if (PlayerSign=='D')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player4.Score+=1;
                    Player4.Player_Info[r][c+1]=2;
                    sound();
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
        }

    }
}
