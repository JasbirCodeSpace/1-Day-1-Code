#include<bits/stdc++.h>
using namespace std;

int largestRectArea1(int *arr, int size);       // O(n^2)
int largestRectArea2(int *arr, int size);      //  O(n)
int main(int argc, char const *argv[])
{
    int hist[] =  {6, 2, 5, 4, 5, 1, 6};
    int size = sizeof(hist)/sizeof(hist[0]);
    cout << "Largest area is " << largestRectArea2(hist, size);
    return 0;
}

/*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/
int largestRectArea1(int *arr, int size){

    int maxArea = 0, minHeight = 0, width = 1;
    for (int i = 0; i < size-1; i++)
    {
        maxArea = max(maxArea, arr[i]);
        minHeight = arr[i];
        for (int j = i+1; j < size; j++)
        {
            minHeight = min(minHeight, arr[j]);
            width = j - i + 1;
            maxArea = max(maxArea, minHeight * width);
        }
        
    }
    return maxArea;

}

/*
    Time Complexity: O(N)
    Space Complexity: O(N)
*/
int largestRectArea2(int *arr, int size){

    stack<int> s;
    int maxArea = 0, top, tempArea = 0, i=0;
    while (i<size)
    {
        if(s.empty() || arr[s.top()]<=arr[i]){
            s.push(i++);
        }else{
            top = s.top();
            s.pop();
            tempArea = arr[top]*(s.empty()?i:i-s.top()-1);
            if(tempArea > maxArea)maxArea = tempArea;
        }
    }
    while(!s.empty()){
        top = s.top();
        s.pop();
        tempArea = arr[top]*(s.empty()?i:i-s.top()-1);
        if(tempArea > maxArea)maxArea = tempArea;
    }
    return maxArea;
}
