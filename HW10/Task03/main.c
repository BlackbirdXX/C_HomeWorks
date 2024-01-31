/*
Задача 3. Изменить расширение
В файле .txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл.txt.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

int main(int argc, char const *argv[])
{
    char * f_in = "input.txt";
    char * f_out = "output.txt";
    char line[1000];
    read_file(f_in, line);
    printf("Input string  : %s\n", line);
    processing(line);
    printf("Output string : %s\n", line);
    write_file(f_out, line);
    return 0;
}
