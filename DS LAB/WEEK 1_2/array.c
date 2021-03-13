#include <stdio.h>
#include <stdlib.h>

void insertion(int *arr, int size, int pos, int elem)
{
    for (int i = size - 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = elem;
}

void deletion(int *arr, int size, int pos)
{
    for (int i = pos - 1; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
}

void insertion_sort(int *arr, int size)
{
    int j, key;
    for (int i = 1; i < size; i++)
    {
        j = i - 1;
        key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int linear_search(int arr[], int size, int elem)
{
    int idx = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == elem)
        {
            idx = i;
            break;
        }
    }
    return idx;
}

int binary_search(int *arr, int size, int elem)
{

    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == elem)
            return mid;
        else if (arr[mid] > elem)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}
void print_array(int arr[], int size)
{
    printf("Array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int size;
    int arr[100];

    int choice;
    do
    {
        printf("\n ==========Choose an operation======== \n");
        printf("1. Initialize \n");
        printf("2. Updation \n");
        printf("3. Insertion \n");
        printf("4. Deletion \n");
        printf("5. Sorting \n");
        printf("6. Binary Search \n");
        printf("7. Linear Search \n");
        printf("8. Print Array \n");
        printf("9. Exit \n");
        printf("Enter your choice :  ");
        scanf("%d", &choice);

        int pos, elem;
        switch (choice)
        {
        case 1:
            printf("\nEnter the size of array: ");
            scanf("%d", &size);
            printf("\nEnter the array elements: ");
            for (int i = 0; i < size; i++)
            {
                scanf("%d", &arr[i]);
            }
            print_array(arr, size);
            break;
        case 2:
            printf("\nEnter position: ");
            scanf("%d", &pos);
            while (pos < 1 || pos > size)
            {
                printf("Invalid Position");
                printf("\nEnter position: ");
                scanf("%d", &pos);
            }
            printf("Enter the updated value: ");
            scanf("%d", &elem);
            arr[pos - 1] = elem;
            print_array(arr, size);
            break;

        case 3:
        {
            size++;
            printf("\nEnter position: ");
            scanf("%d", &pos);
            while (pos < 1 || pos > size)
            {
                printf("Invalid Position");
                printf("\nEnter position: ");
                scanf("%d", &pos);
            }
            printf("Enter the element: ");
            scanf("%d", &elem);
            insertion(arr, size, pos, elem);
            print_array(arr, size);
        }
        break;
        case 4:
        {
            printf("\nEnter position: ");
            scanf("%d", &pos);
            while (pos < 1 || pos > size)
            {
                printf("Invalid Position");
                printf("\nEnter position: ");
                scanf("%d", &pos);
            }
            deletion(arr, size, pos);
            size--;
            print_array(arr, size);
        }
        break;

        case 5:
            insertion_sort(arr, size);
            print_array(arr, size);
            break;

        case 6:
        {
            printf("\nEnter element to search: ");
            scanf("%d", &elem);
            int result = binary_search(arr, size, elem);
            if (result != -1)
            {
                printf("Element found at position %d\n", result + 1);
            }
            else
            {
                printf("Element not found\n");
            }
        }
        break;
        case 7:
        {
            printf("\nEnter element to search: ");
            scanf("%d", &elem);
            int result = linear_search(arr, size, elem);
            if (result != -1)
            {
                printf("Element found at position %d\n", result + 1);
            }
            else
            {
                printf("Element not found\n");
            }
        }
        break;

        case 8:
        {
            print_array(arr, size);
        }
        break;

        case 9:
            exit(1);
        }
    } while (choice >= 1 && choice <= 9);
    return 0;
}