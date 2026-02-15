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
    void postorder(int& sum, TreeNode* root)
    {
        if(root == NULL)
            return;
        postorder(sum, root -> left);
        postorder(sum, root -> right);
        sum += (root -> val);
    }

    bool checkTree(TreeNode* root) {
        int rootVal = root -> val;
        int sum = 0;
        postorder(sum, root);
        if(rootVal == sum - rootVal)
            return true;
        return false;
    }
};