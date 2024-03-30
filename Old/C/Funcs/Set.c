#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "Random.h"
#include "Reading.h"
#include "Style.h"

#include "Set.h"

void set_user(char* user)
{
    FILE* f_names = fopen("./Files/noms.txt", "r");
    unsigned long f_names_size = nb_char(f_names);
    FILE* names = fopen("./Files/prenoms.txt", "r");
    unsigned long names_size = nb_char(names);
    FILE* user_names = fopen("./Files/user_names.txt", "r");
    unsigned long user_names_size = nb_char(user_names);

    int rmode = /*random_int()%5*/0;
    char new_user[64] = "";;

    switch (rmode)
    {
    case 0:
        
        random_line(new_user, 64, f_names, f_names_size);
        break;
    
    default:
        break;
    }

    fclose(f_names);
    fclose(names);
    fclose(user_names);

    strcpy(user, new_user);
}

void set_target(char* ip)
{
    printf("Choose target : ");
    char new_ip[15] = "0000.000.000.00";
    read(new_ip, 15);

    printf("Searching target ");
    rotating_loading_bar(100, 5);
    if(!check_ip(new_ip))
    {
        printf("Not a valid ip : %s\n", new_ip);
        return;
    }
    printf("Target found\n\n");

    printf("Connecting ");
    progressing_loading_bar(250, 30);
    ip = new_ip;
    printf("%s connected successfully\n", ip);
}