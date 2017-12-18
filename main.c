#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
int R,C,R1,C1; //R1&C1 ARE NUMBER OF DOTS HE NEEDS TO PLAY ON .... R,C ARE ROW AND COLOUMN OF THE PLAY GROUND.
int i,y; //COUNTERS FOR MOST LOOPS.
int P; // PLAYER NUMBER.
int CruR=1,CruC=0; //WHERE THE CRUSUR ? .. ROW AND COLOUMN
int ClcdBtn,wchSign=0; // BUTTON THAT THE PLAYER CLICKED ON FROM THE KEYBOARD... AND WHICH SIGN WE WILL USE - OR |
char main_choice,player_mode,game_difficulty,ex,backKey; // MAIN MENU VARIABLES
char PlayerSign;
int turns=0,wchPlayer=1,Player1Score=0,Player2Score=0;
char A[100][100]; // THE PLAY GROUND.
int  B[100][100]; // ARRAY OF 1 AND 0 FOR REMAINING DOTS AND SOME CHECKS.
void main()
{
    //---------------------------TAKING THE SIZE OF PLAY GROUND----------------------------------

    // scanning number of dots he needs to play on ..
    start_menu();
    R=R1*2-1; // adding places for the -
    C=C1*2-1; // adding places for the |

    //---------------------------arranging the play ground----------------------------------

    for(i=0; i<R; i++)
    {
        for(y=0; y<C; y++)
        {
            if (i%2==0 && y%2==0)
            {
                A[i][y]='O';
            }
            else
            {
                A[i][y]=' ';
            }
        }
    }

    //---------------------------MAKING ARRAY WITH THE SAME SIZE TO CALCULATE THE REMAINING DOTS AND TO CHEACK IF A PLACE WERE TAKEN OR NOT----------------------------------
    for(i=0; i<R; i++)
    {
        for(y=0; y<C; y++)
        {
            B[i][y]=1;
        }
    }
    //---------------------------HERE THE GAME STARTS 3:)----------------------------------
    system("cls");
    printf("\n");
    First_Print();
    while(1)
    {

        Moving();
        system("cls");
        Print();
    }
}

//---------------------------FUNCTION TO CHANGE TEXT'S COLOR DEPENDS On THE PLAYER NUMBER P----------------------------------

void Change_Color(int P)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),P);
    return;
}
//---------------------------FUNCTION TO RESET TEXT'S COLOR TO THE ORDINARY ONE----------------------------------

void Reset_Color()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    return;
}

//---------------------------FUNCTION TO PRINT ONLY THE DOTS WHEN THE GAME STARTS----------------------------------

void First_Print()

{
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t"); // TO MAE MAKE THE GAME START IN THE MIDDLE OF THE SCREEN
    for(i=0; i<C+4; i++) // THE UPPER FRAME AND +4 IS THE 2 SPACES AND THE SIDE FRAMES
    {
        printf("-");
    }
    printf("\n\t\t\t\t\t\t\t"); // TO MAE MAKE THE GAME START IN THE MIDDLE OF THE SCREEN
    for(i=0; i<R; i++) // TO PRINT THE DOTS..
    {
        printf("| "); // THE RIGHT SIDE FRAME
        for(y=0; y<C; y++)
        {
            printf("%c",A[i][y]);
        }
        printf(" |"); // THE LEFT SIDE FRAME
        printf("\n\t\t\t\t\t\t\t");
    }
    for(i=0; i<C+4; i++) // THE DOWN FRAME AND +4 IS THE 2 SPACES AND THE SIDE FRAMES
    {
        printf("-");
    }
}
//---------------------------FUNCTION TO PRINT THE PLAY GROUND DURING THE GAME----------------------------------

void Print()
{
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t"); // TO MAKE THE GAME STARTS IN THE MIDDLE OF THE SCREEN
    for(i=0; i<C+4; i++) // THE UPPER FRAME AND +4 IS THE 2 SPACES AND THE SIDE FRAMES
    {
        printf("-");
    }
    printf("\n\t\t\t\t\t\t\t"); // TO MAKE THE GAME STARTS IN THE MIDDLE OF THE SCREEN
    for(i=0; i<R; i++) // tO PRINT THE DOTS.
    {
        printf("| "); // THE RIGHT SIDE FRAME
        for(y=0; y<C; y++)
        {
            if(i==CruR&&y==CruC) // IF THE CRUSUR IS HERE ... CHANGE THE COLOR AND PRINT IT .
            {
                if(wchPlayer==1)
                {
                    Change_Color(5);
                }
                else if(wchPlayer==2)
                {
                    Change_Color(3);
                }
                printf("%c",A[i][y]);
                Reset_Color();
            }

            else // ELSE PRINT THE PLAYGROUND WITH THE ORDINARY COLOR.
            {
                printf("%c",A[i][y]);
            }
        }
        printf(" |"); // THE LEFT SIDE FRAME
        if(i==R/2-1)  //TO PRINT THE SCORE IN THE MIDDLE OF THE PLAY GROUND
        {
            printf("\n Player 1 Score: %i\t\t\t\t\t",Player1Score);
        }
        else if (i==R/2)  //TO PRINT THE SCORE IN THE MIDDLE OF THE PLAY GROUND
        {
            printf("\n Player 2 Score: %i\t\t\t\t\t",Player2Score);
        }
        else  // TO PRINT THE PLAY GROUND IN THE MIDDLE WITH SPACES AND TABS.
        {
            printf("\n\t\t\t\t\t\t\t");
        }
    }
    for(i=0; i<C+4; i++)
    {
        printf("-"); // THE DOWN FRAME AND +4 IS THE 2 SPACES AND THE SIDE FRAMES
    }

}

//---------------------------FUNCTION THAT MOVES THE CRUSUR AND TO PUT - AND | ----------------------------------

void Moving()
{
Move:
    ClcdBtn=getche(); // TAKE THE CODE OF THE BUTTON HE CLICKED.
    if(ClcdBtn==43) // + BUTTON TO PRINT "|" .
    {
        wchSign=4; // MAKE THE USING SIGN IS |.
        if(B[CruR][CruC]==1) // IF WE DIDN'T USE THIS PLACE YET
        {
            A[CruR][CruC]=' ';
        }
        // PUT THE CRUSUR IN THE FIRST PLACE IN THE ARRAY WE CAN USE |.
        CruR=1;
        CruC=0;
        A[CruR][CruC]='|';
    }
    else if (ClcdBtn==45) // - BUTTON TO PRINT "-" .
    {
        wchSign=5; // MAKE THE USING SIGN IS -.
        if(B[CruR][CruC]==1) // IF WE DIDN'T USE THIS PLACE YET
        {
            A[CruR][CruC]=' ';
        }
        CruR=0; // SET FOR THE FIRST PLANCE IN THE ARRAY CAN USE -.
        CruC=1;
        A[CruR][CruC]='-';
    }
    else if (ClcdBtn==27)
    {
ExitOrNot:
        system("cls");
        printf("\tAre You Sure You Want To Exit This Game ? \n\n\tChoose:\n\t1-Yes\n\t2-No");
        ex=getche();
        switch(ex)
        {
        case 49:
            exit(0);
            break;
        case 50:
            system("cls");
            Print();
            goto Move ;
            break;
        default:
            goto ExitOrNot;
        }
    }

    if(wchSign==4) // IF THE SIGN IS |..
    {
        if (ClcdBtn==13) // ENTER BUTTON TO USE THIS PLACE AND PUT THE SIGN .
        {
            if(B[CruR][CruC]==0)
            {
            }
            else
            {
                B[CruR][CruC]=0;
                Check_Box();
                wchPlayerMove();
            }

        }

        else if (ClcdBtn==77) // 6 BUTTON TO GO > .
        {
            if(B[CruR][CruC]==1)
            {
                A[CruR][CruC]=' ';
            }
            CruC+=2;
            Check_The_Game_Limits();
            A[CruR][CruC]='|';
        }
        else if (ClcdBtn==75) // 4 BUTTON TO GO < .
        {
            if(B[CruR][CruC]==1)
            {
                A[CruR][CruC]=' ';
            }
            CruC-=2;
            Check_The_Game_Limits();
            A[CruR][CruC]='|';
        }
        else if (ClcdBtn==72) // 8 BUTTON TO GO ^ .
        {
            if(B[CruR][CruC]==1)
            {
                A[CruR][CruC]=' ';
            }
            CruR-=2;
            Check_The_Game_Limits();
            A[CruR][CruC]='|';
        }
        else if (ClcdBtn==80) // 2 BUTTON TO GO DOWN .
        {
            if(B[CruR][CruC]==1)
            {
                A[CruR][CruC]=' ';
            }
            CruR+=2;
            Check_The_Game_Limits();
            A[CruR][CruC]='|';
        }
    }

    if(wchSign==5)
    {
        if (ClcdBtn==13) // Enter BUTTON TO USE THIS PLACE  .
        {
            if(B[CruR][CruC]==0)
            {
            }
            else
            {
                B[CruR][CruC]=0;
                Check_Box();
                wchPlayerMove();
            }
        }

        else if (ClcdBtn==77) // 6 BUTTON TO GO > .
        {
            if(B[CruR][CruC]==1)
            {
                A[CruR][CruC]=' ';
            }
            CruC+=2;
            Check_The_Game_Limits();
            A[CruR][CruC]='-';
        }
        else if (ClcdBtn==75) // 4 BUTTON TO GO < .
        {
            if(B[CruR][CruC]==1)
            {
                A[CruR][CruC]=' ';
            }
            CruC-=2;
            Check_The_Game_Limits();
            A[CruR][CruC]='-';
        }
        else if (ClcdBtn==72) // 8 BUTTON TO GO ^ .
        {
            if(B[CruR][CruC]==1)
            {
                A[CruR][CruC]=' ';
            }
            CruR-=2;
            Check_The_Game_Limits();
            A[CruR][CruC]='-';
        }
        else if (ClcdBtn==80) // 2 BUTTON TO GO DOWN .
        {
            if(B[CruR][CruC]==1)
            {
                A[CruR][CruC]=' ';
            }
            CruR+=2;
            Check_The_Game_Limits();
            A[CruR][CruC]='-';
        }
    }
}
//---------------------------FUNCTION THAT CHECK IF THE CRUSUR CROSSED THE PLAYGROUND LIMITS ----------------------------------

void Check_The_Game_Limits()
{
    if(CruR>=R)
    {
        CruR-=2;
    }
    if(CruC>=C)
    {
        CruC-=2;
    }
    if(CruR<0)
    {
        CruR+=2;
    }
    if(CruC<0)
    {
        CruC+=2;
    }

}

//---------------------------START MENU FUNCTION-------------------------------------------------------//
void start_menu()
{
menu:
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-How To Play \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Top 10 player\n\n \t\t\t\t\t\t\t5-Exit\n");
    main_choice=getche();
    switch(main_choice)
    {

    case 49: //BUTTON 1 FOR -NEW GAME-
New_Game:
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Mode:\n\n\n");
        printf("\t\t\t\t\t\t\t1-player vs computer\n\n\t\t\t\t\t\t\t2-player1 vs player2\n");
        player_mode=getche();
        switch(player_mode)
        {
        case 49: // BUTTON 1 FOR PLAYER VS COMPUTER
Player_Vs_Comp:
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Difficulty:\n\n\n");
            printf("\t\t\t\t\t\t\t1-Beginner\n\n\t\t\t\t\t\t\t2-Expert\n\n\t\t\t\t\t\t\t3-Advanced\n");
            game_difficulty=getche();
            switch(game_difficulty)
            {
            case 49: // BUTTON 1 FOR BEGINNER
                R1=3,C1=3;
                break;
            case 50: // BUTTON 2 FOR EXPERT
                R1=5,C1=5;
                break;
            case 51: // BUTTON 3 FOR ADVANCED TO CHOOSE NUMBER OF DOTS HE NEEDS
                system("cls");
                printf("Enter number of rows.\n");
                scanf("%d",&R1);
                system("cls");
                printf("Enter number of columns.\n");
                scanf("%d",&C1);
                break;
            default:
                goto Player_Vs_Comp;
            }
            break;
        case 50: // BUTTON 2 FOR PLAYER 1 VS PLAYER 2
Player1_Vs_Player2:
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Difficulty:\n\n\n");
            printf("\t\t\t\t\t\t\t1-Beginner\n\n\t\t\t\t\t\t\t2-Expert\n\n\t\t\t\t\t\t\t3-Advanced\n");
            game_difficulty=getche();
            switch(game_difficulty)
            {
            case 49: // BUTTON 1 FOR BEGINNER
                R1=3,C1=3;
                break;
            case 50: // BUTTON 2 FOR EXPERT
                R1=5,C1=5;
                break;
            case 51: // BUTTON 3 FOR ADVANCED TO CHOOSE NUMBER OF DOTS HE NEEDS
                system("cls");
                printf("Enter number of rows.\n");
                scanf("%d",&R1);
                system("cls");
                printf("Enter number of columns.\n");
                scanf("%d",&C1);
                break;
            default:
                goto Player1_Vs_Player2;
            }
            break;
        default:
            goto New_Game;
        }
        break;
//HOW TO PLAY//
    case 50: //BUTTON 2 FOR -HOW TO PLAY-
        system("cls");
        printf("\n\n\t\t\t\t\t\t\tHow to play\n\n");
        printf("\t\t  The two players take turns to join two adjacent dots with a horizontal or vertical line. \n");
        printf("\t      If a player completes the fourth side of a box they initial that box and must draw another line. \n");
        printf("\t    When all the boxes have been completed the winner is the player who has initialled the most boxes.\n\n\n\n");
        printf("\t\t\t\t\t\tControls:\n");
        printf("\t\t\t\t\t\tPress + for vertical line\n\t\t\t\t\t\tPress - for horizontal line\n");
        printf("\t\t\t\t\t\tpress 6 to go right\n\t\t\t\t\t\tpress 4 to go left\n\t\t\t\t\t\tpress 8 to go up\n \t\t\t\t\t\tpress 2 to go down\n");
        printf("\t\t\t\t\t\tpress 5 to select place");
        printf("\n\n\t\t\t\t\t\tpress 1 to go back to main menu");
        backKey=getche();
        while (backKey!=49) // BUTTON 1
        {
            system("cls");
            printf("\n\n\t\t\t\t\t\tpress 1 to go back to main menu");
            backKey=getche();
        }
        if(backKey=49) //BUTTON 1
        {
            goto menu;
        }
        break;
    //load game//
    case 51: // BUTTON 3
        printf("Not Available");
        break;
//top 10 players//
    case 52: // BUTTON 4
        printf("Not Available");
        break;
//exit//
    case 53: // BUTTON 5
exit:
        system("cls");
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tAre you sure you want to exit?\n\n\n");
        printf("\t\t\t\t\t\t\t1-YES\n\n\t\t\t\t\t\t\t2-NO\n");
        ex=getche();
        switch(ex)
        {
        case 49: // BUTTON 1
            exit(0);
            break;
        case 50: //BUTTON 2
            goto menu;
            break;
        default:
            goto exit;
        }
        break;
// IF HE CLICKED ON ANY OTHER BUTTON DO NOTHING
    default:
        goto menu;
    }
}


//---------------------------FUNCTION THAT CHECK WHEN THE PLAYER MAKE HIS MOVE IF ANY BOX WAS COMPLETED ----------------------------------

void Check_Box()
{
    if(wchSign==5)  //IF THE SIGN WAS - .
    {
        if(CruR==0)  // LIMITS FOR THE BOARDERS HE CAN CALCULATE BOXES IN WJEN THE CRUSUR IN 1ST ROW
        {
            if(B[CruR+2][CruC]==0 && B[CruR+1][CruC-1]==0 && B[CruR+1][CruC+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[CruR+1][CruC]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1Score+=1;
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2Score+=1;
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN

            }
        }
        else if(CruR==R-1)  // LIMITS FOR THE BOARDERS HE CAN CALCULATE BOXES IN WJEN THE CRUSUR IN LAST ROW
        {
            if(B[CruR-2][CruC]==0 && B[CruR-1][CruC-1]==0 && B[CruR-1][CruC+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[CruR-1][CruC]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1Score+=1;
                }
                else if (PlayerSign=='B') // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2Score+=1;
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
        }

        else
        {
            // IF THIS PLACES WERE ZEROS SO THESE TWO BOXES ARE COMPLETED
            if(B[CruR+2][CruC]==0 && B[CruR+1][CruC-1]==0 && B[CruR+1][CruC+1]==0 && B[CruR-2][CruC]==0 && B[CruR-1][CruC-1]==0 && B[CruR-1][CruC+1]==0)
            {
                A[CruR+1][CruC]=PlayerSign; // PRINT A OR B DEPENDS ON WHICH PLAYER'S MOVE
                A[CruR-1][CruC]=PlayerSign; // PRINT A OR B DEPENDS ON WHICH PLAYER'S MOVE
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                    Player2Score+=2;
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN

            }
            else if(B[CruR-2][CruC]==0 && B[CruR-1][CruC-1]==0 && B[CruR-1][CruC+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[CruR-1][CruC]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1Score+=1;
                }
                else if (PlayerSign=='B') // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2Score+=1;
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
            else if(B[CruR+2][CruC]==0 && B[CruR+1][CruC-1]==0 && B[CruR+1][CruC+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[CruR+1][CruC]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1Score+=1;
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2Score+=1;
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN

            }

        }
    }

    else if(wchSign==4)  // IF THE SIGN WAS | .
    {
        if(CruC==0)
        {
            if(B[CruR][CruC+2]==0 && B[CruR-1][CruC+1]==0 && B[CruR+1][CruC+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[CruR][CruC+1]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1Score+=1;
                }
                else if (PlayerSign=='B')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2Score+=1;
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
        }
        else if(CruC==C-1)
        {
            if(B[CruR][CruC-2]==0 && B[CruR-1][CruC-1]==0 && B[CruR+1][CruC-1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[CruR][CruC-1]=PlayerSign;

                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1Score+=1;
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2Score+=1;
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
        }
        else
        {
            // IF THIS PLACES WERE ZEROS SO THESE TWO BOXES ARE COMPLETED
            if(B[CruR][CruC+2]==0 && B[CruR-1][CruC+1]==0 && B[CruR+1][CruC+1]==0 && B[CruR][CruC-2]==0 && B[CruR-1][CruC-1]==0 && B[CruR+1][CruC-1]==0)
            {
                A[CruR][CruC+1]=PlayerSign;
                A[CruR][CruC-1]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                    Player1Score+=2;
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOXES .. INCRESE HIS SCORE
                {
                    Player2Score+=2;
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
            else if(B[CruR][CruC-2]==0 && B[CruR-1][CruC-1]==0 && B[CruR+1][CruC-1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[CruR][CruC-1]=PlayerSign;

                if(PlayerSign=='A')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1Score+=1;
                }
                else if (PlayerSign=='B')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2Score+=1;
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
            else if(B[CruR][CruC+2]==0 && B[CruR-1][CruC+1]==0 && B[CruR+1][CruC+1]==0)  // IF THIS PLACES WERE ZEROS SO THIS BOX IS COMPLETED
            {
                A[CruR][CruC+1]=PlayerSign;
                if(PlayerSign=='A')  // IF PLAYER 2 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player1Score+=1;
                }
                else if (PlayerSign=='B')  // IF PLAYER 1 CLOSED THE BOX .. INCRESE HIS SCORE
                {
                    Player2Score+=1;
                }
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
        }

    }
}

//---------------------------FUNCTION THAT CHECK WHICH PLAYER SHOULD TAKE THIS TURN AND PLAY ----------------------------------

void wchPlayerMove()
{
    turns++;
    if(turns%2==0)
    {
        wchPlayer=1;
        PlayerSign='A';
    }
    else if(turns%2==1)
    {
        wchPlayer=2;
        PlayerSign='B';
    }

}

