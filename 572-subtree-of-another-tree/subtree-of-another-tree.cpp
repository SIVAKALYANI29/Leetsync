class Solution {
public:
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        queue<pair<TreeNode*,TreeNode*>>pairs;
        pairs.push({root,subRoot});
        while(!pairs.empty()){
            auto [L,R] = pairs.front();
            pairs.pop();
            if(!L && !R) continue;
            if(!L || !R) return false;
            if(L->val != R->val) return false;
            pairs.push({L->left,R->left});
            pairs.push({L->right, R->right});
        }
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot) return false;
        TreeNode* currSubRoot = subRoot;
        queue<TreeNode*>nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* curr = nodes.front();
            if(curr->val == currSubRoot->val){
               if (isSameTree(curr, currSubRoot)) return true;
            } 
            nodes.pop();
            if(curr->left) nodes.push(curr->left);
            if(curr->right) nodes.push(curr->right);
        }
        return false;
    }
};