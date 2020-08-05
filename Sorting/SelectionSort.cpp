#include <bits/stdc++.h>
using namespace std;

void generate_random_array(vector<int> &arr, int size, int limit);
void print_array(vector<int> arr);
void selection_sort(vector<int> &arr);

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

    selection_sort(arr);
    printf("\n\nArray after sorting: ");
    print_array(arr);
    printf("\nIs sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");
    return 0;
}

// Time Complexity: O(n^2) Auxillary Space: O(1)
//The good thing about selection sort is it never makes more than O(n) swaps
//and can be useful when memory write is a costly operation.
void selection_sort(vector<int> &arr)
{
    int i, j, min;
    for (i = 0; i < arr.size() - 1; i++)
    {
        min = i;
        for (j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap(arr[i], arr[min]);
        }
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