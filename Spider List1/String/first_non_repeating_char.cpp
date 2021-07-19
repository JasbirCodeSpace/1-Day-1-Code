#include<bits/stdc++.h>
using namespace std;

#define SIZE 256

// Time: O(n * n!)
int firstNonRepChar(string str){
    pair<int, int> c[SIZE];
    for(int i=0; i<str.length(); i++){
        c[str[i]].first++;
        c[str[i]].second=i;
    }

    int idx = INT_MAX;
    for(int i=0; i<SIZE; i++){
        if(c[i].first == 1){
            idx = min(idx, c[i].second);
        }
    }
    return idx==INT_MAX?-1:idx;
}
int main(int argc, char const *argv[])
{
    
    string str = "gaurdiansofthegalaxy";
    int idx = firstNonRepChar(str);
    if (idx == -1)
        printf("Either all characters are repeating or "
               "string is empty");
    else
        printf("First non-repeating character is %c",
               str[idx]);
    return 0;
}
