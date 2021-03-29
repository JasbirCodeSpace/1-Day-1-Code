#include<bits/stdc++.h>
using namespace std;

class TwoStack
{
private:
    int size;
    int *arr;
    int top1;
    int top2;
public:

    TwoStack(int size){
        this->size = size;
        this->arr = new int[size];
        this->top1 = -1;
        this->top2 = size;
    }
    void push1(int x){
        if(top1<size/2){
            arr[++top1] = x;
        }else{
            cout<<"Overflow of stack1\n";
        }
    }
    void push2(int x){
        if(top2>size/2+1){
            arr[--top2] = x;
        }else{
            cout<<"Overflow of stack2\n";
        }
    }

    int pop1(){
        if(top1==-1){
            cout<<"Underflow of stack1\n";
            return -1;
        }else{
            int x = arr[top1];
            top1--;
            return x;
        }
    }

    int pop2(){
        if(top2 == size){
            cout<<"Underflow of stack2\n";
            return -1;
        }else{
            int x = arr[top2];
            top2++;
            return x;
        }
    }

};


int main(int argc, char const *argv[])
{
    TwoStack ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << " : " << ts.pop1()
         << endl;
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ": " << ts.pop2()
         << endl;
    return 0;
}
