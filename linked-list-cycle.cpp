//Created: 2023-07-04 by VictorieeMan
/* https://leetcode.com/problems/linked-list-cycle
Runtime 29 ms
Beats
5.31%

Memory 11.1 MB
Beats
7.81%
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
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
        set<ListNode*> visited;
        while(head){
            if(visited.find(head->next) != visited.end()){
                return true;
            }
            visited.insert(head->next);
            head = head->next;
        }
        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}