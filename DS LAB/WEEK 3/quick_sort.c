#include <stdio.h>

void quick_sort(int *arr, int left, int right);
int partition(int *arr, int left, int right);
void print_array(int *arr, int size);
void swap(int *x, int *y);
int main()
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    return 0;
}

void quick_sort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    int pivot = partition(arr, left, right);
    quick_sort(arr, left, pivot - 1);
    quick_sort(arr, pivot + 1, right);
}

int partition(int *arr, int left, int right)
{
    int pivot = arr[right - 1];
    int i = left - 1;
    for (int j = i; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right - 1]);
    return i + 1;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_array(int *arr, int size)
{
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}