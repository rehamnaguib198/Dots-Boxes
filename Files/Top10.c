#include <stdio.h>
#include "Top10.h"

struct Top{
char Name[100];
int Score;
};
struct Top top_players[100];


void top10 ()
{
    char Name[1000];
    int score,newP1=0,newP2=0,newP3=0,newP4=0;
    FILE * fpointer1;
    FILE * fpointer2;
    fpointer1=fopen("Top 10\\Top_10.txt","r");
    fpointer2=fopen("Top 10\\Top_10-1.txt","w");

    while (fscanf(fpointer1,"%[^~]~%i×",Name,&score)!=EOF)
    {
            if (Player1.Score>=Player2.Score&&Player1.Score>=Player3.Score&&Player1.Score>=Player4.Score&&!strcmp(Name,Player1.Name)){

                newP1=1;
                if(Player1.Score>score)
                {
                    score=Player1.Score;
                }
        }
            else if (Player2.Score>=Player1.Score&&Player2.Score>=Player3.Score&&Player2.Score>=Player4.Score&&!strcmp(Name,Player2.Name)){

                newP2=1;
                if(Player2.Score>score)
                {
                    score=Player2.Score;
                }

        }
            else if (Num_Of_Players>2&&Player3.Score>=Player1.Score&&Player3.Score>=Player4.Score&&Player3.Score>=Player2.Score&&!strcmp(Name,Player3.Name)){

                newP3=1;
                if(Player3.Score>score)
                {
                    score=Player3.Score;
                }

        }
            else if (Num_Of_Players==4&&Player4.Score>=Player1.Score&&Player4.Score>=Player3.Score&&Player4.Score>=Player2.Score&&!strcmp(Name,Player4.Name)){

                newP4=1;
                if(Player4.Score>score)
                {
                    score=Player4.Score;
                }

        }
        fprintf(fpointer2,"%s~%i×",Name,score);

    }
    fclose(fpointer2);
    fclose(fpointer1);
    if(newP1==0&&Player1.Score>=Player2.Score&&Player1.Score>=Player3.Score&&Player1.Score>=Player4.Score)
    {
        fpointer2=fopen("Top 10\\Top_10-1.txt","a");
        fprintf(fpointer2,"%s~%i×",Player1.Name,Player1.Score);
        fclose(fpointer2);
    }
    if(newP2==0&&PlayerVsComp==0&&Player2.Score>=Player1.Score&&Player2.Score>=Player3.Score&&Player2.Score>=Player4.Score)
    {
        fpointer2=fopen("Top 10\\Top_10-1.txt","a");
        fprintf(fpointer2,"%s~%i×",Player2.Name,Player2.Score);
        fclose(fpointer2);
    }
    if(Num_Of_Players>2&&newP3==0&&PlayerVsComp==0&&Player3.Score>=Player1.Score&&Player3.Score>=Player4.Score&&Player3.Score>=Player2.Score)
    {
        fpointer2=fopen("Top 10\\Top_10-1.txt","a");
        fprintf(fpointer2,"%s~%i×",Player3.Name,Player3.Score);
        fclose(fpointer2);
    }
    if(Num_Of_Players==4&&newP4==0&&PlayerVsComp==0&&Player4.Score>=Player1.Score&&Player4.Score>=Player3.Score&&Player4.Score>=Player2.Score)
    {
        fpointer2=fopen("Top 10\\Top_10-1.txt","a");
        fprintf(fpointer2,"%s~%i×",Player4.Name,Player4.Score);
        fclose(fpointer2);
    }
    fpointer1=fopen("Top 10\\Top_10.txt","w");
    fpointer2=fopen("Top 10\\Top_10-1.txt","r");

    while (fscanf(fpointer2,"%[^~]~%i×",Name,&score)!=EOF)
    {
        fprintf(fpointer1,"%s~%i×",Name,score);
    }
    fclose(fpointer2);
    fclose(fpointer1);

}



void Show_Top10()
{
    int i=0;
    struct Top temp;
    FILE *fpointer1;
    fpointer1=fopen("Top 10\\Top_10.txt","r");
    while (fscanf(fpointer1,"%[^~]~%i×",top_players[i].Name,&top_players[i].Score)!=EOF)
    {
        i++;
    }

    for(int y=0; y<i; y++)
    {
        for(int j=y+1; j<i;)
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
    CursorPosition(54,5);
    if(language==1){
    printf("Players Ranks");
    }
    if(language==2){
    printf("Rangos de jugadores");
    }
    if(language==3){
    printf("Spieler rangiert");
    }
    if(language==4){
    printf("klassement");
    }
    if(language==5){
    printf("Classifica dei giocatori");
    }
    CursorPosition(45,7);
    if(language==1){
    printf("Name");
    }
    else if(language==2){
    printf("Nombre");
    }
    else if(language==3){
    printf("Name");
    }
    else if(language==4){
    printf("Naam");
    }
    else if(language==5){
    printf("Nome");
    }
    CursorPosition(64,7);
    printf("|");
    CursorPosition(74,7);
    if(language==1){
    printf("Score");
    }
    else if(language==2){
    printf("Puntuacion");
    }
   else if(language==3){
    printf("Ergebnis");
    }
   else if(language==4){
    printf("Score");
    }
   else if(language==5){
    printf("Punto");
    }
    CursorPosition(40,8);
    printf("----------------------------------------");

    for(int y=0; y<i; y++)
    {
        if (y<10){
            if (Player1.Score>=Player2.Score&&Player1.Score>=Player3.Score&&Player1.Score>=Player4.Score&&Top10_MenuOrGame==1&&!strcmp(top_players[y].Name,Player1.Name)){
                    Change_Color(Player1.Player_Color);
            }
            else if (Player2.Score>=Player1.Score&&Player2.Score>=Player3.Score&&Player2.Score>=Player4.Score&&Top10_MenuOrGame==1&&!strcmp(top_players[y].Name,Player2.Name)){
                    Change_Color(Player2.Player_Color);
            }
            else if (Num_Of_Players>2&&Player3.Score>=Player1.Score&&Player3.Score>=Player4.Score&&Player3.Score>=Player2.Score&&Top10_MenuOrGame==1&&!strcmp(top_players[y].Name,Player3.Name)){
                    Change_Color(Player3.Player_Color);
            }
            else if (Num_Of_Players==4&&Player4.Score>=Player1.Score&&Player4.Score>=Player3.Score&&Player4.Score>=Player2.Score&&Top10_MenuOrGame==1&&!strcmp(top_players[y].Name,Player4.Name)){
                    Change_Color(Player4.Player_Color);
            }
            CursorPosition(41,9+y);
            printf("%i-%.19s",y+1,top_players[y].Name);
            CursorPosition(75,9+y);
            printf("%i",top_players[y].Score);
            Reset_Color();
            CursorPosition(64,9+y);
            printf("|");
        }
        else {
            if (Player1.Score>=Player2.Score&&Player1.Score>=Player3.Score&&Player1.Score>=Player4.Score&&Top10_MenuOrGame==1&&!strcmp(top_players[y].Name,Player1.Name)){
                CursorPosition(41,20);
                Change_Color(Player1.Player_Color);
                printf("%i-%.19s",y+1,top_players[y].Name);
                CursorPosition(75,20);
                printf("%i",top_players[y].Score);
                Reset_Color();
                CursorPosition(64,26);
        }
            else if (Player2.Score>=Player1.Score&&Player2.Score>=Player3.Score&&Player2.Score>=Player4.Score&&Top10_MenuOrGame==1&&!strcmp(top_players[y].Name,Player2.Name)){
                    CursorPosition(41,21);
                    Change_Color(Player2.Player_Color);
                    printf("%i-%.19s",y+1,top_players[y].Name);
                    CursorPosition(75,21);
                    printf("%i",top_players[y].Score);
                    Reset_Color();
                    CursorPosition(64,26);

            }
            else if (Num_Of_Players>2&&Player3.Score>=Player1.Score&&Player3.Score>=Player4.Score&&Player3.Score>=Player2.Score&&Top10_MenuOrGame==1&&!strcmp(top_players[y].Name,Player3.Name)){
                    CursorPosition(41,22);
                    Change_Color(Player3.Player_Color);
                    printf("%i-%.19s",y+1,top_players[y].Name);
                    CursorPosition(75,22);
                    printf("%i",top_players[y].Score);
                    Reset_Color();
                    CursorPosition(64,26);

            }
            else if (Num_Of_Players==4&&Player4.Score>=Player1.Score&&Player4.Score>=Player3.Score&&Player4.Score>=Player2.Score&&Top10_MenuOrGame==1&&!strcmp(top_players[y].Name,Player4.Name)){
                    CursorPosition(41,23);
                    Change_Color(Player4.Player_Color);
                    printf("%i-%.19s",y+1,top_players[y].Name);
                    CursorPosition(75,23);
                    printf("%i",top_players[y].Score);
                    Reset_Color();
                    CursorPosition(64,26);

            }
    }
}
}
