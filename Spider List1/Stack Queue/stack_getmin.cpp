#include<bits/stdc++.h>
using namespace std;

class Stack
{
private:
    stack<int> s;
    int minElement;
public:

    void push(int x){
        if(s.empty()){
            s.push(x);
            minElement = x;
        }else{
            if(x < minElement){
                s.push(2*x-minElement);
                minElement = x;
            }else{
                s.push(x);
            }
        }
        cout<<"Pushed "<<x<<" onto the stack\n";
        return;
    }

    void pop(){
        if (s.empty())
        {
            cout<<"Stack underflow\n";
        }else{
            int x = s.top();
            s.pop();
            cout<<"Popped element from top of stack: ";
            if(x < minElement){
                cout<<minElement<<'\n';
                minElement = 2*minElement - x;
            }else{
                cout<<x<<'\n';
            }
        }
        
    }

    void getMin(){
        if(s.empty()){
            cout<<"Stack is empty\n";
        }else{
            cout<<"Minimum element is "<<minElement<<'\n';
        }
    }

    void peek(){
        if(s.empty()){
            cout<<"Stack is empty\n";
        }else{
            int x = s.top();
            cout<<"Element on top of stack is: ";
            if(x < minElement){
                cout<<minElement<<'\n';
            }else{
                cout<<x<<'\n';
            }
        }
    }

};

int main(int argc, char const *argv[])
{

    Stack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
    return 0;
}
