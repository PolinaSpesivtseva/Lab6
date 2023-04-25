#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* form(int* size)
{
	int* a;
	printf("enter size of array: "); // ������ ������ �������
	scanf("%d", size);
	a = (int*)malloc(*size * sizeof(int)); // ����������� ������ �� ������ ��� ������ �������
	if (a == NULL) {
		printf("no such memory"); // ���� �� ���� ������, ������� ��������� �� �����
		return NULL;
	}

	for (int i = 0; i < *size; i++) { // ���� ���������� �������
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	return a; // ����� ������� ���������� ����� �� ������� ������� �������
}

void vivod(int* a, int size) // ������� ������ �� �����
{
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%3d ", *(a + i));
	}
	printf("\n");
}

void decrease(int* a, int* size, int i) // ������� �������� �������� � �������� i
{
	for (i; i < *size - 1; i++)
	{
		a[i] = a[i + 1];
	}
	*size = *size - 1; // ��������� ������ ������� �� 1
}

int* delete(int* a, int* size)
{
	int nom2 = -1;
	int kol;
	double sum;
	sum = 0;
	kol = 0;

	for (int i = 0; i < *size; i++)
	{
		sum = sum + a[i];
		kol++;

	}

	double srar;
	srar = sum / kol;

	for (int i = 0; i < *size; i++) // ��� ���� �����, ����� ������ � ���������, ������ ������� ������ �������� ���������������
	{
		if ((a[i] % 2 == 0) && (a[i] > srar))// ���� ����� ������ � ��� ������ �������� ��������������� 
		{
			decrease(a, size, i); //����������� ���
			nom2 = nom2 - 1; //�.�. �������� ���������� �� ���� �����, ������ ���������� ��������, ������ �������� ������ �� "�" ���������� �� �������
			i--; // ������� a[i+1] ���� ��������� a[i] => ��������� ���� ������ ��������� a[i], ��� ����� ������� i = i - 1
		}

	}

	a = (int*)realloc(a, *size * sizeof(int)); // ������� ���������� ������, ���������� ��� ������� �
	return a;
}



int main() {
	printf("Spesivtseva Polina\nLAB WORK#6\n");
	int size;
	int* a = form(&size);
	if (a == NULL) { return 1; }
	vivod(a, size);
	a = delete(a, &size);
	vivod(a, size);
	free(a);
	return 0;
}

