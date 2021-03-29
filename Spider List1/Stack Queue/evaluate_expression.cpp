#include<bits/stdc++.h>
using namespace std;

int precedence(char op);
int applyOperation(int a, int b, char op);
int evaluate(string e);

int main(int argc, char const *argv[])
{
    cout << evaluate("10 + 2 * 6") << "\n";
    cout << evaluate("100 * 2 + 12") << "\n";
    cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14");   
    return 0;
}

int precendence(char op){
    if(op == '*' || op == '/')return 2;
    if(op == '+' || op == '-')return 1;
    return 0;
}

int applyOperation(int a, int b, char op){
    switch (op)
    {
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            return a/b;
            break;                
    }
}

int evaluate(string e){

    stack<int> values;
    stack<char> ops;
    for (int i = 0; i < e.length(); i++)
    {
        if(e[i] == ' ')continue;
        else if(e[i] == '('){
            ops.push(e[i]);
        }
        else if(isdigit(e[i])){
            int val = 0;
            while(i<e.length() && isdigit(e[i])){
                val = val*10 + (e[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }
        else if(e[i] == ')'){
            while(!ops.empty() && ops.top()!='('){
                char op = ops.top();
                ops.pop();
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                
                int result = applyOperation(a, b, op);
                values.push(result);
            }

            if(!ops.empty())
                ops.pop();
        }else{

            while (!ops.empty() && precendence(ops.top())>=precendence(e[i]))
            {
                char op = ops.top();
                ops.pop();
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                
                int result = applyOperation(a, b, op);
                values.push(result);  
            }
            ops.push(e[i]);
            
        }

    }
    while(!ops.empty()){
        char op = ops.top();
        ops.pop();
        int b = values.top();
        values.pop();
        int a = values.top();
        values.pop();
        
        int result = applyOperation(a, b, op);
        values.push(result);           
    }
    return values.top();
    
}