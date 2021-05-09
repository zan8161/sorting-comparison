#include <string.h>
#include "qsor.h"

void SWAP(int *data_1, int *data_2)
{
    int tmp;
    tmp = *data_1;
    *data_1 = *data_2;
    *data_2 = tmp;
}

void SWAPforStrings(char *string1, char *string2)
{
    char *tmp;
    tmp = string1;
    string1 = string2;
    string2 = tmp;
}

int partition(int *number, int left, int right)
{
    int i = left - 1; 
    int j;
    for (j = left; j < right; j++)
    {
        if (number[j] <= number[right])
        {
            i++;
            SWAP(&number[i], &number[j]);
        }
    }

    SWAP(&number[i + 1], &number[right]);
    return i + 1;
}

int partitionforStrings(char **strings, int left, int right)
{
    int i = left - 1; 
    int j;
    for (j = left; j < right; j++)
    {
        if (strcmp(strings[j],strings[right]) <= 0)
        {
            i++;
            SWAPforStrings(strings[i], strings[j]);
        }
    }

    SWAPforStrings(strings[i + 1], strings[right]);
    return i + 1;
}

void quickSort(int *number, int left, int right)
{
    if (left < right)
    {
        int q = partition(number, left, right); 
        quickSort(number, left, q-1); 
        quickSort(number, q+1, right);
    }
}

void quickSortforStrings(char **strings, int left, int right)
{
    if (left < right)
    {
        int q = partitionforStrings(strings, left, right);
        quickSortforStrings(strings, left, q-1); 
        quickSortforStrings(strings, q+1, right);
    }
}