// Alunos: Michael e Daniel
//Selection Sort

#include "stdafx.h"
#include <iostream>
#include "string"
#include <time.h> 

const int TAMANHO = 10;
using  namespace std;

int contadora = 0;

void selection_sort(int  vetor[], int TAMANHO)
{
	int X, Y;
	for (int counter = 0; counter < TAMANHO - 1; counter++) {
		int auxiliar = 0;
		X = counter;
		Y = vetor[counter];
		for (int counter2 = counter + 1; counter2 < TAMANHO; counter2++) {
			if (vetor[counter2] < Y) {
				X = counter2;
				Y = vetor[counter2];
				auxiliar = 1;
				contadora++;
			}
		}
		if (auxiliar) {
			vetor[X] = vetor[counter];
			vetor[counter] = Y;

			contadora = contadora + 2;
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
		vetor[i] = rand() % 1001;
	}

	cout << "Vetor: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	cout << endl;

	selection_sort(vetor, TAMANHO);


	cout << "Vetor sorteado: " << endl;
	desenhar_vetor(vetor, TAMANHO);

	cout << endl << "Trocas: " << contadora << endl;


	system("pause");
	return 0;
}
