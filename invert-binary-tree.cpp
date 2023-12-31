//Created: 2023-7-03 by VictorieeMan
/* https://leetcode.com/problems/invert-binary-tree/
Runtime 0 ms
Beats
100%

Memory 10.2 MB
Beats
15.52%
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// For debugging :)
// void printTree(TreeNode* root){
//     if(!root){
//         //If empty tree
//         return;
//     }
//     cout << root->val << " ";
//     printTree(root->left);
//     printTree(root->right);
// }

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //Recursive function
        if(!root){
            //If empty tree
            return nullptr;
        }
        TreeNode* invTree = new TreeNode(root->val);
        if (!root->left && !root->right){
            //If leaf node
            return root;
        } else if (!root->left){
            //If only with right child
            invTree->left = invertTree(root->right);
            return invTree;
        } else if (!root->right){
            //If only with left child
            invTree->right = invertTree(root->left);
            return invTree;
        } else{
            //If with two children left & right
            invTree->left = invertTree(root->right);
            invTree->right = invertTree(root->left);
            return invTree;
        }
    }
};

int main() {
    Solution sol;
    //Test cases
    TreeNode* test1 = new TreeNode(4);
    test1->left = new TreeNode(2);
    test1->right = new TreeNode(7);
    test1->left->left = new TreeNode(1);
    test1->left->right = new TreeNode(3);
    test1->right->left = new TreeNode(6);
    test1->right->right = new TreeNode(9);

    TreeNode* test2 = new TreeNode(2);
    test2->left = new TreeNode(1);
    test2->right = new TreeNode(3);

    //For the testing to work a function is needed to print the tree in order.
    //root, left, right, l_l, l_r, r_l, r_r...
    // //Test case 1
    // cout << "Test case 1:" << endl;
    // cout << "Expected: 4 7 2 9 6 3 1" << endl;
    // cout << "Output: ";
    // inorderTraversal(sol.invertTree(test1));
    // cout << endl;

    // //Test case 2
    // cout << "Test case 2:" << endl;
    // cout << "Expected: 2 3 1" << endl;
    // cout << "Output: ";
    // // printTree(sol.invertTree(test2));
    // cout << endl;
    return 0;
}