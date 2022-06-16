// Alunos: Michael e Daniel
//Quick Sort

#include "stdafx.h"
#include <iostream>
#include "string"
#include <time.h> //

using  namespace std;

const int TAMANHO = 10;
int contadora = 0;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
	contadora = contadora + 3;
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

	int vetor[TAMANHO];

	srand(time(NULL));

	for (int i = 0; i < TAMANHO; i++)
	{
		vetor[i] = rand() % 101;
	}

	cout << "Vetor: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	cout << endl;

	quickSort(vetor, 0, TAMANHO - 1);

	cout << "Vetor sorteado: " << endl;
	


	desenhar_vetor(vetor, TAMANHO);

	cout << endl << "Trocas: " << contadora << endl;
	
	system("pause");
	return 0;
}