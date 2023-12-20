#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Task01(int num);
void Task02(int a, int b);
void Task03(int num);
void Task04(int nums[]);
char* FillString(char* str,int max_len);
void Task05(char str[]);
int Task06(int n, int p);

int main(int argc, char const *argv[])
{
    Task01(54321);
    printf("\n");
    Task02(7,2);
    Task02(2,7);
    Task03(255);
    int nums[] ={12, 13, 173, 28, 19, 0};
    Task04(nums);
    char str[40];
    FillString(str, 40);
    Task05(str);
    printf("\n%d\n", Task06(3, 4));
    return 0;
}

void Task01(int num)
{ 
    /*Дано натуральное число N. Выведите все его цифры по одной, в прямом
    порядке, разделяя их пробелами или новыми строками. Необходимо
    реализовать рекурсивную функцию.*/

    if (num == 0){
        return;
    }
    Task01(num / 10);
    printf("%d ", num % 10);
}

void Task02(int a, int b)
{
    /*Составить рекурсивную функцию. Выведите все числа от A до B
    включительно, в порядке возрастания, если A < B, или в порядке убывания в
    противном случае.*/
    if (a == b){
        printf("%d \n", a);
        return;
    }
    if (a <= b){
        printf("%d ", a);
        Task02(a + 1, b);
    }

    if (a >= b){
        printf("%d ", b);
        Task02(b + 1, a);
    }
}

void Task03(int num)
{
    /*Дано натуральное число N. Посчитать количество «1» в двоичной записи
    числа.*/
    static int count = 0;
    if (num == 0){
        printf("%d\n", count);
        count = 0;
        return;
    }
    if (num % 2 == 1){
        count ++;
    }
    Task03(num / 2);
}

void Task04(int nums[])
{
    /*Дана последовательность целых чисел через пробел, завершающаяся числом0. 
    Выведите все нечетные числа из этой последовательности, сохраняя их порядок.*/
    static int index = 0;
    if (nums[index] == 0)
    {
        index = 0;
        return;
    }
    if ((nums[index] % 2) != 0)
    {
        printf("%d ", nums[index]);
    }
    index ++;
    Task04(nums);
}

char* FillString(char* str,int max_len)
{
    puts("\nEnter the line.\n");
    int i = 0;
    char ch;
    while ((ch = getchar()) != '.' && ch != EOF && i < max_len -1){
        str[i++] = ch;
    }
    str[i] = '.';
    str[i+1] = '\0';
    return str;
}

void Task05(char str[])
{
    /*Дана строка из английских символов, пробелов и знаков препинания. В конце
    строки символ точка. Необходимо реализовать рекурсивную функцию,
    которая считывает данную строку со стандартного потока ввода и возвращает
    целое число – количество символов 'a' в данной строке.*/

    static int counter = 0;
    static int ctr = 0;
    if (str[counter] == '.')
    {
        printf("%d ", ctr);
        counter = 0;
        return;
    }
    if (str[counter] == 'a')
    {
        ctr++;
    }
    counter ++;
    Task05(str);
}

int Task06(int n, int p)
{
    /*Написать рекурсивную функцию возведения целого числа n в степень p.*/

    if(!p){
        return 1;
    }
    return n * Task06(n, p-1);
}