#include <bits/stdc++.h>
using namespace std;

void generate_random_array(vector<int> &arr, int size, int limit);
void print_array(vector<int> arr);

void heap_sort(vector<int> &arr);
void heapify(vector<int> &arr, int size, int i);
int main()
{
    int size, limit;
    printf("\nEnter the size of array: ");
    scanf("%d", &size);
    printf("\nEnter the maximum value in array: ");
    scanf("%d", &limit);

    vector<int> arr(size, 0);
    generate_random_array(arr, size, limit);
    printf("\n\nInitial array: ");
    print_array(arr);
    printf("\nIs array sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");

    heap_sort(arr);
    printf("\n\nAfter sorting: ");
    print_array(arr);
    printf("\nIs array sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");

    return 0;
}

// Time complexity: O(n*logn)
// Auxilliary space : O(1)
void heap_sort(vector<int> &arr)
{

    for (int i = arr.size() / 2 - 1; i >= 0; i--)
    {
        heapify(arr, arr.size(), i);
    }

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(vector<int> &arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
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