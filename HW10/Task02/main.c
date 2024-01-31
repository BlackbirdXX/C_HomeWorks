/*
Задача 2. Удалить пробелы из текста
В файле .txt необходимо удалить все лишние пробелы (в начале предложения
и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
записать в .txt.
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
