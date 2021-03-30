#include<bits/stdc++.h>
using namespace std;

void calculateSpan1(int* price, int* span, int size);    // O(n^2)
void calculateSpan2(int* price, int* span, int size);    // O(n)
void printArray(int *arr, int size);
int main(int argc, char const *argv[])
{
    int price[] = { 10, 4, 5, 90, 120, 80 };
    int size = sizeof(price)/sizeof(price[0]);
    int span[size];
    calculateSpan2(price, span, size);
    printArray(span, size);
    return 0;
}

void calculateSpan1(int *price, int *span, int size){

    span[0] = 1;
    for (int i = 1; i < size; i++)
    {
        span[i] = 1;
        for (int j = i-1; j>=0 && price[i]>=price[j]; j--)
        {
            span[i]++;
        }
    }
    
}

void calculateSpan2(int *price, int *span, int size){
    span[0] = 1;
    stack<int> s;
    s.push(0);

    for (int i = 1; i < size; i++)
    {
        while (!s.empty() && price[s.top()]<=price[i])
        {
            s.pop();
        }
        span[i] = s.empty()? (i+1): (i - s.top());
        s.push(i);
    }
    
}
void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}