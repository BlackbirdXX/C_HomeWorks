#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct element
{
    char data;
    struct element* next;
} OBJ;

OBJ* Push(OBJ* top, char data)
{
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

OBJ* Pop(OBJ* top)
{
    if(top == NULL)
        return top;
    
    OBJ* ptr_next = top->next;
    free(top);

    return ptr_next;
}

void Show(const OBJ* top)
{
    const OBJ* current = top;
    while(current != NULL) {
        printf("%c", current->data);
        current = current->next;
    }
}

char* FillString(char* str,int max_len)
{
    int i = 0;
    char ch;
    while ((ch = getchar()) != '.' && ch != EOF && i < max_len -1){
        str[i++] = ch;
    }
    str[i] = '\0';
    return str;
}

char* ClearString(char* src, char* dst)
{
    int clear_count = 0;
    int max_len = strlen(src);;
    for (size_t i = 0; i < max_len; i++)
    {
        if(src[i] == '(' || src[i] == ')'){
            dst[clear_count++] = src[i];
        }
    }
    dst[clear_count] = '\0';
    return dst;
}

int validate(char* str, OBJ* top)
{
    int valid_len = strlen(str);
    if(valid_len % 2 != 0)
        return 0;

    if(str[0] == ')' || str[valid_len] == '(')
        return 0;

    char val;
    for (int i = 0; i < valid_len; i++)
    {
        val = str[i];
        if(val  == '('){
            top = Push(top, str[i]);
        }
        else if (val == ')')
        {
            top = Pop(top);
        }
    }
    if(top != NULL)
        return 0;
    
    return 1;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Rus");
    puts("Программа проверяющая правильность расставления скобок в математических выражениях.\n");
    puts("Введите математическое выражение для проверки.\nВ конце выражения нужно обязательно поставить точку.\n");
    OBJ* top = NULL;
    char staples[1000];
    // char staples[1000] = {"x = ((a-b)*(a+b))."};
    int max_len = sizeof(staples);
    char staples_clear[max_len];
    FillString(staples, max_len);
    puts(staples);
    ClearString(staples, staples_clear);
    puts(staples_clear);
    int len = strlen(staples_clear);
    
    printf(validate(staples_clear, top) ? "Yes" : "No");
    
   
    return 0;
}
