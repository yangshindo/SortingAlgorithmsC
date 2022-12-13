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
void selectionSort(int array[], int size) {

  clock_t t;   // declara variável de tempo
  t = clock(); // inicia contagem

  int i, j, min, swap;

  for (i = 0; i < (size - 1); i++) {
    // acha o elemento mínimo do array não ordenado, atribuido na variável min
    // (mínimo)
    min = i;
    for (j = i + 1; j < size; j++) {
      // Caso tenha algum numero menor este novo número passa a ser o novo
      // mínimo
      if (array[j] < array[min]) {
        min = j;
      }
    }
    // Se o minimo for diferente do primeiro numero não ordenado ele faz a troca
    // para ordena-los
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
// O primeiro left_arr[s1] que indica a primeira metade do 0 ao centro
// (esquerda) O segundo right_arr[s2] que indica a segunda metade do meio + 1 ao
// fim
void merge(int array[], int left, int mid, int right) {
  int i, j, k;
  int s1 = mid - left + 1;
  int s2 = right - mid;

  int left_array[s1], right_array[s2];

  for (i = 0; i < s1; i++)
    left_array[i] = array[left + i];

  for (j = 0; j < s2; j++)
    right_array[j] = array[mid + 1 + j];

  i = 0;
  j = 0;
  k = left;

  // verifica nos dois subarrays ordenados iniciando pelo mesmo indicice quem é
  // o menor dentre os dois subarrays verificados o elemento que for menor é
  // adicionado ao array final o indíce de um array só incrementa caso o valor
  // seja menor, o do array final sempre incrementa
  while (i < s1 && j < s2) {
    if (left_array[i] <= right_array[j]) {
      array[k] = left_array[i];
      i++;
    } else {
      array[k] = right_array[j];
      j++;
    }
    k++;
  }
  // caso tenham sobrado elementos no array da esquerda, adiciona ao array final
  while (i < s1) {
    array[k] = left_array[i];
    i++;
    k++;
  }
  // caso tenham sobrado elementos no array da direita, adiciona ao array final
  while (j < s2) {
    array[k] = right_array[j];
    j++;
    k++;
  }
}

void merge_sort(int array[], int left, int right) {
  if (left < right) {

    // acha o valor do meio do array
    int mid = left + (right - left) / 2;

    // chama mergesort pra primeira metade (esquerda)
    merge_sort(array, left, mid);

    // chama mergesort pra segunda metade (direita)
    merge_sort(array, mid + 1, right);

    // chama a função merge (com os subarrays já ordenados individualmente)
    merge(array, left, mid, right);
  }
}

int mergeFinal(array[], size) {

  clock_t t;   // declara variável de tempo
  t = clock(); // inicia contagem
  merge_sort(array, 0,
             size - 1); // executa função principal que chama as outras duas
  t = clock() - t;      // finaliza contagem
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // em segundos

  // Printa o Array
  int i;
  for (i = 0; i < size; i++)
    printf("%d\n", array[i]);
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
    randArray[i] = rand() % 5; // máximo random

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
