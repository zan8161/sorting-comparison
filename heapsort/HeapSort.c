#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "hsor.h"
#define MaxNumberNum 1000000
#define StringLen 101

int main()
{
    struct timeval start;
    struct timeval end;

    int Data[MaxNumberNum];

    static char *Strings[MaxNumberNum];
    for (int i = 0; i < MaxNumberNum; i++)
    {
        Strings[i] = NULL;
    }

    srand(time(NULL));
    // 生成整數
    for (int i = 0; i < MaxNumberNum; i++)
    {
        Data[i] = rand() % 2147483646;
    }

    // 生成字串
    for (int i = 0; i < MaxNumberNum; i++)
    {
        char *String = malloc(StringLen);
        for (int j = 0; j < StringLen - 1; j++)
        {
            String[j] = rand() % 25 + 65;
        }
        String[StringLen - 1] = '\0';
        Strings[i] = String;
    }

    //生成資料集(整數)
    FILE *fp_int;
    if ((fp_int = fopen("dataset1.txt", "w")) != NULL)
    {
        for (int i = 0; i < MaxNumberNum; i++)
        {
            char NumString[StringLen];
            sprintf(NumString, "%d\n", Data[i]);
            fputs(NumString, fp_int);
        }
        fclose(fp_int);
    }
    else{
        printf("Error!\n");
        exit(1);
    }
    //生成資料集(字串)
    FILE *fp_string;
    if ((fp_string = fopen("dataset2.txt", "w")) != NULL)
    {
        for (int i = 0; i < MaxNumberNum; i++)
        {
            fputs(Strings[i], fp_string);
            fputs("\n", fp_string);
        }
        fclose(fp_string);
    }
    else{
        printf("Error!\n");
        exit(1);
    }
    //計時開始
    gettimeofday(&start, NULL);

    heapSort(Data, MaxNumberNum);
    heapSortforStrings(Strings, MaxNumberNum);
    
    gettimeofday(&end, NULL);
    //計時結束

    double diff = 0;
    diff = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
    printf("Time of the operation : %f\n", diff / 1000000.0);
    
    //釋放記憶體
    for (int i = 0; i < MaxNumberNum; i++)
    {
        free(Strings[i]);
    }
}