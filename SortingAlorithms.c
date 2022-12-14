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

// MERGE SORT

// Combina dois sub-arrays do array principal
// O primeiro left_arr[s1] que indica a primeira metade do 0 ao centro
// (esquerda) O segundo right_arr[s2] que indica a segunda metade do meio + 1 ao
// fim
void merge(int array[], int left, int mid, int right) {
  int i, j, k;
  int s1 = mid - left + 1;
  int s2 = right - mid;

  int *left_array, *right_array;
  left_array = (int *)malloc(s1 * sizeof(int));
  right_array = (int *)malloc(s2 * sizeof(int));

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
  free(left_array);
  free(right_array);
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

void mergeFinal(int array[], int size) {
  clock_t t;   // declara variável de tempo
  t = clock(); // inicia contagem
  merge_sort(array, 0,
             size - 1); // executa função principal que chama as outras duas
  t = clock() - t;      // finaliza contagem
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // em segundos

  // Printa o Array
  // int i;
  // for (i = 0; i < size; i++)
  //  printf("%d\n", array[i]);
  // Printa o tempo de procesamento do sort
  printf("\nTempo de processamento do sort: %.21f seconds\n", time_taken);
}

// QUICK SORT

// Função swap entre dois elementos
void swap(int array[], int i, int j) {
  int swap = array[i];
  array[i] = array[j];
  array[j] = swap;
}

// Particionando (retorna índice do pivô)
int partition(int array[], int left, int right) {
  int pivot, pivot_index, i;

  pivot = array[right]; // o pivô é sempre o último elemento
  pivot_index = left;

  for (i = left; i < right; i++) {
    // verifica se o elemento é <= ao pivô
    if (array[i] <= pivot) {
      // troca
      swap(array, i, pivot_index);
      // incrementa o índice do pivot
      pivot_index++;
    }
  }

  // troca o pivô
  swap(array, pivot_index, right);

  // retorna o índice do pivô
  return pivot_index;
}

// Pivô randômico para evitar pior caso
int random_partition(int array[], int left, int right) {
  // seleciona um número entre fim e início
  int pivot_index = (rand() % (right - left + 1)) + left;

  // faz a troca para colocar o pivô no fim
  swap(array, pivot_index, right);

  // chama função partition
  return partition(array, left, right);
}

void quick_sort(int array[], int left, int right) {
  if (left < right) {
    // chama função random partition e retorna o índice do pivô
    int pivot_index = random_partition(array, left, right);

    // chamadas recursivas
    quick_sort(array, left, pivot_index - 1);
    quick_sort(array, pivot_index + 1, right);
  }
}

void quickFinal(int array[], int size) {
  clock_t t;                      // declara variável de tempo
  t = clock();                    // inicia contagem
  srand(time(NULL));              // random seed
  quick_sort(array, 0, size - 1); // chamada do quicksort
  t = clock() - t;                // finaliza contagem
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // em segundos

  /*
  Printa o Array
  int i;
  printf("\n");
  for (i = 0; i < size; i++) {
    printf("%d \n", array[i]);}
  */
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
  int *randArray;
  randArray = (int *)malloc(size * sizeof(int)); // mallocando;

  int i;
  for (i = 0; i < size; i++)
    randArray[i] = rand() % RAND_MAX; // máximo random

  // Printa o Array
  /*
  printf("\n");
  for (i = 0; i < size; i++) {11
    printf("%d \n", randArray[i]);
  }
  */

  int sortMethod;
  printf(
      "\n Informe qual o método a ser utilizado:\n 1- Bubble\n 2 -Insertion \n "
      "3- Selecion\n 4- Merge\n 5- Quick \n 0- Sair \n\n");
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
  case 5:
    quickFinal(randArray, size);
    printf("Repetir?\n1- Sim\n2- Não\n");
    scanf("%d", &repeat);
    if (repeat == 1) {
      quickFinal(randArray, size);
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
