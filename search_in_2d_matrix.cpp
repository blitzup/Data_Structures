#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binary_search_col(vector<vector<int>> &matrix, int low, int mid, int high, int target)
    {
        int size = matrix[0].size();
        if(low >= high)
        {
            int msize = matrix.size()-1;
            if(mid+1 <= msize && target >= matrix[mid+1][0])
                return mid+1;
            else if(target >= matrix[mid][0])
                return mid;
            else
                return mid - 1;

        }
        
        int middle = low + (high - low)/2;
        
        if(matrix[middle][0] == target)
            return middle;
        
        else if(matrix[middle][0] > target)
        {
            if(target > matrix[middle - 1][size - 1])
                return middle;
            return binary_search_col(matrix, low, middle, middle - 1, target);
        }
        
        else
        {
            if(target < matrix[middle + 1][0])
                return middle;
            return binary_search_col(matrix, middle+1, middle, high, target);
        }
            
    }
    
    int binary_search_row(vector<vector<int>> &matrix, int low, int high, int target, int i)
    {
        if(low > high)
            return -1;
        
        int mid = low + (high - low)/2;
        
        if(matrix[i][mid] == target)
            return mid;
        
        else if(matrix[i][mid] > target)
            return binary_search_row(matrix, low, mid - 1, target, i);
        
        else
            return binary_search_row(matrix, mid+1, high, target, i);
            
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col_size = matrix.size() - 1;
        int row_size = matrix[0].size() - 1;
        int col_mid = col_size/2;
        
        int col = binary_search_col(matrix, 0, col_mid, col_size, target);
        if(col == -1) return false;
        int row = binary_search_row(matrix, 0, row_size, target, col);
        bool ret = false;
        
        if(row == -1) ret = false;
        else ret = true;

        return ret;
        
    }


     bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size(), low=0, high = m*n-1, mid=0, row=0, col=0;
        
        while(low<=high)
        {
            mid = high - (high - low)/2;
            
            row = mid/n;
            col = mid%n;
            
            if(matrix[row][col] == target)
                return 1;
            
            else if(matrix[row][col] < target)
                low = mid+1;
            
            else
                high = mid-1;
        }
        
        return 0;
    }
};

int main()
{

    Solution ob;
    int n, m, target;
    bool res;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for(auto i=0; i<n; i++)
    {
        for(auto j=0; j<m; j++)
            cin >> matrix[i][j];
    }

    cin >> target;
    res = ob.searchMatrix2(matrix, target);
    cout << res;
    return 0;
}
// -9 -9 -9 -8 -8 -7 -6 -4 -4 -3  
// 0 1 2 2 4 5 5 5 7 9 
// 12 12 14 14 15 17 19 19 19 21  
// 22 23 23 25 25 26 26 28 28 29  
// 31 31 31 33 34 36 37 38 38 39  
// 40 42 43 44 46 46 46 47 49 50  
// 52 54 55 57 59 60 60 62 64 66  
// 68 68 70 71 71 72 74 76 78 80  
// 82 83 85 85 85 87 88 88 89 89  
// 90 90 90 91 93 94 94 95 95 97  
// 98 98 99 99 101 103 105 106 108 109 
// 112 112 112 113 113 113 114 116 118 118 
// 119 121 122 124 125 125 125 126 127 128 
// 131 133 134 134 134 135 135 137 137 139 
// 141 143 145 147 148 150 150 150 150 152 
// 153 153 154 155 157 157 157 159 161 162 
// 164 166 167 167 167 169 170 170 171 173 
// 176 176 178 179 181 182 183 183 184 186  