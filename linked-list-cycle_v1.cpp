//Created: 2023-07-04 by VictorieeMan
/* https://leetcode.com/problems/linked-list-cycle
Runtime 21 ms
Beats
14.10%

Memory 11.2 MB
Beats
7.81%
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
        unordered_map<ListNode*,bool> visited;
        while(head){
            if(visited[head->next]){
                return true;
            }
            visited[head->next] = true;
            head = head->next;
        }
        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}