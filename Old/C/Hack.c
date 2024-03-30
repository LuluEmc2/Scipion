#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "Funcs/Set.h"


int main(void)
{
    choose_int_seed((int)time(NULL));
    choose_long_seed((long)time(NULL));

    srand((unsigned int)time(NULL));

    char* ip = "000.000.000.000";
    char user[256] = "";

    set_target(ip);

    printf("%s", ip);
    return 0;
}