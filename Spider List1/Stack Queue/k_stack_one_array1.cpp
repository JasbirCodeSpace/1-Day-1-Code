#include<bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *arr;
    int size;
    int k;
    int *top;
public:
    Stack(int size, int k){
        this->size = size;
        this->k = k;
        this->arr = new int[size];
        this->top = new int[k];
        for (int i = 0; i < k; i++)top[i]=-1;
        
    }
    void push(int x, int i){

        int startIdx = (size/k)*i;
        int endIdx = (i+1)*(size/k)-1;
        if(top[i] > endIdx){
            cout<<"Overflow for stack"<<i<<'\n';
            return;
        }
        if(top[i] == -1){
            top[i] = startIdx-1;
        }
        arr[++top[i]] = x;

    }

    int pop(int i){
        if(top[i] == -1){
            cout<<"Underflow for stack"<<i<<'\n';
            return -1;
        }
        int x = arr[top[i]--];
        return x;
    }

    void printStack(){
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        
    }
};

int main(int argc, char const *argv[])
{
    int size = 10, k =3;
    Stack ks(size, k);
  
    ks.push(15, 2);
    ks.push(45, 2);
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
    
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
    return 0;
}
