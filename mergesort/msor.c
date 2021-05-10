#include "msor.h"
#include <string.h>

void merge(int *number, int left, int mid, int right)
{
    int Len_A = mid - left + 1;
    int Len_B = right - mid;
    int A[Len_A];
    int B[Len_B];

    for (int i = 0; i < Len_A; i++)
        A[i] = number[left + i];

    for (int i = 0; i < Len_B; i++)
        B[i] = number[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < Len_A && j < Len_B)
    {
        if (A[i] < B[j])
        {
            number[k] = A[i];
            i++;
        }else{
            number[k] = B[j];
            j++;
        }
        k++;
    }

    while (i < Len_A)
    {
        number[k] = A[i];
        i++;
        k++;
    }
    while (j < Len_B)
    {
        number[k] = B[j];
        j++;
        k++;
    }
}

void mergeSort(int *number, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(number, left, mid);
        mergeSort(number, mid + 1, right);
        merge(number, left, mid, right);
    }
}

void mergeforStrings(char **strings, int left, int mid, int right)
{
    int Len_A = mid - left + 1;
    int Len_B = right - mid;
    char *A[Len_A];
    char *B[Len_B];

    for (int i = 0; i < Len_A; i++)
        A[i] = strings[left + i];

    for (int i = 0; i < Len_B; i++)
        B[i] = strings[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < Len_A && j < Len_B)
    {
        if (strcmp(A[i], B[j]) < 0)
        {
            strings[k] = A[i];
            i++;
        }else{
            strings[k] = B[j];
            j++;
        }
        k++;
    }

    while (i < Len_A)
    {
        strings[k] = A[i];
        i++;
        k++;
    }
    while (j < Len_B)
    {
        strings[k] = B[j];
        j++;
        k++;
    }
}

void mergeSortforStrings(char **strings, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSortforStrings(strings, left, mid);
        mergeSortforStrings(strings, mid + 1, right);
        mergeforStrings(strings, left, mid, right);
    }
}