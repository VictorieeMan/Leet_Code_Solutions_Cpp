//Created: 2023-07-04 by VictorieeMan
/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock
Runtime 139 ms
Beats
81.29%

Memory 93.3 MB
Beats
72.86%
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
        //Greedy algorithm, doing tests along the iteration taking best found.
        int buy = prices[0];
        int max_profit = 0;
        int days = prices.size();
        for(int i = 1; i < days; ++i){
            int today = prices[i];
            if(buy < today){
                if(int profit = today-buy; profit > max_profit){
                    max_profit = profit;
                }
            } else if(buy > today){
                buy = today;
            }
        }
        return max_profit;
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