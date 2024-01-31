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



void processing(char * line)
{
    char temp;
    for (size_t i = 0; i < strlen(line);)
    {
        if(line[i] == ' ')
        {
            i++;
        }
        else if (line[i] == ' ' && line[i+1] == ' ')
        {
            i += 2;
        }
        else if (line[i+1] == ' ')
        {
            temp = line[i];
            line[i] = line[i+2]; 
            line[i+2] = temp;
            i += 3;
        }
        else if (line[i+1] == '\0')
        {
            break;
        }
        
        else
        {
            temp = line[i];
            line[i] = line[i+1]; 
            line[i+1] = temp;
            i += 2;
        }
    }
}