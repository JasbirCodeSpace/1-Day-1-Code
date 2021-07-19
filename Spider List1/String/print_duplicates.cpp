#include<bits/stdc++.h>
using namespace std;
#define SIZE 256

// Time: O(N)
void printDuplicates(string s){
    int count[SIZE]={0};

    for(int i=0; i<s.length(); i++)
        count[s[i]]++;
    
    for(int i=0; i<SIZE; i++){
        if(count[i]>1){
            cout<<(char)i<<" = "<<count[i]<<endl;
        }
    }
}
int main(int argc, char const *argv[])
{
    string str = "gaurdiansofthegalaxy";
    printDuplicates(str);
    return 0;
}
