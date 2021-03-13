#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void merge_sort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);
void max_heapify(int *arr, int n, int i);
void heap_sort(int *arr, int n);
int partition(int *arr, int l, int h);
int partition_random(int *arr, int l, int h);
void quick_sort(int *arr, int l, int h);
void print_array(int *arr, int size);
void swap(int *x, int *y);

void insertion_sort(int *arr, int size);
int min(int x, int y){ return x>y?y:x;}
void tim_sort(int *arr, int size);

int main(){
    srand(time(NULL));
    int size;
    int arr[1000];
    int choice;
    do{
        printf("\n\n ==========Choose an operation======== \n");
        printf("1. Initialize the array\n");
        printf("2. Generate random array\n");
        printf("3. Print array\n");
        printf("4. Merge Sort\n");
        printf("5. Heap Sort\n");
        printf("6. Quick Sort\n");
        printf("7. Tim Sort\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the size of array: ");
            scanf("%d", &size);
            printf("\nEnter the array elements: ");
            for (int i = 0; i < size; i++)scanf("%d", &arr[i]);
            break;
        case 2:
            printf("\nEnter the size of array: ");
            scanf("%d", &size);
            for(int i=0;i<size;i++)arr[i] = rand()%1000;

        case 3:
            print_array(arr, size);
            break;
        case 4: 
            merge_sort(arr, 0, size-1);
            print_array(arr, size);
            break;
        case 5: 
            heap_sort(arr, size);
            print_array(arr, size);
            break;
        case 6:
            quick_sort(arr, 0, size-1);
            print_array(arr, size);
            break;
        case 7:
            tim_sort(arr, size);
            print_array(arr, size);
        default:
            break;
        }
    }while(choice>=1 && choice<=7);
    return 0;
}

void merge_sort(int *arr, int l, int r){
    if(l>=r)return;
    int mid = l + (r-l)/2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

void merge(int *arr, int l, int m, int r){
    int i = l;
    int j = m+1;
    if(arr[m]<=arr[j])return;
    while(i<=m && j<=r){
        if(arr[i]<=arr[j])i++;
        else{
            int value = arr[j];
            int idx = j;
            while(idx!=i){
                arr[idx] = arr[idx-1];
                idx--;
            }
            arr[idx] = value;
            i++;
            m++;
            j++;
        }
    }
    return;
}

// void merge(int *arr, int l, int m, int r){
//     int size1 = m - l + 1;
//     int size2 = r - m;
//     int left[size1];
//     int right[size2];
//     for (int i = 0; i < size1; i++)left[i] = arr[l+i];
//     for(int i = 0;i < size2; i++)right[i] = arr[m+i+1];

//     int i=0, j=0, k = l;
//     while(i<size1 && j<size2){
//         if(left[i]<=right[j]){
//             arr[k++] = left[i++];
//         }else{
//             arr[k++] = right[j++];
//         }
//     }

//     while(i<size1)arr[k++] = left[i++];
//     while(j<size2)arr[k++] = right[j++];

//     return;
     
// }
void max_heapify(int *arr, int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]>arr[largest])largest = left;
    if(right<n && arr[right]>arr[largest])largest = right;
    if(i!=largest){
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, n, largest);
    }
    return;
}

void heap_sort(int *arr, int n){
    for (int i = n/2-1; i>=0; i--)
    {
        max_heapify(arr, n, i);
    }

    for (int i = n-1; i >=0; i--)
    {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, i, 0);
    }
    return;
}
int partition_random(int *arr, int l, int h){
    srand(time(NULL));
    int idx =l + rand()%(h-l);
    swap(&arr[idx], &arr[h]);
    return partition(arr, l, h);
}
int partition(int *arr, int l, int h){
    int i = l-1;
    int j = l;
    int pivot = arr[h];
    while(j<h){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    } 
    swap(&arr[i+1], &arr[h]);
    return i+1;
}

void quick_sort(int *arr, int l, int h){
    if(l>=h)return;
    int pivot = partition_random(arr, l, h);
    quick_sort(arr, l, pivot-1);
    quick_sort(arr, pivot+1, h);
}
void print_array(int *arr, int size){
    printf("\nArray: [");
    for (int i = 0; i < size; i++)printf("%d ", arr[i]);
    printf("]");
    return;
    
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void insertion_sort(int *arr, int l, int r){
    int i, j, key;
    for (i = l; i <=r; i++)
    {
        j = i;
        key = arr[j];
        while (j>=l+1 && arr[j-1]>key)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }
    
}

void tim_sort(int *arr, int size){
    int RUN = 32;
    for (int i = 0; i < size; i+=RUN)
    {
        insertion_sort(arr, i, min(RUN+i-1, size-1));
    }

    for (int  s = RUN; s < size; s*=2)
    {
        for (int l = 0; l < size; l += 2*s)
        {
            int r = min(l+2*s-1, size-1);
            int mid = l + s -1;
            merge(arr, l, mid, r);

        }
        
    }
    
    
}