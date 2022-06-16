// Alunos: Michael e Daniel
//Quick Sort

#include "stdafx.h"
#include <iostream>
#include "string"
#include <time.h> //
#include <windows.h>//
#include<stdio.h> ///

const int TAMANHO = 1000;//
using  namespace std;

double PCFreq = 0.0;//
__int64 CounterStart = 0;//

void StartCounter()//
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		printf("QueryPerformanceFrequency Failed.\n");
	PCFreq = (double)(li.QuadPart) / 1000.0;
	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}


double GetCounter()//
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return (double)(li.QuadPart - CounterStart) / PCFreq;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int vetor[], int menor, int maior)
{
	int pivot = vetor[maior];
	int i = (menor - 1);

	for (int j = menor; j <= maior - 1; j++)
	{
		if (vetor[j] <= pivot)
		{
			i++;
			swap(&vetor[i], &vetor[j]);
		}
	}
	swap(&vetor[i + 1], &vetor[maior]);
	return (i + 1);
}

void quickSort(int vetor[], int menor, int maior)
{
	if (menor < maior)
	{
		int pi = partition(vetor, menor, maior);
		quickSort(vetor, menor, pi - 1);
		quickSort(vetor, pi + 1, maior);
	}
}

void desenhar_vetor(int vetor[], int TAMANHO)
{
	for (int i = 0; i < TAMANHO; i++)
		cout << vetor[i] << " ";
}

int main() {
	double tempoEmMilissegundo = 0.0000000;//
	int vetor[TAMANHO];//

	srand(time(NULL));//

	for (int i = 0; i < TAMANHO; i++)//
	{
		vetor[i] = rand() % 101;
	}

	cout << "Vetor: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	cout << endl;

	
	StartCounter();//
	quickSort(vetor, 0, TAMANHO - 1);
	tempoEmMilissegundo = GetCounter();//

	

	cout << "Vetor sorteado: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	
	printf("\nTempo = %.7lf milissegundos\n", tempoEmMilissegundo);//
	
	system("pause");
	return 0;
}
