#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparator (const int *a, const int *b);
void Task01(void);
void Task02(void);
void Task03(void);
void Task04(void);
void Task05(void);
void Task06(void);

int main(int argc, char const *argv[])
{
    Task01();
    Task02();
    Task03();
    Task04();
    Task05();
    Task06();
    return 0;
}

int comparator (const int *a, const int *b) {
    return *a - *b;
}

// Задача 1. По одному разу
void Task01(void)
{
    char * task1_in = "task1_in.txt";
    char * task1_out = "task1_out.txt";
    char line[100];
    char tsk1[2][100];
    FILE *fp;
    int count = 0;
    fp = fopen(task1_in, "r");
    while (fscanf(fp, "%s", line) == 1)
    {
        strcpy(tsk1[count++], line);
    }
    fclose(fp);

    fp = fopen(task1_out, "w");
    for (int i = 0; i < strlen(tsk1[0]); i++)
    {
        for (int j = 0; j < strlen(tsk1[1]); j++)
        {   
            if(tsk1[0][i] == tsk1[1][j]){
                fprintf(fp, "%c ", tsk1[0][i]);
            }
        }
    }
    fclose(fp);
}

// Задача 2. Заменить a на b
void Task02(void)
{
    char * task2_in = "task2_in.txt";
    char * task2_out = "task2_out.txt";
    char line[1000];
    FILE *fp;
    fp = fopen(task2_in, "r");
    fscanf(fp, "%s", line);
    fclose(fp);
    fp = fopen(task2_out, "w");
    for (int i = 0; i < strlen(line); i++)
    {
        if(line[i] == 'a'){
            fprintf(fp, "%c", 'b');
        }
        else if(line[i] == 'A'){
            fprintf(fp, "%c", 'B');
        }
        else if(line[i] == 'b'){
            fprintf(fp, "%c", 'a');
        }
        else if(line[i] == 'B'){
            fprintf(fp, "%c", 'A');
        }
        else {
            fprintf(fp, "%c", line[i]);
        }
    }
    fclose(fp);
}

// Задача 3. Числа в массив

void Task03(void)
{
    char * task3_in = "task3_in.txt";
    char * task3_out = "task3_out.txt";
    char line[1000];
    char tsk3[25][1000];
    FILE *fp;
    int count = 0;
    fp = fopen(task3_in, "r");
    while (fscanf(fp, "%*[^0-9]%s", line) == 1)
    {
        strcpy(tsk3[count++], line);
    }
    fclose(fp);

    int numbers[count];

    for (int i = 0; i < count; i++)
    {
        numbers[i] = atoi(tsk3[i]);
    }
    
    qsort(numbers, count, sizeof (int), (int(*) (const void *, const void *)) comparator);
    
    fp = fopen(task3_out, "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d ", numbers[i]);
    }
    fclose(fp);
}

// Задача 4. Удалить повторяющиеся символы

void Task04(void)
{
    char * task4_in = "task4_in.txt";
    char * task4_out = "task4_out.txt";
    char line[1000];
    char tsk4[1000] = {"\0"};
    FILE *fp;
    int count = 0;
    fp = fopen(task4_in, "r");
    while (fscanf(fp, "%s", line) == 1)
    {
        strcat(tsk4, line);
    }
    fclose(fp);
    char out_line[strlen(tsk4)];
    int can_insert = 1;
    int insert_count = 0;
    char c;
    for (int i = 0; i < strlen(tsk4); i++)
    {
        c = tsk4[i];
        if(strchr(out_line, c) == NULL ){
            out_line[insert_count] = c;
            insert_count++;
        }
    }
    out_line[insert_count] = '\0';
    fp = fopen(task4_out, "w");
    fprintf(fp, "%s", out_line);
    fclose(fp);
}

// Задача 5. Самое длинное слово
void Task05(void)
{
    char * task5_in = "task5_in.txt";
    char * task5_out = "task5_out.txt";
    char line[100];
    char tsk5[20][100];
    FILE *fp;
    int word_counter = 0;
    fp = fopen(task5_in, "r");
    while (fscanf(fp, "%s", line) == 1)
    {
        strcpy(tsk5[word_counter++], line);
    }
    fclose(fp);

    int new_count = 0;
    int max_str_len = 0;
    int index_max = 0;
    for (int i = 0; i < word_counter; i++)
    {
        if(max_str_len < strlen(tsk5[i])){
            max_str_len = strlen(tsk5[i]);
            index_max = i;
        }
    }
    
    fp = fopen(task5_out, "w");
    fprintf(fp, "%s", tsk5[index_max]);
    fclose(fp);
}

// Задача 6. Заканчивается на a

void Task06(void)
{
    char * task6_in = "task6_in.txt";
    char * task6_out = "task6_out.txt";
    char line[100];
    char tsk6[20][100];
    FILE *fp;
    int word_counter = 0;
    fp = fopen(task6_in, "r");
    while (fscanf(fp, "%s", line) == 1)
    {
        strcpy(tsk6[word_counter++], line);
    }
    fclose(fp);

    int a_count = 0;
    for (int i = 0; i < word_counter; i++)
    {
        if(tsk6[i][strlen(tsk6[i])-1] == 'a'){ 
            a_count++;
        }
    }
    
    fp = fopen(task6_out, "w");
    fprintf(fp, "%d", a_count);
    fclose(fp);
}