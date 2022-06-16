// Alunos: Michael e Daniel
//Insertion Sort

#include "stdafx.h"
#include <iostream>
#include "string"
#include <time.h> 

const int TAMANHO = 10;
using  namespace std;


int insortion_sort(int vetor[], int TAMANHO) {
	
	int counter2, contadora = 0;

	for (int counter = 1; counter < TAMANHO; counter++)
	{
		int auxiliar = vetor[counter];
		counter2 = counter - 1;
		while (counter2 >= 0 && vetor[counter2] > auxiliar)
		{
			vetor[counter2 + 1] = vetor[counter2];
			counter2 = counter2 - 1;
			contadora++;
		}
		vetor[counter2 + 1] = auxiliar;
		contadora++;
	}
	return contadora;
}

void desenhar_vetor(int vetor[], int TAMANHO)
{
	for (int counter = 0; counter < TAMANHO; counter++) {
		cout << vetor[counter] << " ";
	}
	cout << ("\n");
}

int main() {
	int vetor[TAMANHO], contadora = 0;

	srand(time(NULL));//

	for (int i = 0; i < TAMANHO; i++)//
	{
		vetor[i] = rand() % 101;
	}

	cout << "Vetor: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	cout << endl;

	contadora = insortion_sort(vetor, TAMANHO);


	cout << "Vetor sorteado: " << endl;
	desenhar_vetor(vetor, TAMANHO);

	cout << endl << "Trocas: " << contadora << endl;

	system("pause");
	return 0;
}