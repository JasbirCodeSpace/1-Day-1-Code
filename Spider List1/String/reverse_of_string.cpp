#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(n)
*/
string reverse1(string s);
string reverse2(string s);
int main(int argc, char const *argv[])
{
    string s = "Jasbir"; 
    cout<<"Reversed string: "<<reverse2(s);
    return 0;
}

string reverse1(string s){
    if(s.size() == 0)return "";
    return s[s.size()-1]+reverse1(s.substr(0, s.size()-1));
}

string reverse2(string s){
    string r = "";
    for (int i = s.size()-1; i >= 0; i--)
        r += s[i];
    return r;
    
}