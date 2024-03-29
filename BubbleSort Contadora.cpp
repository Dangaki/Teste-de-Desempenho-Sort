// Alunos: Michael e Daniel
//Bubble Sort

#include "stdafx.h"
#include <iostream>
#include "string"
#include <time.h>

const int TAMANHO = 10;
using  namespace std;


int bubble_sort(int vetor[], int TAMANHO) {
	int contador = 0;

	for (int counter = 0; counter < TAMANHO - 1; counter++) {
		for (int counter2 = 0; counter2 < TAMANHO - 1; counter2++) {
			if (vetor[counter2]>vetor[counter2 + 1]) {
				int auxiliar = vetor[counter2];
				vetor[counter2] = vetor[counter2 + 1];
				vetor[counter2 + 1] = auxiliar;
				contador = contador + 3;
			}
		}
	}
	return contador;
}

void desenhar_vetor(int vetor[], int TAMANHO)
{
	for (int counter = 0; counter < TAMANHO; counter++) {
		cout << vetor[counter] << " ";
	}
	cout << ("\n");
}

int main() {
	int vetor[TAMANHO], contador = 0;

	srand(time(NULL));

	for (int i = 0; i < TAMANHO; i++)
	{
		vetor[i] = rand() % 1001;
	}

	cout << "Vetor: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	cout << endl;

	contador = bubble_sort(vetor, TAMANHO);

	cout << "Vetor sorteado: " << endl;
	desenhar_vetor(vetor, TAMANHO);

	cout << "Trocas: "<< contador << endl;

	system("pause");
	return 0;
}