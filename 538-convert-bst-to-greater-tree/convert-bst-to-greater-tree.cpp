class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        return fun(sum,root);
    }
    TreeNode* fun(int &sum,TreeNode* root)
    {
        if(root==NULL) return NULL;
        fun(sum,root->right);
        root->val = root->val + sum;
        sum = root->val;
        fun(sum,root->left);
        return root;
    }
};