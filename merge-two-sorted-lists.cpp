//Created: 2023- by VictorieeMan
/* https://leetcode.com/problems/merge-two-sorted-lists/
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //Function to append linked list.
    static void addNode(ListNode* head, int x){
        ListNode* newNode = new ListNode(x);
        ListNode* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedHead;
        ListNode* current_1 = list1;
        ListNode* current_2 = list2;
        do{


        //Iterate until we have reached the end of both lists.
        } while (current_1->next != nullptr && current_2->next != nullptr);
        return mergedHead;
    }
};

int main() {
    Solution sol;
    //Test cases
    //Input: l1 = [1,2,4], l2 = [1,3,4]
    //Output: [1,1,2,3,4,4]

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    //Using a function like this, avoids the need to stack and manually keep
    //track of how many levels of ->next are needed before adding a new node.
    ListNode* list2 = new ListNode(1);
    sol.addNode(list2, 2);
    sol.addNode(list2, 3);

    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    //Print out mergedList
    while(mergedList != nullptr){
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    return 0;
}