/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void postorder(int& sum, TreeNode* root, int l, int h)
    {
        if(root == NULL)
            return;
        postorder(sum, root -> left, l, h);
        postorder(sum, root -> right, l, h);
        if(root->val <= h && root->val >= l)
            sum += root->val;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        postorder(sum, root, low, high);
        return sum;
    }
};