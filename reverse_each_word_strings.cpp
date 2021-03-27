#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {

        string::iterator it = s.begin(), last = s.end();
        string final_str = " ";

        while (*last == ' ')
            last--;

        string str(s.begin(), last + 1);
        str.push_back(' ');
        string::iterator str_start = str.begin();

        while (str_start != str.end())
        {
            while (*str_start == ' ')
                str_start++;

            size_t ind = str.find(" ", str_start - str.begin());
            string mid(str_start, str.begin() + ind);

            reverse(mid.begin(), mid.end());
            final_str += mid;
            final_str += " ";

            str_start = str.begin() + ind + 1;
        }

        return final_str;
    }
};

int main()
{

    string s2;
    getline(cin, s2);
    Solution s;
    string fin = s.reverseWords(s2);
    cout << fin.substr(1);
    return 0;
}