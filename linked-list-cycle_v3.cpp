//Created: 2023-07-04 by VictorieeMan
/* https://leetcode.com/problems/linked-list-cycle

Run 1:
Runtime 7 ms
Beats
96.63%

Memory 8 MB
Beats
69.94%

Run 2:
Runtime 9 ms
Beats
78.46%

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

        while(fast && fast->next){
            if(slow == fast){
                return true;
            }
            //Slow walks at one step per iteration.
            slow = slow->next;

            //Fast walks at two steps per iteration.
            fast = fast->next->next;
            
        }
        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}