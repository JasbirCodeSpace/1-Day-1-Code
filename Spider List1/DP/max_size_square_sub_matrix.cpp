#include<bits/stdc++.h>
using namespace std;
#define R 6
#define C 5

void printMaxSubSquareMatrix(int M[R][C]);  // O(m*n)
int main(int argc, char const *argv[])
{
    int M[R][C] = {{0, 1, 1, 0, 1},
                {1, 1, 0, 1, 0},
                {0, 1, 1, 1, 0},
                {1, 1, 1, 1, 0},
                {1, 1, 1, 1, 1},
                {0, 0, 0, 0, 0}};
                     
    printMaxSubSquareMatrix(M);
    return 0;
}

void printMaxSubSquareMatrix(int M[R][C]){

    int S[R][C];
    for(int i=0; i<R; i++)
        S[i][0] = M[0][i];
    for(int i=0; i<C; i++)
        S[0][i] = M[0][i];
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(M[i][j] == 0)
                S[i][j] = 0;
            else{
                S[i][j] = min(S[i-1][j-1], min(S[i-1][j], S[i][j-1]))+1;
            }
        }
    }

    int maxSize = S[0][0];
    int maxI = 0;
    int maxJ = 0;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(maxSize<S[i][j]){
                maxSize = S[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    cout<<"Maximum size sub matrix : \n";
    for (int i = maxI; i > maxI-maxSize; i--){
        for (int j = maxJ; j > maxJ-maxSize; j--)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
    
}