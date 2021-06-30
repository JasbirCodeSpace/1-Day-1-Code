#include<iostream>

double powerRecursive(int x, int n){
    if(n==0)
        return 1;
    
    double temp = powerRecursive(x, n/2);
    if(n&1){
        if(n>0)
            return temp * temp * x;
        else
            return (temp * temp)/x;
    }
    else
        return temp * temp;
}

double powerIterative(int x, int n){

    double result=1;

    while(n){
        if(n&1){
            if(n>0)
                result *=x;
            else
                result /=x;
        }

        n = n / 2;
        x *= x;
    }

    return result;
}
int main()
{
    int x = 3;
    unsigned int y = 5;
 
    printf("Power is %lf \n", powerIterative(x, y));
    printf("Power is %lf \n", powerIterative(x, -y));
 
    return 0;
}