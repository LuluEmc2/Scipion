#include <windows.h>
#include <stdio.h>

#include "Style.h"

void rotating_loading_bar(int time, int iteration)
{
    for(int i = 0; i < iteration; i++)
    {
        Sleep(time);
        printf("/");
        printf("\b");
    
        Sleep(time);
        printf("|");
        printf("\b");
    
        Sleep(time);
        printf("\\");
        printf("\b");
    
        Sleep(time);
        printf("-");
        printf("\b");
    }
    
    Sleep(time);
    printf(" \n");
}

void progressing_loading_bar(int time, int iteration)
{
    printf("[");
    for(int i = 0; i < iteration; i++)
        printf(" ");
    printf("]");
    for(int i = 0; i < iteration+1; i++)
        printf("\b");

    for(int i = 0; i < iteration; i++)
    {
        Sleep(time);
        printf("=");
    }

    printf("]\n");
}
