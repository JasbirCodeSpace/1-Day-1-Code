#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(V+E)
    Space complexity: O(V)
*/
class Graph{
    private:
        map<int, list<int>> adj;
    public:
        void addEdge(int u, int v){
            adj[u].push_back(v);
        }

        bool detectCycle(){
            map<int, bool> visited;
            map<int, bool> recStk;

            for(auto v: adj){
                if(detectCycle_Util(v.first, visited, recStk))
                    return true;
            }
            return false;
        }

        bool detectCycle_Util(int u, map<int, bool>& visited, map<int, bool>& recStk){

            if(visited[u] == false){
                visited[u] = true;
                recStk[u] = true;
                for (auto v = adj[u].begin(); v != adj[u].end(); v++)
                {
                    if(!visited[*v] && detectCycle_Util(*v, visited, recStk))
                        return true;
                    else if(recStk[*v])
                        return true;
                }
                
            }
            recStk[u] = false;
            return false;

        }

};

int main(int argc, char const *argv[])
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
  
    if(g.detectCycle())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";  
    return 0;
}
