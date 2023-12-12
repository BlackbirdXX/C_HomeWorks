#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

void Task01(void){
    printf("Задача 1. Сколько зерен на доске?\n");
    int cell = 0;
    unsigned long long corn = 1;
    printf("Выберите клетку Шахматной доски. От 1 до 64.\n");
    scanf("%d", &cell);

    while (cell < 1 || cell > 64){
        printf("Повторите ввод. От 1 до 64.\n");
        scanf("%d", &cell);
    }

    corn = pow(2, cell-1);
    printf("corn = %d\n", corn);
}

int Nod(int a, int b){
    while (a != b) {
        if (a > b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;
}

void Task02(void){
    int a,b;
    printf("Задача 2. НОД.\n");
    printf("Введите два целых числа, разделяя их пробелом.\n");
    scanf("%d %d", &a , &b);
    printf("%d\n", Nod(a, b));
}

int Is_happy_number(int n){
    int sum, mult;
    for (; n > 0; n /=10)
    {
        sum += n % 10;
        mult *= n % 10;
    }
    if (sum == mult)
    {
        return 1;
    }
    else {
        return 0;
    }
}

void Task03(void){
    printf("Задача 3. Сумма цифр равна произведению.\n");
    int num = 0;
    printf("Введите положительное число.\n");
    scanf("%d", &num);

    while (num < 1){
        printf("Повторите ввод. Число должно быть положительным.\n");
        scanf("%d", &num);
    }
    printf(Is_happy_number(num) ? "Yes\n" : "No\n");
}

void Task04(void){
    printf("Задача 4. Сумма от 1 до N.\n");
    int num, sum = 0;
    printf("Введите положительное число.\n");
    scanf("%d", &num);

    while (num < 1){
        printf("Повторите ввод. Число должно быть положительным.\n");
        scanf("%d", &num);
    }

    for (int i = 0; i <= num; i++)
    {
        sum += i;
    }
    printf("%d", sum);
}



int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Rus");
    Task01();
    Task02();
    Task03();
    Task04();
    return 0;
}