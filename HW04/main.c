#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Rus");
    Task01();
    Task02();
    Task03();
    Task04();
    return 0;
}

int Task01(){
    // Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.

    int n1, n2, sum;
    printf("Введите два целых числа, разделяя их пробелом.\nПервое число должно быть меньше или равно второму\n");
    scanf("%d %d", &n1, &n2);
    if (n1 <= n2) {
        n1 = n1 < 0 ? n1 * -1 : n1;
        n2 = n2 < 0 ? n2 * -1 : n2;
        for (int i = n1; i <= n2; i++)
        {
            sum += i*i;
        }
        printf("n1 = %d, n2 = %d Сумма квадратов чисел от n1 до n2 : %d\n",n1, n2, sum);
    }
    else{
        printf("n1 > n2, неверный ввод.");
    }
    return;
}

int Task02(){
    // Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
    int num, count;
    printf("Введите число\n");
    scanf("%d", &num);
    num = num < 0 ? num * -1 : num;
    while (num > 0)
    {
        count ++;
        num = num / 10;
    }
    if (count == 3)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return;
}

int Task03(){
    // Ввести целое число и определить, верно ли, что все его цифры четные
    int num, count = 0;
    printf("Введите число\n");
    scanf("%d", &num);
    while (num > 0)
    {
        if (num % 2 == 0){
            count = 1;
        }
        else
        {
            count = 0;
            break;
        }
        
        num = num / 10;
    }
    if (count == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return;
}

int Task04(){
    // Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.
    int num, rev;
    printf("Введите число\n");
    scanf("%d", &num);
    // num = num < 0 ? num * -1 : num;
    while (num)
    {
        rev = rev * 10 + (num % 10);
        num = num / 10;
    }

    printf("%d",rev);
}