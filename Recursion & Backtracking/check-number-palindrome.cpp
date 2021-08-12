#include<iostream>
#include<string.h>
using namespace std;

void reverse(int n, int &temp){
    if(n == 0)
        return;
    else{
        temp = temp*10 + n%10;
        reverse(n/10, temp);
    }
}
string checkPalindrome(int n){
    int temp = 0;
    reverse(n, temp);
    if(n == temp)
        return "Yes";
    else 
        return "No";
}
int main(int argc, char const *argv[])
{
    int n = 12322;
    cout<<"Number: "<<n<<endl;
    cout<<"Is palindrome: "<<checkPalindrome(n)<<endl;
    return 0;
}
