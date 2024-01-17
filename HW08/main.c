#include <stdio.h>
#include <stdlib.h>

int comparator (const int *a, const int *b);
void sort_array(int size, int a[]);
void print_array(int size, int a[]);
void sort_even_odd(int n, int a[]);
void find_max_array(int size, int a[]);
void is_two_same(int size, int a[]);
void change_max_min(int size, int a[]);
void more_average_trace(int x, int y, int a[x][y]);
void chessboard();

int main(int argc, char const *argv[])
{
    int arr1[20] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
    int arr2[5][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4},{5,5,5,5,5}};
    print_array(20, arr1);
    sort_array(20,arr1);
    print_array(20, arr1);
    sort_even_odd(20, arr1);
    print_array(20, arr1);
    find_max_array(20,arr1);
    is_two_same(20, arr1);
    change_max_min(20, arr1);
    print_array(20, arr1);
    more_average_trace(5, 5, arr2);
    chessboard();
    return 0;
}


void print_array(int size, int a[]){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
// Задача 1. Сортировка по возрастанию
int comparator (const int *a, const int *b) {
    return *a - *b;
}

void sort_array(int size, int a[]){
    qsort(a, size, sizeof (int), (int(*) (const void *, const void *)) comparator);
}

// Задача 2. Четные в начало

void sort_even_odd(int size, int a[]){
    int temp = 0;
    for (int i = 0; i < size - 1;)
    {
        if((a[i] % 2 != 0) && (a[i+1] % 2 == 0)){
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
            i--;
        }
        else  i++;
    }
}

// Задача 3. Максимум в массиве

void find_max_array(int size, int a[]){
    int max = a[0];
    for (int i = 1; i < size-1; i++)
    {
        if(max < a[i]){
            max = a[i];
        }
    }
    printf("Max value in array = %d\n", max);
}

// Задача 4. Два одинаковых

void is_two_same(int size, int a[]){
    int ok = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(a[i] == a[j])
            {
                ok = 1;
                break;
            }
            if(ok) break;
        }
    }
    if(ok) printf("Yes!\n");
    else  printf("No.\n");
}

// Задача 5. Поменять местами

void change_max_min(int size, int a[])
{
    int max = a[0];
    int min = a[0];
    int index_max = 0;
    int index_min = 0;
    int temp = 0;
    for (int i = 1; i < size; i++)
    {
        if(max < a[i]) 
        {
            max = a[i];
            index_max = i;
        }
        if(min > a[i]) 
        {
            min = a[i];
            index_min = i;
        }
    }
    temp = a[index_max];
    a[index_max] = a[index_min];
    a[index_min] = temp;
}

// Задача 6. Больше среднего

void more_average_trace(int x, int y, int a[x][y])
{
    int sum = 0;
    int avr = 0;
    int count = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (i == j) sum += a[i][j];
        }
    }
    avr = sum / x;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (a[i][j] > avr) count++;
        }
    }
    printf("%d\n", count);
}

// Задача 7*. Клетки

void chessboard(void){
    
    char x;
    int y = 0;
    puts("Enter the point of the chessboard in the format. For example A2 or H8.");
    scanf("%c %d", &x, &y);
    if (((x=='A')||(x=='C')||(x=='E')||(x=='G'))&&(y%2!=0)) printf("BLACK");
    else if (((x=='B')||(x=='D')||(x=='F')||(x=='H'))&&(y%2==0)) printf("BLACK");
    else printf("WHITE"); 
}