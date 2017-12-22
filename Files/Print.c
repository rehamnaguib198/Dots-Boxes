#include "Print.h"
#include <Windows.h>

void Print()
{
    //Print Names
    int x1,x2,x3,x4;
    if (Num_Of_Players==2)
    {
        x1=30;
        x3=85;
    }
    else if (Num_Of_Players==4||Num_Of_Players==3)
    {
        x1=10,x2=85;
        x4=115,x3=40;
    }
    CursorPosition(x1,1);
    Change_Color(Player1.Player_Color);
    printf("%.20s",Player1.Name);
    Reset_Color();
    if (Num_Of_Players>2)
    {
        CursorPosition(x2,1);
        Change_Color(Player3.Player_Color);
        printf("%.20s",Player3.Name);
        Reset_Color();
    }
    CursorPosition(x3,1);
    Change_Color(Player2.Player_Color);
    printf("%.20s",Player2.Name);
    Reset_Color();

    if (Num_Of_Players==4)
    {
        CursorPosition(x4,1);
        Change_Color(Player4.Player_Color);
        printf("%.20s",Player4.Name);
        Reset_Color();
    }
//Print Score
    CursorPosition(x1,3);
    Change_Color(Player1.Player_Color);
    if(language==1)
    {
        printf("Score:%i",Player1.Score);
    }
    else if(language==2)
    {
        printf("Puntuacion:%i",Player1.Score);
    }
    else if(language==3)
    {
        printf("Ergebnis:%i",Player1.Score);
    }
    else if(language==4)
    {
        printf("Score:%i",Player1.Score);
    }
    else if(language==5)
    {
        printf("Punto:%i",Player1.Score);
    }
    Reset_Color();
    if (Num_Of_Players>2)
    {
        CursorPosition(x2,3);
        Change_Color(Player3.Player_Color);
        if(language==1)
        {
            printf("Score:%i",Player3.Score);
        }
        else if(language==2)
        {
            printf("Puntuacion:%i",Player3.Score);
        }
        else if(language==3)
        {
            printf("Ergebnis:%i",Player3.Score);
        }
        else if(language==4)
        {
            printf("Score:%i",Player3.Score);
        }
        else if(language==5)
        {
            printf("Punto:%i",Player3.Score);
        }
        Reset_Color();
    }
    CursorPosition(x3,3);
    Change_Color(Player2.Player_Color);
    if(language==1)
    {
        printf("Score:%i",Player2.Score);
    }
    else if(language==2)
    {
        printf("Puntuacion:%i",Player2.Score);
    }
    else if(language==3)
    {
        printf("Ergebnis:%i",Player2.Score);
    }
    else if(language==4)
    {
        printf("Score:%i",Player2.Score);
    }
    else if(language==5)
    {
        printf("Punto:%i",Player2.Score);
    }
    Reset_Color();

    if (Num_Of_Players==4)
    {
        CursorPosition(x4,3);
        Change_Color(Player4.Player_Color);
        if(language==1)
        {
            printf("Score:%i",Player4.Score);
        }
        else if(language==2)
        {
            printf("Puntuacion:%i",Player4.Score);
        }
        else if(language==3)
        {
            printf("Ergebnis:%i",Player4.Score);
        }
        else if(language==4)
        {
            printf("Score:%i",Player4.Score);
        }
        else if(language==5)
        {
            printf("Punto:%i",Player4.Score);
        }
        Reset_Color();
    }
//Print Moves

    CursorPosition(x1,4);
    Change_Color(Player1.Player_Color);
    if(language==1)
    {
        printf("Moves:%i",Player1.Played_Moves);
    }
    else if(language==2)
    {
        printf("movimientos:%i",Player1.Played_Moves);
    }
    else if(language==3)
    {
        printf("Bewegung:%i",Player1.Played_Moves);
    }
    else if(language==4)
    {
        printf("zetten:%i",Player1.Played_Moves);
    }
    else if(language==5)
    {
        printf("movimento:%i",Player1.Played_Moves);
    }
    Reset_Color();
    if (Num_Of_Players>2)
    {
        CursorPosition(x2,4);
        Change_Color(Player3.Player_Color);
        if(language==1)
        {
            printf("Moves:%i",Player3.Played_Moves);
        }
        else if(language==2)
        {
            printf("movimientos:%i",Player3.Played_Moves);
        }
        else if(language==3)
        {
            printf("Bewegung:%i",Player3.Played_Moves);
        }
        else if(language==4)
        {
            printf("zetten:%i",Player3.Played_Moves);
        }
        else if(language==5)
        {
            printf("movimento:%i",Player3.Played_Moves);
        }
        Reset_Color();
    }
    CursorPosition(x3,4);
    Change_Color(Player2.Player_Color);
    if(language==1)
    {
        printf("Moves:%i",Player2.Played_Moves);
    }
    else if(language==2)
    {
        printf("movimientos:%i",Player2.Played_Moves);
    }
    else if(language==3)
    {
        printf("Bewegung:%i",Player2.Played_Moves);
    }
    else if(language==4)
    {
        printf("zetten:%i",Player2.Played_Moves);
    }
    else if(language==5)
    {
        printf("movimento:%i",Player2.Played_Moves);
    }
    Reset_Color();

    if (Num_Of_Players==4)
    {
        CursorPosition(x4,4);
        Change_Color(Player4.Player_Color);
        if(language==1)
        {
            printf("Moves:%i",Player4.Played_Moves);
        }
        else if(language==2)
        {
            printf("movimientos:%i",Player4.Played_Moves);
        }
        else if(language==3)
        {
            printf("Bewegung:%i",Player4.Played_Moves);
        }
        else if(language==4)
        {
            printf("zetten:%i",Player4.Played_Moves);
        }
        else if(language==5)
        {
            printf("movimento:%i",Player4.Played_Moves);
        }
        Reset_Color();
    }
//Print Time&Turns
    if(dif>=60)
    {
        minute++;
        dif-=60;
    }
    CursorPosition(54,2);
    Change_Color(10);
    if(language==1)
    {
        printf("TIME IS :%i:%.2lf",minute,dif);
    }
    else if(language==2)
    {
        printf("el tiempo es :%i:%.2lf",minute,dif);
    }
    else if(language==3)
    {
        printf("Zeit ist :%i:%.2lf",minute,dif);
    }
    else if(language==4)
    {
        printf("gespeelde tijd :%i:%.2lf",minute,dif);
    }
    else if(language==5)
    {
        printf("il tempo è :%i:%.2lf",minute,dif);
    }
    Reset_Color();
    CursorPosition(53,3);
    Change_Color(10);
    if(language==1)
    {
        printf("remaining lines: %i",sum);
    }
    else if(language==2)
    {
        printf("lineas restantes: %i",sum);
    }
    else if(language==3)
    {
        printf("verbleibende Zeilen: %i",sum);
    }
    else if(language==4)
    {
        printf("resterende regels: %i",sum);
    }
    else if(language==5)
    {
        printf("linee rimanenti: %i",sum);
    }
    Reset_Color();

    printf("\n\n"); // TO MAE MAKE THE GAME START IN THE MIDDLE OF THE SCREEN
    if(wchPlayer==1)
    {
        Change_Color(14);
        if(language==1)
        {
            printf("\t\t\t\t\t\t    %.20s's Turn",Player1.Name);
        }
        if(language==2)
        {
            printf("\t\t\t\t\t\t    %.20s's giro",Player1.Name);
        }
        if(language==3)
        {
            printf("\t\t\t\t\t\t    %.20s's Wende",Player1.Name);
        }
        if(language==4)
        {
            printf("\t\t\t\t\t\t    %.20s's beurt",Player1.Name);
        }
        if(language==5)
        {
            printf("\t\t\t\t\t\t    %.20s's turno",Player1.Name);
        }
        if(ValidPlace==0)
        {
            CursorPosition(42,5);
            Change_Color(12);
            if(language==1)
            {
                printf("\n\t\t\t\t\t This Place Is Taken .. Play In Another Place Please.");
            }
            else if(language==2)
            {
                printf("\n\t\t\t\t\t Este lugar esta ocupado .. Juega en otro lugar, por favor.");
            }
            else if(language==3)
            {
                printf("\n\t\t\t\t\t Dieser Ort wird genommen .. Spielen Sie an einem anderen Ort bitte");
            }
            else if(language==4)
            {
                printf("\n\t\t\t\t\t op deze plaats is er al gespeeld .. speel op een andere plaats");
            }
            else if(language==5)
            {
                printf("\n\t\t\t\t\t Questo posto e preso .. Gioca in un altro posto per favore.");
            }
            CursorPosition(51,5);

        }
        Reset_Color();
    }
    else if (wchPlayer==2)
    {
        Change_Color(11);
        if(language==1)
        {
            printf("\t\t\t\t\t\t    %.20s's Turn",Player2.Name);
        }
        if(language==2)
        {
            printf("\t\t\t\t\t\t    %.20s's giro",Player2.Name);
        }
        if(language==3)
        {
            printf("\t\t\t\t\t\t    %.20s's Wende",Player2.Name);
        }
        if(language==4)
        {
            printf("\t\t\t\t\t\t    %.20s's beurt",Player2.Name);
        }
        if(language==5)
        {
            printf("\t\t\t\t\t\t    %.20s's turno",Player2.Name);
        }
        if(ValidPlace==0)
        {
            CursorPosition(42,5);
            Change_Color(12);
            if(language==1)
            {
                printf("\n\t\t\t\t\t This Place Is Taken .. Play In Another Place Please.");
            }
            else if(language==2)
            {
                printf("\n\t\t\t\t\t Este lugar esta ocupado .. Juega en otro lugar, por favor.");
            }
            else if(language==3)
            {
                printf("\n\t\t\t\t\t Dieser Ort wird genommen .. Spielen Sie an einem anderen Ort bitte");
            }
            else if(language==4)
            {
                printf("\n\t\t\t\t\t op deze plaats is er al gespeeld .. speel op een andere plaats");
            }
            else if(language==5)
            {
                printf("\n\t\t\t\t\t Questo posto e preso .. Gioca in un altro posto per favore.");
            }
            CursorPosition(51,5);
        }
        Reset_Color();
    }
    else if (wchPlayer==3)
    {
        Change_Color(Player3.Player_Color);
        if(language==1)
        {
            printf("\t\t\t\t\t\t    %.20s's Turn",Player3.Name);
        }
        if(language==2)
        {
            printf("\t\t\t\t\t\t    %.20s's giro",Player3.Name);
        }
        if(language==3)
        {
            printf("\t\t\t\t\t\t    %.20s's Wende",Player3.Name);
        }
        if(language==4)
        {
            printf("\t\t\t\t\t\t    %.20s's beurt",Player3.Name);
        }
        if(language==5)
        {
            printf("\t\t\t\t\t\t    %.20s's turno",Player3.Name);
        }
        if(ValidPlace==0)
        {
            CursorPosition(42,5);
            Change_Color(12);
            if(language==1)
            {
                printf("\n\t\t\t\t\t This Place Is Taken .. Play In Another Place Please.");
            }
            else if(language==2)
            {
                printf("\n\t\t\t\t\t Este lugar esta ocupado .. Juega en otro lugar, por favor.");
            }
            else if(language==3)
            {
                printf("\n\t\t\t\t\t Dieser Ort wird genommen .. Spielen Sie an einem anderen Ort bitte");
            }
            else if(language==4)
            {
                printf("\n\t\t\t\t\t op deze plaats is er al gespeeld .. speel op een andere plaats");
            }
            else if(language==5)
            {
                printf("\n\t\t\t\t\t Questo posto e preso .. Gioca in un altro posto per favore.");
            }
            CursorPosition(51,5);
        }
        Reset_Color();
    }
    else if (wchPlayer==4)
    {
        Change_Color(Player4.Player_Color);
        if(language==1)
        {
            printf("\t\t\t\t\t\t    %.20s's Turn",Player4.Name);
        }
        if(language==2)
        {
            printf("\t\t\t\t\t\t    %.20s's giro",Player4.Name);
        }
        if(language==3)
        {
            printf("\t\t\t\t\t\t    %.20s's Wende",Player4.Name);
        }
        if(language==4)
        {
            printf("\t\t\t\t\t\t    %.20s's beurt",Player4.Name);
        }
        if(language==5)
        {
            printf("\t\t\t\t\t\t    %.20s's turno",Player4.Name);
        }
        if(ValidPlace==0)
        {
            CursorPosition(42,5);
            Change_Color(12);
            if(language==1)
            {
                printf("\n\t\t\t\t\t This Place Is Taken .. Play In Another Place Please.");
            }
            else if(language==2)
            {
                printf("\n\t\t\t\t\t Este lugar esta ocupado .. Juega en otro lugar, por favor.");
            }
            else if(language==3)
            {
                printf("\n\t\t\t\t\t Dieser Ort wird genommen .. Spielen Sie an einem anderen Ort bitte");
            }
            else if(language==4)
            {
                printf("\n\t\t\t\t\t op deze plaats is er al gespeeld .. speel op een andere plaats");
            }
            else if(language==5)
            {
                printf("\n\t\t\t\t\t Questo posto e preso .. Gioca in un altro posto per favore.");
            }
            CursorPosition(51,5);
        }
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
                Change_Color(255);
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
                else if (A[i][y]=='C'||(A[i][y+1]=='C'&&y+1<C))
                {
                    Change_Color(Player3.Player_Color*17);
                    printf(" ");
                    Reset_Color();
                }
                else if (A[i][y]=='D'||(A[i][y+1]=='D'&&y+1<C))
                {
                    Change_Color(Player4.Player_Color*17);
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



}
