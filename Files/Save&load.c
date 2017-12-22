#include "Save&load.h"
#include <stdio.h>

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
            fprintf(fSave,"%i %i %i %i ",Player1.Player_Info[i][y],Player2.Player_Info[i][y],Player3.Player_Info[i][y],Player4.Player_Info[i][y]);
        }
    }
    fprintf(fSave,"%i %i %i %i %i %i %i %i %i %i %lf %i %i %i %i %i ",CruR,CruC,ClcdBtn,wchSign,WchSignCounter,turns,wchPlayer,NumRemainningDots,sum,minute,dif,PlayerVsComp,undoCounter,Valid_Redo,Last_Redo,Num_Of_Players);
    for( i=0; i<=undoCounter; i++)
    {
        fprintf(fSave,"%i %i %i ",undoR[i],undoC[i],undoTurns[i]);
    }
    fprintf(fSave,"%i %i %i %i %i %i %i %i ",Player1.Played_Moves,Player1.Score,Player2.Played_Moves,Player2.Score,Player3.Played_Moves,Player3.Score,Player4.Played_Moves,Player4.Score);
    fprintf(fSave,"%c ",PlayerSign);
    fprintf(fSave,"%s; %s, %s! %s@",Player1.Name,Player2.Name,Player3.Name,Player4.Name);
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
            fscanf(fSave,"%i %i %i %i ",&Player1.Player_Info[i][y],&Player2.Player_Info[i][y],&Player3.Player_Info[i][y],&Player4.Player_Info[i][y]);
        }
    }
    fscanf(fSave,"%i %i %i %i %i %i %i %i %i %i %lf %i %i %i %i %i ",&CruR,&CruC,&ClcdBtn,&wchSign,&WchSignCounter,&turns,&wchPlayer,&NumRemainningDots,&sum,&minute,&dif,&PlayerVsComp,&undoCounter,&Valid_Redo,&Last_Redo,&Num_Of_Players);
    for( i=0; i<=undoCounter; i++)
    {
        fscanf(fSave,"%i %i %i ",&undoR[i],&undoC[i],&undoTurns[i]);
    }
    fscanf(fSave,"%i %i %i %i %i %i %i %i ",&Player1.Played_Moves,&Player1.Score,&Player2.Played_Moves,&Player2.Score,&Player3.Played_Moves,&Player3.Score,&Player4.Played_Moves,&Player4.Score);
    fscanf(fSave,"%c ",&PlayerSign);
    fscanf(fSave,"%[^;]; %[^,], %[^!]! %[^@]@",Player1.Name,Player2.Name,Player3.Name,Player4.Name);
    fclose(fSave);
}

