#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "Moving.h"
//---------------------------FUNCTION THAT MOVES THE CRUSUR AND TO PUT - AND | ----------------------------------
void After_Min()
{
    while (1)
    {
        if (kbhit())
        {
            dif1=0;
            ClcdBtn=getche();
            break;
        }

        else
        {
            start1 = clock();
            Sleep(20);
            end1 = clock();
            dif1+= (end1-start1)/(double)CLOCKS_PER_SEC;
            if(dif1>60)
            {
                dif1=0;
                minPassed=1;
                end=clock();
                dif+=(end-start)/(double)CLOCKS_PER_SEC;
                start=clock();
                Print();
            }
        }
    }
}
void Moving()
{
Move:
    if (CruR%2==0&&CruC%2==1) // --
    {
        wchSign=5;
        WchSignCounter=2;
    }
    else if (CruR%2==1&&CruC%2==0) // |
    {
        wchSign=4;
        WchSignCounter=1;
    }
    After_Min();
    if(ClcdBtn==32) // SPACE BUTTON TO PRINT "|" .
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
        if(language==1)
        {
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
        }
        else if(language==2)
        {
            switch(ArrowVal)
            {

            case 1:
                Change_Color(10);
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Nuevo juego");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-controles \n \n\t\t\t\t\t\t\t3-Cargar juego \n\n \t\t\t\t\t\t\t4-guardar partida\n\n \t\t\t\t\t\t\t5-Salir\n");
                printf("\n\n\t\t\t\t\t\t\t Presiona esc para regresar al juego...");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuevo juego\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-controles ");
                Reset_Color();
                printf("\n \n\t\t\t\t\t\t\t3-Cargar juego \n\n \t\t\t\t\t\t\t4-guardar partida\n\n \t\t\t\t\t\t\t5-Salir\n");
                printf("\n\n\t\t\t\t\t\t\t Presiona esc para regresar al juego...");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuevo juego\n\n \t\t\t\t\t\t\t2-controles \n \n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->3-Cargar juego ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t4-guardar partida\n\n \t\t\t\t\t\t\t5-Salir\n");
                printf("\n\n\t\t\t\t\t\t\t Presiona esc para regresar al juego...");
                break;
            case 4:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuevo juego\n\n \t\t\t\t\t\t\t2-controles \n \n\t\t\t\t\t\t\t3-Cargar juego \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->4-guardar partida");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t5-Salir\n");
                printf("\n\n\t\t\t\t\t\t\t Presiona esc para regresar al juego...");
                break;
            case 5:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuevo juego\n\n \t\t\t\t\t\t\t2-controles \n \n\t\t\t\t\t\t\t3-Cargar juego \n\n \t\t\t\t\t\t\t4-guardar partida\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->5-Salir\n");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t Presiona esc para regresar al juego...");
                break;
            }
        }
        if(language==3)
        {
            switch(ArrowVal)
            {

            case 1:
                Change_Color(10);
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Neues Spiel");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-Kontrollen \n \n\t\t\t\t\t\t\t3-Spiel laden \n\n \t\t\t\t\t\t\t4-Spiel speichern\n\n \t\t\t\t\t\t\t5-Beenden\n");
                printf("\n\n\t\t\t\t\t\t\t Drucken Sie esc, um zum Spiel zuruckzukehren...");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Neues Spiel\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-Kontrollen ");
                Reset_Color();
                printf("\n \n\t\t\t\t\t\t\t3-Spiel laden \n\n \t\t\t\t\t\t\t4-Spiel speichern\n\n \t\t\t\t\t\t\t5-Beenden\n");
                printf("\n\n\t\t\t\t\t\t\t Drucken Sie esc, um zum Spiel zuruckzukehren...");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Neues Spiel\n\n \t\t\t\t\t\t\t2-Kontrollen \n \n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->3-Spiel laden ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t4-Spiel speichern\n\n \t\t\t\t\t\t\t5-Beenden\n");
                printf("\n\n\t\t\t\t\t\t\t Drucken Sie esc, um zum Spiel zuruckzukehren...");
                break;
            case 4:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Neues Spiel\n\n \t\t\t\t\t\t\t2-Kontrollen \n \n\t\t\t\t\t\t\t3-Spiel laden \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->4-Spiel speichern");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t5-Beenden\n");
                printf("\n\n\t\t\t\t\t\t\t Drucken Sie esc, um zum Spiel zuruckzukehren...");
                break;
            case 5:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Neues Spiel\n\n \t\t\t\t\t\t\t2-Kontrollen \n \n\t\t\t\t\t\t\t3-Spiel laden \n\n \t\t\t\t\t\t\t4-Spiel speichern\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->5-Beenden\n");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t Drucken Sie esc, um zum Spiel zuruckzukehren...");
                break;
            }
        }
        if(language==4)
        {
            switch(ArrowVal)
            {

            case 1:
                Change_Color(10);
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Nieuw spel");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t\t3-Spel laden \n\n \t\t\t\t\t\t\t4-spel opslaan\n\n \t\t\t\t\t\t\t5-spel verlaten\n");
                printf("\n\n\t\t\t\t\t\t\t Druk op esc om terug te gaan naar het spel...");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nieuw spel\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-Controls ");
                Reset_Color();
                printf("\n \n\t\t\t\t\t\t\t3-Spel laden \n\n \t\t\t\t\t\t\t4-spel opslaan\n\n \t\t\t\t\t\t\t5-spel verlaten\n");
                printf("\n\n\t\t\t\t\t\t\t Druk op esc om terug te gaan naar het spel...");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nieuw spel\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->3-Spel laden ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t4-spel opslaan\n\n \t\t\t\t\t\t\t5-spel verlaten\n");
                printf("\n\n\t\t\t\t\t\t\t Druk op esc om terug te gaan naar het spel...");
                break;
            case 4:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nieuw spel\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t\t3-Spel laden \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->4-spel opslaan");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t5-spel verlaten\n");
                printf("\n\n\t\t\t\t\t\t\t Druk op esc om terug te gaan naar het spel...");
                break;
            case 5:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nieuw spel\n\n \t\t\t\t\t\t\t2-Controls \n \n\t\t\t\t\t\t\t3-Spel laden \n\n \t\t\t\t\t\t\t4-spel opslaan\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->5-spel verlaten\n");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t Druk op esc om terug te gaan naar het spel...");
                break;
            }
        }
        if(language==5)
        {
            switch(ArrowVal)
            {

            case 1:
                Change_Color(10);
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t----->1-Nuovo gioco");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t2-controlli \n \n\t\t\t\t\t\t\t3-Carica gioco \n\n \t\t\t\t\t\t\t4-salva il gioco\n\n \t\t\t\t\t\t\t5-Uscire\n");
                printf("\n\n\t\t\t\t\t\t\t Premi Esc per tornare al gioco...");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuovo gioco\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->2-controlli ");
                Reset_Color();
                printf("\n \n\t\t\t\t\t\t\t3-Carica gioco \n\n \t\t\t\t\t\t\t4-salva il gioco\n\n \t\t\t\t\t\t\t5-Uscire\n");
                printf("\n\n\t\t\t\t\t\t\t Premi Esc per tornare al gioco...");
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuovo gioco\n\n \t\t\t\t\t\t\t2-controlli \n \n\t\t\t\t\t\t");
                Change_Color(10);
                printf("----->3-Carica gioco ");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t4-salva il gioco\n\n \t\t\t\t\t\t\t5-Uscire\n");
                printf("\n\n\t\t\t\t\t\t\t Premi Esc per tornare al gioco...");
                break;
            case 4:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuovo gioco\n\n \t\t\t\t\t\t\t2-controlli \n \n\t\t\t\t\t\t\t3-Carica gioco \n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->4-salva il gioco");
                Reset_Color();
                printf("\n\n \t\t\t\t\t\t\t5-Uscire\n");
                printf("\n\n\t\t\t\t\t\t\t Premi Esc per tornare al gioco...");
                break;
            case 5:
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1-Nuovo gioco\n\n \t\t\t\t\t\t\t2-controlli \n \n\t\t\t\t\t\t\t3-Carica gioco \n\n \t\t\t\t\t\t\t4-salva il gioco\n\n \t\t\t\t\t\t");
                Change_Color(10);
                printf("----->5-Uscire\n");
                Reset_Color();
                printf("\n\n\t\t\t\t\t\t\t Premi Esc per tornare al gioco...");
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
            if(language==1)
            {
                printf("\n\n\n\n\t\t\t\t\t\tControls:\n");
                printf("\t\t\t\t\t\tPress Space to change from vertical line to horizontal line and V.V\n");
                printf("\t\t\t\t\t\tpress Use right arrow to go right\n\t\t\t\t\t\tpress left arrow to go left\n\t\t\t\t\t\tpress up arrow to go up\n \t\t\t\t\t\tpress down arrow to go down\n");
                printf("\t\t\t\t\t\tpress \"U\" to Undo move & \"R\" to Redo move ");
                printf("\n\t\t\t\t\t\tpress Enter to select place");
                printf("\n\n\t\t\t\t\t\tpress esc to go back");
                printf("\n\t\t\t\t\t\tpress \"M\" to Mute the music");
                printf("\n\t\t\t\t\t\tpress \"P\" to Play the music again");
            }
            else if(language==2)
            {
                printf("\n\n\n\n\t\t\t\t\t\tControles:\n");
                printf("\t\t\t\t\t\tPresione Espacio para cambiar de linea vertical a linea horizontal\n");
                printf("\t\t\t\t\t\tpresione la flecha derecha para ir a la derecha\n\t\t\t\t\t\tpresione la flecha izquierda para ir a la izquierda\n\t\t\t\t\t\tpresionar la flecha hacia arriba para subir\n \t\t\t\t\t\tpresionar la flecha hacia abajo para bajar\n");
                printf("\t\t\t\t\t\tpresione \"U\" para deshacer movimiento & \"R\" para rehacer mover ");
                printf("\n\t\t\t\t\t\tpresione Enter para seleccionar el lugar");
                printf("\n\t\t\t\t\t\tpresione esc para ver las opciones");
                printf("\n\t\t\t\t\t\tpresiona \"M\" para silenciar la musica durante el juego");
                printf("\n\t\t\t\t\t\tpresione \"P\" para reproducir la musica nuevamente");
            }
            else if(language==3)
            {
                printf("\n\n\n\n\t\t\t\t\t\tKontrollen:\n");
                printf("\t\t\t\t\t\tDrucken Sie die Leertaste, um von der vertikalen Linie zur horizontalen Linie\n");
                printf("\t\t\t\t\t\tDrucke den rechten Pfeil, um nach rechts zu gehen\n\t\t\t\t\t\tDrucken Sie den linken Pfeil, um nach links zu gehen\n\t\t\t\t\t\tDrucken Sie den Pfeil nach oben, um nach oben zu gehen\n \t\t\t\t\t\tDrucken Sie den Pfeil nach unten, um nach unten zu gehen\n");
                printf("\t\t\t\t\t\tDrucke \"U\" um die Bewegung ruckgangig zu machen und \"R\" um die Bewegung zu wiederholen ");
                printf("\n\t\t\t\t\t\tDrucken Sie die Eingabetaste, um den Ort auszuwahlen");
                printf("\n\t\t\t\t\t\tDrucken Sie esc fur Optionen");
                printf("\n\t\t\t\t\t\tDrucken Sie \"M\", um die Musik wahrend des Spiels stumm zu schalten");
                printf("\n\t\t\t\t\t\tDrucken Sie \"P\", um die Musik erneut abzuspielen");

            }
            else if(language==4)
            {
                printf("\n\n\n\n\t\t\t\t\t\tControls:\n");
                printf("\n\t\t\t\t\t\t druk op Spatie om van verticale lijn naar horizontale lijn \n");
                printf("\n\t\t\t\t\t\t druk op de pijl naar rechts om naar rechts te gaan\n\t\t\t\t\t\tdruk op de linkerpijl om naar links te gaan\n\t\t\t\t\t\t druk op de pijl omhoog om omhoog te gaan\n \t\t\t\t\t\t druk op de pijl omlaag om naar beneden te gaan\n");
                printf("\n\t\t\t\t\t\t druk op \"U\" om verplaatsing ongedaan te maken & \"R\" om Opnieuw te verplaatsen ");
                printf("\n\t\t\t\t\t\t druk op Enter om een plaats te selecteren");
                printf("\n\t\t\t\t\t\t druk op esc voor opties");
                printf("\n\t\t\t\t\t\t druk op \"M\", om de muziek tijdens het spel te dempen");
                printf("\n\t\t\t\t\t\t druk op \"P\", om de muziek opnieuw af te spelen");

            }
            else if(language==5)
            {
                printf("\n\n\n\n\t\t\t\t\t\tcontrolli:\n");
                printf("\t\t\t\t\t\tPremere Spazio per passare dalla linea verticale alla linea orizzontale\n");
                printf("\t\t\t\t\t\tpremi la freccia destra per andare a destra\n\t\t\t\t\t\tpremere la freccia sinistra per andare a sinistra\n\t\t\t\t\t\tpremere la freccia su per salire\n \t\t\t\t\t\tpremere la freccia giu per scendere\n");
                printf("\t\t\t\t\t\tpremere \"U\" per annullare la mossa e \"R\" per ripetere la mossa ");
                printf("\n\t\t\t\t\t\tpremere Invio per selezionare il luogo");
                printf("\n\t\t\t\t\t\tpremere esc per le opzioni");
                printf("\n\t\t\t\t\t\tpremere \"M\", per silenziare la musica durante il gioco");
                printf("\n\t\t\t\t\t\tpremere \"P\", per riprodurre di nuovo la musica");
            }
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
                system("cls");
                Load(FileName);
                if(Valid_Load==0)
                {
                    system("cls");
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
            if(language==1)
            {
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
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSave Game");
                    printf("\n\n\t\t\t\t\t\t\t1-Game 1\n\n \t\t\t\t\t\t\t2-Game 2");
                    Change_Color(10);
                    printf(" \n \n\t\t\t\t\t\t----->3-Game 3");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t Press esc to go back to the game...");
                    strcpy(FileName,"Save 3");
                    break;
                }
            }
            else if(language==2)
            {
                switch(ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\Guardar partida");
                    Change_Color(10);
                    printf("\n\n\t\t\t\t\t\t----->1-Juego 1");
                    Reset_Color();
                    printf("\n\n \t\t\t\t\t\t\t2-Juego 2 \n \n\t\t\t\t\t\t\t3-Juego 3");
                    printf("\n\n\t\t\t\t\t\t\t Presiona esc para regresar al juego...");
                    strcpy(FileName,"Save 1");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tGuardar partida");
                    printf("\n\n\t\t\t\t\t\t\t1-Juego 1");
                    Change_Color(10);
                    printf("\n\n \t\t\t\t\t\t----->2-Juego 2");
                    Reset_Color();
                    printf(" \n \n\t\t\t\t\t\t\t3-Juego 3");
                    printf("\n\n\t\t\t\t\t\t\t Presiona esc para regresar al juego...");
                    strcpy(FileName,"Save 2");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tGuardar partida");
                    printf("\n\n\t\t\t\t\t\t\t1-Juego 1\n\n \t\t\t\t\t\t\t2-Juego 2");
                    Change_Color(10);
                    printf(" \n \n\t\t\t\t\t\t----->3-Juego 3");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t Presiona esc para regresar al juego...");
                    strcpy(FileName,"Save 3");
                    break;
                }
            }
            else if(language==3)
            {
                switch(ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\Spiel speichern");
                    Change_Color(10);
                    printf("\n\n\t\t\t\t\t\t----->1-Spiel 1");
                    Reset_Color();
                    printf("\n\n \t\t\t\t\t\t\t2-Spiel 2 \n \n\t\t\t\t\t\t\t3-Spiel 3");
                    printf("\n\n\t\t\t\t\t\t\t Drucken Sie esc, um zum Spiel zuruckzukehren...");
                    strcpy(FileName,"Save 1");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSpiel speichern");
                    printf("\n\n\t\t\t\t\t\t\t1-Spiel 1");
                    Change_Color(10);
                    printf("\n\n \t\t\t\t\t\t----->2-Spiel 2");
                    Reset_Color();
                    printf(" \n \n\t\t\t\t\t\t\t3-Spiel 3");
                    printf("\n\n\t\t\t\t\t\t\t Drucken Sie esc, um zum Spiel zuruckzukehren...");
                    strcpy(FileName,"Save 2");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSpiel speichern");
                    printf("\n\n\t\t\t\t\t\t\t1-Spiel 1\n\n \t\t\t\t\t\t\t2-Spiel 2");
                    Change_Color(10);
                    printf(" \n \n\t\t\t\t\t\t----->3-Spiel 3");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t Drucken Sie esc, um zum Spiel zuruckzukehren...");
                    strcpy(FileName,"Save 3");
                    break;
                }
            }
            else if(language==4)
            {
                switch(ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\Spel opslaan");
                    Change_Color(10);
                    printf("\n\n\t\t\t\t\t\t----->1-Spel 1");
                    Reset_Color();
                    printf("\n\n \t\t\t\t\t\t\t2-Spel 2 \n \n\t\t\t\t\t\t\t3-Spel 3");
                    printf("\n\n\t\t\t\t\t\t\t Druk op esc om terug te gaan naar het spel...");
                    strcpy(FileName,"Save 1");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSpel opslaan");
                    printf("\n\n\t\t\t\t\t\t\t1-Spel 1");
                    Change_Color(10);
                    printf("\n\n \t\t\t\t\t\t----->2-Spel 2");
                    Reset_Color();
                    printf(" \n \n\t\t\t\t\t\t\t3-Spel 3");
                    printf("\n\n\t\t\t\t\t\t\t Druk op esc om terug te gaan naar het spel...");
                    strcpy(FileName,"Save 2");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSpel opslaan");
                    printf("\n\n\t\t\t\t\t\t\t1-Spel 1\n\n \t\t\t\t\t\t\t2-Spel 2");
                    Change_Color(10);
                    printf(" \n \n\t\t\t\t\t\t----->3-Spel 3");
                    Reset_Color();
                    printf("\n\n\t\t\t\t\t\t\t Druk op esc om terug te gaan naar het spel...");
                    strcpy(FileName,"Save 3");
                    break;
                }
            }
            else if(language==5)
            {
                switch(ArrowVal)
                {
                case 1:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\Salva il gioco");
                    Change_Color(10);
                    printf("\n\n\t\t\t\t\t\t----->1-gioco 1");
                    Reset_Color();
                    printf("\n\n \t\t\t\t\t\t\t2-gioco 2 \n \n\t\t\t\t\t\t\t3-gioco 3");
                    printf("\n\n\t\t\t\t\t\t\t Premi Esc per tornare al gioco...");
                    strcpy(FileName,"Save 1");
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSalva il gioco");
                    printf("\n\n\t\t\t\t\t\t\t1-gioco 1");
                    Change_Color(10);
                    printf("\n\n \t\t\t\t\t\t----->2-gioco 2");
                    Reset_Color();
                    printf(" \n \n\t\t\t\t\t\t\t3-gioco 3");
                    printf("\n\n\t\t\t\t\t\t\t Premi Esc per tornare al gioco...");
                    strcpy(FileName,"Save 2");
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSalva il gioco");
                    printf("\n\n\t\t\t\t\t\t\t1-gioco 1\n\n \t\t\t\t\t\t\t2-gioco 2");
                    Change_Color(10);
                    printf(" \n \n\t\t\t\t\t\t----->3-gioco 3");
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
                ValidPlace=0; // to print warning
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
                else if (wchPlayer==3)
                {
                    Player3.Played_Moves++;
                }
                else if (wchPlayer==4)
                {
                    Player4.Played_Moves++;
                }
                wchPlayerMove(Num_Of_Players);
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
        else if (ClcdBtn==75) // left arrow BUTTON TO GO < .
        {
            if(B[CruR][CruC]==1)
            {
                A[CruR][CruC]=' ';
            }
            CruC-=2;
            Check_The_Game_Limits();
            A[CruR][CruC]='|';
        }
        else if (ClcdBtn==72) // up arrpw BUTTON TO GO ^ .
        {
            if(B[CruR][CruC]==1)
            {
                A[CruR][CruC]=' ';
            }
            CruR-=2;
            Check_The_Game_Limits();
            A[CruR][CruC]='|';
        }
        else if (ClcdBtn==80) // down arrow BUTTON TO GO DOWN .
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
                ValidPlace=0;
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
                else if (wchPlayer==3)
                {
                    Player3.Played_Moves++;
                }
                else if (wchPlayer==4)
                {
                    Player4.Played_Moves++;
                }
                wchPlayerMove(Num_Of_Players);
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
