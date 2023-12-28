#include <stdio.h>
#include <stdlib.h>

int *FillArray(int *str, int max_len);
void PrintArray(int *arr, int len);
void Task01(int arr[], int arrLen);
void Task02(int arr[], int arrLen);
void TurnRight(int arr[], int arrLen);
void Task03(int arr[], int arrLen);
void Task04(int arr[], int arrLen);
void Task05(int arr[], int arrLen);
void Task06(int arr[], int arrLen);


int main(int argc, char const *argv[])
{
    printf("Task 1\n");
    int tsk1[5];
    FillArray(tsk1, 5);
    Task01(tsk1, 5);
    printf("\nTask 2\n");
    Task02(tsk1, 5);
    printf("\nTask 3\n");
    int tsk3[12];
    FillArray(tsk3, 12);
    PrintArray(tsk3, 12);
    Task03(tsk3, 12);
    // Далее буду заполнять массивы в коде программы, так как не удобно и долго будет проверять работоспособность.
    // А алгоритм и код точно такой же, как и в предыдущих функциях.
    printf("\nTask 4\n");
    int tsk4[10] = {14, 25, 13, 30, 76, 58, 32, 11, 41, 97};
    PrintArray(tsk4, 10);
    Task04(tsk4, 10);
    printf("\nTask 5\n");
    int tsk5[10] = {40, 105, 203, 1, 14, 1000, 22, 33, 44, 55};
    PrintArray(tsk5, 10);
    Task05(tsk5, 10);
    printf("\nTask 6\n");
    int tsk6[10] = {4, 1, 2, 1, 11, 2, 34, 11, 0, 11};
    PrintArray(tsk6, 10);
    Task06(tsk6, 10);
    return 0;
}

int *FillArray(int *str, int max_len)
{
    puts("\nEnter the array.\n");
    for (int i = 0; i < max_len; i++)
    {
        scanf("%d", &str[i]);
    }

    return str;
}

void PrintArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void Task01(int arr[], int arrLen)
{
    // Ввести с клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива
    int sum = 0;
    float avr = 0;
    for (int i = 0; i < arrLen; i++)
    {
        sum += arr[i];
    }
    avr = (float)sum / arrLen;
    printf("%.3f\n", avr);
}

void Task02(int arr[], int arrLen)
{
    // Ввести с клавиатуры массив из 5 элементов, найти минимальный из них.
    int min = arr[0];
    for (int i = 1; i < arrLen; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("%d", min);
}

void TurnRight(int arr[], int arrLen)
{
    int temp = arr[arrLen - 1];
    for (int i = arrLen; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

void Task03(int arr[], int arrLen)
{
    // Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.
    for (int i = 0; i < 4; i++)
    {
        TurnRight(arr, arrLen);
    }
    PrintArray(arr, 12);
}

void Task04(int arr[], int arrLen)
{
    // Считать массив из 10 элементов и отсортировать его по последней цифре.
    for (int i = 0; i < arrLen - 1; i++)
    {
        for (int j = (arrLen - 1); j > i; j--)
        {
            if ((arr[j - 1] % 10) > (arr[j] % 10))
            {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    PrintArray(arr, arrLen);
}

void Task05(int arr[], int arrLen)
{
    // Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.
    for (int i = 0; i < arrLen; i++)
    {
        if ((arr[i] / 10) % 10 == 0){
            printf("%d ", arr[i]);
        }
    }
    printf(" \n");
}

void Task06(int arr[], int arrLen)
{
    // Дан массив из 10 элементов. Определить, какое число в массиве встречается
    // чаще всего. Гарантируется, что такое число ровно 1.
    int num = arr[0];
    int count;
    int mostlyCount = 1;
    for (int i = 0; i < arrLen - 1; i++)
    {
        count = 1;
        for (int j = i + 1; j < arrLen; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > mostlyCount)
        {
            mostlyCount = count;
            num = arr[i];
        }
    }
    if (mostlyCount > 1)
    {
        printf("Number %d it occurs most often\n", num);
    }
    else
    {
        printf("Num not found.\n");
    }
}

