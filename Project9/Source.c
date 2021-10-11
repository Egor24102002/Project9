#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define HEADER ("������������ ������ �4\n���������: ����� �. � �������� �.\n")

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void dfs(int** G, int* NUM, int v, int n)
{
	NUM[v] = true;
	printf(" %d ", v);
	for (int i = 0; i < n; i++)
	{
		if ((G[v][i] == 1) && (NUM[i] == false))
		{
			dfs(G, NUM, i, n);
		}
	}
}

void task_1_1(int** G, int n)
{
	printf("\n������� 1.\n\n����� 1.\n������� ���������:\n");
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			G[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				G[i][j] = 0;
			}
			else
			{
				G[i][j] = G[j][i];
			}
			printf(" %d ", G[i][j]);
		}
		printf("\n");
	}
}

void task_1_2(int** G, int n)
{
	int* NUM = (int*)malloc(n * sizeof(int));
	int v;
	for (int i = 0; i < n; i++)
	{
		NUM[i] = false;
	}
	printf("\n����� 2.\n������� ����� �����: ");
	scanf("%d", &v);
	printf("��������� ������ ��������� ������ � �������(�������): ");
	dfs(G, NUM, v, n);
	free(NUM);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	printf(HEADER);
	int n;
	printf("������� ����������� �������: ");
	scanf("%d", &n);
	int** G = (int**)malloc(n * sizeof(int*));
	task_1_1(G, n);
	task_1_2(G, n);
	free(G);
	system("PAUSE");
	return 0;
}

