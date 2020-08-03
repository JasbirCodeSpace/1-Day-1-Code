#include <bits/stdc++.h>
using namespace std;

vector<int> generateRandomArray(int limit, int size);
void printArray(vector<int> arr);

void mergeSort(vector<int> &arr);
void divide(vector<int> &arr, vector<int> &temp, int startIdx, int endIdx);
void mergeHalves(vector<int> &arr, vector<int> &temp, int startIdx, int middleIdx, int endIdx);

int main()
{
    int size, limit;

    printf("\nEnter size of array: ");
    scanf("%d", &size);

    printf("\nEnter maximum value in array: ");
    scanf("%d", &limit);

    vector<int> arr = generateRandomArray(limit, size);

    printf("\nInitial Array: ");
    printArray(arr);
    printf("Is Sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");

    mergeSort(arr);
    printf("\n\nAfter Sorting: ");
    printArray(arr);
    printf("Is Sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");

    return 0;
}

vector<int> generateRandomArray(int limit, int size)
{
    srand((int)time(0));
    vector<int> arr(size, 0);

    for (int i = 0; i < size; i++)
    {
        arr[i] = 1 + rand() % limit;
    }

    return arr;
}

void printArray(vector<int> arr)
{

    for (int elem : arr)
        printf("%d ", elem);
    printf("\n");
}

// Time Complexity: O(n*logn) in all 3 cases
void mergeSort(vector<int> &arr)
{
    vector<int> temp(arr.begin(), arr.end());

    divide(arr, temp, 0, arr.size() - 1);
}

void divide(vector<int> &arr, vector<int> &temp, int startIdx, int endIdx)
{
    if (startIdx >= endIdx)
        return;
    int midIdx = (startIdx + endIdx) / 2;
    divide(temp, arr, startIdx, midIdx);
    divide(temp, arr, midIdx + 1, endIdx);
    mergeHalves(arr, temp, startIdx, midIdx, endIdx);
}

void mergeHalves(vector<int> &arr, vector<int> &temp, int startIdx, int middleIdx, int endIdx)
{
    int i = startIdx, j = middleIdx + 1, k = startIdx;

    while (i <= middleIdx && j <= endIdx)
    {
        if (temp[i] <= temp[j])
        {
            arr[k++] = temp[i++];
        }
        else
        {
            arr[k++] = temp[j++];
        }
    }

    while (i <= middleIdx)
    {
        arr[k++] = temp[i++];
    }
    while (j <= endIdx)
    {
        arr[k++] = temp[j++];
    }
}