// Alunos: Michael e Daniel
//Shell Sort

#include "stdafx.h"
#include <iostream>
#include "string"
#include <time.h> //
#include <windows.h>//

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

int shellSort(int vetor[], int TAMANHO)
{
	for (int gap = TAMANHO / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < TAMANHO; i += 1)
		{
			int temp = vetor[i];
			int j;
			for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap)
				vetor[j] = vetor[j - gap];
			vetor[j] = temp;
		}
	}
	return 0;
}

void desenhar_vetor(int vetor[], int TAMANHO)
{
	for (int i = 0; i<TAMANHO; i++)
		cout << vetor[i] << " ";
}

int main() {
	double tempoEmMilissegundo = 0.0000000;//
	int vetor[TAMANHO];//

	srand(time(NULL));//

	for (int i = 0; i < TAMANHO; i++)//
	{
		vetor[i] = rand() % 1001;
	}

	cout << "Vetor: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	cout << endl;

	
	StartCounter();//
	shellSort(vetor, TAMANHO);
	tempoEmMilissegundo = GetCounter();//

	

	cout << "Vetor sorteado: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	
	printf("\nTempo = %.7lf milissegundos\n", tempoEmMilissegundo);//
	
	system("pause");
	return 0;
}