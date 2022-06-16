// Alunos: Michael e Daniel

#include "stdafx.h"
#include <iostream>
#include "string"

using  namespace std;

void selection_sort (int  vetor[], int TAMANHO) 
{  
  int X,Y; 
   for (int counter = 0; counter < TAMANHO-1; counter++) { 
    int auxiliar = 0;  	
    X = counter; 
 	  Y = vetor[counter]; 
    for (int counter2 = counter+1; counter2 < TAMANHO; counter2++) {  	   
      if (vetor[counter2] < Y) { 
 	 	    X = counter2; 
 	 	    Y = vetor[counter2];
        auxiliar = 1; 
        } 
    }  	
    if (auxiliar) {  	  
      vetor[X] = vetor[counter];  	  
      vetor[counter] = Y; } 
    } 
  } 

int main() {
  int TAMANHO=10;
    int vetor[]={10,5,4,2,7,1,3,8,6,9};

  for(int counter=0;counter< TAMANHO;counter++){
    cout<<vetor[counter]<<" ";
  }

  cout<<endl;

  selection_sort(vetor, TAMANHO);

  for(int counter2=0;counter2 < TAMANHO;counter2++){
    cout<<vetor[counter2]<<" ";
  }
  system ("pause");
  return 0;
}
