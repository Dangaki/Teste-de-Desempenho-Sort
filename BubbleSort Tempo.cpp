// Alunos: Michael e Daniel
//Bubble Sort

#include "stdafx.h"
#include <iostream>
#include "string"
#include <time.h> //
#include <windows.h>//

const int TAMANHO = 10;//
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

void bubble_sort(int vetor[], int TAMANHO) {
	for (int counter = 0; counter < TAMANHO - 1; counter++) {
		for (int counter2 = 0; counter2 < TAMANHO - 1; counter2++) {
			if (vetor[counter2]>vetor[counter2 + 1]) {
				int auxiliar = vetor[counter2];
				vetor[counter2] = vetor[counter2 + 1];
				vetor[counter2 + 1] = auxiliar;
			}
		}
	}
}

void desenhar_vetor(int vetor[], int TAMANHO)
{
	for (int counter = 0; counter < TAMANHO; counter++) {
		cout << vetor[counter] << " ";
	}
	cout << ("\n");
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
	bubble_sort(vetor, TAMANHO);
	tempoEmMilissegundo = GetCounter();//

	

	cout << "Vetor sorteado: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	
	printf("\nTempo = %.7lf milissegundos\n", tempoEmMilissegundo);//
	
	system("pause");
	return 0;
}