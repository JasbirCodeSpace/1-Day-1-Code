#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& s, int data){
    if(s.empty()){
        s.push(data);
    }else{
        int top = s.top();
        s.pop();
        insertAtBottom(s, data);
        s.push(top);
    }
}
void reverseStack(stack<int>& s){
    if(s.empty())
        return;
    int top = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, top);
}
int main(int argc, char const *argv[])
{
    stack<int> s;
    for(int i=0; i<5; i++)
        s.push(i);
    
    reverseStack(s);
    cout<<"Reverse stack: ";

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
