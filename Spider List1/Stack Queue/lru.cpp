#include<bits/stdc++.h>
using namespace std;

class LRU
{
private:
    list<int> cache;
    unordered_map<int, list<int>::iterator> m;
    int size;
public:
    LRU(int size){
        this->size = size;
    }

    void refer(int x){
        if (m.find(x) == m.end())       // x not present in cache right now
        {
            if(cache.size() == this->size){
                m.erase(cache.back());
                cache.pop_back();
            }

        }else{                          // x is present in cache
            cache.erase(m[x]);
        }
        cache.push_front(x);
        m[x] = cache.begin();
    }

    void display(){

        for (auto i = cache.begin(); i != cache.end(); i++)
        {
           cout<<*i<<" ";
        }
        cout<<'\n';
    }
};


int main(int argc, char const *argv[])
{
    LRU ca(4);
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
     
    return 0;
}
