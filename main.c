#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Files/players.h"
#include "Files/Playing.h"
#include "Files/Print.h"
#include "Files/Moving.h"
#include "Files/CheckBox.h"
#include "Files/Computer.h"
#include "Files/Menu.h"
#include "Files/Save&load.h"
#include "Files/Top10.h"
#include "Files/Undo&Redo.h"
int R,C,R1,C1; //R1&C1 ARE NUMBER OF DOTS HE NEEDS TO PLAY ON .... R,C ARE ROW AND COLOUMN OF THE PLAY GROUND.
int i,y; //COUNTERS FOR MOST LOOPS.
int CruR=1,CruC=0; //WHERE THE CRUSUR IS ! .. ROW AND COLOUMN
int ClcdBtn,wchSign=0,WchSignCounter=0; // BUTTON THAT THE PLAYER CLICKED ON FROM THE KEYBOARD... AND WHICH SIGN WE WILL USE - OR |
int Arrow=0,ArrowVal=1,main_choice=1,esc_choice=1,player_mode=1,game_difficulty=1,ex=1,Save_Value=1,loadValue=0,Valid_Load=1;
int backKey=0;  // MAIN MENU VARIABLES --- ARROW AND ARROWVAL FOR THE MOVING ARROW IN THE MAIN MENU
char PlayerSign; // VARIABLE TO TAKE THE PLAYER SIGN 'A' OR 'B'
int turns=0,wchPlayer=1; // NUMBER OF TURNS DURING THE GAME .. AND PLAYER 1 OR 2
int After_Game=1; // GLOBAL VARIABLE TO KNOW WHAT DID THE PLAYER CHOOSE TO DO AFTER THE GAME END
char A[20][20]; // THE PLAY GROUND.
int  B[20][20],MiniMax[100][100]; // ARRAY OF 1 AND 0 FOR SOME CHECKS.
int  RemainingDots[20][20],NumRemainningDots=0; // ARRAY TO CALCULATE THE REMAINING DOTS.
int  undoC[300],undoR[300],undoCounter=-1,undoTurns[300],Valid_Redo=0,Last_Redo=0;// ARRAYS TO SAVE EVERY MOVE'S ROW AND COLOUMN AND HOW PLAYED IT .. VARIABLES TO CHECK THE REDO AND UNDO
int sum=0; //sums up all the ones in the B array to know when the game ends.
int enter; //a key to continue.
time_t start,end; //To Calculate Time
int minute=0;
double dif=0; // VARIABLES TO CALCULATE TIME
int ValidRow,ValidColumn; // TO CHECK IF THE INPUT IS VALID OR NOT IN ADVANCED MODE
int PlayerVsComp=0;
char FileName[10];
int Played=0;
int Top10_MenuOrGame=0;
time_t start1,end1; //To Calculate Time
int minute1=0;
double dif1=0;
int ValidPlace=1;
int Num_Of_Players=2;
int language=0,minPassed=0;


//-----------------------------------------Players Stucture ----------------------------------
struct Players Player1;
struct Players Player2;
// initialize the structure values
struct Players Player1 =
{
    .Score=0,
    .Played_Moves=0,
    .Player_Sign='A',
    .Player_Color=14
};
struct Players Player2 =
{
    .Score=0,
    .Played_Moves=0,
    .Player_Sign='B',
    .Player_Color=11
};
struct Players Player3 =
{
    .Score=0,
    .Played_Moves=0,
    .Player_Sign='C',
    .Player_Color=13
};
struct Players Player4 =
{
    .Score=0,
    .Played_Moves=0,
    .Player_Sign='D',
    .Player_Color=9
};
struct COORD
{
    int x;
    int y;
};
COORD cord;
// to set the console position and size on screen
void SetSizeOfScreen()
{
    //Get the window console handle(isn't the right code but works for these sample
    HWND ConsoleWindow;
    ConsoleWindow=GetForegroundWindow();

    //Getting the desktop hadle and rectangule
    HWND   hwndScreen;
    RECT   rectScreen;
    hwndScreen=GetDesktopWindow ();
    GetWindowRect(hwndScreen,&rectScreen);

    //Set windows size(see the width problem)
    SetWindowPos (ConsoleWindow,NULL,0,0,1400,650, SWP_SHOWWINDOW);

    // Get the current width and height of the console
    RECT rConsole;
    GetWindowRect (ConsoleWindow,&rConsole);
    int Width = rConsole.left = rConsole.right;
    int Height = rConsole.bottom - rConsole.top;

    //caculate the window console to center of the screen
    int ConsolePosX;
    int ConsolePosY;
    ConsolePosX = ((rectScreen.right-rectScreen.left)/2-Width/2 );
    ConsolePosY = ((rectScreen.bottom-rectScreen.top)/2- Height/2 );
    SetWindowPos(ConsoleWindow,NULL,ConsolePosX,ConsolePosY, Width, Height, SWP_SHOWWINDOW || SWP_NOSIZE);

}
// ----------------------------------- THE MAIN FUNCTION-------------------------------------
void main()
{
    SetSizeOfScreen();
    SetConsoleTitle("Dots And Boxes Game"); // TO MAKE TITLE FOR THE GAME .
    Language();
    PlaySound(TEXT("Music\\Upbeat Ukulele Background Music - That Positive Feeling by Alumo.wav"), NULL,SND_LOOP | SND_ASYNC); //menu music

VoidMenu:
    start_menu();
    if(loadValue==0) // if its a new game not loaded one
    {
        R=R1*2-1; // adding places for the -
        C=C1*2-1; // adding places for the |
        Reset_After_Game();
Play_Again:
        //---------------------------arranging the play ground----------------------------------
        Arranging_Play_Ground(R,C);
        //---------------------------HERE THE GAME STARTS 3:)----------------------------------
        system("cls");
        endgame(&sum);
        Calculate_Remainning_Dots(CruR,CruC);
    }

    PlaySound(NULL,NULL,NULL); //TO STOP THE MUSIC AFTER THE GAME END
    PlaySound(TEXT("Music\\Happy Background Music - Sunny Side Up by Alumo.wav"), NULL, SND_LOOP | SND_ASYNC); //game music
    Print(); // PRINT THE PLAYGROUND WITHOUT ANYTHING
    Playing();
    PlaySound(NULL,NULL,NULL); //TO STOP THE MUSIC AFTER THE GAME END
    music(); // play sound after game
    winner();
    top10();
    Top10_MenuOrGame=1;
    system("cls");
    Reset_Color();
    Show_Top10();
    if (language==1)
    {
        printf("\n\n\n\t\t\t\t\t Please Press Any Button To Continue.");
    }
    else if (language==2)
    {
        printf("\n\n\n\t\t\t\t\t Presione cualquier boton para continuar.");
    }
    else if (language==3)
    {
        printf("\n\n\n\t\t\t\t\t Bitte drucken Sie eine beliebige Taste, um fortzufahren.");
    }
    else if (language==4)
    {
        printf("\n\n\n\t\t\t\t\t Druk op een willekeurige knop om verder te gaan.");
    }
    else if (language==5)
    {
        printf("\n\n\n\t\t\t\t\t Si prega di premere qualsiasi pulsante per continuare.");
    }

    getche();
    Top10_MenuOrGame=0;
    PlaySound(TEXT("Music\\Upbeat Ukulele Background Music - That Positive Feeling by Alumo.wav"), NULL, SND_ASYNC); //menu music
    aftergame();
    if (After_Game==1)
    {
        Reset_After_Game();
        PlaySound(TEXT("Music\\Happy Background Music - Sunny Side Up by Alumo.wav"), NULL, SND_LOOP | SND_ASYNC); //game music
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
            Player3.Player_Info[i][y]=0;
            Player4.Player_Info[i][y]=0;
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
//---------------------------FUNCTION THAT CHECK WHICH PLAYER SHOULD TAKE THIS TURN AND PLAY ----------------------------------
void wchPlayerMove(int NumOfPlayers)
{
    turns++;
    if(turns%NumOfPlayers==0)
    {
        wchPlayer=1;
        PlayerSign='A';
    }
    else if(turns%NumOfPlayers==1)
    {
        wchPlayer=2;
        PlayerSign='B';
    }
    else if(turns%NumOfPlayers==2)
    {
        wchPlayer=3;
        PlayerSign='C';
    }
    else if(turns%NumOfPlayers==3)
    {
        wchPlayer=4;
        PlayerSign='D';
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
    Player3.Played_Moves=0;
    Player3.Score=0;
    Player4.Played_Moves=0;
    Player4.Score=0;
    minute=0;
    dif=0;
    CruC=0;
    CruR=1;
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

//to save the played move of every player to mange the color in the printing
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
    else if (wchPlayer==3)
    {
        Player3.Player_Info[i][y]=1;
    }
    else if (wchPlayer==4)
    {
        Player4.Player_Info[i][y]=1;
    }
}
// to print the line with the player's color
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
    else if(Player3.Player_Info[i][y]==1)
    {
        Change_Color(Player3.Player_Color);
    }
    else if(Player3.Player_Info[i][y]==2)
    {
        Change_Color(Player3.Player_Color*17+1);
    }
    else if(Player4.Player_Info[i][y]==1)
    {
        Change_Color(Player4.Player_Color);
    }
    else if(Player4.Player_Info[i][y]==2)
    {
        Change_Color(Player4.Player_Color*17+1);
    }
}
//----------------------------calculate number of remaining lines -----------------------//
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
    if ( Player1.Score > Player2.Score &&Player1.Score > Player3.Score &&Player1.Score > Player4.Score )
    {
        Change_Color(Player1.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score (WINNER): %d",Player1.Name,Player1.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion (GANADOR): %d",Player1.Name,Player1.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis (GEWINNER): %d",Player1.Name,Player1.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score (WINNAAR): %d",Player1.Name,Player1.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto (VINCITORE): %d",Player1.Name,Player1.Score);
        }
        Change_Color(Player2.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player2.Name,Player2.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player2.Name,Player2.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player2.Name,Player2.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player2.Name,Player2.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player2.Name,Player2.Score);
        }
        Reset_Color();

        if (Num_Of_Players>2)
        {
            Change_Color(Player3.Player_Color);
            if(language==1)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player3.Name,Player3.Score);
            }
            if(language==2)
            {
                printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player3.Name,Player3.Score);
            }
            if(language==3)
            {
                printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player3.Name,Player3.Score);
            }
            if(language==4)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player3.Name,Player3.Score);
            }
            if(language==5)
            {
                printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player3.Name,Player3.Score);
            }
        }
        if (Num_Of_Players==4)
        {
            Change_Color(Player4.Player_Color);
            if(language==1)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player4.Name,Player4.Score);
            }
            if(language==2)
            {
                printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player4.Name,Player4.Score);
            }
            if(language==3)
            {
                printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player4.Name,Player4.Score);
            }
            if(language==4)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player4.Name,Player4.Score);
            }
            if(language==5)
            {
                printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player4.Name,Player4.Score);
            }
        }
        Reset_Color();

    }
    else if ( Player2.Score > Player1.Score &&Player2.Score > Player3.Score &&Player2.Score > Player4.Score )
    {
        Change_Color(Player2.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score (WINNER): %d",Player2.Name,Player2.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion (GANADOR): %d",Player2.Name,Player2.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis (GEWINNER): %d",Player2.Name,Player2.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score (WINNAAR): %d",Player2.Name,Player2.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto (VINCITORE): %d",Player2.Name,Player2.Score);
        }
        Change_Color(Player1.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player1.Name,Player1.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player1.Name,Player1.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player1.Name,Player1.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player1.Name,Player1.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player1.Name,Player1.Score);
        }
        Reset_Color();
        if (Num_Of_Players>2)
        {
            Change_Color(Player3.Player_Color);
            if(language==1)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player3.Name,Player3.Score);
            }
            if(language==2)
            {
                printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player3.Name,Player3.Score);
            }
            if(language==3)
            {
                printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player3.Name,Player3.Score);
            }
            if(language==4)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player3.Name,Player3.Score);
            }
            if(language==5)
            {
                printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player3.Name,Player3.Score);
            }
        }
        if (Num_Of_Players==4)
        {
            Change_Color(Player4.Player_Color);
            if(language==1)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player4.Name,Player4.Score);
            }
            if(language==2)
            {
                printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player4.Name,Player4.Score);
            }
            if(language==3)
            {
                printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player4.Name,Player4.Score);
            }
            if(language==4)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player4.Name,Player4.Score);
            }
            if(language==5)
            {
                printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player4.Name,Player4.Score);
            }
            Reset_Color();
        }
    }
    else if ( Player3.Score > Player2.Score &&Player3.Score > Player1.Score &&Player3.Score > Player4.Score )
    {
        Change_Color(Player3.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score (WINNER): %d",Player3.Name,Player3.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion (GANADOR): %d",Player3.Name,Player3.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis (GEWINNER): %d",Player3.Name,Player3.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score (WINNAAR): %d",Player3.Name,Player3.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto (VINCITORE): %d",Player3.Name,Player3.Score);
        }
        Change_Color(Player2.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player2.Name,Player2.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player2.Name,Player2.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player2.Name,Player2.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player2.Name,Player2.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player2.Name,Player2.Score);
        }
        Reset_Color();
        Change_Color(Player1.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player1.Name,Player1.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player1.Name,Player1.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player1.Name,Player1.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player1.Name,Player1.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player1.Name,Player1.Score);
        }
        if (Num_Of_Players==4)
        {
            Change_Color(Player4.Player_Color);
            if(language==1)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player4.Name,Player4.Score);
            }
            if(language==2)
            {
                printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player4.Name,Player4.Score);
            }
            if(language==3)
            {
                printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player4.Name,Player4.Score);
            }
            if(language==4)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player4.Name,Player4.Score);
            }
            if(language==5)
            {
                printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player4.Name,Player4.Score);
            }
        }
    }
    else if ( Player4.Score > Player2.Score &&Player4.Score > Player3.Score &&Player4.Score > Player1.Score )
    {
        Change_Color(Player4.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score (WINNER): %d",Player4.Name,Player4.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion (GANADOR): %d",Player4.Name,Player4.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis (GEWINNER): %d",Player4.Name,Player4.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score (WINNAAR): %d",Player4.Name,Player4.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto (VINCITORE): %d",Player4.Name,Player4.Score);
        }
        Change_Color(Player2.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player2.Name,Player2.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player2.Name,Player2.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player2.Name,Player2.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player2.Name,Player2.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player2.Name,Player2.Score);
        }
        Reset_Color();
        Change_Color(Player3.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player3.Name,Player3.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player3.Name,Player3.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player3.Name,Player3.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player3.Name,Player3.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player3.Name,Player3.Score);
        }
        Change_Color(Player1.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player1.Name,Player1.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player1.Name,Player1.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player1.Name,Player1.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player1.Name,Player1.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player1.Name,Player1.Score);
        }
        Reset_Color();
    }
    else
    {
        Change_Color(Player1.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player1.Name,Player1.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player1.Name,Player1.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player1.Name,Player1.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player1.Name,Player1.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player1.Name,Player1.Score);
        }
        Change_Color(Player2.Player_Color);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player2.Name,Player2.Score);
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player2.Name,Player2.Score);
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player2.Name,Player2.Score);
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t %s's score: %d",Player2.Name,Player2.Score);
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player2.Name,Player2.Score);
        }
        Reset_Color();
        Change_Color(Player3.Player_Color);
        if (Num_Of_Players>2)
        {
            if(language==1)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player3.Name,Player3.Score);
            }
            if(language==2)
            {
                printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player3.Name,Player3.Score);
            }
            if(language==3)
            {
                printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player3.Name,Player3.Score);
            }
            if(language==4)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player3.Name,Player3.Score);
            }
            if(language==5)
            {
                printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player3.Name,Player3.Score);
            }
        }
        if (Num_Of_Players==4)
        {
            Change_Color(Player4.Player_Color);
            if(language==1)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player4.Name,Player4.Score);
            }
            if(language==2)
            {
                printf("\n\n\t\t\t\t\t\t %s's Puntuacion: %d",Player4.Name,Player4.Score);
            }
            if(language==3)
            {
                printf("\n\n\t\t\t\t\t\t %s's Ergebnis: %d",Player4.Name,Player4.Score);
            }
            if(language==4)
            {
                printf("\n\n\t\t\t\t\t\t %s's score: %d",Player4.Name,Player4.Score);
            }
            if(language==5)
            {
                printf("\n\n\t\t\t\t\t\t %s's Punto: %d",Player4.Name,Player4.Score);
            }
        }
        Reset_Color();
        printf("\n\t\t\t\t\t\t\t  DRAW! ");
    }
    if (language==1)
    {
        printf("\n\n\t\t\t\t\t\t   press Enter to continue ");
    }
    else if (language==2)
    {
        printf("\n\n\t\t\t\t\t\t   presione enter para continuar ");
    }
    else if (language==3)
    {
        printf("\n\n\t\t\t\t\t\t   Drucken Sie Enter, um fortzufahren ");
    }
    else if (language==4)
    {
        printf("\n\n\t\t\t\t\t\t   druk op enter om verder te gaan ");
    }
    else if (language==5)
    {
        printf("\n\n\t\t\t\t\t\t   premere Invio per continuare ");
    }

    enter=getche();
    if(enter==13)
    {
    }
    else
    {
        goto Winner;
    }
}
//---------------------------------------After the game ends--------------------------//
void aftergame()
{
    After_Game=1;
    system("cls");
after:
    system("cls");
    if(language==1)
    {
        switch(After_Game)
        {
        case 1:
            Change_Color(10);
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Play again");
            Reset_Color();
            printf("\n\n \t\t\t\t\t\t\t2-Go back to menu");
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Play again\n\n \t\t\t\t\t\t");
            Change_Color(10);
            printf("----->2-Go back to menu");
            Reset_Color();
            break;
        }
    }
    if(language==2)
    {
        switch(After_Game)
        {
        case 1:
            Change_Color(10);
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Juega de nuevo");
            Reset_Color();
            printf("\n\n \t\t\t\t\t\t\t2-Volver al menu");
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Juega de nuevo\n\n \t\t\t\t\t\t");
            Change_Color(10);
            printf("----->2-Volver al menu");
            Reset_Color();
            break;
        }
    }
    if(language==3)
    {
        switch(After_Game)
        {
        case 1:
            Change_Color(10);
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Spiel nochmal");
            Reset_Color();
            printf("\n\n \t\t\t\t\t\t\t2-Gehe zuruck zum Menu");
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Spiel nochmal\n\n \t\t\t\t\t\t");
            Change_Color(10);
            printf("----->2-Gehe zuruck zum Menu");
            Reset_Color();
            break;
        }
    }
    if(language==4)
    {
        switch(After_Game)
        {
        case 1:
            Change_Color(10);
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Speel opnieuw");
            Reset_Color();
            printf("\n\n \t\t\t\t\t\t\t2-Ga terug naar het menu");
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Speel opnieuw\n\n \t\t\t\t\t\t");
            Change_Color(10);
            printf("----->2-Ga terug naar het menu");
            Reset_Color();
            break;
        }
    }
    if(language==5)
    {
        switch(After_Game)
        {
        case 1:
            Change_Color(10);
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Gioca di nuovo");
            Reset_Color();
            printf("\n\n \t\t\t\t\t\t\t2-Torna al menu");
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Gioca di nuovo\n\n \t\t\t\t\t\t");
            Change_Color(10);
            printf("----->2-Torna al menu");
            Reset_Color();
            break;
        }
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
    else if (wchPlayer==3)
    {
        Beep(400,120);
    }
    else if (wchPlayer==4)
    {
        Beep(500,120);
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

//play music after game
void music()
{
    if (PlayerVsComp==0)
    {
        if (Num_Of_Players==2)
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
        else
        {
            if (Player1.Score==Player2.Score&&Player2.Score==Player3.Score&&Player3.Score==Player4.Score)
            {
                PlaySound(TEXT("Music\\tie.wav"), NULL, SND_ASYNC); //Draw music

            }
            else if (Player1.Score==Player2.Score&&Player2.Score==Player3.Score&&Num_Of_Players==3)
            {
                PlaySound(TEXT("Music\\tie.wav"), NULL, SND_ASYNC); //Draw music

            }
            else if (Player1.Score==Player2.Score&&Player3.Score==Player4.Score)
            {
                PlaySound(TEXT("Music\\tie.wav"), NULL, SND_ASYNC); //Draw music

            }
            else if (Player1.Score==Player3.Score&&Player2.Score==Player4.Score)
            {
                PlaySound(TEXT("Music\\tie.wav"), NULL, SND_ASYNC); //Draw music

            }
            else if (Player1.Score==Player4.Score&&Player3.Score==Player2.Score)
            {
                PlaySound(TEXT("Music\\tie.wav"), NULL, SND_ASYNC); //Draw music

            }
            else if (Player1.Score>Player2.Score&&Player1.Score>Player3.Score&&Player1.Score>Player4.Score)
            {
                PlaySound(TEXT("Music\\win.wav"), NULL, SND_ASYNC); //winner music
            }
            else if (Player2.Score>Player1.Score&&Player2.Score>Player3.Score&&Player2.Score>Player4.Score)
            {
                PlaySound(TEXT("Music\\win.wav"), NULL, SND_ASYNC); //winner music
            }
            else if (Player3.Score>Player2.Score&&Player3.Score>Player1.Score&&Player3.Score>Player4.Score)
            {
                PlaySound(TEXT("Music\\win.wav"), NULL, SND_ASYNC); //winner music
            }
            else if (Player4.Score>Player2.Score&&Player4.Score>Player1.Score&&Player4.Score>Player3.Score)
            {
                PlaySound(TEXT("Music\\win.wav"), NULL, SND_ASYNC); //winner music
            }


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

void Language()
{
    ArrowVal=1;
lang:
    Print_Logo(0);
    // CursorPosition(55,5);
    //printf("LANGUAGE");
    //CursorPosition(0,0);
    switch(ArrowVal)
    {

    case 1:
        Change_Color(10);
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-English");
        Reset_Color();
        printf("\n\n \t\t\t\t\t\t\t2-Spanish \n \n\t\t\t\t\t\t\t3-German \n\n \t\t\t\t\t\t\t4-Dutch\n\n \t\t\t\t\t\t\t5-Italian\n");
        break;
    case 2:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-English\n\n \t\t\t\t\t\t");
        Change_Color(10);
        printf("----->2-Spanish ");
        Reset_Color();
        printf("\n \n\t\t\t\t\t\t\t3-German \n\n \t\t\t\t\t\t\t4-Dutch\n\n \t\t\t\t\t\t\t5-Italian\n");
        break;
    case 3:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-English\n\n \t\t\t\t\t\t\t2-Spanish \n \n\t\t\t\t\t\t");
        Change_Color(10);
        printf("----->3-German ");
        Reset_Color();
        printf("\n\n \t\t\t\t\t\t\t4-Dutch\n\n \t\t\t\t\t\t\t5-Italian\n");
        break;
    case 4:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-English\n\n \t\t\t\t\t\t\t2-Spanish \n \n\t\t\t\t\t\t\t3-German \n\n \t\t\t\t\t\t");
        Change_Color(10);
        printf("----->4-Dutch");
        Reset_Color();
        printf("\n\n \t\t\t\t\t\t\t5-Italian\n");
        break;
    case 5:
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-English\n\n \t\t\t\t\t\t\t2-Spanish \n \n\t\t\t\t\t\t\t3-German \n\n \t\t\t\t\t\t\t4-Dutch\n\n \t\t\t\t\t\t");
        Change_Color(10);
        printf("----->5-Italian\n");
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
        goto lang;
        break;
    case 80: // DOWN
        if(ArrowVal<5)
        {
            Beep(300,70);
            ArrowVal++;
            main_choice++;
        }
        goto lang;
        break;
    case 13 : // ENTER
        Beep(130,120);
        break;
    default:
        goto lang;
    }

    switch(main_choice)
    {

    case 1:
        language=1;
        main_choice=1;
        break;
    case 2:
        language=2;
        main_choice=1;
        break;
    case 3:
        language=3;
        main_choice=1;
        break;
    case 4:
        language=4;
        main_choice=1;
        break;
    case 5:
        language=5;
        main_choice=1;
        break;
    }
}
