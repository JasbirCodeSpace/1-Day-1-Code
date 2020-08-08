#include <bits/stdc++.h>
using namespace std;

const int RUN = 32;

void generate_random_array(vector<int> &arr, int size, int limit);
void print_array(vector<int> arr);

void insertion_sort(vector<int> &arr, int leftIdx, int rightIdx);
void mergeHalves(vector<int> &arr, vector<int> &temp, int leftIdx, int middle, int rightIdx);
void tim_sort(vector<int> &arr);

int main()
{
    int size, limit;
    printf("\nEnter the size of array: ");
    scanf("%d", &size);
    printf("\nEnter the maximum value in array: ");
    scanf("%d", &limit);

    vector<int> arr(size, 0);
    generate_random_array(arr, size, limit);
    printf("\n\nInput array: ");
    print_array(arr);
    printf("\nIs sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");

    tim_sort(arr);
    printf("\n\nAfter sorting: ");
    print_array(arr);
    printf("\nIs sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");

    return 0;
}

void tim_sort(vector<int> &arr)
{
    int right = 0, mid = 0;
    vector<int> temp(arr);
    for (int i = 0; i < arr.size(); i += RUN)
    {
        insertion_sort(arr, i, min(RUN + i - 1, (int)arr.size() - 1));
    }

    for (int size = RUN; size < arr.size(); size *= 2)
    {

        for (int left = 0; left < arr.size(); left += 2 * size)
        {
            right = min(left + 2 * size - 1, (int)arr.size() - 1);
            mid = left + size - 1;
            mergeHalves(arr, temp, left, mid, right);
        }
    }
}
void insertion_sort(vector<int> &arr, int leftIdx, int rightIdx)
{
    int j, key;
    for (int i = leftIdx + 1; i <= rightIdx; i++)
    {
        j = i;
        key = arr[i];
        while (j >= leftIdx + 1 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}
void copyArray(vector<int> &a, int aBegin, vector<int> &b, int bBegin, int size)
{

    for (int i = aBegin, j = bBegin; i <= size; ++i, ++j)
    {
        b[j] = a[i];
    }
    return;
}
void mergeHalves(vector<int> &arr, vector<int> &temp, int leftStart, int middle, int rightEnd)
{

    int leftEnd = middle;
    int rightStart = middle + 1;

    int i = leftStart;
    int j = rightStart;
    int k = leftStart;

    while (i <= leftEnd && j <= rightEnd)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= leftEnd)
    {
        temp[k++] = arr[i++];
    }
    while (j <= rightEnd)
    {
        temp[k++] = arr[j++];
    }
    copyArray(temp, leftStart, arr, leftStart, rightEnd);
}
void generate_random_array(vector<int> &arr, int size, int limit)
{
    srand((int)time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = 1 + rand() % limit;
    }
}

void print_array(vector<int> arr)
{
    for (int elem : arr)
    {
        printf("%d ", elem);
    }
}