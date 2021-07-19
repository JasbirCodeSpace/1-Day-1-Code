#include<bits/stdc++.h>
using namespace std;

/*
    Time: O(N)
    Space: O(N)
*/
string reverseWords(string str){
    vector<string> words;
    string temp = "";

    for(int i=0; i<str.length(); i++){
        if(str[i]==' '){
            words.push_back(temp);
            temp = "";
        }else{
            temp += str[i];
        }
    }
    words.push_back(temp);

    temp = "";
    for(int i=words.size()-1; i>0; i--)
        temp += words[i]+" ";
    temp +=words[0];
    return temp;
}
int main(int argc, char const *argv[])
{
    string s = "i like this program very much";
    string res = reverseWords(s);
    cout<<"Reverse words: "<<res<<endl;
    return 0;
}
