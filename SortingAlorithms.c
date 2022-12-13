#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void bubbleSort(int array[], int size)
{
  clock_t t; //declara variável de tempo
  t = clock(); //inicia contagem
  int i, j, swap;
  for (i = 0 ; i < size - 1; i++)
  {
    for (j = 0 ; j < size - i - 1; j++)
    {
      if (array[j] > array[j+1]) 
      {
        swap       = array[j];
        array[j]   = array[j+1];
        array[j+1] = swap;
      }
    }
  }
  t = clock() - t; //finaliza contagem
  double time_taken = ((double)t)/CLOCKS_PER_SEC; //em segundos

  //Printa o array
  for (i = 0; i < size; i++)
     printf("%d\n", array[i]);

  //Printa o tempo de processamento do sort
  printf("\nTempo de processamento do sort: %.21f seconds\n", time_taken);

}

void insertionSort(int array[], int size) {
  clock_t t; //declara variável de tempo
  t = clock(); //inicia contagem
  int i, j, key;
  for (i=1; i < size; i++) {
    key = array[i];
    j = i -1;

    /*move os elementos arr[0..i-1], que são maiores que a key, para uma
    posição a frente de sua posição atual*/
    while((j >= 0) && (key < array[j])) {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
  }
  t = clock() - t; //finaliza contagem
  double time_taken = ((double)t)/CLOCKS_PER_SEC; //em segundos

  //Printa o Array
  for (i = 0; i < size; i++)
     printf("%d\n", array[i]);

  //Printa o tempo de procesamento do sort
  printf("\nTempo de processamento do sort: %.21f seconds\n", time_taken);
}

void selectionSort(int array[], int size) {
  clock_t t; //declara variável de tempo
  t = clock(); //inicia contagem
  int smaller, i, j, swap;
  for (i = 0; i < size - 1; i++) {
    smaller = i;
    for(j = i + 1; j < size; j++) {
      if (array[smaller] > array[j]) {
        smaller = j;
      }
      if (i != smaller) {
        swap = array[i];
        array[i] = array[smaller];
        array[smaller] = swap;
      }
    }
  }
  t = clock() - t; //finaliza contagem
  double time_taken = ((double)t)/CLOCKS_PER_SEC; //em segundos

  //Printa o Array
  for (i = 0; i < size; i++)
     printf("%d\n", array[i]);

  //Printa o tempo de procesamento do sort
  printf("\nTempo de processamento do sort: %.21f seconds\n", time_taken);
}

int main(void) {
  
  int size;// tamanho do array
  printf("Qual o tamanho do array de números aleatórios que você deseja gerar? "
         "(máximo 1 milhão)?\n");
  scanf("%d", &size);
  int randArray[size]; // variável que armazena o array
  int i;
  for (i = 0; i < size; i++)
    randArray[i] = rand() % RAND_MAX; // máximo random

  for (i = 0; i < size; i++) {
    printf("%d \n", randArray[i]);
  }


  int sortMethod;
  printf("Informe qual o método a ser utilizado:\n 1- Bubble\n 2 -Insertion \n "
         "3- Selecion\n 0- Sair \n");
  scanf("%d", &sortMethod);


  int repeat; //boolean para repetir ou não o mesmo sort method
  
  switch (sortMethod) {
  case 1:
    bubbleSort(randArray, size);
    printf("Repetir?\n1- Sim\n2- Não\n");
    scanf("%d", &repeat);
    if (repeat == 1) {
      bubbleSort(randArray, size);
    } else {
    break;}
  case 2:
    insertionSort(randArray, size);
    printf("Repetir?\n1- Sim\n2- Não\n");
    scanf("%d", &repeat);
    if (repeat == 1) {
      insertionSort(randArray, size);
    } else {
    break;}
  case 3:
    selectionSort(randArray, size);
    printf("Repetir?\n1- Sim\n2- Não\n");
    scanf("%d", &repeat);
    if (repeat == 1) {
      selectionSort(randArray, size);
    } else {
    break;}
  case 0:
    exit(0);
  default:
    printf("O método escolhido foi inválido, favor digitar apenas o número do "
           "método desejado");
  }
}
