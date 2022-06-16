// Alunos: Michael e Daniel

#include "stdafx.h"
#include <iostream>
#include "string"

using  namespace std;
int shellSort(int vetor[], int TAMANHO)
{
    for (int gap = TAMANHO/2; gap > 0; gap /= 2)
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
    for (int i=0; i<TAMANHO; i++)
        cout << vetor[i] << " ";
}
 
int main()
{
   int vetor[] = {10,5,4,2,7,1,3,8,6,9}; 
    int TAMANHO = 10; 
  
    cout<<("Vetor: \n"); 
    desenhar_vetor(vetor, TAMANHO); 
    shellSort(vetor, TAMANHO);
    cout << endl << "Vetor sorteado: \n"; 
    desenhar_vetor(vetor, TAMANHO); 
    
    system ("pause");
    return 0; 
}
