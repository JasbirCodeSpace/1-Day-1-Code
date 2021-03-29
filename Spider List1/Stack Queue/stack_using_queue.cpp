#include<bits/stdc++.h>
using namespace std;

class Stack
{
private:
    queue<int> q1, q2;
    int size;
public:

    Stack(){
        size = 0;
    }

    void push(int x){
        size++;
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q = q1;
        q1 = q2;
        q2 = q;   
    }

    int pop(){
        if(q1.empty()){
            cout<<"Stack underflow\n";
            return -1;
        }
        size--;
        int x = q1.front();
        q1.pop();
        return x;
    }
    int top(){
        return q1.front();
    }
    int stackSize(){
        return size;
    }

};

int main(int argc, char const *argv[])
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
  
    cout << "current size: " << s.stackSize()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
  
    cout << "current size: " << s.stackSize()
         << endl;
    return 0;
}
