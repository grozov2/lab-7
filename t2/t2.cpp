#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "locale.h"
#include <queue>

using namespace std;
int *dist; // указатель на вектор
int **matr;//указатель для массива указателей


void BFSD(int v, int n)
{
	queue <int> Q;
	Q.push(v);
	dist[v] = 0;
	printf("Порядок обхода:");
	while (!Q.empty())
	{
		v = Q.front();
		Q.pop();
		printf("%d", v);
		for (int i = 0;i < n; i++)
		{
			if ((matr[v][i] > 0) && (dist[i] > (dist[v] + matr[v][i]))) 
			{
				Q.push(i);
				dist[i] = dist[v] + matr[v][i];
			}
		}
	}
	printf("\nРасстояние: ");
	for (int i = 0; i < n; i++)
	{
		if (dist[i] != -1)
		{
			printf("%d\t", dist[i]);
		}
		dist[i] = 1000;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	system("chcp 1251");
	system("cls");
	int n, i, j;

	printf("Введите размер матририцы: ");
	scanf_s("%d", &n);

	dist = (int*)malloc(n * sizeof(int));
	matr = (int**)malloc(n * sizeof(int*));

	for (i = 0; i<n; i++) {		//выделение памяти под массив указателей
		matr[i] = (int*)malloc(n * sizeof(int));
	}

	for (i = 0; i < n; i++)	//выделение памяти для массива значений
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				matr[i][j] = 0;
			}

			if (i < j)
			{
				matr[i][j] = rand() % 6;
				matr[j][i] = matr[i][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		dist[i] = -1;
	}


	printf("Result: ");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%d\t", matr[i][j]);

	}
	printf(" \n   ");
	printf(" \n   ");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", dist[i]);
	}
	printf(" \n   ");

	for (int i = 0; i < n; i++)
	{
		BFSD(i, n);
		printf("\n");
	}

	_getch();
}
