class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        
        long long last = LLONG_MIN;
        TreeNode* cur = root;
        
        while(!stk.empty() || cur){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }
            
            cur = stk.top(); stk.pop();
            
            if(cur->val <= last) return false;
            last = cur->val;
            
            cur = cur->right;
        }
        
        return true;
    }
};