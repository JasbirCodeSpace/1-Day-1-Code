#include <bits/stdc++.h>
using namespace std;

void print_array(int N, vector<int> &arr)
{

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selection_sort(int N, vector<int> &arr)
{
    int i, j, min;
    for (i = 0; i < arr.size() - 1; i++)
    {
        min = i;
        for (j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
        print_array(N, arr);
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    selection_sort(N, arr);
    return 0;
}