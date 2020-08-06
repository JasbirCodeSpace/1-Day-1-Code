#include <bits/stdc++.h>
using namespace std;

void generate_random_array(vector<int> &arr, int size, int limit);
void print_array(vector<int> arr);
void bubble_sort(vector<int> &arr);

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
    printf("\nIs sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");

    bubble_sort(arr);
    printf("\n\nAfter sorting: ");
    print_array(arr);
    printf("\nIs sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");
}
// Worst and Average Case Time Complexity: O(n^2). Worst case occurs when array is reverse sorted.
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
// Auxiliary Space: O(1)
// Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
void bubble_sort(vector<int> &arr)
{
    int i, lastUnsorted = arr.size() - 1;
    bool isSorted = false;

    while (!isSorted)
    {
        isSorted = true;
        for (i = 0; i < lastUnsorted; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
        lastUnsorted--;
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