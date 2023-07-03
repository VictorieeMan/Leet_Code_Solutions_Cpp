//Created: 2023-07-03 by VictorieeMan
/* https://leetcode.com/problems/merge-two-sorted-lists/
Followup version, attempting to speed things up by working with list properties.
*First of all a linked list head can be used directly as a boolean,
since the nullptr == false
*Secondly using pointer magic lists can get linked directly,
removing the need to reiterate through the list on each add.

Runtime 4 ms
Beats
93.66%

Memory 14.7 MB
Beats
58.19%
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
    //Function to append linked list, good for creating custom test input.
    static void addNode(ListNode* head, int x){
        ListNode* newNode = new ListNode(x);
        ListNode* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode mergedList(0);
        ListNode* tail = &mergedList;

        //Iterates as long we aren't at the end of any list.
        while(list1 && list2){
            //Compares to add the smallest value
            if(list1->val < list2->val){
                //Copies adresses instead of values; pointer magic
                tail->next = list1;
                //Increments list to it's next adress / link
                list1 = list1->next;
            } else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; //Moves tail to next link.
        }

        //If we are left with one empty list,
        //we'll just add it's head from where we are like a chain on our tail.
        if(list1){
            tail->next = list1;
        } else{
            tail->next = list2;
        }

        //Skipping the initialized 0,
        //we return the merged list from the head of what has been merged.
        return mergedList.next;
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
    sol.addNode(list2, 3);
    sol.addNode(list2, 4);

    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    //Print out mergedList
    while(mergedList != nullptr){
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    return 0;
}