#include<bits/stdc++.h>
using namespace std;

void reverse(string str){

    if(str == "")
        return;
    reverse(str.substr(1));
    cout<<str[0];
}
int main(int argc, char const *argv[])
{
    string str = "recursion";
    cout<<"String: "<<str<<endl;
    cout<<"Reverse: ";
    reverse(str);
    cout<<endl;
    return 0;
}
