#include<bits/stdc++.h>
using namespace std;

class Queue
{
private:
    stack<int> s1, s2;
    int size;
public:
    void enqueue(int x){
        s1.push(x);
    }
    int dequeue(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        if(s2.empty()){
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
};


int main(int argc, char const *argv[])
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
  
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';

    return 0;
}
