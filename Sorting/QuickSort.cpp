#include <bits/stdc++.h>
using namespace std;

void generate_random_array(vector<int> &arr, int size, int limit);
void print_array(vector<int> arr);

void quick_sort(vector<int> &arr);
void quick_sort(vector<int> &arr, int startIdx, int endIdx);
int partition(vector<int> &arr, int startIdx, int endIdx);
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
    printf("\nIs array sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");

    quick_sort(arr);
    printf("\n\nAfter sorting: ");
    print_array(arr);
    printf("\nIs array sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");
    return 0;
}

// Time complexity: O(n*logn)
// Handle the worst case with random pivot selection
// Auxilliary space: None (Inplace algorithm)
void quick_sort(vector<int> &arr)
{
    quick_sort(arr, 0, arr.size() - 1);
}

void quick_sort(vector<int> &arr, int startIdx, int endIdx)
{
    if (startIdx >= endIdx)
        return;
    int pivotIdx = partition(arr, startIdx, endIdx);
    quick_sort(arr, startIdx, pivotIdx - 1);
    quick_sort(arr, pivotIdx + 1, endIdx);
}

int partition(vector<int> &arr, int startIdx, int endIdx)
{
    srand((int)time(0));
    int pivotIdx = startIdx + rand() % (endIdx - startIdx + 1);
    swap(arr[pivotIdx], arr[endIdx]);
    int pivot = arr[endIdx];

    int i = startIdx - 1, j = startIdx;
    for (; j <= endIdx - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[endIdx]);
    return i + 1;
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
