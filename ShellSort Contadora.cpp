// Alunos: Michael e Daniel
//Shell Sort

#include "stdafx.h"
#include <iostream>
#include "string"
#include <time.h> //

const int TAMANHO = 10;
using  namespace std;
int contadora = 0;

int shellSort(int vetor[], int TAMANHO)
{
	for (int gap = TAMANHO / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < TAMANHO; i += 1)
		{
			int temp = vetor[i];
			int j;
			for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap) {
				vetor[j] = vetor[j - gap];
				contadora++;
			}
			
			vetor[j] = temp;
			contadora++;
		
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

	int vetor[TAMANHO];

	srand(time(NULL));
	for (int i = 0; i < TAMANHO; i++)
	{
		vetor[i] = rand() % 1001;
	}

	cout << "Vetor: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	cout << endl;

	shellSort(vetor, TAMANHO);

	cout << "Vetor sorteado: " << endl;
	desenhar_vetor(vetor, TAMANHO);

	cout<< endl << "Trocas: "<< contadora << endl;

	system("pause");
	return 0;
}