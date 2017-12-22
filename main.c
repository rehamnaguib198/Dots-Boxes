#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "players.h"
#include <time.h>
#include <string.h>
int R,C,R1,C1; //R1&C1 ARE NUMBER OF DOTS HE NEEDS TO PLAY ON .... R,C ARE ROW AND COLOUMN OF THE PLAY GROUND.
char Size[100]; // ARRAY TO TAKE NUMBER OF ROWS AND COLOUMNS OF THE PLAYGROUND
int i,y; //COUNTERS FOR MOST LOOPS.
int P; // PLAYER NUMBER.
int CruR=1,CruC=0; //WHERE THE CRUSUR ? .. ROW AND COLOUMN
int ClcdBtn,wchSign=0,WchSignCounter=0; // BUTTON THAT THE PLAYER CLICKED ON FROM THE KEYBOARD... AND WHICH SIGN WE WILL USE - OR |
int Arrow=0,ArrowVal=1,main_choice=1,esc_choice=1,player_mode=1,game_difficulty=1,ex=1,Save_Value=1,loadValue=0,Valid_Load=1;
int backKey=0;  // MAIN MENU VARIABLES --- ARROW AND ARROWVAL FOR THE MOVING ARROW IN THE MAIN MENU
char PlayerSign; // VARIABLE TO TAKE THE PLAYER SIGN 'A' OR 'B'
int turns=0,wchPlayer=1; // NUMBER OF TURNS DURING THE GAME .. AND PLAYER 1 OR 2
int After_Game=1; // GLOBAL VARIABLE TO KNOW WHAT DID THE PLAYER CHOOSE TO DO AFTER THE GAME END
char A[100][100]; // THE PLAY GROUND.
int  B[100][100],MiniMax[100][100]; // ARRAY OF 1 AND 0 FOR SOME CHECKS.
int  RemainingDots[100][100],NumRemainningDots=0; // ARRAY TO CALCULATE THE REMAINING DOTS.
int  undoC[250],undoR[250],undoCounter=-1,undoTurns[250],Valid_Redo=0,Last_Redo=0;// ARRAYS TO SAVE EVERY MOVE'S ROW AND COLOUMN AND HOW PLAYED IT .. VARIABLES TO CHECK THE REDO AND UNDO
int sum=0; //sums up all the ones in the B array to know when the game ends.
int enter; //a key to continue.
time_t start,end; //To Calculate Time
int minute=0;
double dif=0; // VARIABLES TO CALCULATE TIME
int ValidRow,ValidColumn; // TO CHECK IF THE INPUT IS VALID OR NOT IN ADVANCED MODE
int PlayerVsComp=0;
char FileName[10];
int Played=0;
//-----------------------------------------Players Stucture ----------------------------------
struct Players Player1;
struct Players Player2;
struct Top top_players[50];

struct MiniMaxS
{
    int R;
    int C;
    int Sc;
};
struct MiniMaxS MiniMaxA[100];
COORD cord;

// ----------------------------------- THE MAIN FUNCTION-------------------------------------
void main()
{
    SetConsoleTitle("Dots And Boxes Game"); // TO MAKE TITLE FOR THE GAME .
    //---------------------------TAKING THE SIZE OF PLAY GROUND----------------------------------
    PlaySound(TEXT("Music\\Upbeat Ukulele Background Music - That Positive Feeling by Alumo.wav"), NULL, SND_ASYNC); //menu music

VoidMenu:
    start_menu();
    if(loadValue==0)
    {
        R=R1*2-1; // adding places for the -
        C=C1*2-1; // adding places for the |
Play_Again:
        //---------------------------arranging the play ground----------------------------------
        Arranging_Play_Ground(R,C);
        //---------------------------HERE THE GAME STARTS 3:)----------------------------------
        system("cls");
        endgame(&sum);
        Calculate_Remainning_Dots(CruR,CruC);
    }

    PlaySound(NULL,NULL,NULL); //TO STOP THE MUSIC AFTER THE GAME END
    PlaySound(TEXT("Music\\Happy Background Music - Sunny Side Up by Alumo.wav"), NULL, SND_ASYNC); //game music
    Print(); // PRINT THE PLAYGROUND WITHOUT ANYTHING
    Playing();
    PlaySound(NULL,NULL,NULL); //TO STOP THE MUSIC AFTER THE GAME END
    music();
    winner();
    top10();
    PlaySound(TEXT("Music\\Upbeat Ukulele Background Music - That Positive Feeling by Alumo.wav"), NULL, SND_ASYNC); //menu music
    aftergame();
    if (After_Game==1)
    {
        Reset_After_Game();
        PlaySound(TEXT("Music\\Happy Background Music - Sunny Side Up by Alumo.wav"), NULL, SND_ASYNC); //game music
        goto Play_Again;
    }
    else if (After_Game==2)
    {
        Reset_After_Game();
        Reset_To_Back();
        goto VoidMenu;
    }

}

//---------------------------FUNCTION TO ARRANGE THE PLAY GROUND AND ANOTHER ARRAYS THAT WILL HELP----------------------------------
void Playing()
{
    while(sum>0)
    {
        start = clock();
        if(PlayerVsComp==0)
        {
            Moving();
        }
        else if (PlayerVsComp==1)
        {
            if(wchPlayer==1)
            {
                Moving();
            }
            else if (wchPlayer==2)
            {
                computerRandom();

            }
        }
        else if (PlayerVsComp==2)
        {
            if(wchPlayer==1)
            {
                Moving();
            }
            else if (wchPlayer==2)
            {
                computerGreedy();
            }
        }

        end = clock();
        dif+= (end-start)/(double)CLOCKS_PER_SEC;
        system("cls");
        Print();
    }
}
void Arranging_Play_Ground(int R,int C)
{
    for(i=0; i<R; i++)
    {
        for(y=0; y<C; y++)
        {
            if (i%2==0 && y%2==0)
            {
                A[i][y]=254;
            }
            else
            {
                A[i][y]=' ';
            }
        }
    }
    A[CruR][CruC]='|';

    //---------------------------MAKING ARRAY WITH THE SAME SIZE TO CHANGE COLOR FOR EACH PLAYER----------------------------------
    //---------------------------MAKING ARRAY WITH THE SAME SIZE TO CALCULATE THE REMAINING DOTS----------------------------------
    //---------------------------MAKING ARRAY WITH THE SAME SIZE TO CHEACK IF A PLACE WERE TAKEN OR NOT----------------------------------
    for(i=0; i<R; i++)
    {
        for(y=0; y<C; y++)
        {
            Player1.Player_Info[i][y]=0;
            Player2.Player_Info[i][y]=0;
            if (i%2==1 && y%2==1)
            {
                RemainingDots[i][y]=0;
                B[i][y]=0;
            }
            else if (i%2==0 && y%2==0)
            {
                RemainingDots[i][y]=1;
                B[i][y]=0;
            }
            else
            {
                RemainingDots[i][y]=0;
                B[i][y]=1;
            }
        }
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

//---------------------------FUNCTION TO PRINT THE PLAY GROUND DURING THE GAME----------------------------------

void Print()
{
    //Print Names
    CursorPosition(30,1);
    Change_Color(Player1.Player_Color);
    printf("%.20s",Player1.Name);
    Reset_Color();
    CursorPosition(85,1);
    Change_Color(Player2.Player_Color);
    printf("%.20s",Player2.Name);
    Reset_Color();
//Print Score
    CursorPosition(30,3);
    Change_Color(Player1.Player_Color);
    printf("Score:%i",Player1.Score);
    Reset_Color();
    CursorPosition(85,3);
    Change_Color(Player2.Player_Color);
    printf("Score:%i",Player2.Score);
    Reset_Color();
//Print Moves
    CursorPosition(30,4);
    Change_Color(Player1.Player_Color);
    printf("Moves:%i",Player1.Played_Moves);
    Reset_Color();
    CursorPosition(85,4);
    Change_Color(Player2.Player_Color);
    printf("Moves:%i",Player1.Played_Moves);
    Reset_Color();
//Print Time&Turns
    CursorPosition(52,2);
    Change_Color(10);
    printf("TIME IS :%i:%.2lf",minute,dif);
    Reset_Color();
    CursorPosition(51,3);
    Change_Color(10);
    printf("remaining lines: %i",sum);
    Reset_Color();

    printf("\n\n"); // TO MAE MAKE THE GAME START IN THE MIDDLE OF THE SCREEN
    if(wchPlayer==1)
    {
        Change_Color(14);
        printf("\t\t\t\t\t\t    %.20s's Turn",Player1.Name);
        Reset_Color();
    }
    else if (wchPlayer==2)
    {
        Change_Color(11);
        printf("\t\t\t\t\t\t      %.20s's Turn",Player2.Name);
        Reset_Color();
    }
    printf("\n\n\n\t\t\t\t\t\t"); // TO MAKE THE GAME STARTS IN THE MIDDLE OF THE SCREEN
    for(i=0; i<2*C+3; i++) // THE UPPER FRAME AND +4 IS THE 2 SPACES AND THE SIDE FRAMES
    {
        printf("-");
    }
    printf("\n\t\t\t\t\t\t"); // TO MAKE THE GAME STARTS IN THE MIDDLE OF THE SCREEN
    for(i=0; i<R; i++) // tO PRINT THE DOTS.
    {
        printf("| "); // THE Left SIDE FRAME
        for(y=0; y<C; y++)
        {
            if(i==CruR&&y==CruC) // IF THE CRUSUR IS HERE ... CHANGE THE COLOR AND PRINT IT .
            {
                if(wchPlayer==1)
                {
                    Change_Color(255);
                }
                else if(wchPlayer==2)
                {
                    Change_Color(255);
                }
                printf("%c",A[i][y]);
                Reset_Color();
            }

            else // ELSE PRINT THE PLAYGROUND WITH THE ORDINARY COLOR.
            {
                Change_Player_Color(i,y);
                printf("%c",A[i][y]);
                Reset_Color();
            }

            if (i%2==0)
            {
                if(A[i][y]==' ')
                {
                    printf(" ");
                }
                else if (A[i][y]=='-')
                {
                    Change_Player_Color(i,y);
                    printf("-");
                    Reset_Color();
                }
                else
                {
                    if(A[i][y+1]==' '&&y+1<C)
                    {
                        printf(" ");
                    }
                    else if (A[i][y+1]=='-'&&y+1<C)
                    {
                        Change_Player_Color(i,y+1);
                        printf("-");
                        Reset_Color();
                    }
                }

            }
            else if(i%2==1)
            {
                if (A[i][y]=='A'||(A[i][y+1]=='A'&&y+1<C))
                {
                    Change_Color(14*17);
                    printf(" ");
                    Reset_Color();
                }
                else if (A[i][y]=='B'||(A[i][y+1]=='B'&&y+1<C))
                {
                    Change_Color(11*17);
                    printf(" ");
                    Reset_Color();
                }
                else
                {
                    printf(" ");
                }
            }

        }
        if(i%2==0)
        {
            printf(" |");// THE Right SIDE FRAME
        }
        else if(i%2==1)
        {
            printf("|");// THE Right SIDE FRAME
        }
        printf("\n\t\t\t\t\t\t");
    }
    for(i=0; i<2*C+3; i++)
    {
        printf("-"); // THE DOWN FRAME AND +4 IS THE 2 SPACES AND THE SIDE FRAMES
    }

    if(dif>=60)
    {
        minute++;
        dif-=60;
        PlaySound(TEXT("Music\\Happy Background Music - Sunny Side Up by Alumo.wav"), NULL, SND_ASYNC); //game music
    }

}

//---------------------------FUNCTION THAT MOVES THE CRUSUR AND TO PUT - AND | ----------------------------------

void Moving()
{
Move:
    if (CruR%2==0&&CruC%2==1)
    {
        wchSign=5;
        WchSignCounter=2;
    }
    else if (CruR%2==1&&CruC%2==0)
    {
        wchSign=4;
        WchSignCounter=1;
    }
    ClcdBtn=getche(); // TAKE THE CODE OF THE BUTTON HE CLICKED.
    if(ClcdBtn==32) // space BUTTON TO PRINT "|" .
    {
        WchSignCounter++;
        if(WchSignCounter%2==1)
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
        else if (WchSignCounter%2==0)
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
    }

    else if (ClcdBtn==27) // WHEN HE CLICK ON ESC .. TO SAVE .. LOAD .. EXIT
    {

        ArrowVal=1;
        esc_choice=1;  // variable to know which option he choosed
escmenu:
        system("cls"); // clear the screen
        switch(ArrowVal)
        {

        case 1:
            Change_Color(10);
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-New Game");
            Reset_Color();
            printf("\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Save Game\n\n \t\t\t\t\t\t\t5-Exit\n");
            printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t");
            Change_Color(10);
            printf("----->2-Controls ");
            Reset_Color();
            printf("\n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Save Game\n\n \t\t\t\t\t\t\t5-Exit\n");
            printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
            break;
        case 3:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t");
            Change_Color(10);
            printf("----->3-Load Game ");
            Reset_Color();
            printf("\n\n \t\t\t\t\t\t\t4-Save Game\n\n \t\t\t\t\t\t\t5-Exit\n");
            printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
            break;
        case 4:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t");
            Change_Color(10);
            printf("----->4-Save Game");
            Reset_Color();
            printf("\n\n \t\t\t\t\t\t\t5-Exit\n");
            printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
            break;
        case 5:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Save Game\n\n \t\t\t\t\t\t");
            Change_Color(10);
            printf("----->5-Exit\n");
            Reset_Color();
            printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
            break;
        }
        Arrow=getche();
        switch(Arrow)
        {

        case 72: // UP
            if(ArrowVal>1)
            {
                Beep(200,70);
                ArrowVal--;
                esc_choice--;

            }
            goto escmenu;
            break;
        case 80: // DOWN
            if(ArrowVal<5)
            {
                Beep(300,70);
                ArrowVal++;
                esc_choice++;
            }
            goto escmenu;
            break;
        case 13 : // ENTER
            Beep(130,120);
            break;
        case 27 :
            system("cls");
            Print();
            goto Move;
            break;
        default:
            goto escmenu;
        }

        switch(esc_choice)
        {
        case 1:
            Reset_After_Game();
            Arranging_Play_Ground(R,C);
            system("cls");
            Print(); // PRINT THE PLAYGROUND WITHOUT ANYTHING
            endgame(&sum);
            Calculate_Remainning_Dots(CruR,CruC);
            goto Move;
            break;
        case 2:
controls:
            system("cls");
            printf("\n\n\n\n\t\t\t\t\t\tControls:\n");
            printf("\t\t\t\t\t\tPress Space to change from vertical line to horizontal line and V.V\n");
            printf("\t\t\t\t\t\tpress Use right arrow to go right\n\t\t\t\t\t\tpress left arrow to go left\n\t\t\t\t\t\tpress up arrow to go up\n \t\t\t\t\t\tpress down arrow to go down\n");
            printf("\t\t\t\t\t\tpress \"U\" to Undo move & \"R\" to Redo move ");
            printf("\t\t\t\t\t\tpress Enter to select place");
            printf("\n\n\t\t\t\t\t\tpress esc to go back...");
            Arrow=getche();
            switch(Arrow)
            {
            case 27:
                Reset_To_Back();
                goto escmenu;
                break;
            default:
                goto controls;
            }
            break;
        case 3:
            ArrowVal=1;
load:
            system("cls");
            switch(ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoad Game");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->1-Game 1");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-Game 2 \n \n\t\t\t\t\t\t\t3-Game 3");
                printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
                strcpy(FileName,"Save 1");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoad Game");
                printf("\n\n\t\t\t\t\t\t\t1-Game 1");
                Change_Color(10);
                printf("\n\n \t\t\t\t\t\t----->2-Game 2");
                Reset_Color();
                printf(" \n \n\t\t\t\t\t\t\t3-Game 3");
                printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
                strcpy(FileName,"Save 2");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoad Game");
                printf("\n\n\t\t\t\t\t\t\t1-Game 1\n\n \t\t\t\t\t\t\t2-Game 2");
                Change_Color(10);
                printf(" \n \n\t\t\t\t\t\t----->3-Game 3");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
                strcpy(FileName,"Save 3");
                break;
            }
            Arrow=getche();
            switch(Arrow)
            {

            case 72: // UP
                if(ArrowVal>1)
                {
                    Beep(200,70);
                    ArrowVal--;
                    Save_Value--;

                }
                goto load;
                break;
            case 80: // DOWN
                if(ArrowVal<3)
                {
                    Beep(300,70);
                    ArrowVal++;
                    Save_Value++;
                }
                goto load;
                break;
            case 13 : // ENTER
                Beep(130,120);
                system("cls");
                Load(FileName);
                if(Valid_Load==0)
                {
                    system("cls");
                    printf("\n\n\n\n\t\t\t\tSorry This File Doesn't Contain Any Saved Game ..\n\t\t\t\tPlease Save Game In This File First Befor Loading It\n\n\t\t\t\tClick Any Button To back.");
                    getche();
                    Reset_To_Back();
                    esc_choice=1;
                    goto escmenu;
                }
                system("cls");
                Print();
                goto Move;
                break;
            case 27 :
                system("cls");
                Reset_To_Back();
                goto escmenu;
                break;
            default:
                goto load;
            }
            break;
        case 4:

            ArrowVal=1;
save:
            system("cls");
            switch(ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\Save Game");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->1-Game 1");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-Game 2 \n \n\t\t\t\t\t\t\t3-Game 3");
                printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
                strcpy(FileName,"Save 1");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSave Game");
                printf("\n\n\t\t\t\t\t\t\t1-Game 1");
                Change_Color(10);
                printf("\n\n \t\t\t\t\t\t----->2-Game 2");
                Reset_Color();
                printf(" \n \n\t\t\t\t\t\t\t3-Game 3");
                printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
                strcpy(FileName,"Save 2");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoad Game");
                printf("\n\n\t\t\t\t\t\t\t1-Game 1\n\n \t\t\t\t\t\t\t2-Game 2");
                Change_Color(10);
                printf(" \n \n\t\t\t\t\t\t----->3-Game 3");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
                strcpy(FileName,"Save 3");
                break;
            }
            Arrow=getche();
            switch(Arrow)
            {

            case 72: // UP
                if(ArrowVal>1)
                {
                    Beep(200,70);
                    ArrowVal--;
                    Save_Value--;

                }
                goto save;
                break;
            case 80: // DOWN
                if(ArrowVal<3)
                {
                    Beep(300,70);
                    ArrowVal++;
                    Save_Value++;
                }
                goto save;
                break;
            case 13 : // ENTER
                Beep(130,120);
                system("cls");
                Save(FileName);
                system("cls");
                Print();
                goto Move;
                break;
            case 27 :
                system("cls");
                Reset_To_Back();
                goto escmenu;
                break;
            default:
                goto save;
            }
            break;
        case 5:
            ArrowVal=1;
ExitOrNot:
            system("cls");
            switch(ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tAre you sure you want to exit?\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-YES");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-NO\n");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tAre you sure you want to exit?\n\n\n");
                printf("\t\t\t\t\t\t\t1-YES");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->2-NO\n");
                Reset_Color();
                break;
            }

            Arrow=getche();
            switch(Arrow)
            {
            case 72:
                if(ArrowVal>1)
                {
                    ArrowVal--;
                    ex--;
                    Beep(200,70);

                }
                goto ExitOrNot;
                break;
            case 80:
                if(ArrowVal<2)
                {
                    ArrowVal++;
                    ex++;
                    Beep(300,70);
                }
                goto ExitOrNot;
                break;
            case 13:
                Beep(130,120);
                break;
            default:
                goto ExitOrNot;

            }
            switch(ex)
            {
            case 1: // BUTTON 1
                exit(0);
                break;
            case 2: //BUTTON 2
                Reset_To_Back();
                system("cls");
                Print();
                goto Move;
                break;
            default:
                goto ExitOrNot;
            }

            break;
        }

    }

    if(wchSign==4) // IF THE SIGN IS |..
    {
        if (ClcdBtn==13) // ENTER BUTTON TO USE THIS PLACE AND PUT THE SIGN .
        {
            if(B[CruR][CruC]==0) // if the place is taken
            {
            }
            else
            {
                SaveMoves(CruR,CruC);
                Valid_Redo=0;
                B[CruR][CruC]=0;
                sum--;
                Check_Box(CruR,CruC);
                Change_In_Player_Info(CruR,CruC);
                if (wchPlayer==1)
                {
                    Player1.Played_Moves++;
                }
                else if (wchPlayer==2)
                {
                    Player2.Played_Moves++;
                }
                wchPlayerMove();
                Calculate_Remainning_Dots(CruR,CruC);

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

        else if (ClcdBtn==112)
        {
            if(Played==0)
            {
                PlaySound(TEXT("Music\\Happy Background Music - Sunny Side Up by Alumo.wav"), NULL, SND_ASYNC); //game music
                Played=1;
            }
        }
        else if (ClcdBtn==109)
        {
            PlaySound(NULL,NULL,NULL); //TO STOP THE MUSIC AFTER THE GAME END
            Played=0;
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
        else if (ClcdBtn==117)
        {
            if(PlayerVsComp==1||PlayerVsComp==2)
            {
                while(undoTurns[undoCounter]==2)
                {
                    undo();
                }
                undo();
            }
            else if(PlayerVsComp==0)
            {
                undo();
            }
        }
        else if (ClcdBtn==114)
        {
            if(PlayerVsComp==1||PlayerVsComp==2)
            {
                redo();
                while(undoTurns[undoCounter+1]==2)
                {
                    redo();
                }
            }
            else if(PlayerVsComp==0)
            {
                redo();
                wchSign=4;
            }

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
                SaveMoves(CruR,CruC);
                Valid_Redo=0;
                B[CruR][CruC]=0;
                sum--;
                Check_Box(CruR,CruC);
                Change_In_Player_Info(CruR,CruC);
                if (wchPlayer==1)
                {
                    Player1.Played_Moves++;
                }
                else if (wchPlayer==2)
                {
                    Player2.Played_Moves++;
                }
                wchPlayerMove();
                Calculate_Remainning_Dots(CruR,CruC);

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
        else if (ClcdBtn==112)
        {
            if(Played==0)
            {
                PlaySound(TEXT("Music\\Happy Background Music - Sunny Side Up by Alumo.wav"), NULL, SND_ASYNC); //game music
                Played=1;
            }
        }
        else if (ClcdBtn==109)
        {
            PlaySound(NULL,NULL,NULL); //TO STOP THE MUSIC AFTER THE GAME END
            Played=0;
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
        else if (ClcdBtn==117)
        {
            if(PlayerVsComp==1||PlayerVsComp==2)
            {
                while(undoTurns[undoCounter]==2)
                {
                    undo();
                }
                undo();
            }
            else if(PlayerVsComp==0)
            {
                undo();
            }
        }
        else if (ClcdBtn==114)
        {
            if(PlayerVsComp==1||PlayerVsComp==2)
            {

                redo();
                while(undoTurns[undoCounter+1]==2)
                {
                    redo();
                }

            }
            else if(PlayerVsComp==0)
            {
                redo();
            }

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
    ArrowVal=1;
menu:
    system("cls");
    switch(ArrowVal)
    {

    case 1:
        Change_Color(10);
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-New Game");
        Reset_Color();
        printf("\n\n \t\t\t\t\t\t\t2-How To Play \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Top 10 player\n\n \t\t\t\t\t\t\t5-Exit\n");
        break;
    case 2:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t");
        Change_Color(10);
        printf("----->2-How To Play ");
        Reset_Color();
        printf("\n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Top 10 player\n\n \t\t\t\t\t\t\t5-Exit\n");
        break;
    case 3:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-How To Play \n \n\t\t\t\t\t\t");
        Change_Color(10);
        printf("----->3-Load Game ");
        Reset_Color();
        printf("\n\n \t\t\t\t\t\t\t4-Top 10 player\n\n \t\t\t\t\t\t\t5-Exit\n");
        break;
    case 4:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-How To Play \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t");
        Change_Color(10);
        printf("----->4-Top 10 player");
        Reset_Color();
        printf("\n\n \t\t\t\t\t\t\t5-Exit\n");
        break;
    case 5:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-How To Play \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Top 10 player\n\n \t\t\t\t\t\t");
        Change_Color(10);
        printf("----->5-Exit\n");
        Reset_Color();
        break;
    }
    Arrow=getche();
    switch(Arrow)
    {

    case 72: // UP
        if(ArrowVal>1)
        {
            Beep(200,70);
            ArrowVal--;
            main_choice--;

        }
        goto menu;
        break;
    case 80: // DOWN
        if(ArrowVal<5)
        {
            Beep(300,70);
            ArrowVal++;
            main_choice++;
        }
        goto menu;
        break;
    case 13 : // ENTER
        Beep(130,120);
        break;
    default:
        goto menu;
    }

    switch(main_choice)
    {

    case 1: //BUTTON 1 FOR -NEW GAME-
        ArrowVal=1;
New_Game:
        system("cls");
        switch(ArrowVal)
        {
        case 1:
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Mode:\n\n\n");
            Change_Color(10);
            printf("\t\t\t\t\t\t----->1-player vs computer");
            Reset_Color();
            printf("\n\n\t\t\t\t\t\t\t2-player1 vs player2\n");
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Mode:\n\n\n");
            printf("\t\t\t\t\t\t\t1-player vs computer\n\n\t\t\t\t\t\t");
            Change_Color(10);
            printf("----->2-player1 vs player2\n");
            Reset_Color();
            break;
        }
        Arrow=getche();
        switch(Arrow)
        {
        case 27:
            Reset_To_Back();
            goto menu;
            break; //ESC TO GO BACK
        case 72: // UP
            if(ArrowVal>1)
            {
                ArrowVal--;
                player_mode--;
                Beep(200,70);
            }
            goto New_Game;
            break;
        case 80: //DOWN
            if(ArrowVal<2)
            {
                ArrowVal++;
                player_mode++;
                Beep(300,70);

            }
            goto New_Game;
            break;
        case 13 : // ENTER
            Beep(130,120);
            break;
        default:
            goto New_Game;
        }

        switch(player_mode)
        {
        case 1:  // BUTTON 1 FOR PLAYER VS COMPUTER

// TO TAKE THE PLAYER NAME
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player1.Name,100,stdin);
            while(Player1.Name[0]=='\n')
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
                printf("\n\n\t\t\t\t\t\t\t   ");
                fflush(stdin);
                fgets(Player1.Name,100,stdin);
                fflush(stdin);

            }
            int z=0;
            while (Player1.Name[z]!='\0')
            {
                z++;
            }
            Player1.Name[z-1]='\0';

            fflush(stdin);
            strcpy(Player2.Name,"Computer");

            // TO CONTINUE IN THE MENU
            ArrowVal=1;
            PlayerVsComp=1;
Player_vs_Comp:

            system("cls");
            switch (ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Difficulty:\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-Easy");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-Hard\n");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Difficulty:\n\n\n");
                printf("\t\t\t\t\t\t\t1-Easy\n\n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-Hard\n");
                Reset_Color();
                break;
            }
            Arrow=getche();
            switch(Arrow)
            {
            case 27: //esc
                Reset_To_Back();
                PlayerVsComp=0;
                goto New_Game;
                break;
            case 72: //up
                if(ArrowVal>1)
                {
                    ArrowVal--;
                    PlayerVsComp--;
                    Beep(200,70);
                }
                goto Player_vs_Comp;
                break;
            case 80:
                if(ArrowVal<2)
                {
                    ArrowVal++;
                    PlayerVsComp++;
                    Beep(300,70);

                }
                goto Player_vs_Comp;
                break;
            case 13 :
                Beep(130,120);

                break;
            default:
                goto Player_vs_Comp;

            }

            ArrowVal=1;
Player_Vs_Comp_Size:
            system("cls");
            switch (ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Size:\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-2x2");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-Choose Your Size\n");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Size:\n\n\n");
                printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-5x5");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t3-Choose Your Size\n");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Size:\n\n\n");
                printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->3-Choose Your Size\n");
                Reset_Color();
                break;
            }
            Arrow=getche();
            switch(Arrow)
            {
            case 27:
                Reset_To_Back();
                PlayerVsComp=1;
                goto Player_vs_Comp;
                break;
            case 72:
                if(ArrowVal>1)
                {
                    ArrowVal--;
                    game_difficulty--;
                    Beep(200,70);
                }
                goto Player_Vs_Comp_Size;
                break;
            case 80:
                if(ArrowVal<3)
                {
                    ArrowVal++;
                    game_difficulty++;
                    Beep(300,70);

                }
                goto Player_Vs_Comp_Size;
                break;
            case 13 :
                Beep(130,120);

                break;
            default:
                goto Player_Vs_Comp_Size;

            }
            switch(game_difficulty)
            {
            case 1: // BUTTON 1 FOR BEGINNER
                R1=3,C1=3;

                break;
            case 2: // BUTTON 2 FOR EXPERT
                R1=5,C1=5;
                break;
            case 3: // BUTTON 3 FOR ADVANCED TO CHOOSE NUMBER OF DOTS HE NEEDS
                system("cls");
                printf("Enter Number Of Rows. \n  WARNING .. If You Entered Number In The Beginning Of A String We Will Make The Number OF Rows Equal To This Number\n\n");
                gets(Size);
                ValidRow=atoi(Size);
                if(ValidRow>=2&&ValidRow<=10)
                {
                    R1=ValidRow;
                    goto jumpRow;
                }
                while(ValidRow < 2 || ValidRow>10)
                {
                    system("cls");
                    printf("WRONG INPUT ,, PLEASE ENTER NUMBER BETWEEN 2 AND 100\n\n");
                    printf("Enter Number Of Rows. \n  WARNING .. If You Entered Number In The Beginning Of A String We Will Make The Number OF Rows Equal To This Number\n\n");
                    gets(Size);
                    ValidRow=atoi(Size);
                }
                R1=ValidRow;
jumpRow:
                system("cls");
                printf("Enter Number Of Column. \n  WARNING .. If You Entered Number In The Beginning Of A String We Will Make The Number OF Rows Equal To This Number\n\n");
                gets(Size);
                ValidColumn=atoi(Size);
                if(ValidColumn>=2&&ValidColumn<=10)
                {
                    C1=ValidColumn;
                    goto jumpColumn;
                }
                while(ValidColumn < 2 || ValidColumn>10)
                {
                    system("cls");
                    printf("WRONG INPUT ,, PLEASE ENTER NUMBER BETWEEN 2 AND 100\n\n");
                    printf("Enter Number Of Column. \n  WARNING .. If You Entered Number In The Beginning Of A String We Will Make The Number OF Rows Equal To This Number\n\n");
                    gets(Size);
                    ValidColumn=atoi(Size);
                }
                C1=ValidColumn;
jumpColumn:
                break;
            default:
                goto Player_Vs_Comp_Size;
            }
            break;
        case 2: // BUTTON 2 FOR PLAYER 1 VS PLAYER 2
            // TO TAKE PLAYER NAME
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player1.Name,100,stdin);

            while(Player1.Name[0]=='\n')
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
                printf("\n\n\t\t\t\t\t\t\t   ");
                fflush(stdin);
                fgets(Player1.Name,100,stdin);
            }
            z=0;
            while (Player1.Name[z]!='\0')
            {
                z++;
            }
            Player1.Name[z-1]='\0';

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 2's Name:");
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player2.Name,100,stdin);

            while(Player2.Name[0]=='\n')
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 2's Name:");
                printf("\n\n\t\t\t\t\t\t\t   ");
                fflush(stdin);
                fgets(Player2.Name,100,stdin);
            }
            z=0;
            while (Player2.Name[z]!='\0')
            {
                z++;
            }
            Player2.Name[z-1]='\0';
            // TO CONTINUE IN THE MENU
            ArrowVal=1;
Player1_Vs_Player2:
            system("cls");

            switch (ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Size:\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-2x2");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-Choose Your Size\n");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Size:\n\n\n");
                printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-5x5");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t3-Choose Your Size\n");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Size:\n\n\n");
                printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->3-Choose Your Size\n");
                Reset_Color();
                break;
            }
            Arrow=getche();
            switch(Arrow)
            {
            case 27:
                Reset_To_Back();
                goto New_Game;
                break;
            case 72:
                if(ArrowVal>1)
                {
                    ArrowVal--;
                    game_difficulty--;
                    Beep(200,70);
                }
                goto Player1_Vs_Player2;
                break;
            case 80:
                if(ArrowVal<3)
                {
                    ArrowVal++;
                    game_difficulty++;
                    Beep(300,70);

                }
                goto Player1_Vs_Player2;
                break;
            case 13 :
                Beep(130,120);

                break;
            default:
                goto Player1_Vs_Player2;

            }
            switch(game_difficulty)
            {
            case 1: // BUTTON 1 FOR BEGINNER
                R1=3,C1=3;
                break;
            case 2: // BUTTON 2 FOR EXPERT
                R1=5,C1=5;
                break;
            case 3: // BUTTON 3 FOR ADVANCED TO CHOOSE NUMBER OF DOTS HE NEEDS
                system("cls");
                printf("Enter Number Of Rows. \n  WARNING .. If You Entered Number In The Beginning Of A String We Will Make The Number OF Rows Equal To This Number\n\n");
                gets(Size);
                ValidRow=atoi(Size);
                if(ValidRow>=2&&ValidRow<=10)
                {
                    R1=ValidRow;
                    goto jumpRow1;
                }
                while(ValidRow < 2 || ValidRow>10)
                {
                    system("cls");
                    printf("WRONG INPUT ,, PLEASE ENTER NUMBER BETWEEN 2 AND 100\n\n");
                    printf("Enter Number Of Rows. \n  WARNING .. If You Entered Number In The Beginning Of A String We Will Make The Number OF Rows Equal To This Number\n\n");
                    gets(Size);
                    ValidRow=atoi(Size);
                }
                R1=ValidRow;
jumpRow1:
                system("cls");
                printf("Enter Number Of Column. \n  WARNING .. If You Entered Number In The Beginning Of A String We Will Make The Number OF Rows Equal To This Number\n\n");
                gets(Size);
                ValidColumn=atoi(Size);
                if(ValidColumn>=2&&ValidColumn<=10)
                {
                    C1=ValidColumn;
                    goto jumpColumn1;
                }
                while(ValidColumn < 2 || ValidColumn>10)
                {
                    system("cls");
                    printf("WRONG INPUT ,, PLEASE ENTER NUMBER BETWEEN 2 AND 100\n\n");
                    printf("Enter Number Of Column. \n  WARNING .. If You Entered Number In The Beginning Of A String We Will Make The Number OF Rows Equal To This Number\n\n");
                    gets(Size);
                    ValidColumn=atoi(Size);
                }
                C1=ValidColumn;
jumpColumn1:
                break;
            default:
                goto Player1_Vs_Player2;
            }
            break;
        }
        break;
//HOW TO PLAY//
    case 2: //BUTTON 2 FOR -HOW TO PLAY-
        system("cls");
        printf("\n\n\t\t\t\t\t\t\tHow to play\n\n");
        printf("\t\t  The two players take turns to join two adjacent dots with a horizontal or vertical line. \n");
        printf("\t      If a player completes the fourth side of a box they initial that box and must draw another line. \n");
        printf("\t    When all the boxes have been completed the winner is the player who has initialled the most boxes.");
        printf("\n\n\n\n\t\t\t\t\t\tControls:\n");
        printf("\t\t\t\t\t\tPress Space to change from vertical line to horizontal line and V.V\n");
        printf("\t\t\t\t\t\tpress Use right arrow to go right\n\t\t\t\t\t\tpress left arrow to go left\n\t\t\t\t\t\tpress up arrow to go up\n \t\t\t\t\t\tpress down arrow to go down\n");
        printf("\t\t\t\t\t\tpress \"U\" to Undo move & \"R\" to Redo move ");
        printf("\n\t\t\t\t\t\tpress Enter to select place");
        printf("\n\n\n\t\t\t\t\t\tpress 1 to go back to main menu");
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
    case 3: // BUTTON 3
        ArrowVal=1;
        Save_Value=1;
load:
        system("cls");
        switch(ArrowVal)
        {
        case 1:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoad Game");
            Change_Color(10);
            printf("\n\n\t\t\t\t\t\t----->1-Game 1");
            Reset_Color();
            printf("\n\n \t\t\t\t\t\t\t2-Game 2 \n \n\t\t\t\t\t\t\t3-Game 3");
            printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
            strcpy(FileName,"Save 1");
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoad Game");
            printf("\n\n\t\t\t\t\t\t\t1-Game 1");
            Change_Color(10);
            printf("\n\n \t\t\t\t\t\t----->2-Game 2");
            Reset_Color();
            printf(" \n \n\t\t\t\t\t\t\t3-Game 3");
            printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
            strcpy(FileName,"Save 2");
            break;
        case 3:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoad Game");
            printf("\n\n\t\t\t\t\t\t\t1-Game 1\n\n \t\t\t\t\t\t\t2-Game 2");
            Change_Color(10);
            printf(" \n \n\t\t\t\t\t\t----->3-Game 3");
            Reset_Color();
            printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
            strcpy(FileName,"Save 3");
            break;
        }
        Arrow=getche();
        switch(Arrow)
        {

        case 72: // UP
            if(ArrowVal>1)
            {
                Beep(200,70);
                ArrowVal--;
                Save_Value--;

            }
            goto load;
            break;
        case 80: // DOWN
            if(ArrowVal<3)
            {
                Beep(300,70);
                ArrowVal++;
                Save_Value++;
            }
            goto load;
            break;
        case 13 : // ENTER
            Beep(130,120);
            system("cls");
            Load(FileName);
            if(Valid_Load==0)
            {
                system("cls");
                printf("\n\n\n\n\t\t\t\tSorry This File Doesn't Contain Any Saved Game ..\n\t\t\t\tPlease Save Game In This File First Befor Loading It\n\n\t\t\t\tClick Any Button To back.");
                getche();
                Reset_To_Back();
                goto menu;
            }
            system("cls");
            loadValue=1;
            goto Done;
            break;
        case 27 :
            system("cls");
            Reset_To_Back();
            goto menu;
            break;
        default:
            goto load;
        }

        break;
//top 10 players//
    case 4: // BUTTON 4
        while (backKey!=13)
        {
            system("cls");
            Show_Top10();
            CursorPosition(41,15);
            printf("Press enter to go back to menu");
            backKey=getche();
        }
        if(backKey==13)
        {
            Reset_To_Back();
            goto menu;
        }
        break;
//exit//
    case 5: // BUTTON 5
        ArrowVal=1;
exit:
        system("cls");
        switch(ArrowVal)
        {
        case 1:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tAre you sure you want to exit?\n\n\n");
            Change_Color(10);
            printf("\t\t\t\t\t\t----->1-YES");
            Reset_Color();
            printf("\n\n\t\t\t\t\t\t\t2-NO\n");
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tAre you sure you want to exit?\n\n\n");
            printf("\t\t\t\t\t\t\t1-YES\n\n\t\t\t\t\t\t");
            Change_Color(10);
            printf("----->2-NO\n");
            Reset_Color();
            break;
        }

        Arrow=getche();
        switch(Arrow)
        {
        case 72:
            if(ArrowVal>1)
            {
                ArrowVal--;
                ex--;
                Beep(200,70);
            }
            goto exit;
            break;
        case 80:
            if(ArrowVal<2)
            {
                ArrowVal++;
                ex++;
                Beep(300,70);
            }
            goto exit;
            break;
        case 13:
            Beep(130,120);

            break;
        default:
            goto exit;

        }
        switch(ex)
        {
        case 1: // BUTTON 1
            exit(0);
            break;
        case 2: //BUTTON 2
            ArrowVal=1;
            main_choice=1;
            Arrow=1;
            ex=1;
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
Done:
    system("cls");
}


//---------------------------FUNCTION THAT CHECK WHEN THE PLAYER MAKE HIS MOVE IF ANY BOX WAS COMPLETED ----------------------------------

void Check_Box(int r,int c)
{
    if(wchSign==5)  //IF THE SIGN WAS - .
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
                turns--; //TO MAKE THE SAME PLAYER PLAY AGAIN
            }
        }

        else
        {
            // IF THIS PLACES WERE ZEROS SO THESE TWO BOXES ARE COMPLETED
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
//---------------------------FUNCTION TO RESET ALL THE VARIABLE WE USE IN MAIN MENUE SO IT DOESNT AFFECT ON EACH OTHER WHEN WE BACK ----------------------------------

void Reset_To_Back()
{
    Arrow=1;
    ArrowVal=1;
    ex=1;
    main_choice=1;
    game_difficulty=1;
    player_mode=1;
    PlayerVsComp=0;
    backKey=0;
    esc_choice=1;

}
void Reset_After_Game()
{
    loadValue=0;
    Arrow=1;
    ArrowVal=1;
    ex=1;
    main_choice=1;
    game_difficulty=1;
    player_mode=1;
    turns=0,wchPlayer=1;
    wchSign=0;
    WchSignCounter=0;
    undoCounter=-1;
    Player1.Played_Moves=0;
    Player1.Score=0;
    Player2.Played_Moves=0;
    Player2.Score=0;
    minute=0;
    dif=0;
    CruC=0;
    CruR=1;
    strcpy(Size,"");
    sum=0,Last_Redo=0,Valid_Redo=0;


    // TO RESET THE ARRAY OF REMAINING DOTS
    for(i=0; i<R; i++)
    {
        for(y=0; y<C; y++)
        {
            if (i%2==1 && y%2==1)
            {
                RemainingDots[i][y]=0;
            }
            else if (i%2==0 && y%2==0)
            {
                RemainingDots[i][y]=1;
            }
            else
            {
                RemainingDots[i][y]=0;
            }
        }
    }



}

void Change_In_Player_Info(int i,int y)
{
    if(wchPlayer==1)
    {
        Player1.Player_Info[i][y]=1;

    }
    else if (wchPlayer==2)
    {
        Player2.Player_Info[i][y]=1;
    }
}
void Change_Player_Color(int i,int y)
{
    if(Player1.Player_Info[i][y]==1)
    {
        Change_Color(14);
    }
    else if(Player1.Player_Info[i][y]==2)
    {
        Change_Color(224);
    }
    else if(Player2.Player_Info[i][y]==1)
    {
        Change_Color(11);
    }
    else if(Player2.Player_Info[i][y]==2)
    {
        Change_Color(11*17+1);
    }
}
//----------------------------end the game-----------------------//
void endgame(int *sum)
{
    *sum=0;
    for(i=0; i<R; i++)
    {
        for(y=0; y<C; y++)
        {
            *sum+=B[i][y];
        }
    }
}
//-------------------------------------------------Winner------------------------------------//
void winner()
{
Winner:

    Print();
    Change_Color(13);
    printf("\n\n\t\t\t\t\t\t\t  Game Over");
    Reset_Color();
    if ( Player1.Score > Player2.Score )
    {
        Change_Color(Player1.Player_Color);
        printf("\n\nt\t\t\t\t\t %s's score (WINNER): %d",Player1.Name,Player1.Score);
        Change_Color(Player2.Player_Color);
        printf("\n\t\t\t\t\t\t %s's score : %d",Player2.Name,Player2.Score);
        Reset_Color();
    }
    else if (Player1.Score < Player2.Score)
    {
        Change_Color(Player2.Player_Color);
        printf("\n\n\t\t\t\t\t\t %s's score (WINNER): %d",Player2.Name,Player2.Score);
        Change_Color(Player1.Player_Color);
        printf("\n\t\t\t\t\t\t %s's score : %d",Player1.Name,Player1.Score);
        Reset_Color();
    }
    else if (Player1.Score == Player2.Score)
    {
        Change_Color(Player1.Player_Color);
        printf("\n\n\t\t\t\t\t\t %s's score : %d",Player1.Name,Player1.Score);
        Change_Color(Player2.Player_Color);
        printf("\n\t\t\t\t\t\t %s's score : %d",Player2.Name,Player2.Score);
        Reset_Color();
        printf("\n\t\t\t\t\t\t\t  DRAW! ");
    }
    printf("\n\n\t\t\t\t\t\t   press Enter to continue ");
    enter=getche();
    if(enter==13)
    {
        system("cls");
        Show_Top10();
        printf("\n\n\t\t\t\t\t\t   press Enter to continue ");
        enter=getche();
        if(enter==13){

        }
        else    {
        goto Winner;
    }
    }
    else
    {
        goto Winner;
    }
}

//---------------------------------------After the game ends--------------------------//
void aftergame()
{
    system("cls");
after:
    system("cls");
    switch(After_Game)
    {
    case 1:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Play again\n\n \t\t\t\t\t\t\t2-Go back to menu");
        break;
    case 2:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Play again\n\n \t\t\t\t\t\t----->2-Go back to menu");
        break;
    }
    Arrow=getche();
    switch(Arrow)
    {
    case 72: // UP
        After_Game=1;
        Beep(200,70);
        goto after;
        break;
    case 80: // DOWN
        After_Game=2;
        Beep(300,70);
        goto after;
        break;
    case 13 : // ENTER
        Beep(130,120);
        break;
    default:
        goto after;

    }
}

void sound()
{
    if(wchPlayer==1)
    {
        Beep(200,120);
    }
    else if (wchPlayer==2)
    {
        Beep(300,120);
    }
}

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
        int r=undoR[undoCounter];
        int c=undoC[undoCounter];
        A[r][c]=' ';
        B[r][c]=1;
        Player1.Player_Info[r][c]=0;
        Player2.Player_Info[r][c]=0;
        if(r%2==0)
        {
            int a=0;
            if(A[r+1][c]==' '&&r<R-1)
            {
            }
            else
            {
                A[r+1][c]=' ';
                if(Player1.Player_Info[r+1][c]==2)
                {
                    Player1.Score--;
                    Player1.Player_Info[r+1][c]=0;
                    turns++;
                    a=1;
                }
                else if(Player2.Player_Info[r+1][c]==2)
                {
                    Player2.Score--;
                    Player2.Player_Info[r+1][c]=0;
                    turns++;
                    a=1;
                }
            }
            if(A[r-1][c]==' '&&r>0)
            {
            }
            else
            {
                A[r-1][c]=' ';
                if(Player1.Player_Info[r-1][c]==2)
                {
                    Player1.Score--;
                    Player1.Player_Info[r-1][c]=0;
                    if(a==0)
                    {
                        turns++;
                    }
                }
                else if(Player2.Player_Info[r-1][c]==2)
                {
                    Player2.Score--;
                    Player2.Player_Info[r-1][c]=0;
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
            else
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
            }
            if(A[r][c-1]==' '&&r>0)
            {
            }
            else
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
            }
            else if(undoTurns[undoCounter]==2)
            {
                wchPlayer=2;
                PlayerSign='B';
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

            Check_Box(r,c);

            if(undoTurns[undoCounter]==1)
            {
                Player1.Played_Moves++;
            }
            else if (undoTurns[undoCounter]==2)
            {
                Player2.Played_Moves++;
            }


            endgame(&sum);
            wchPlayerMove();
        }

    }
}
void Calculate_Remainning_Dots(int r,int c)  // IF HE WANT THE REMAINING LINES WE WILL CHANGE IN THE SAME ARRAY THE 0 IN ONE COnDITION TO 1 V.V
{
    if (wchSign==4)
    {
        if(r<R-1)
        {
            RemainingDots[r+1][c]=0;
        }
        if (r>0)
        {
            RemainingDots[r-1][c]=0;
        }
    }
    else if (wchSign==5)
    {
        if(c<C-1)
        {
            RemainingDots[r][c+1]=0;
        }
        if (c>0)
        {
            RemainingDots[r][c-1]=0;
        }
    }
    NumRemainningDots=0;
    int i,y;
    for(i=0; i<R; i++)
    {
        for(y=0; y<C; y++)
        {
            NumRemainningDots+=RemainingDots[i][y];
        }
    }

}


void Esc()
{
escmenu:
    system("cls");
    ArrowVal=1;
    esc_choice=1;
    switch(ArrowVal)
    {

    case 1:
        Change_Color(10);
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-New Game");
        Reset_Color();
        printf("\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Save Game\n\n \t\t\t\t\t\t\t5-Exit\n");
        break;
    case 2:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t");
        Change_Color(10);
        printf("----->2-Controls ");
        Reset_Color();
        printf("\n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Save Game\n\n \t\t\t\t\t\t\t5-Exit\n");
        break;
    case 3:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t");
        Change_Color(10);
        printf("----->3-Load Game ");
        Reset_Color();
        printf("\n\n \t\t\t\t\t\t\t4-Save Game\n\n \t\t\t\t\t\t\t5-Exit\n");
        break;
    case 4:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t");
        Change_Color(10);
        printf("----->4-Save Game");
        Reset_Color();
        printf("\n\n \t\t\t\t\t\t\t5-Exit\n");
        break;
    case 5:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Save Game\n\n \t\t\t\t\t\t");
        Change_Color(10);
        printf("----->5-Exit\n");
        Reset_Color();
        break;
    }
    Arrow=getche();
    switch(Arrow)
    {

    case 72: // UP
        if(ArrowVal>1)
        {
            Beep(200,70);
            ArrowVal--;
            esc_choice--;

        }
        goto escmenu;
        break;
    case 80: // DOWN
        if(ArrowVal<5)
        {
            Beep(300,70);
            ArrowVal++;
            esc_choice++;
        }
        goto escmenu;
        break;
    case 13 : // ENTER
        Beep(130,120);
        break;
    default:
        goto escmenu;
    }

    switch(esc_choice)
    {
    case 1:
        Reset_After_Game();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    }

}




void computerRandom()
{
    srand(time(NULL));   // should only be called once
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
                wchPlayerMove();
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
                wchPlayerMove();
                Calculate_Remainning_Dots(CruR,CruC);

            }
            else
            {
                x=1;
            }

        }
    }
}

void Save(char name[10])
{
    FILE *fSave;
    char Name[20];
    sprintf(Name, "Saved games\\%s.txt",name);
    fSave=fopen(Name,"w");
    fprintf(fSave,"%i %i",R,C);
    int i,y;
    for ( i=0; i<R; i++)
    {
        for( y=0; y<C; y++)
        {
            fprintf(fSave,"%c",A[i][y]);
        }
    }
    for ( i=0; i<R; i++)
    {
        for( y=0; y<C; y++)
        {
            fprintf(fSave,"%i ",B[i][y]);
        }
    }
    for ( i=0; i<R; i++)
    {
        for( y=0; y<C; y++)
        {
            fprintf(fSave,"%i ",RemainingDots[i][y]);
        }
    }
    for ( i=0; i<R; i++)
    {
        for( y=0; y<C; y++)
        {
            fprintf(fSave,"%i %i ",Player1.Player_Info[i][y],Player2.Player_Info[i][y]);
        }
    }
    fprintf(fSave,"%i %i %i %i %i %i %i %i %i %i %lf %i %i %i %i ",CruR,CruC,ClcdBtn,wchSign,WchSignCounter,turns,wchPlayer,NumRemainningDots,sum,minute,dif,PlayerVsComp,undoCounter,Valid_Redo,Last_Redo);
    for( i=0; i<=undoCounter; i++)
    {
        fprintf(fSave,"%i %i %i ",undoR[i],undoC[i],undoTurns[i]);
    }
    fprintf(fSave,"%i %i %i %i ",Player1.Played_Moves,Player1.Score,Player2.Played_Moves,Player2.Score);
    fprintf(fSave,"%c ",PlayerSign);
    fprintf(fSave,"%s; %s,",Player1.Name,Player2.Name);
    fclose(fSave);
}

void Load(char name[10])
{
    FILE *fSave;
    char Name[20];
    sprintf(Name, "Saved games\\%s.txt",name);
    fSave=fopen(Name,"r");
    if (fSave==NULL)
    {
        Valid_Load=0;
    }
    else
    {
        Valid_Load=1;
    }
    fscanf(fSave,"%i %i",&R,&C);
    int i,y;
    for (i=0; i<R; i++)
    {
        for( y=0; y<C; y++)
        {
            fscanf(fSave,"%c",&A[i][y]);
        }
    }
    for ( i=0; i<R; i++)
    {
        for( y=0; y<C; y++)
        {
            fscanf(fSave,"%i ",&B[i][y]);
        }
    }
    for ( i=0; i<R; i++)
    {
        for( y=0; y<C; y++)
        {
            fscanf(fSave,"%i ",&RemainingDots[i][y]);
        }
    }
    for ( i=0; i<R; i++)
    {
        for( y=0; y<C; y++)
        {
            fscanf(fSave,"%i %i ",&Player1.Player_Info[i][y],&Player2.Player_Info[i][y]);
        }
    }
    fscanf(fSave,"%i %i %i %i %i %i %i %i %i %i %lf %i %i %i %i ",&CruR,&CruC,&ClcdBtn,&wchSign,&WchSignCounter,&turns,&wchPlayer,&NumRemainningDots,&sum,&minute,&dif,&PlayerVsComp,&undoCounter,&Valid_Redo,&Last_Redo);
    for( i=0; i<=undoCounter; i++)
    {
        fscanf(fSave,"%i %i %i ",&undoR[i],&undoC[i],&undoTurns[i]);
    }
    fscanf(fSave,"%i %i %i %i ",&Player1.Played_Moves,&Player1.Score,&Player2.Played_Moves,&Player2.Score);
    fscanf(fSave,"%c ",&PlayerSign);
    fscanf(fSave,"%[^;]; %[^,]",&Player1.Name,&Player2.Name);
    fclose(fSave);
}


void top10 ()
{
    char Name[500];
    int score,newP1=0,newP2=0;
    FILE * fpointer1;
    FILE * fpointer2;
    fpointer1=fopen("Top_10.txt","r");
    fpointer2=fopen("Top_10-1.txt","w");

    while (fscanf(fpointer1,"%[^,],%i;",Name,&score)!=EOF)
    {
        if(!strcmp(Name,Player1.Name))
        {
            newP1=1;
            if(Player1.Score>score)
            {
                score=Player1.Score;
            }
        }
        else if(!strcmp(Name,Player2.Name))
        {
            newP2=1;
            if(Player2.Score>score)
            {
                score=Player2.Score;
            }
        }
        fprintf(fpointer2,"%s,%i;",Name,score);

    }
    fclose(fpointer2);
    fclose(fpointer1);
    if(newP1==0)
    {
        fpointer2=fopen("Top_10-1.txt","a");
        fprintf(fpointer2,"%s,%i;",Player1.Name,Player1.Score);
        fclose(fpointer2);
    }
    if(newP2==0&&PlayerVsComp==0)
    {
        fpointer2=fopen("Top_10-1.txt","a");
        fprintf(fpointer2,"%s,%i;",Player2.Name,Player2.Score);
        fclose(fpointer2);
    }
    fpointer1=fopen("Top_10.txt","w");
    fpointer2=fopen("Top_10-1.txt","r");

    while (fscanf(fpointer2,"%s",Name)!=EOF)
    {
        fprintf(fpointer1,"%s",Name);
    }
    fclose(fpointer2);
    fclose(fpointer1);

}

void Show_Top10()
{
    int i=0;
    int y,j;
    struct Top temp;
    FILE *fpointer1;
    fpointer1=fopen("Top_10.txt","r");
    while (fscanf(fpointer1,"%[^,],%i;",top_players[i].Name,&top_players[i].Score)!=EOF)
    {
        i++;
    }

    for(y=0; y<i; y++)
    {
        for(j=y+1; j<i;)
        {
            if(top_players[y].Score<top_players[j].Score)
            {
                temp=top_players[y];
                top_players[y]=top_players[j];
                top_players[j]=temp;
            }
            else
            {
                j++;
            }
        }
    }
    CursorPosition(41,2);
    printf("Name");
    CursorPosition(60,2);
    printf("|");
    CursorPosition(70,2);
    printf("Score");
    CursorPosition(36,3);
    printf("----------------------------------------");

    for(y=0; y<10; y++)
    {
        CursorPosition(37,4+y);
        printf("%i-%.19s",y+1,top_players[y].Name);
        CursorPosition(71,4+y);
        printf("%i",top_players[y].Score);
        CursorPosition(60,4+y);
        printf("|");

    }
}

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
    wchPlayerMove();
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
    wchPlayerMove();
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
    wchPlayerMove();
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
    wchPlayerMove();
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
    wchPlayerMove();
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
    wchPlayerMove();
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
    wchPlayerMove();
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
    wchPlayerMove();
    Calculate_Remainning_Dots(i+1,y+1);
}




void computerGreedy()
{
    int i,y,x=0;
// Check if there is only one side left of a box
    for(i=0; i<R-2; i+=2)
    {
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
    if (x==0&&randd==1)
    {
        for(i=0; i<R-2; i+=2)
        {
            for(y=1; y<C; y+=2)
            {
                if (B[i][y]+B[i+2][y]+B[i+1][y+1]+B[i+1][y-1]==3||B[i][y]+B[i+2][y]+B[i+1][y+1]+B[i+1][y-1]==4)
                {
                    if(B[i][y]==1)
                    {
                        if(i==0)
                        {
                            PlayTop(i,y);
                            x=1;
                            break;
                        }
                        else
                        {
                            if (B[i-2][y]+B[i-1][y-1]+B[i-1][y+1]+B[i][y]==3||B[i-2][y]+B[i-1][y-1]+B[i-1][y+1]+B[i][y]==4)
                            {
                                PlayTop(i,y);
                                x=1;
                                break;
                            }

                        }
                    }
                    if (i==R-3)
                    {
                        if(B[i+2][y]==1)
                        {
                            PlayBottom(i,y);
                            x=1;
                            break;
                        }
                    }

                    if (y==1)
                    {
                        if(B[i+1][y-1]==1)
                        {
                            Playleft(i,y);
                            x=1;
                            break;
                        }

                    }
                    if (y==C-2)
                    {
                        if(B[i+1][y+1]==1)
                        {
                            PlayRight(i,y);
                            x=1;
                            break;
                        }
                    }

                    if (B[i+1][y+1]==1)
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





    if (x==0&&randd==0)
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





    if (x==0)
    { int d,f;
        int MiniMaxCounter=0;
        for(d=0; d<R; d+=2)
        {
            for(f=1; f<C; f+=2)
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
        if (x==1){
        int BestMove=0;;
        int i;
        for (i=0; i<MiniMaxCounter; i++)
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
    if (x==0){
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

void music()
{
    if (PlayerVsComp==0)
    {
        if (Player1.Score>Player2.Score||Player2.Score>Player1.Score)
        {
            PlaySound(TEXT("Music\\win.wav"), NULL, SND_ASYNC); //winner music
        }
        else if (Player1.Score==Player2.Score)
        {
            PlaySound(TEXT("Music\\tie.wav"), NULL, SND_ASYNC); //Draw music

        }
    }


    else if (PlayerVsComp==1||PlayerVsComp==2)
    {
        if (Player1.Score>Player2.Score)
        {
            PlaySound(TEXT("Music\\win.wav"), NULL, SND_ASYNC); //winner music
        }
        else if (Player1.Score<Player2.Score)
        {
            PlaySound(TEXT("Music\\lose.wav"), NULL, SND_ASYNC); //Lose music

        }
        else if (Player1.Score==Player2.Score)
        {
            PlaySound(TEXT("Music\\tie.wav"), NULL, SND_ASYNC); //Draw music

        }
    }

}

void CursorPosition(int X1,int Y1)
{
    cord.X=X1;
    cord.Y=Y1;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),cord);

}
