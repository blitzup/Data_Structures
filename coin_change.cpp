#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       vector<vector<long long int>> matrix(m+1, vector<long long int>(n, 0));
       for(auto i=1; i<=m; i++)
       {
           for(auto j=0; j<n; j++)
           {
               if(S[i-1] > j+1)  matrix[i][j] = matrix[i-1][j];
               else if(S[i-1] == j+1) matrix[i][j] = matrix[i-1][j] + 1;
               else matrix[i][j] = matrix[i-1][j] + matrix[i][j-S[i-1]];
           }
       }
       
       return matrix[m][n-1];
       
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[m];

        for(auto i=0; i<m; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }
    return 0;
}