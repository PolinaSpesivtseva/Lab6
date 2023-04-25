#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* form(int* size)
{
	int* a;
	printf("enter size of array: "); // вводим размер массива
	scanf("%d", size);
	a = (int*)malloc(*size * sizeof(int)); // запрашиваем память на нужный нам размер массива
	if (a == NULL) {
		printf("no such memory"); // если не дает память, выводим сообщение на экран
		return NULL;
	}

	for (int i = 0; i < *size; i++) { // ввод эллементов массива
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	return a; // иначе функция возвращает адрес на нулевой элемент массива
}

void vivod(int* a, int size) // выводим массив на экран
{
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%3d ", *(a + i));
	}
	printf("\n");
}

void decrease(int* a, int* size, int i) // функция удаления элемента с индексом i
{
	for (i; i < *size - 1; i++)
	{
		a[i] = a[i + 1];
	}
	*size = *size - 1; // уменьшаем размер массива на 1
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

	for (int i = 0; i < *size; i++) // для всех чисел, между первым и последним, модуль которых больше среднего арифметического
	{
		if ((a[i] % 2 == 0) && (a[i] > srar))// если число четное и оно больше среднего арифметического 
		{
			decrease(a, size, i); //вычеркиваем его
			nom2 = nom2 - 1; //т.к. элементы сместились на один влево, индекс последнего значения, модуль которого меньше хб "р" уменьшился на единицу
			i--; // элемент a[i+1] стал элементом a[i] => следующий цикл должен проверить a[i], для этого запишем i = i - 1
		}

	}

	a = (int*)realloc(a, *size * sizeof(int)); // изменим количество памяти, отведенной для массива а
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

