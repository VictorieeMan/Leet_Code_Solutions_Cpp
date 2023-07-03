//Created: 2023-7-03 by VictorieeMan
/* https://leetcode.com/problems/invert-binary-tree/
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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return nullptr;
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

    //Test case 1
    cout << "Test case 1:" << endl;
    cout << "Expected: 4 7 2 9 6 3 1" << endl;
    cout << "Output: ";
    sol.invertTree(test1);
    cout << endl;

    //Test case 2
    cout << "Test case 2:" << endl;
    cout << "Expected: 2 3 1" << endl;
    cout << "Output: ";
    sol.invertTree(test2);
    cout << endl;
    return 0;
}