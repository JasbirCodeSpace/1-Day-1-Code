#include<iostream>
using namespace std;

int sumOfDigit(int n){
    if(n == 0)
        return 0;
    return n%10 + sumOfDigit(n/10);
}

int main(int argc, char const *argv[])
{
    int n = 12345;
    cout<<"N = "<<n<<endl;
    cout<<"Sum of digits = "<<sumOfDigit(n)<<endl;
    return 0;
}
