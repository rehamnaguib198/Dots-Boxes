#include <windows.h>
#include <stdio.h>
#include "Menu.h"

void Print_Logo(int line)
{
    system("cls");
    CursorPosition(55,2);
    Change_Color(11);
    printf("DOTS & BOXES");
    Reset_Color();
    if (line==0)
    {
        CursorPosition(0,0);
    }
}

//---------------------------START MENU FUNCTION-------------------------------------------------------//
void start_menu()
{
    ArrowVal=1;
menu:
    Print_Logo(0);

    switch(ArrowVal)
    {
        {
        case 1:
            if(language==1)
            {
                Change_Color(10);
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-New Game");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-How To Play \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Exit\n");
                break;
            }
            else if(language==2)
            {
                Change_Color(10);
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Nuevo juego");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-Como jugar \n \n\t\t\t\t\t\t\t3-Cargar juego \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Salir\n");
                break;
            }
            else if(language==3)
            {
                Change_Color(10);
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-neues Spiel");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-Spielanleitung \n \n\t\t\t\t\t\t\t3-Spiel laden \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Beenden\n");
                break;
            }
            else if(language==4)
            {
                Change_Color(10);
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Nieuw spel");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-Hoe speel je het spelregels \n \n\t\t\t\t\t\t\t3-Spel laden \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-spel verlaten\n");
                break;
            }
            else if(language==5)
            {
                Change_Color(10);
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Nuovo gioco");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-Come giocare \n \n\t\t\t\t\t\t\t3-Caricare il gioco \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Uscire\n");
                break;
            }
        case 2:

            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-How To Play ");
                Reset_Color();
                printf("\n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Exit\n");
                break;
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuevo juego\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-Como jugar ");
                Reset_Color();
                printf("\n \n\t\t\t\t\t\t\t3-Cargar juego \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Salir\n");
                break;
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-neues Spiel\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-Spielanleitung ");
                Reset_Color();
                printf("\n \n\t\t\t\t\t\t\t3-Spiel laden \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Beenden\n");
                break;
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nieuw spel\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-Hoe speel je het spelregels ");
                Reset_Color();
                printf("\n \n\t\t\t\t\t\t\t3-Spel laden \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-spel verlaten\n");
                break;
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuovo gioco\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-Come giocare ");
                Reset_Color();
                printf("\n \n\t\t\t\t\t\t\t3-Caricare il gioco \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Uscire\n");
                break;
            }
        case 3:
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-How To Play \n \n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->3-Load Game ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Exit\n");
                break;
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuevo juego\n\n \t\t\t\t\t\t\t2-Como jugar \n \n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->3-Cargar juego ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Salir\n");
                break;
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-neues Spiel\n\n \t\t\t\t\t\t\t2-Spielanleitung \n \n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->3-Spiel laden ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Beenden\n");
                break;
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nieuw spel\n\n \t\t\t\t\t\t\t2-Hoe speel je het spelregels \n \n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->3-Spel laden ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-spel verlaten\n");
                break;
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuovo gioco\n\n \t\t\t\t\t\t\t2-Come giocare \n \n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->3-Caricare il gioco ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t\t5-Uscire\n");
                break;
            }
        case 4:
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-How To Play \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->4-Top 10 ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t5-Exit\n");
                break;
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuevo juego\n\n \t\t\t\t\t\t\t2-Como jugar \n \n\t\t\t\t\t\t\t3-Cargar juego \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->4-Top 10 ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t5-Salir\n");
                break;
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-neues Spiel\n\n \t\t\t\t\t\t\t2-Spielanleitung \n \n\t\t\t\t\t\t\t3-Spiel laden \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->4-Top 10 ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t5-Beenden\n");
                break;
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nieuw spel\n\n \t\t\t\t\t\t\t2-Hoe speel je het spelregels \n \n\t\t\t\t\t\t\t3-Spel laden \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->4-Top 10 ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t5-spel verlaten\n");
                break;
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuovo gioco\n\n \t\t\t\t\t\t\t2-Come giocare \n \n\t\t\t\t\t\t\t3-Caricare il gioco \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->4-Top 10 ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t5-Uscire\n");
                break;
            }
        case 5:
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-New Game\n\n \t\t\t\t\t\t\t2-How To Play \n \n\t\t\t\t\t\t\t3-Load Game \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->5-Exit\n");
                Reset_Color();
                break;
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuevo juego\n\n \t\t\t\t\t\t\t2-Como jugar \n \n\t\t\t\t\t\t\t3-Cargar juego \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->5-Salir\n");
                Reset_Color();
                break;
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-neues Spiel\n\n \t\t\t\t\t\t\t2-Spielanleitung \n \n\t\t\t\t\t\t\t3-Spiel laden \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->5-Beenden\n");
                Reset_Color();
                break;
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nieuw spel\n\n \t\t\t\t\t\t\t2-Hoe speel je het spelregels \n \n\t\t\t\t\t\t\t3-Spel laden \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->5-spel verlaten\n");
                Reset_Color();
                break;
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuovo gioco\n\n \t\t\t\t\t\t\t2-Come giocare \n \n\t\t\t\t\t\t\t3-Caricare il gioco \n\n \t\t\t\t\t\t\t4-Top 10 \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->5-Uscire\n");
                Reset_Color();
                break;
            }
        }
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
        Print_Logo(0);
        switch(ArrowVal)
        {
        case 1:
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Mode:\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-player vs computer");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-two players");
                printf("\n\n\t\t\t\t\t\t\t3-three players");
                printf("\n\n\t\t\t\t\t\t\t4-four players\n");
                break;
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tModo de juego:\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-jugador vs computer");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-dos jugadores");
                printf("\n\n\t\t\t\t\t\t\t3-tres jugadores");
                printf("\n\n\t\t\t\t\t\t\t4-quatro jugadores\n");

                break;
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tSpielmodus:\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-Spieler vs computer");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-Zwei Spieler");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t3-Drei Spieler");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t4-Vier Spieler\n");
                break;
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tspelmodus:\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-speler vs computer");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-twee spelers");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t3-drie spelers");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t4-vier spelers\n");
                break;
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tmodalita di gioco:\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-giocatore vs computer");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-due giocatori");
                printf("\n\n\t\t\t\t\t\t\t3-tre giocatori");
                printf("\n\n\t\t\t\t\t\t\t4-quattro giocatori\n");
                break;
            }
        case 2:
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Mode:\n\n\n");
                printf("\t\t\t\t\t\t\t1-player vs computer");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->2-two players");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t3-three players");
                printf("\n\n\t\t\t\t\t\t\t4-four players\n");
                break;
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tModo de juego:\n\n\n");
                printf("\t\t\t\t\t\t\t1-jugador vs computer");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->2-dos jugadores");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t3-tres jugadores");
                printf("\n\n\t\t\t\t\t\t\t4-quatro jugadores\n");

                break;
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tSpielmodus:\n\n\n");
                printf("\t\t\t\t\t\t\t1-Spieler vs computer");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->2-Zwei Spieler");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t3-Drei Spieler");
                printf("\n\n\t\t\t\t\t\t\t4-Vier Spieler\n");
                break;
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tspelmodus:\n\n\n");
                printf("\t\t\t\t\t\t\t1-speler vs computer");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->2-twee spelers");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t3-drie spelers");
                printf("\n\n\t\t\t\t\t\t\t4-vier spelers\n");
                break;
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tmodalita di gioco:\n\n\n");
                printf("\t\t\t\t\t\t\t1-giocatore vs computer");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->2-due giocatori");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t3-tre giocatori");
                printf("\n\n\t\t\t\t\t\t\t4-quattro giocatori\n");
                break;
            }
        case 3:
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Mode:\n\n\n");
                printf("\t\t\t\t\t\t\t1-player vs computer");
                printf("\n\n\t\t\t\t\t\t\t2-two players");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->3-three players");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t4-four players\n");
                break;
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tModo de juego:\n\n\n");
                printf("\t\t\t\t\t\t\t1-jugador vs computer");
                printf("\n\n\t\t\t\t\t\t\t2-dos jugadores");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->3-tres jugadores");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t4-quatro jugadores\n");

                break;
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tSpielmodus:\n\n\n");
                printf("\t\t\t\t\t\t\t1-Spieler vs computer");
                printf("\n\n\t\t\t\t\t\t\t2-Zwei Spieler");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->3-Drei Spieler");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t4-Vier Spieler\n");
                break;
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tspelmodus:\n\n\n");
                printf("\t\t\t\t\t\t\t1-speler vs computer");
                printf("\n\n\t\t\t\t\t\t\t2-twee spelers");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->3-drie spelers");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t4-vier spelers\n");
                break;
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tmodalita di gioco:\n\n\n");
                printf("\t\t\t\t\t\t\t1-giocatore vs computer");
                printf("\n\n\t\t\t\t\t\t\t2-due giocatori");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->3-tre giocatori");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t4-quattro giocatori\n");
                break;
            }
        case 4:
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGame Mode:\n\n\n");
                printf("\t\t\t\t\t\t\t1-player vs computer");
                printf("\n\n\t\t\t\t\t\t\t2-two players");
                printf("\n\n\t\t\t\t\t\t\t3-three players");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->4-four players\n");
                Reset_Color();
                break;
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tModo de juego:\n\n\n");
                printf("\t\t\t\t\t\t\t1-jugador vs computer");
                printf("\n\n\t\t\t\t\t\t\t2-dos jugadores");
                printf("\n\n\t\t\t\t\t\t\t3-tres jugadores");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->4-quatro jugadores\n");
                Reset_Color();

                break;
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tSpielmodus:\n\n\n");
                printf("\t\t\t\t\t\t\t1-Spieler vs computer");
                printf("\n\n\t\t\t\t\t\t\t2-Zwei Spieler");
                printf("\n\n\t\t\t\t\t\t\t3-Drei Spieler");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->4-Vier Spieler\n");
                Reset_Color();
                break;
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tspelmodus:\n\n\n");
                printf("\t\t\t\t\t\t\t1-speler vs computer");
                printf("\n\n\t\t\t\t\t\t\t2-twee spelers");
                printf("\n\n\t\t\t\t\t\t\t3-drie spelers");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->4-vier spelers\n");
                Reset_Color();
                break;
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tmodalita di gioco:\n\n\n");
                printf("\t\t\t\t\t\t\t1-giocatore vs computer");
                printf("\n\n\t\t\t\t\t\t\t2-due giocatori");
                printf("\n\n\t\t\t\t\t\t\t3-tre giocatori");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->4-quattro giocatori\n");
                Reset_Color();
                break;
            }
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
            if(ArrowVal<4)
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
            Num_Of_Players=2;
// TO TAKE THE PLAYER NAME
            Print_Logo(0);
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 1:");
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 1 ein:");
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 1 in:");
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 1:");
            }
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player1.Name,100,stdin);
            while(Player1.Name[0]=='\n')
            {
                Print_Logo(0);
                if(language==1)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
                }
                else if(language==2)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 1:");
                }
                else if(language==3)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 1 ein:");
                }
                else if(language==4)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 1 in:");
                }
                else if(language==5)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 1:");
                }
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

            Print_Logo(0);
            if(language==1)
            {
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
            }
            else if(language==2)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tdificultad de juego:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-facil");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-dificil\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tdificultad de juego:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-facil\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-dificil\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==3)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tSpielschwierigkeit:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-leicht");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-schwer\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tSpielschwierigkeit:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-leicht\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-schwer\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==4)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tmoeilijkheidsgraad:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-makkelijk");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-moeilijk\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tmoeilijkheidsgraad:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-makkelijk\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-moeilijk\n");
                    Reset_Color();
                    break;
                }
            }
            else  if(language==5)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tdifficoltà di gioco:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-facile");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-difficile\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tdifficoltà di gioco:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-facile\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-difficile\n");
                    Reset_Color();
                    break;
                }

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
            Print_Logo(0);
            if(language==1)
            {
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
            }
            else  if(language==2)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-elige tu talla\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-elige tu talla\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-elige tu talla\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==3)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-Wahlen Sie Ihre Grosse\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-Wahlen Sie Ihre Grosse\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-Wahlen Sie Ihre Grosse\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==4)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-kies je roostergrootte\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-kies je roostergrootte\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-kies je roostergrootte\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==5)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-scegli la tua taglia\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-scegli la tua taglia\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-scegli la tua taglia\n");
                    Reset_Color();
                    break;
                }
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
TakeRow:
                system("cls");
                if(language==1)
                {
                    printf("Enter Number Of Rows.. Minimum 3 & Maximum 9 ");
                }
                else if(language==2)
                {
                    printf("Ingrese el numero de filas.. minimo 3 & maximo 9 ");
                }
                else if(language==3)
                {
                    printf("Geben Sie die Anzahl der Zeilen ein.. Minimum 3 & Maximum 9 ");
                }
                else if(language==4)
                {
                    printf("voeg het aantal rijen in.. Minimum 3 & Maximum 9 ");
                }
                else if(language==5)
                {
                    printf("Inserisci il numero di righe.. minimo 3 & massimo 9 ");
                }
                ValidRow=getche();
                switch(ValidRow)
                {
                case 51:
                    R1=3;
                    break;
                case 52:
                    R1=4;
                    break;
                case 53:
                    R1=5;
                    break;
                case 54:
                    R1=6;
                    break;
                case 55:
                    R1=7;
                    break;
                case 56:
                    R1=8;
                    break;
                case 57:
                    R1=9;
                    break;
                default:
                    goto TakeRow;
                }
TakeCol:
                system("cls");
                if(language==1)
                {
                    printf("Enter Number Of Columns.. Minimum 3 & Maximum 9 ");
                }
                else if(language==2)
                {
                    printf("Ingrese el numero de columnas.. minimo 3 & maximo 9 ");
                }
                else if(language==3)
                {
                    printf("Geben Sie Anzahl der Spalten ein.. Minimum 3 & Maximum 9 ");
                }
                else if(language==4)
                {
                    printf("voeg het aantal kolommen in.. Minimum 3 & Maximum 9 ");
                }
                else if(language==5)
                {
                    printf("Inserisci il numero di colonne.. minimo 3 & massimo 9 ");
                }
                ValidColumn=getche();
                switch(ValidColumn)
                {
                case 51:
                    C1=3;
                    break;
                case 52:
                    C1=4;
                    break;
                case 53:
                    C1=5;
                    break;
                case 54:
                    C1=6;
                    break;
                case 55:
                    C1=7;
                    break;
                case 56:
                    C1=8;
                    break;
                case 57:
                    C1=9;
                    break;
                default:
                    goto TakeCol;
                }
                break;
            default:
                goto Player_Vs_Comp_Size;
            }
            break;
        case 2: // BUTTON 2 FOR PLAYER 1 VS PLAYER 2
            Num_Of_Players=2;
            // TO TAKE PLAYER NAME
            Print_Logo(0);
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 1:");
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 1 ein:");
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 1 in:");
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 1:");
            }
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player1.Name,100,stdin);

            while(Player1.Name[0]=='\n')
            {
                Print_Logo(0);
                if(language==1)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
                }
                else if(language==2)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 1:");
                }
                else if(language==3)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 1 ein:");
                }
                else if(language==4)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 1 in:");
                }
                else if(language==5)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 1:");
                }
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

            Print_Logo(0);
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 2's Name:");
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 2:");
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 2 ein:");
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 2 in:");
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 2:");
            }
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player2.Name,100,stdin);

            while(Player2.Name[0]=='\n')
            {
                Print_Logo(0);
                if(language==1)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 2's Name:");
                }
                else if(language==2)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 2:");
                }
                else if(language==3)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 2 ein:");
                }
                else if(language==4)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 2 in:");
                }
                else if(language==5)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 2:");
                }
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
            Print_Logo(0);
            if(language==1)
            {
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
            }
            else if(language==2)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-elige tu talla\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-elige tu talla\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-elige tu talla\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==3)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-Wahlen Sie Ihre Grosse\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-Wahlen Sie Ihre Grosse\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-Wahlen Sie Ihre Grosse\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==4)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-kies je roostergrootte\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-kies je roostergrootte\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-kies je roostergrootte\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==5)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-scegli la tua taglia\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-scegli la tua taglia\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-scegli la tua taglia\n");
                    Reset_Color();
                    break;
                }
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
TakeRow1:
                system("cls");
                if(language==1)
                {
                    printf("Enter Number Of Rows.. Minimum 3 & Maximum 9 ");
                }
                else if(language==2)
                {
                    printf("Ingrese el numero de filas.. minimo 3 & maximo 9 ");
                }
                else if(language==3)
                {
                    printf("Geben Sie die Anzahl der Zeilen ein.. Minimum 3 & Maximum 9 ");
                }
                else if(language==4)
                {
                    printf("voeg het aantal rijen in.. Minimum 3 & Maximum 9 ");
                }
                else if(language==5)
                {
                    printf("Inserisci il numero di righe.. minimo 3 & massimo 9 ");
                }
                ValidRow=getche();
                switch(ValidRow)
                {
                case 51:
                    R1=3;
                    break;
                case 52:
                    R1=4;
                    break;
                case 53:
                    R1=5;
                    break;
                case 54:
                    R1=6;
                    break;
                case 55:
                    R1=7;
                    break;
                case 56:
                    R1=8;
                    break;
                case 57:
                    R1=9;
                    break;
                default:
                    goto TakeRow1;
                }
TakeCol1:
                system("cls");
                if(language==1)
                {
                    printf("Enter Number Of Columns.. Minimum 3 & Maximum 9 ");
                }
                else if(language==2)
                {
                    printf("Ingrese el numero de columnas.. minimo 3 & maximo 9 ");
                }
                else if(language==3)
                {
                    printf("Geben Sie Anzahl der Spalten ein.. Minimum 3 & Maximum 9 ");
                }
                else if(language==4)
                {
                    printf("voeg het aantal kolommen in.. Minimum 3 & Maximum 9 ");
                }
                else if(language==5)
                {
                    printf("Inserisci il numero di colonne.. minimo 3 & massimo 9 ");
                }
                ValidColumn=getche();
                switch(ValidColumn)
                {
                case 51:
                    C1=3;
                    break;
                case 52:
                    C1=4;
                    break;
                case 53:
                    C1=5;
                    break;
                case 54:
                    C1=6;
                    break;
                case 55:
                    C1=7;
                    break;
                case 56:
                    C1=8;
                    break;
                case 57:
                    C1=9;
                    break;
                default:
                    goto TakeCol1;
                }
                break;
            default:
                goto Player1_Vs_Player2;
            }
            break;



        case 3: // BUTTON 3 FOR PLAYER 1 VS PLAYER 2 VS PLAYER 3
            Num_Of_Players=3;
            // TO TAKE PLAYER NAME
            Print_Logo(0);
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 1:");
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 1 ein:");
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 1 in:");
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 1:");
            }
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player1.Name,100,stdin);

            while(Player1.Name[0]=='\n')
            {
                Print_Logo(0);
                if(language==1)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
                }
                else if(language==2)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 1:");
                }
                else if(language==3)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 1 ein:");
                }
                else if(language==4)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 1 in:");
                }
                else if(language==5)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 1:");
                }
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

            Print_Logo(0);
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 2's Name:");
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 2:");
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 2 ein:");
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 2 in:");
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 2:");
            }
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player2.Name,100,stdin);

            while(Player2.Name[0]=='\n')
            {
                Print_Logo(0);
                if(language==1)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 2's Name:");
                }
                else if(language==2)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 2:");
                }
                else if(language==3)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 2 ein:");
                }
                else if(language==4)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 2 in:");
                }
                else if(language==5)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 2:");
                }
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

            Print_Logo(0);
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 3's Name:");
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 3:");
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 3 ein:");
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 3 in:");
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 3:");
            }
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player3.Name,100,stdin);

            while(Player3.Name[0]=='\n')
            {
                Print_Logo(0);
                if(language==1)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 3's Name:");
                }
                else if(language==2)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 3:");
                }
                else if(language==3)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 3 ein:");
                }
                else if(language==4)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 3 in:");
                }
                else if(language==5)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 3:");
                }
                printf("\n\n\t\t\t\t\t\t\t   ");
                fflush(stdin);
                fgets(Player3.Name,100,stdin);
            }
            z=0;
            while (Player3.Name[z]!='\0')
            {
                z++;
            }
            Player3.Name[z-1]='\0';


            // TO CONTINUE IN THE MENU
            ArrowVal=1;
Player1_Vs_Player2_Vs_Player3:
            Print_Logo(0);
            if(language==1)
            {
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
            }
            else if(language==2)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-elige tu talla\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-elige tu talla\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-elige tu talla\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==3)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-Wahlen Sie Ihre Grosse\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-Wahlen Sie Ihre Grosse\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-Wahlen Sie Ihre Grosse\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==4)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-kies je roostergrootte\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-kies je roostergrootte\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-kies je roostergrootte\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==5)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-scegli la tua taglia\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-scegli la tua taglia\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-scegli la tua taglia\n");
                    Reset_Color();
                    break;
                }
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
                goto Player1_Vs_Player2_Vs_Player3;
                break;
            case 80:
                if(ArrowVal<3)
                {
                    ArrowVal++;
                    game_difficulty++;
                    Beep(300,70);

                }
                goto Player1_Vs_Player2_Vs_Player3;
                break;
            case 13 :
                Beep(130,120);

                break;
            default:
                goto Player1_Vs_Player2_Vs_Player3;

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
TakeRow2:
                system("cls");
                if(language==1)
                {
                    printf("Enter Number Of Rows.. Minimum 3 & Maximum 9 ");
                }
                else if(language==2)
                {
                    printf("Ingrese el numero de filas.. minimo 3 & maximo 9 ");
                }
                else if(language==3)
                {
                    printf("Geben Sie die Anzahl der Zeilen ein.. Minimum 3 & Maximum 9 ");
                }
                else if(language==4)
                {
                    printf("voeg het aantal rijen in.. Minimum 3 & Maximum 9 ");
                }
                else if(language==5)
                {
                    printf("Inserisci il numero di righe.. minimo 3 & massimo 9 ");
                }
                ValidRow=getche();
                switch(ValidRow)
                {
                case 51:
                    R1=3;
                    break;
                case 52:
                    R1=4;
                    break;
                case 53:
                    R1=5;
                    break;
                case 54:
                    R1=6;
                    break;
                case 55:
                    R1=7;
                    break;
                case 56:
                    R1=8;
                    break;
                case 57:
                    R1=9;
                    break;
                default:
                    goto TakeRow2;
                }
TakeCol2:
                system("cls");
                if(language==1)
                {
                    printf("Enter Number Of Columns.. Minimum 3 & Maximum 9 ");
                }
                else if(language==2)
                {
                    printf("Ingrese el numero de columnas.. minimo 3 & maximo 9 ");
                }
                else if(language==3)
                {
                    printf("Geben Sie Anzahl der Spalten ein.. Minimum 3 & Maximum 9 ");
                }
                else if(language==4)
                {
                    printf("voeg het aantal kolommen in.. Minimum 3 & Maximum 9 ");
                }
                else if(language==5)
                {
                    printf("Inserisci il numero di colonne.. minimo 3 & massimo 9 ");
                }
                ValidColumn=getche();
                switch(ValidColumn)
                {
                case 51:
                    C1=3;
                    break;
                case 52:
                    C1=4;
                    break;
                case 53:
                    C1=5;
                    break;
                case 54:
                    C1=6;
                    break;
                case 55:
                    C1=7;
                    break;
                case 56:
                    C1=8;
                    break;
                case 57:
                    C1=9;
                    break;
                default:
                    goto TakeCol2;
                }
                break;
            default:
                goto Player1_Vs_Player2_Vs_Player3;
            }
            break;




        case 4: // BUTTON 4 FOR PLAYER 1 VS PLAYER 2 VS PLAYER 3 VS PLAYER 4
            Num_Of_Players=4;
            // TO TAKE PLAYER NAME
            Print_Logo(0);
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 1:");
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 1 ein:");
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 1 in:");
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 1:");
            }
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player1.Name,100,stdin);

            while(Player1.Name[0]=='\n')
            {
                Print_Logo(0);
                if(language==1)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 1's Name:");
                }
                else if(language==2)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 1:");
                }
                else if(language==3)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 1 ein:");
                }
                else if(language==4)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 1 in:");
                }
                else if(language==5)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 1:");
                }
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

            Print_Logo(0);
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 2's Name:");
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 2:");
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 2 ein:");
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 2 in:");
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 2:");
            }
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player2.Name,100,stdin);

            while(Player2.Name[0]=='\n')
            {
                Print_Logo(0);
                if(language==1)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 2's Name:");
                }
                else if(language==2)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 2:");
                }
                else if(language==3)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 2 ein:");
                }
                else if(language==4)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 2 in:");
                }
                else if(language==5)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 2:");
                }
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

            Print_Logo(0);

            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 3's Name:");
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 3:");
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 3 ein:");
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 3 in:");
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 3:");
            }
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player3.Name,100,stdin);

            while(Player3.Name[0]=='\n')
            {
                Print_Logo(0);
                if(language==1)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 3's Name:");
                }
                else if(language==2)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 3:");
                }
                else if(language==3)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 3 ein:");
                }
                else if(language==4)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 3 in:");
                }
                else if(language==5)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 3:");
                }
                printf("\n\n\t\t\t\t\t\t\t   ");
                fflush(stdin);
                fgets(Player3.Name,100,stdin);
            }
            z=0;
            while (Player3.Name[z]!='\0')
            {
                z++;
            }
            Player3.Name[z-1]='\0';

            Print_Logo(0);
            if(language==1)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 4's Name:");
            }
            else if(language==2)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 4:");
            }
            else if(language==3)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 4 ein:");
            }
            else if(language==4)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 4 in:");
            }
            else if(language==5)
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 4:");
            }
            printf("\n\n\t\t\t\t\t\t\t   ");
            fflush(stdin);
            fgets(Player4.Name,100,stdin);

            while(Player4.Name[0]=='\n')
            {
                Print_Logo(0);
                if(language==1)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Player 4's Name:");
                }
                else if(language==2)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tingrese el nombre del jugador 4:");
                }
                else if(language==3)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGib den Namen von Spieler 4 ein:");
                }
                else if(language==4)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tvul de naam van speler 4 in:");
                }
                else if(language==5)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tinserisci il nome del giocatore 4:");
                }
                printf("\n\n\t\t\t\t\t\t\t   ");
                fflush(stdin);
                fgets(Player4.Name,100,stdin);
            }
            z=0;
            while (Player4.Name[z]!='\0')
            {
                z++;
            }
            Player4.Name[z-1]='\0';


            // TO CONTINUE IN THE MENU
            ArrowVal=1;
Player1_Vs_Player2_Vs_Player3_Vs_Player4:
            Print_Logo(0);
            if(language==1)
            {
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
            }
            else if(language==2)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-elige tu talla\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-elige tu talla\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tTamano de la cuadricula:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-elige tu talla\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==3)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-Wahlen Sie Ihre Grosse\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-Wahlen Sie Ihre Grosse\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tGittergrosse:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-Wahlen Sie Ihre Grosse\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==4)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-kies je roostergrootte\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-kies je roostergrootte\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\troostergrootte:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-kies je roostergrootte\n");
                    Reset_Color();
                    break;
                }
            }
            else if(language==5)
            {
                switch (ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    Change_Color(10);
                    printf("\t\t\t\t\t\t----->1-2x2");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t\t3-scegli la tua taglia\n");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->2-5x5");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t3-scegli la tua taglia\n");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tDimensione della griglia:\n\n\n");
                    printf("\t\t\t\t\t\t\t1-2x2\n\n\t\t\t\t\t\t\t2-5x5\n\n\t\t\t\t\t\t");
                    Change_Color(10);
                    printf("----->3-scegli la tua taglia\n");
                    Reset_Color();
                    break;
                }
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
                goto Player1_Vs_Player2_Vs_Player3_Vs_Player4;
                break;
            case 80:
                if(ArrowVal<3)
                {
                    ArrowVal++;
                    game_difficulty++;
                    Beep(300,70);

                }
                goto Player1_Vs_Player2_Vs_Player3_Vs_Player4;
                break;
            case 13 :
                Beep(130,120);

                break;
            default:
                goto Player1_Vs_Player2_Vs_Player3_Vs_Player4;

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
TakeRow3:
                system("cls");
                if(language==1)
                {
                    printf("Enter Number Of Rows.. Minimum 3 & Maximum 9 ");
                }
                else if(language==2)
                {
                    printf("Ingrese el numero de filas.. minimo 3 & maximo 9 ");
                }
                else if(language==3)
                {
                    printf("Geben Sie die Anzahl der Zeilen ein.. Minimum 3 & Maximum 9 ");
                }
                else if(language==4)
                {
                    printf("voeg het aantal rijen in.. Minimum 3 & Maximum 9 ");
                }
                else if(language==5)
                {
                    printf("Inserisci il numero di righe.. minimo 3 & massimo 9 ");
                }
                ValidRow=getche();
                switch(ValidRow)
                {
                case 51:
                    R1=3;
                    break;
                case 52:
                    R1=4;
                    break;
                case 53:
                    R1=5;
                    break;
                case 54:
                    R1=6;
                    break;
                case 55:
                    R1=7;
                    break;
                case 56:
                    R1=8;
                    break;
                case 57:
                    R1=9;
                    break;
                default:
                    goto TakeRow3;
                }
TakeCol3:
                system("cls");
                if(language==1)
                {
                    printf("Enter Number Of Columns.. Minimum 3 & Maximum 9 ");
                }
                else if(language==2)
                {
                    printf("Ingrese el numero de columnas.. minimo 3 & maximo 9 ");
                }
                else if(language==3)
                {
                    printf("Geben Sie Anzahl der Spalten ein.. Minimum 3 & Maximum 9 ");
                }
                else if(language==4)
                {
                    printf("voeg het aantal kolommen in.. Minimum 3 & Maximum 9 ");
                }
                else if(language==5)
                {
                    printf("Inserisci il numero di colonne.. minimo 3 & massimo 9 ");
                }
                ValidColumn=getche();
                switch(ValidColumn)
                {
                case 51:
                    C1=3;
                    break;
                case 52:
                    C1=4;
                    break;
                case 53:
                    C1=5;
                    break;
                case 54:
                    C1=6;
                    break;
                case 55:
                    C1=7;
                    break;
                case 56:
                    C1=8;
                    break;
                case 57:
                    C1=9;
                    break;
                default:
                    goto TakeCol3;
                }
                break;
            default:
                goto Player1_Vs_Player2_Vs_Player3_Vs_Player4;
            }
            break;


        }
        break;
//HOW TO PLAY//
    case 2: //BUTTON 2 FOR -HOW TO PLAY-
howToPlay:
        Print_Logo(1);
        if(language==1)
        {
            printf("\n\n\t\t\t\t\t\t\tHow to play\n\n");
            printf("\t\t  The two players take turns to join two adjacent dots with a horizontal or vertical line. \n");
            printf("\t      If a player completes the fourth side of a box they initial that box and must draw another line. \n");
            printf("\t    When all the boxes have been completed the winner is the player who has initialled the most boxes.");
            printf("\n\n\n\n\t\t\t\t\t\tControls:\n");
            printf("\t\t\t\t\t\tPress Space to change from vertical line to horizontal line and V.V\n");
            printf("\t\t\t\t\t\tpress right arrow to go right\n\t\t\t\t\t\tpress left arrow to go left\n\t\t\t\t\t\tpress up arrow to go up\n \t\t\t\t\t\tpress down arrow to go down\n");
            printf("\t\t\t\t\t\tpress \"U\" to Undo move & \"R\" to Redo move ");
            printf("\n\t\t\t\t\t\tpress Enter to select place");
            printf("\n\t\t\t\t\t\tpress esc for options");
            printf("\n\t\t\t\t\t\tpress \"M\" to mute the music during the game");
            printf("\n\t\t\t\t\t\tpress \"P\" to Play the music again");

            printf("\n\n\n\t\t\t\t\t\tpress esc to go back to main menu");
        }
        if(language==2)
        {
            printf("\n\n\t\t\t\t\t\t\tComo jugar\n\n");
            printf("\t\t  Los dos jugadores se turnan para unir dos puntos adyacentes con una linea horizontal o vertical. \n");
            printf("\t      Si un jugador completa el cuarto lado de un recuadro, inicializa ese recuadro y debe dibujar otra linea. \n");
            printf("\t    Cuando se hayan completado todas las casillas, el ganador es el jugador que ha rubricado mas casillas.");
            printf("\n\n\n\n\t\t\t\t\t\tcontroles:\n");
            printf("\t\t\t\t\t\tPresione Espacio para cambiar de linea vertical a linea horizontal\n");
            printf("\t\t\t\t\t\tpresione la flecha derecha para ir a la derecha\n\t\t\t\t\t\tpresione la flecha izquierda para ir a la izquierda\n\t\t\t\t\t\tpresionar la flecha hacia arriba para subir\n \t\t\t\t\t\tpresionar la flecha hacia abajo para bajar\n");
            printf("\t\t\t\t\t\tpresione \"U\" para deshacer movimiento & \"R\" para rehacer mover ");
            printf("\n\t\t\t\t\t\tpresione Enter para seleccionar el lugar");
            printf("\n\t\t\t\t\t\tpresione esc para ver las opciones");
            printf("\n\t\t\t\t\t\tpresiona \"M\" para silenciar la musica durante el juego");
            printf("\n\t\t\t\t\t\tpresione \"P\" para reproducir la musica nuevamente");

            printf("\n\n\n\t\t\t\t\t\tpresione esc para volver al menu principal");
        }
        if(language==3)
        {
            printf("\n\n\t\t\t\t\t\t\tSpielanleitung\n\n");
            printf("\t\t  Die beiden Spieler wechseln abwechselnd zwei benachbarte Punkte mit einer horizontalen oder vertikalen Linie. \n");
            printf("\t      Wenn ein Spieler die vierte Seite einer Box vervollstandigt, initialisiert er diese Box und muss eine weitere Linie ziehen. \n");
            printf("\t    Wenn alle Felder abgeschlossen sind, gewinnt der Spieler, der die meisten Felder paraphiert hat.");
            printf("\n\n\n\n\t\t\t\t\t\tKontrollen:\n");
            printf("\t\t\t\t\t\tDrucken Sie die Leertaste, um von der vertikalen Linie zur horizontalen Linie\n");
            printf("\t\t\t\t\t\tDrucke den rechten Pfeil, um nach rechts zu gehen\n\t\t\t\t\t\tDrucken Sie den linken Pfeil, um nach links zu gehen\n\t\t\t\t\t\tDrucken Sie den Pfeil nach oben, um nach oben zu gehen\n \t\t\t\t\t\tDrucken Sie den Pfeil nach unten, um nach unten zu gehen\n");
            printf("\t\t\t\t\t\tDrucke \"U\" um die Bewegung ruckgangig zu machen und \"R\" um die Bewegung zu wiederholen ");
            printf("\n\t\t\t\t\t\tDrucken Sie die Eingabetaste, um den Ort auszuwahlen");
            printf("\n\t\t\t\t\t\tDrucken Sie esc fur Optionen");
            printf("\n\t\t\t\t\t\tDrucken Sie \"M\", um die Musik wahrend des Spiels stumm zu schalten");
            printf("\n\t\t\t\t\t\tDrucken Sie \"P\", um die Musik erneut abzuspielen");

            printf("\n\n\n\t\t\t\t\t\tDrucken Sie esc, um zum Hauptmenu zuruckzukehren");
        }
        if(language==4)
        {
            printf("\n\n\t\t\t\t\t\t\tHoe speel je het spelregels\n\n");
            printf("\t\t  Beide spelers spelen om de beurt. Er moeten 2 aangrenzende punten verbonden worden met een horizontale of verticale lijn. \n");
            printf("\t       Wanneer een speler 4 zijde van een vierkant getekend heeft, is dit compleet en mag er nog eens gespeeld worden.  \n");
            printf("\t    Wanneer alle punten gespeeld zijn is het spel gedaan en wint de speler met de meeste complete vierkanten.");
            printf("\n\n\n\n\t\t\t\t\t\tControls:\n");
            printf("\t\t\t\t\t\t druk op Spatie om van verticale lijn naar horizontale lijn \n");
        printf("\t\t\t\t\t\t druk op de pijl naar rechts om naar rechts te gaan\n\t\t\t\t\t\tdruk op de linkerpijl om naar links te gaan\n\t\t\t\t\t\t druk op de pijl omhoog om omhoog te gaan\n \t\t\t\t\t\t druk op de pijl omlaag om naar beneden te gaan\n");
        printf("\t\t\t\t\t\t druk op \"U\" om verplaatsing ongedaan te maken & \"R\" om Opnieuw te verplaatsen ");
        printf("\n\t\t\t\t\t\t druk op Enter om een plaats te selecteren");
        printf("\n\t\t\t\t\t\t druk op esc voor opties");
        printf("\n\t\t\t\t\t\t druk op \"M\", om de muziek tijdens het spel te dempen");
        printf("\n\t\t\t\t\t\t druk op \"P\", om de muziek opnieuw af te spelen");

            printf("\n\n\n\t\t\t\t\t\tdruk op esc om terug te gaan naar het hoofdmenu");
        }
        if(language==5)
        {
            printf("\n\n\t\t\t\t\t\t\tCome giocare\n\n");
            printf("\t\t   I due giocatori, a turno, si uniscono a due punti adiacenti con una linea orizzontale o verticale. \n");
            printf("\t      Se un giocatore completa il quarto lato di una scatola, inizia quella casella e deve tracciare un'altra linea. \n");
            printf("\t    Quando tutte le caselle sono state completate, il vincitore è il giocatore che ha siglato il maggior numero di caselle.");
            printf("\n\n\n\n\t\t\t\t\t\tcontrolli:\n");
            printf("\t\t\t\t\t\tPremere Spazio per passare dalla linea verticale alla linea orizzontale\n");
            printf("\t\t\t\t\t\tpremi la freccia destra per andare a destra\n\t\t\t\t\t\tpremere la freccia sinistra per andare a sinistra\n\t\t\t\t\t\tpremere la freccia su per salire\n \t\t\t\t\t\tpremere la freccia giù per scendere\n");
            printf("\t\t\t\t\t\tpremere \"U\" per annullare la mossa e \"R\" per ripetere la mossa ");
            printf("\n\t\t\t\t\t\tpremere Invio per selezionare il luogo");
            printf("\n\t\t\t\t\t\tpremere esc per le opzioni");
            printf("\n\t\t\t\t\t\tpremere \"M\", per silenziare la musica durante il gioco");
            printf("\n\t\t\t\t\t\tpremere \"P\", per riprodurre di nuovo la musica");

            printf("\n\n\n\t\t\t\t\t\tpremere esc per tornare al menu principale");
        }
        backKey=getche();
        switch (backKey)
        {
        case 27:
            Reset_To_Back();
            goto menu;
            break; //ESC TO GO BACK
        default:
            goto howToPlay;

        }
        break;
    //load game//
    case 3: // BUTTON 3
        ArrowVal=1;
        Save_Value=1;
load:
        Print_Logo(0);
        if(language==1)
        {
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
        }
        if(language==2)
        {
            switch(ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tCargar juego");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->1-juego 1");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-juego 2 \n \n\t\t\t\t\t\t\t3-juego 3");
                printf("\n\n\t\t\t\t\t\t\t Presiona esc para regresar al juego...");
                strcpy(FileName,"Save 1");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tCargar juego");
                printf("\n\n\t\t\t\t\t\t\t1-juego 1");
                Change_Color(10);
                printf("\n\n \t\t\t\t\t\t----->2-juego 2");
                Reset_Color();
                printf(" \n \n\t\t\t\t\t\t\t3-juego 3");
                printf("\n\n\t\t\t\t\t\t\t Presiona esc para regresar al juego...");
                strcpy(FileName,"Save 2");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tCargar juego");
                printf("\n\n\t\t\t\t\t\t\t1-juego 1\n\n \t\t\t\t\t\t\t2-juego 2");
                Change_Color(10);
                printf(" \n \n\t\t\t\t\t\t----->3-juego 3");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t Presiona esc para regresar al juego...");
                strcpy(FileName,"Save 3");
                break;
            }
        }
        if(language==3)
        {
            switch(ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSpiel laden");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->1-Spiel 1");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-Spiel 2 \n \n\t\t\t\t\t\t\t3-Spiel 3");
                printf("\n\n\t\t\t\t\t\t\t Drucken Sie esc, um zum Spiel zuruckzukehren...");
                strcpy(FileName,"Save 1");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSpiel laden");
                printf("\n\n\t\t\t\t\t\t\t1-Spiel 1");
                Change_Color(10);
                printf("\n\n \t\t\t\t\t\t----->2-Spiel 2");
                Reset_Color();
                printf(" \n \n\t\t\t\t\t\t\t3-Spiel 3");
                printf("\n\n\t\t\t\t\t\t\t Drucken Sie esc, um zum Spiel zuruckzukehren...");
                strcpy(FileName,"Save 2");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSpiel laden");
                printf("\n\n\t\t\t\t\t\t\t1-Spiel 1\n\n \t\t\t\t\t\t\t2-Spiel 2");
                Change_Color(10);
                printf(" \n \n\t\t\t\t\t\t----->3-Spiel 3");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t Drucken Sie esc, um zum Spiel zuruckzukehren...");
                strcpy(FileName,"Save 3");
                break;
            }
        }
        if(language==4)
        {
            switch(ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tspel laden");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->1-spel 1");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-spel 2 \n \n\t\t\t\t\t\t\t3-spel 3");
                printf("\n\n\t\t\t\t\t\t\t Druk op esc om terug te gaan naar het spel...");
                strcpy(FileName,"Save 1");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tspel laden");
                printf("\n\n\t\t\t\t\t\t\t1-spel 1");
                Change_Color(10);
                printf("\n\n \t\t\t\t\t\t----->2-spel 2");
                Reset_Color();
                printf(" \n \n\t\t\t\t\t\t\t3-spel 3");
                printf("\n\n\t\t\t\t\t\t\t Druk op esc om terug te gaan naar het spel...");
                strcpy(FileName,"Save 2");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tspel laden");
                printf("\n\n\t\t\t\t\t\t\t1-spel 1\n\n \t\t\t\t\t\t\t2-spel 2");
                Change_Color(10);
                printf(" \n \n\t\t\t\t\t\t----->3-spel 3");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t Druk op esc om terug te gaan naar het spel...");
                strcpy(FileName,"Save 3");
                break;
            }
        }
        if(language==5)
        {
            switch(ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tCarica partita");
                Change_Color(10);
                printf("\n\n\t\t\t\t\t\t----->1-Gioco 1");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-Gioco 2 \n \n\t\t\t\t\t\t\t3-Gioco 3");
                printf("\n\n\t\t\t\t\t\t\t Premi Esc per tornare al gioco...");
                strcpy(FileName,"Save 1");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tCarica partita");
                printf("\n\n\t\t\t\t\t\t\t1-Gioco 1");
                Change_Color(10);
                printf("\n\n \t\t\t\t\t\t----->2-Gioco 2");
                Reset_Color();
                printf(" \n \n\t\t\t\t\t\t\t3-Gioco 3");
                printf("\n\n\t\t\t\t\t\t\t Premi Esc per tornare al gioco...");
                strcpy(FileName,"Save 2");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tCarica partita");
                printf("\n\n\t\t\t\t\t\t\t1-Gioco 1\n\n \t\t\t\t\t\t\t2-Gioco 2");
                Change_Color(10);
                printf(" \n \n\t\t\t\t\t\t----->3-Gioco 3");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t Premi Esc per tornare al gioco...");
                strcpy(FileName,"Save 3");
                break;
            }
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
            Print_Logo(0);
            Load(FileName);
            if(Valid_Load==0)
            {
                Print_Logo(0);
                if(language==1)
                {
                    printf("\n\n\n\n\t\t\t\tSorry This File Doesn't Contain Any Saved Game ..\n\t\t\t\tPlease Save Game In This File First Before Loading It\n\n\t\t\t\tClick Any Button To go back.");
                }
                else if(language==2)
                {
                    printf("\n\n\n\n\t\t\t\tLo sentimos, este archivo no contiene ningun juego guardado ..\n\t\t\t\tGuarde el juego en este archivo antes de cargarlo\n\n\t\t\t\tHaga clic en cualquier botón para retroceder.");
                }
                else if(language==3)
                {
                    printf("\n\n\n\n\t\t\t\tEntschuldigung, diese Datei enthält kein gespeichertes Spiel ..\n\t\t\t\tBitte speichern Sie das Spiel in dieser Datei, bevor Sie es laden\n\n\t\t\t\tKlicken Sie auf eine beliebige Schaltflache, um zuruckzugehen.");
                }
                else if(language==4)
                {
                    printf("\n\n\n\n\t\t\t\tdit bestand bevat geen opgeslagen spel ..\n\t\t\t\tBewaar spel in dit bestand eerst voordat je het laadt\n\n\t\t\t\tKlik op een willekeurige knop Om terug te gaan.");
                }
                else if(language==5)
                {
                    printf("\n\n\n\n\t\t\t\tSpiacente Questo file non contiene alcun gioco salvato ..\n\t\t\t\tSi prega di salvare il gioco in questo file prima di caricarlo\n\n\t\t\t\tFare clic su qualsiasi pulsante Per tornare indietro.");
                }
                getche();
                Reset_To_Back();
                goto menu;
            }
            Print_Logo(0);
            loadValue=1;
            goto Done;
            break;
        case 27 :
            Print_Logo(0);
            Reset_To_Back();
            goto menu;
            break;
        default:
            goto load;
        }

        break;
//top 10 players//
    case 4: // BUTTON 4
        while (backKey!=27)
        {
            Print_Logo(1);
            Show_Top10();
            CursorPosition(45,20);
            if(language==1)
            {
                printf("Press esc to go back to menu");
            }
            else if(language==2)
            {
                printf("Presione esc para volver al menu");
            }
            else if(language==3)
            {
                printf("Drucken Sie esc, um zum Menu zuruckzukehren");
            }
            else if(language==4)
            {
                printf("Druk op esc om terug te gaan naar het menu");
            }
            else if(language==5)
            {
                printf("Premere esc per tornare al menu");
            }
            backKey=getche();
        }
        if(backKey==27)
        {
            Reset_To_Back();
            goto menu;
        }
        break;
//exit//
    case 5: // BUTTON 5
        ArrowVal=1;
exit:
        Print_Logo(0);
        if(language==1)
        {
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
        }
        else  if(language==2)
        {
            switch(ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSeguro que quieres salir?\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-SI");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-NO\n");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSeguro que quieres salir?\n\n\n");
                printf("\t\t\t\t\t\t\t1-SI\n\n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-NO\n");
                Reset_Color();
                break;
            }
        }
        else  if(language==3)
        {
            switch(ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSie sind sicher, dass Sie beenden wollen?\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-JA");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-NEIN\n");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSie sind sicher, dass Sie beenden wollen?\n\n\n");
                printf("\t\t\t\t\t\t\t1-JA\n\n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-NEIN\n");
                Reset_Color();
                break;
            }
        }
        else  if(language==4)
        {
            switch(ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWeet u zeker dat u wilt afsluiten?\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-JA");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-NEE\n");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWeet u zeker dat u wilt afsluiten?\n\n\n");
                printf("\t\t\t\t\t\t\t1-JA\n\n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-NEE\n");
                Reset_Color();
                break;
            }
        }
        else  if(language==5)
        {
            switch(ArrowVal)
            {
            case 1:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSei sicuro di voler uscire?\n\n\n");
                Change_Color(10);
                printf("\t\t\t\t\t\t----->1-SI");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t2-NO\n");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSei sicuro di voler uscire?\n\n\n");
                printf("\t\t\t\t\t\t\t1-SI\n\n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-NO\n");
                Reset_Color();
                break;
            }
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
    Print_Logo(0);
}
