/* Programa que recebe um vetor e o coloca em ordem.
Este programa não verifica se o vetor está em ordem. */

#include <iostream>

using namespace std;

//Função para trocar as posições do vetor
void organizaVetor (int *vetor1, int *vetor2){
    int aux;

    aux = *vetor1;
    *vetor1 = *vetor2;
    *vetor2 = aux;

}

//Funçao para imprimir o vetor
void imprimeArray (int vetor[], int tamanhoDoVetor){
    int i=0;

    for (i = 0; i < tamanhoDoVetor; i++) {

        cout << vetor[i] << "\t";

    }

    cout << "\n"; //Insere duas quebras de linhas antes da próxima linha
}

//Função para organizar o vetor
void bubbleSort (int vetor[], int x){

    for (int i = 0; i < (x-1); i++) {
        for (int j = 0; j < (x-1); j++) {
            if (vetor[j] > vetor[j+1]) {
                organizaVetor(&vetor[j], &vetor[j+1]);

            }

        }

    }

}

int main() {

    int array[8] = {12, 5, 8, 1, 14, 3, 9, 2};

    int arraySize;

    arraySize = sizeof(array)/sizeof(array[0]);

    cout << "\nAntes da organizacao do vetor \n\n";

    //Este for imprime os elementos do vetor
    imprimeArray(array, arraySize);

    //Esta função organiza o vetor
    bubbleSort(array, arraySize);

    cout << "\nDepois da organizacao do vetor \n\n";

    //Este for organiza o vetor
    imprimeArray(array, arraySize);


}

