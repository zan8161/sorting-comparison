#include "hsor.h"
#include <string.h>

void SWAP(int *data_1, int *data_2) {
    int temp = *data_1;
    *data_1 = *data_2;
    *data_2 = temp;
}
  
void heapify(int *number, int n, int i) {
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && number[left] > number[largest])
        largest = left;
  
    if (right < n && number[right] > number[largest])
        largest = right;

    if (largest != i) {
        SWAP(&number[i], &number[largest]);
        heapify(number, n, largest);
    }
}

void heapSort(int *number, int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(number, n, i);

    for (int i = n - 1; i >= 0; i--) {
        SWAP(&number[0], &number[i]);
        heapify(number, i, 0);
    }
}

void heapifyforStrings(char **strings, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && strcmp(strings[left], strings[largest]) > 0)
        largest = left;

    if (right < n && strcmp(strings[right], strings[largest]) > 0)
        largest = right;

    if (largest != i) {
        char *tmp;
        tmp = strings[i];
        strings[i] = strings[largest];
        strings[largest] = tmp;
        heapifyforStrings(strings, n, largest);
    }
}

void heapSortforStrings(char **strings, int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyforStrings(strings, n, i);

    for (int i = n - 1; i >= 0; i--) {
        char *tmp;
        tmp = strings[i];
        strings[i] = strings[0];
        strings[0] = tmp;
        heapifyforStrings(strings, i, 0);
    }
}