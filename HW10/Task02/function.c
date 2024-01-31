#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

void read_file(char *f_in, char * line)
{
    FILE *fp;
    fp = fopen(f_in, "r");
    if (fp == NULL)
    {
        printf("Error, unable to open the file \n");
        exit(-1);
    }
    else
    {
        while ((fgets(line, 1000, fp)) != NULL)
        {
            printf ("File read - OK\n");
        }
        fclose(fp);
    }
}

void write_file(char *f_out, char * line)
{
    FILE *fp;
    fp = fopen(f_out, "w");
    if(fp)
    {
        fputs(line, fp);
        fclose(fp);
        printf("File has been written\n");
    }
}
void line_turn_left(int pos, char * line)
{
    while (pos < strlen(line))
    {
        line[pos] = line[pos + 1];
        pos++;
    }
}

void processing(char * line)
{
    while (line[0] == ' ')
    {
        line_turn_left(0, line);
    }
    for (int i = 0; i < strlen(line); i++)
    {
        if((line[i] == ' ') && (line[i+1] == ' '))
        {
            line_turn_left(i, line);
            i--;
        }
    }
}