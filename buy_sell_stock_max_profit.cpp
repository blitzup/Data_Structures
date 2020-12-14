#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        if (prices.size() <= 1)
            return 0;
        int buy = prices[0], diff = 0, flag = 0;

        for (int cost : prices)
        {
            if (cost < buy)
                buy = cost;
            else if ((cost >= buy) && (cost - buy > diff))
                diff = cost - buy, flag = 1;
        }

        if (flag == 0)
            return 0;
        return diff;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> prices(n);
        for(auto i=0; i<n; i++) cin >> prices[i];

        Solution ob;
        int max_profit = ob.maxProfit(prices);
        cout << max_profit << endl;
    }
}
