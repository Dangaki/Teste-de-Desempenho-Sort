// Alunos: Michael e Daniel

#include "stdafx.h"
#include <iostream>      
#include "string"
#include <time.h>

const int TAMANHO = 10;

using namespace std;

void intercala(int X[], int inicio, int fim, int meio) {
	int posLivre, inicio_vetor1, inicio_vetor2, i;
	int aux[TAMANHO];
	inicio_vetor1 = inicio;
	inicio_vetor2 = meio + 1;
	posLivre = inicio;
	while (inicio_vetor1 <= meio && inicio_vetor2 <= fim) {
		if (X[inicio_vetor1] <= X[inicio_vetor2])
		{
			aux[posLivre] = X[inicio_vetor1];
			inicio_vetor1++;
		}
		else {
			aux[posLivre] = X[inicio_vetor2];
			inicio_vetor2++;
		}
		posLivre++;
	}

	for (int i = inicio_vetor1; i <= meio; ++i)
	{
		aux[posLivre] = X[i];
		posLivre++;
	}

	for (int i = inicio_vetor2; i <= fim; ++i)
	{
		aux[posLivre] = X[i];
		posLivre++;
	}

	for (int i = inicio; i <= fim; ++i)
	{
		X[i] = aux[i];
	}
}
void merge(int X[], int inicio, int fim) {
	int meio;
	if (inicio < fim)
	{
		meio = (inicio + fim) / 2;
		merge(X, inicio, meio);
		merge(X, meio + 1, fim);
		intercala(X, inicio, fim, meio);

	}
}

void desenhar_vetor(int vetor[], int TAMANHO)
{
	for (int counter = 0; counter < TAMANHO; counter++) {
		cout << vetor[counter] << " ";
	}
	cout << ("\n");
}

int main()
{
	int vetor[TAMANHO];

	srand(time(NULL));

	for (int i = 0; i < TAMANHO; i++)
	{
		vetor[i] = rand() % 1001;
	}

	cout << "Vetor: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	cout << endl;

	merge(vetor, 0, TAMANHO - 1);

	cout << "Vetor: " << endl;
	desenhar_vetor(vetor, TAMANHO);
	cout << endl;

	system ("pause");
  	return 0;
}
