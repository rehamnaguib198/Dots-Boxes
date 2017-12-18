#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
int R,C,R1,C1; //R1&C1 ARE NUMBER OF DOTS HE NEEDS TO PLAY ON .... R,C ARE ROW AND COLOUMN OF THE PLAY GROUND.
int i,y; //COUNTERS FOR MOST LOOPS.
int P; // PLAYER NUMBER.
int CruR=1,CruC=0; //WHERE THE CRUSUR ? .. ROW AND COLOUMN
int ClcdBtn,wchSign=0; // BUTTON THAT THE PLAYER CLICKED ON FROM THE KEYBOARD... AND WHICH SIGN WE WILL USE - OR |
char main_choice,player_mode,game_difficulty,ex,backKey;
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
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t");
    for(i=0;i<=R+3;i++){
    printf("-");
}
 printf("\n\t\t\t\t\t\t\t");
    for(i=0;i<R;i++)
    { printf("| ");
        for(y=0;y<C;y++)
        {
            printf("%c",A[i][y]);
        }
        printf(" |");
    printf("\n\t\t\t\t\t\t\t");
    }
      for(i=0;i<=R+3;i++){
    printf("-");
}
}
    //---------------------------FUNCTION TO PRINT THE PLAY GROUND DURING THE GAME----------------------------------

void Print()
{
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t");
    for(i=0;i<=R+3;i++){
    printf("-");
}
    printf("\n\t\t\t\t\t\t\t");
    for(i=0;i<R;i++){
        printf("| ");
        for(y=0;y<C;y++)
        {
            if(i==CruR&&y==CruC) // IF THE CRUSUR IS HERE ... CHANGE THE COLOR AND PRINT IT .
            {
                Change_Color(5);
                printf("%c",A[i][y]);
                Reset_Color();
            }

            else // ELSE PRINT THE PLAYGROUND WITH THE ORDINARY COLOR.
            {
                printf("%c",A[i][y]);
            }
        }
        printf(" |");
        printf("\n\t\t\t\t\t\t\t");
    }
    for(i=0;i<=R+3;i++){
    printf("-");
}
    printf("\n\n");
}

    //---------------------------FUNCTION THAT MOVES THE CRUSUR AND TO PUT - AND | ----------------------------------

void Moving()
{
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

    if(wchSign==4) // IF THE SIGN IS |..
    {
        if (ClcdBtn==13) // 5 BUTTON TO USE THIS PLACE AND PUT THE SIGN .
        {
            B[CruR][CruC]=0; // MARK IT AS USED.
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
        if (ClcdBtn==13) // 5 BUTTON TO USE THIS PLACE  > .
        {
            B[CruR][CruC]=0;
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

void Check_The_Game_Limits(){
    if(CruR>=R){
        CruR-=2;
    }
    if(CruC>=C){
        CruC-=2;
    }
    if(CruR<0){
        CruR+=2;
    }
    if(CruC<0){
        CruC+=2;
    }

}

//---------------------------START MENU FUNCTION-------------------------------------------------------//
void start_menu(){
    menu:
        system("cls");
printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-How To Play \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Top 10 player\n\n \t\t\t\t\t\t\t5-Exit\n");
main_choice=getche();
switch(main_choice){
    //new game//
case 49:
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Mode:\n\n\n");
    printf("\t\t\t\t\t\t\t1-player vs computer\n\n\t\t\t\t\t\t\t2-player1 vs player2\n");
player_mode=getche();
switch(player_mode){
case 49:
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Difficulty:\n\n\n");
    printf("\t\t\t\t\t\t\t1-Beginner\n\n\t\t\t\t\t\t\t2-Expert\n\n\t\t\t\t\t\t\t3-Advanced\n");
 game_difficulty=getche();
    switch(game_difficulty){
case 49:
    R1=3,C1=3;
    break;
case 50:
    R1=5,C1=5;
    break;
case 51:
     system("cls");
    printf("Enter number of rows.\n");
    scanf("%d",&R1);
    system("cls");
    printf("Enter number of columns.\n");
    scanf("%d",&C1);
    break;
    }
case 50:
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Difficulty:\n\n\n");
    printf("\t\t\t\t\t\t\t1-Beginner\n\n\t\t\t\t\t\t\t2-Expert\n\n\t\t\t\t\t\t\t3-Advanced\n");
   game_difficulty=getche();
   switch(game_difficulty){
case 49:
    R1=3,C1=3;
    break;
case 50:
    R1=5,C1=5;
    break;
case 51:
    system("cls");
    printf("Enter number of rows.\n");
    scanf("%d",&R1);
    system("cls");
    printf("Enter number of columns.\n");
    scanf("%d",&C1);
    break;
    }
    break;
}
//how to play//
case 50:
    system("cls");
    printf("\n\n\t\t\t\t\t\t\tHow to play\n");
    printf("The two players take turns to join two adjacent dots with a horizontal or vertical line. If a player completes the fourth side of a box they initial that box and must draw another line.");
    printf("When all the boxes have been completed the winner is the player who has initialled the most boxes.\n\n\n");
    printf("\t\t\t\t\t\t\tControls:\n");
    printf("\t\t\t\t\t\t\tPress + for vertical line\n\t\t\t\t\t\t\tPress - for horizontal line\n");
    printf("\t\t\t\t\t\t\tpress 6 to go right\n\t\t\t\t\t\t\tpress 4 to go left\n\t\t\t\t\t\t\tpress 8 to go up\n \t\t\t\t\t\t\tpress 2 to go down\n");
    printf("\t\t\t\t\t\t\tpress 5 to select place");
    printf("\n\n\t\t\t\t\t\t\tpress 1 to go back to main menu");
    backKey=getche();
   while (backKey!=49){
            system("cls");
        printf("\n\n\t\t\t\t\t\tpress 1 to go back to main menu");
    backKey=getche();
    }
    if(backKey=49){
        //goto menu;
    }
    break;
    //load game//
case 51:
    printf("Not Available");
break;
//top 10 players//
case 52:
printf("Not Available");
break;
//exit//
case 53:
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tAre you sure you want to exit?\n\n\n");
    printf("\t\t\t\t\t\t\t1-YES\n\n\t\t\t\t\t\t\t2-NO\n");
    ex=getche();
    switch(ex){
case 49:
    exit(0);
case 50:
    goto menu;
    }
break;
}
}
