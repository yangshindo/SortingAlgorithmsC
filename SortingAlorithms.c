#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// BUBBLE SORT
void bubbleSort(int array[], int size) {
  clock_t t;   // declara variável de tempo
  t = clock(); // inicia contagem
  int i, j, swap;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap = array[j];
        array[j] = array[j + 1];
        array[j + 1] = swap;
      }
    }
  }
  t = clock() - t;                                  // finaliza contagem
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // em segundos

  // Printa o array
  for (i = 0; i < size; i++)
    printf("%d\n", array[i]);

  // Printa o tempo de processamento do sort
  printf("\nTempo de processamento do sort: %.21f seconds\n", time_taken);
}

// INSERTION SORT
void insertionSort(int array[], int size) {
  clock_t t;   // declara variável de tempo
  t = clock(); // inicia contagem
  int i, j, key;
  for (i = 1; i < size; i++) {
    key = array[i];
    j = i - 1;

    /*move os elementos arr[0..i-1], que são maiores que a key, para uma
    posição a frente de sua posição atual*/
    while ((j >= 0) && (key < array[j])) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
  t = clock() - t;                                  // finaliza contagem
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // em segundos

  // Printa o Array
  for (i = 0; i < size; i++)
    printf("%d\n", array[i]);

  // Printa o tempo de procesamento do sort
  printf("\nTempo de processamento do sort: %.21f seconds\n", time_taken);
}

// SELECTION SORT
void selectionSort (int array[],int size) {
  clock_t t;   // declara variável de tempo
  t = clock(); // inicia contagem
  int i, j, min, swap;

  for (i = 0; i < (size - 1); i++) {
    // acha o elemento mínimo do array não ordenado, atribuido na variável min (mínimo)
    min = i;
    for (j = i+1; j < size; j++) {
      // Caso tenha algum numero menor este novo número passa a ser o novo mínimo
      if (array[j] < array[min]) {
   min = j;
      }
    }
    //Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los
    if (i != min) {
      swap = array[i];
      array[i] = array[min];
      array[min] = swap;
    }
  }
  t = clock() - t;                                  // finaliza contagem
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // em segundos
  // Printa o Array
  for (i = 0; i < size; i++)
    printf("%d\n", array[i]);

  // Printa o tempo de procesamento do sort
  printf("\nTempo de processamento do sort: %.21f seconds\n", time_taken);
}

// MERGESORT ABAIXO

// Combina dois sub-arrays do array principal
// O primeiro arr[l..m] que indica a primeira metade do 0 ao centro (esquerda)
// O segundo arr[m+1..r] que indica a segunda metade do meio + 1 ao fim
// (direita)
void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Criando arrays temporários
  int L[n1], R[n2];

  // Copia os dados para os errays temporários
  // L[] e R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  // Combina os arrays temporários arr[l..r]

  // Index inicial do primeiro subarray
  i = 0;

  // Index inicial do segundo subarray
  j = 0;

  // Index inicial do array combinado
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copia os elementos que faltam de L[], se houver algum
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copia os elementos que faltam de R[], se houver algum
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// l é para index esquerdo (left) e r é para index direito (right)
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Da no mesmo que (l+r)/2, mas evita overflow
    int m = l + (r - l) / 2;

    // Organiza a primeira e a segunda metade
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Executa função acima (merge)
    merge(arr, l, m, r);
  }
}

// Função final
void mergeFinal(int array[], size) {
  clock_t t;                                 // declara variável de tempo
  t = clock();                               // inicia contagem
  *array = malloc(2000000 * sizeof(*array)); // mallocando
  mergeSort(array, 0, size - 1); // executa função principal que executará as
                                 // outras duas auxiliáres
  t = clock() - t;                                  // finaliza contagem
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // em segundos

  // Printa o Array
  int i;
  for (i = 0; i < size; i++)
    printf("%d\n", array[i]);

  // Printa o tempo de procesamento do sort
  printf("\nTempo de processamento do sort: %.21f seconds\n", time_taken);
}

////////////////////////////////////////////////////////////////////////////////////////////

// MAIN

int main(void) {

  int size; // tamanho do array
  printf("Qual o tamanho do array de números aleatórios que você deseja gerar? "
         "(máximo 1 milhão)?\n\n");
  scanf("%d", &size);
  int randArray[size]; // variável que armazena o array
  int i;
  for (i = 0; i < size; i++)
    randArray[i] = rand() % RAND_MAX; // máximo random

  printf("\n");
  for (i = 0; i < size; i++) {
    printf("%d \n", randArray[i]);
  }

  int sortMethod;
  printf(
      "\n Informe qual o método a ser utilizado:\n 1- Bubble\n 2 -Insertion \n "
      "3- Selecion\n 4- Merge\n 0- Sair \n\n");
  scanf("%d", &sortMethod);

  int repeat; // boolean para repetir ou não o mesmo sort method

  switch (sortMethod) {
  case 1:
    bubbleSort(randArray, size);
    printf("\nRepetir?\n1- Sim\n2- Não\n\n");
    scanf("%d", &repeat);
    if (repeat == 1) {
      bubbleSort(randArray, size);
    } else {
      break;
    }
  case 2:
    insertionSort(randArray, size);
    printf("\nRepetir?\n1- Sim\n2- Não\n \n");
    scanf("%d", &repeat);
    if (repeat == 1) {
      insertionSort(randArray, size);
    } else {
      break;
    }
  case 3:
    selectionSort(randArray, size);
    printf("\nRepetir?\n1- Sim\n2- Não\n\n");
    scanf("%d", &repeat);
    if (repeat == 1) {
      selectionSort(randArray, size);
    } else {
      break;
    }
  case 4:
    mergeFinal(randArray, size);
    printf("Repetir?\n1- Sim\n2- Não\n");
    scanf("%d", &repeat);
    if (repeat == 1) {
      mergeFinal(randArray, size);
    } else {
      break;
    }
  case 0:
    exit(0);
  default:
    printf("O método escolhido foi inválido, favor digitar apenas o número do "
           "método desejado");
  }
}
