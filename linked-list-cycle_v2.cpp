//Created: 2023-07-04 by VictorieeMan
/* https://leetcode.com/problems/linked-list-cycle
Runtime 15 ms
Beats
35.72%

Memory 7.9 MB
Beats
95.94%
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //Floyd's Tortoise and Hare Algorithm
        if(!head || !head->next){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast){
            if(slow == fast){
                return true;
            }
            //Slow walks at one step per iteration.
            slow = slow->next;

            //Fast walks at two steps per iteration.
            if(fast->next){
                fast = fast->next;
            } else{
                break;
            }
            if(fast->next){
                fast = fast->next;
            } else{
                break;
            }
            
        }
        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}