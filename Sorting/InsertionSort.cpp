#include <bits/stdc++.h>
using namespace std;

vector<int> generate_random_array(int size, int limit);
void print_array(vector<int> arr);
void insertion_sort(vector<int> &arr);

int main()
{
    int size, limit;
    printf("\nEnter the size of array: ");
    scanf("%d", &size);
    printf("\nEnter the maximum value in array: ");
    scanf("%d", &limit);

    vector<int> arr = generate_random_array(size, limit);
    printf("\nInitial array: ");
    print_array(arr);
    printf("\nIs sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");

    insertion_sort(arr);
    printf("\n\nAfter sorting: ");
    print_array(arr);
    printf("\nIs sorted: %s", is_sorted(arr.begin(), arr.end()) ? "true" : "false");
    return 0;
}

void insertion_sort(vector<int> &arr)
{
    int i, j, key;
    for (i = 1; i < arr.size(); i++)
    {
        j = i;
        key = arr[j];
        while (j >= 1 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

vector<int> generate_random_array(int size, int limit)
{
    vector<int> arr(size, 0);
    srand((int)time(0));

    for (int i = 0; i < size; i++)
    {
        arr[i] = 1 + rand() % limit;
    }

    return arr;
}

void print_array(vector<int> arr)
{
    for (int elem : arr)
        printf("%d ", elem);
}