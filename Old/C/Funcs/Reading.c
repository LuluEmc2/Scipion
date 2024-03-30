#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Random.h"

#include "Reading.h"

unsigned long nb_char(FILE* file)
{
	unsigned long l = 0;
    char c;

 
	while((c=fgetc(file)) != EOF)
	{
        l++;
	}

    rewind(file);
	return l;
}

void empty_buffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void random_line(char* line, int size, FILE* file, unsigned long file_size)
{
    unsigned long rand_char = random_long()%(unsigned long)file_size;
    fseek(file, rand_char, SEEK_SET);

    char c = '0';
    while((c=fgetc(file)) != '\n')
        continue;
    int i = 0;
    while((c=fgetc(file)) != '\n')
    {
        line[i] = c;
        i++;
        continue;
    }
}

int read(char* str, int size)
{
    char* startPos = NULL;
 
    if (fgets(str, size+1, stdin) != NULL)
    {
        startPos = strchr(str, '\n');
        if (startPos != NULL)
        {
            *startPos = '\0';
        }
        else
        {
            empty_buffer();
        }
        return 0;
    }
    else
    {
        empty_buffer();
        return 1;
    }
}

int check_ip(char* ip)
{
    int ip1 = 0;
    int ip2 = 0;
    int ip3 = 0;
    int ip4 = 0;
    char c = 0;

    if(sscanf_s(ip, "%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4) == EOF)
        return 0;
    if(ip1 > 255 || ip2 > 255 || ip3 > 255 || ip4 > 255)
        return 0;
    if(ip1 < 0 || ip2 < 0 || ip3 < 0 || ip4 < 0)
        return 0;
    
    return 1;
}