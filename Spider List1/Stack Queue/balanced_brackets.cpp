#include<bits/stdc++.h>
using namespace std;

bool checkBalancedBrackets(string e){

    stack<char> s;
    char c;
    for (int i = 0; i < e.length(); i++)
    {
        c = e[i];
        if(c == '[' || c == '{' || c == '('){
            s.push(c);
            continue;
        }else{

            if(s.empty())return false;

            char t = s.top();
            s.pop();
            switch (c)
            {
            case ')':
                if(t != '(')return false;
                break;
            case ']':
                if(t != '[')return false;
                break;
            case '}':
                if(t != '{')return false;
                break;                           
            default:
                return false;
                break;
            }
        }
        
    }
    return s.empty();
    
}
int main(int argc, char const *argv[])
{
    string expr = "{()}[]";
    bool result = checkBalancedBrackets(expr);
    (result)?cout<<"Balanced":cout<<"Not Balanced";
    return 0;
}
