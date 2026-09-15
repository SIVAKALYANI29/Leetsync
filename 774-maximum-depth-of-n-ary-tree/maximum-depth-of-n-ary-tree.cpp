class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;

        int maxHeight = 0;
        for(Node* child : root->children){
            maxHeight = max(maxHeight, maxDepth(child));
        }

        return 1 + maxHeight;
    }
};