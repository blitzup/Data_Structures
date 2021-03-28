#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
     static bool compare(string s1, string s2)
    {
        return (s1.size() < s2.size());
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix = ""; 
        int prefix_len = 0;
        
        
        string mini =  *min_element(strs.begin(), strs.end(), compare);
        int low = 0, high = mini.size()-1;
        int flag = 0;
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            string match = mini.substr(0, mid+1);
            flag = 0;
            for(auto const &ele : strs)
            {
                int ans = match.compare(ele.substr(0, mid+1));
                if(ans != 0)
                {
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 1)
                high = mid - 1;
            else{
                prefix = match;
                low = mid + 1;
            } 
            
        }
        
        return prefix;
        
    }
};

int main()
{
    vector<string> svec;
    int n;
    cin >> n;
    cin.ignore();
    string str;
    for(auto i=0; i<n; i++)
    {
        getline(cin, str);
        svec.push_back(str);
    }
    Solution s;
    string prefix = s.longestCommonPrefix(svec);
    cout << prefix; 
        
    return 0;
}