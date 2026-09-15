class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }

private:
    TreeNode* merge(TreeNode* r1, TreeNode* r2) {
        if (r1 == nullptr)
            return r2;

        if (r2 == nullptr)
            return r1;

        r1->val += r2->val;

        r1->left = merge(r1->left, r2->left);
        r1->right = merge(r1->right, r2->right);

        return r1;
    }
};