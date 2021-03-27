#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {

        if (s.begin() == s.end())
            return "";

        string mid = "";
        string::iterator it = s.begin();

        while (*it == ' ')
            it++;

        while (it != s.end() && *it != ' ')
        {
            mid.push_back(*it);
            it++;
        }
        string fin = reverseWords(s.substr(it - s.begin())) + " " + mid;

        int i = 0;
        while (i < fin.size() && fin[i] == ' ')
            i++;

        return fin.substr(i);
    }

    string reverseWords_iterative(string s) {
            
            string::iterator it = s.begin();
                vector<string> svec;
                while(it != s.end())
                {
                    while(it != s.end() && *it == ' ')
                        it++;

                    string mid = "";
                    while(it != s.end() && *it != ' ')
                    {
                        mid.push_back(*it);
                        it++;
                    }
                    int flag = 0;
                    svec.push_back(mid);
                    if(it == s.end()) 
                    {
                        flag = 5;
                        break;
                    }


                    it++;
                }

                vector<string>::reverse_iterator vbegin = svec.rbegin();
                string fin = "";
                while(vbegin != svec.rend())
                {
                    fin+=*vbegin + " ";
                    vbegin++;
                }
                
                while(fin.back() == ' ')
                    fin.pop_back();
        
                string::iterator pos = fin.begin(), endpos = fin.end();
                while(*pos == ' ')
                    pos++;
        

                return fin.substr(pos - fin.begin(), endpos-fin.begin());
        }
};

int main()
{
    Solution s;
    string str;
    getline(cin, str);

    string fin = s.reverseWords_iterative(str);
    cout << endl;

    cout << fin;
    return 0;
}