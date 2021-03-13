#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int size;
    int upper_bound = INT_MAX;
    FILE *fptr;
    printf("\nEnter the size of array:");
    scanf("%d", &size);
    fptr = fopen("input.txt", "w");
    if (fptr == NULL)
    {
        printf("ERROR Creating File!");
        exit(1);
    }
    fprintf(fptr, "%d", &size);
    for (int i = 0; i < size; i++)
    {
        int elem = rand() % 10;
        fprintf(fptr, "%d ", elem);
    }
    fprintf(fptr, "\n");

    fclose(fptr);
    return 0;
}