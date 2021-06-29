#include<iostream>
#include<cstring>
using namespace std;

int makeEqualLength(string& s1, string& s2){

    int len1 = s1.size();
    int len2 = s2.size();

    if(len1 < len2){
        for(int i=0; i<(len2-len1); i++)
            s1 =  '0'+s1; 
        return len2;   
    }else{
        for(int i=0; i<(len1-len2); i++)
            s2 = '0'+s2;
        return len1;
    }

    return len1;
}

string addString(string s1, string s2){

    string result = "";
    int len = makeEqualLength(s1, s2);
    int carry = 0;

    for(int i=(len-1); i>=0; i--){
        int x = s1[i]-'0';
        int y = s2[i]-'0';

        char sum = (x ^ y ^ carry) + '0';
        result = sum + result;
        carry = (x&y)|(y&carry)|(x&carry);
    }

    if(carry)
        result = '1'+result;

    return result;
}

int multiplySingleBit(string s1, string s2){
    return (s1[0]-'0')*(s2[0]-'0');
}


long int multiply(string s1, string s2){            // T(n) = O(n^log2(3)) = O(n^1.59)

    int len = makeEqualLength(s1, s2);

    if(len == 0)
        return 0;
    if(len == 1)
        return multiplySingleBit(s1, s2);

    int fh = len/2;
    int sh = len - fh;

    string xr = s1.substr(fh, sh);
    string xl = s1.substr(0, fh);

    string yr = s2.substr(fh, sh);
    string yl = s2.substr(0, fh);

    long int P1 = multiply(xl, yl);
    long int P2 = multiply(xr, yr);
    long int P3 = multiply(addString(xl, xr), addString(yl, yr));

    return P1*(1<<(2*sh)) + (1<<sh) * (P3 - P1 - P2) + P2;
    
}
int main(){
    printf ("%ld\n", multiply("1100", "1010"));
    printf ("%ld\n", multiply("110", "1010"));
    printf ("%ld\n", multiply("11", "1010"));
    printf ("%ld\n", multiply("1", "1010"));
    printf ("%ld\n", multiply("0", "1010"));
    printf ("%ld\n", multiply("111", "111"));
    printf ("%ld\n", multiply("11", "11"));
    return 0;
}