#include <stdio.h>
#include <locale.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "Rus");
	printf("������ 1. ����� ���� �����\n");
	task1();
	sleep(1);
	printf("������ 2. ����� � ������������ ���� �����\n");
	task2();
	sleep(1);
	printf("������ 3. �������� ���� �����\n");
	task3();
	sleep(1);
	printf("������ 4. ����� ������� �������������� ���� ��������������� �����\n");
	task4();
	return 0;
}

task1(){
	int n1, n2, n3;
    int sum;
	printf("������� ��� ����� �������� �� ��������\n");
    scanf("%d %d %d", &n1, &n2, &n3);
    sum = n1 + n2 + n3;
    printf("����� ����� %d %d %d ����� : %d\n\n", n1, n2, n3, sum);
	return;
}

task2(){
	int n1, n2, n3;
    int sum;
	int mult;
	printf("������� ��� ����� �������� �� ��������\n");
    scanf("%d %d %d", &n1, &n2, &n3);
    sum = n1 + n2 + n3;
	mult = n1 * n2 * n3;
    printf("����� ����� %d %d %d ����� : %d\n", n1, n2, n3, sum);
	printf("������������ ����� %d %d %d ����� : %d\n\n", n1, n2, n3, mult);
	return;
}

task3(){
	int n1, n2, diff;
	printf("������� ��� ����� �������� �� ��������\n");
	scanf("%d %d", &n1, &n2);
	diff = n1 - n2;
	printf("�������� ����� %d %d ����� : %d\n", n1, n2, diff);
}

task4(){
	int num, sum, count;
	float average_without_zero, average_with_zero;
	printf("������� �������������� �����\n");
	scanf("%d", &num);
	sum = (num/1000) + ((num / 100) % 10) + ((num % 100) / 10) + (num % 10);
	if(num / 1000 != 0){
		count ++;
	}
	if(((num / 100) % 10) != 0){
		count ++;
	}
	if((num % 100) / 10 != 0){
		count ++;
	}
	if(num % 10 != 0){
		count ++;
	}
	average_without_zero = (float)sum/count;
	average_with_zero = (float)sum/4;
	if(count == 4){
		printf("������� �������������� ���� ����� : %d ����� %.2f\n", num, average_without_zero);
	}
	else{
		printf("������� �������������� ���� ����� %d �������� ���� ����� : %.2f\n", num, average_with_zero);
		printf("������� �������������� ���� ����� %d �������� ���� ����� : %.2f\n", num, average_without_zero);
	}
	
}