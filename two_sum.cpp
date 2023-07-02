//Created: 2023-07-02 by VictorieeMan
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    //Custom compare function for thew pair comp int situation.
    static bool pair_comp(const pair<int,int>& p, int value){
        return p.first < value;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> two_sum;
        int length = nums.size();
        //Creatinga vector of pairs, storing numbers with their original indicies
        //To benefit from efficencies of working with sorted values, while keeping track of indicies.
        vector<pair<int, int>> num_pairs;
        for (int i = 0; i < length; ++i){
            num_pairs.push_back(make_pair(nums[i],i));
        }

        //Sorting the vector of pairs
        sort(num_pairs.begin(), num_pairs.end());

        for(int i = 0; i < length; ++i){
            int diff = target - num_pairs[i].first;
            //This diff method makeus sure that we don't have to revisit any value <=i,
            //hence we begin our search at i+1 to not double count any elements.
            auto it = lower_bound(num_pairs.begin()+i+1, num_pairs.end(), diff, pair_comp);
            int diff_idx = distance(num_pairs.begin(), it);

            if(it != num_pairs.end() && it->first == diff){
                two_sum.push_back(num_pairs[i].second);
                two_sum.push_back(num_pairs[diff_idx].second);
                return two_sum;
            }
        }
        //In case of nothing found...
        two_sum.push_back(-1);
        return two_sum;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,4,3,0};
    int target = 0;
    vector<int> two_sum = sol.twoSum(nums, target);
    cout << two_sum[0] << " " << two_sum[1] << endl;
    return 0;
}