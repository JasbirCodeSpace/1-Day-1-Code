#include<bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5

int rowNeighbour[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colNeighbour[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isSafe(int M[][COL], int row, int col, bool visited[][COL]){

    return (row>=0 && row<ROW && col>=0 && col<COL && M[row][col]==1 && !visited[row][col]);
}

void dfs(int M[][COL], int row, int col, bool visited[][COL]){

    visited[row][col] = true;
    for (int i = 0; i < 8; i++)
    {
        if(isSafe(M, row+rowNeighbour[i], col+colNeighbour[i], visited)){
            dfs(M, row+rowNeighbour[i], col+colNeighbour[i], visited);
        }
    }
    
}
int countIslands(int M[][COL]){

    bool visited[ROW][COL];
    int count = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if(M[i][j]==1 && !visited[i][j]){
                dfs(M, i, j, visited);
                count++;
            }
        }
        
    }
    return count;
    
}
int main(int argc, char const *argv[])
{
    int M[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 1, 0 } };
 
    cout << "Number of islands is: " << countIslands(M);   
    return 0;
}
