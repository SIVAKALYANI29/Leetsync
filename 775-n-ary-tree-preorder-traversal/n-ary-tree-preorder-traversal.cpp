class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

private:
    void helper(Node* root, vector<int>& ans) {
        if (root == nullptr)
            return;

        ans.push_back(root->val);

        for (Node* child : root->children) {
            helper(child, ans);
        }
    }
};