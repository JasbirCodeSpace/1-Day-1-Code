#include<bits/stdc++.h>
using namespace std;


int maxSumDQ(int *arr, int l, int h);                   // O(nlogn)
int maxCrossingSum(int *arr, int l, int m, int h);

int maxSumKadanes(int *arr, int l, int h){              // O(n)

    int max_so_far = INT_MIN, curr_max = 0;

    int start=0, end=0, t=0;
    for (int i = 0; i <= h; i++)
    {
        curr_max += arr[i];
        if(curr_max > max_so_far){
            max_so_far = curr_max;
            start = t;
            end=i;
        }

        if(curr_max < 0){
            curr_max = 0;
            t=i+1;
        }
    }
    printf("start = %d, end = %d \n", start, end);
    return max_so_far;
    
}

int maxSumDP(int *arr, int l, int h){                   // O(n)
    int max_so_far = arr[l], curr_max = arr[l];

    for(int i=1; i<=h; i++){
        curr_max = max(arr[i], curr_max+arr[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}
int main(int argc, char const *argv[])
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSumDP(a, 0, n-1);
    cout << "Maximum contiguous sum is " << max_sum<<endl;
    return 0;
}

int maxSumDQ(int *arr, int l, int h){           
    if(l==h)
        return arr[l];
    
    int m = (l+h)/2;
    return max(maxSumDQ(arr, l, m), max(maxSumDQ(arr, m+1, h), maxCrossingSum(arr, l, m, h)));
}

int maxCrossingSum(int *arr, int l, int m, int h){
    int sum = 0;
    int left_sum = INT_MIN;

    for(int i=m; i>=l; i--){
        sum += arr[i];
        if(sum > left_sum)
            left_sum = sum;
    }

    int right_sum = INT_MIN;
    sum=0;
    for(int i=m+1; i<=h; i++){
        sum += arr[i];
        if(right_sum < sum)
            right_sum = sum;
    }

    return max(left_sum+right_sum, max(left_sum, right_sum));
}