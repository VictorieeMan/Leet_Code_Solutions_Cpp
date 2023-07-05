//Created: 2023-07-04 by VictorieeMan
/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<pair<int,int>> price_days;
        int days = prices.size();
        for(int i = 0; i < days; ++i){
            price_days.push_back(make_pair(prices[i],i));
        }

        sort(price_days.begin(),price_days.end());
        vector<int> diffs(1,0);

        int iterations = 0;
        for(int i = 0; i < days; ++i){
            for(int j = days-1; j > i; --j){
                if(price_days[i].second < price_days[j].second){
                    int diff = price_days[j].first - price_days[i].first;
                    cout << diff << " ";
                    if(diff <= 0){
                        break;
                    }
                    diffs.push_back(diff);
                }
                ++iterations;
            }
        }

        auto it = max_element(diffs.begin(),diffs.end());

        cout << ", " << iterations << endl;
        return *it;
    }
};

int main() {
    Solution sol;
    //Test case
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices) << endl;

    prices = {7,6,4,3,1};
    cout << sol.maxProfit(prices) << endl;

    prices = {2,4,1};
    cout << sol.maxProfit(prices) << endl;

    prices = {4,7,1,2};
    cout << sol.maxProfit(prices) << endl;

    prices = {7,11,1,4,2};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}