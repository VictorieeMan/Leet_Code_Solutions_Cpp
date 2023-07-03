//Created: 2023- by VictorieeMan
/* https://leetcode.com/problems/merge-two-sorted-lists/
Runtime 8 ms
Beats
71.47%

Memory 14.9 MB
Beats
10.89%
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

    static bool check_if_list_have_items(ListNode* list){
        if(list == nullptr){
            return false;
        } else{
            return true;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedList;
        
        //Lists l1 and l2 are assumed empty on declaration.
        bool l1_have_items = 0;
        bool l2_have_items = 0;
        //Checks if lists have items, are non empty
        if(list1 != nullptr){
            l1_have_items = 1;
        }
        if(list2 != nullptr){
            l2_have_items = 1;
        }
        if(!l1_have_items && !l2_have_items){
            //If both lists are empty
            return nullptr;
        }
        if(l1_have_items && !l2_have_items){
            //If list two is empty
            return list1;
        } else if(!l1_have_items && l2_have_items){
            //If list one is empty
            return list2;
        }

        //Otherwise start merging the lists
        int val1 = list1->val;
        int val2 = list2->val;
        if(val1 < val2){
                mergedList = new ListNode(val1);
                list1 = list1->next;
                l1_have_items = check_if_list_have_items(list1);
            } else{
                mergedList = new ListNode(val2);
                list2 = list2->next;
                l2_have_items = check_if_list_have_items(list2);
            }

        //Loop over the rest.
        do{
            if(l1_have_items && l2_have_items){
                //If both lists have items
                val1 = list1->val;
                val2 = list2->val;
                if(val1 < val2){
                    addNode(mergedList,val1);
                    list1 = list1->next;
                } else{
                    addNode(mergedList,val2);
                    list2 = list2->next;
                }
            } else if(l1_have_items && !l2_have_items){
                //If list2 is empty
                val1 = list1->val;
                addNode(mergedList,val1);
                list1 = list1->next;
            } else if(!l1_have_items && l2_have_items){
                //If list1 is empty
                val2 = list2->val;
                addNode(mergedList,val2);
                list2 = list2->next;
            }
            l1_have_items = check_if_list_have_items(list1);
            l2_have_items = check_if_list_have_items(list2);
        //Iterate until we have reached the end of both lists.
        } while (l1_have_items || l2_have_items);
        return mergedList;
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