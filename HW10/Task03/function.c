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

void add_extension(char *line)
{
    strcat(line, ".html");
}

void processing(char * line)
{
    int i = strlen(line);
    int index_point = 0;
    int index_slash = 0;
    while (i != 0)
    {
        if(line[i] == '.')
        {
            index_point = i;
        }
        if(line[i] == '/')
        {
            index_slash = i;
            break;
        }
        i--;
    }
    if (index_slash > index_point)
    {
        strcat(line, ".html");
    }
    else if (index_slash < index_point)
    {
        strcpy(line + index_point, ".html");
    }
    else
    {
        strcat(line, ".html");
    }
}