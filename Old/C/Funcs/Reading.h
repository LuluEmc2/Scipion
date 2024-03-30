#ifndef __READING_DEF__
#define __READING_DEF__

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Random.h"


unsigned long nb_char(FILE* file);
int read(char* str, int size);
int check_ip(char* ip);
void random_line(char* line, int size, FILE* file, unsigned long file_size);

#endif