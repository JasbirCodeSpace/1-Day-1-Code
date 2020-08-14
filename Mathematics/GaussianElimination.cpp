#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<double>> matrix);
void gaussian_elimination(vector<vector<double>> &matrix);
int forward_elimination(vector<vector<double>> &matrix);

int main()
{
    int N;
    vector<vector<double>> matrix{{3.0, 2.0, -4.0, 3.0},
                                  {2.0, 3.0, 3.0, 15.0},
                                  {5.0, -3, 1.0, 14.0}};

    print_matrix(matrix);

    return 0;
}

void gaussian_elimination(vector<vector<double>> &matrix)
{
    int singular_flag = forward_elimination(matrix);
    if (singular_flag != -1)
    {
        printf("\n Singular matrix: ");
        if (matrix[singular_flag][matrix[0].size()])
        {
            printf("Inconsistent system");
        }
        else
        {
            printf("May have infinitely many solutions");
        }
    }
}

int forward_elimination(vector<vector<double>> &matrix)
{
}

void print_matrix(vector<vector<double>> matrix)
{

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }

        printf("\n");
    }
}