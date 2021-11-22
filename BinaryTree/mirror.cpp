// https://leetcode.com/problems/symmetric-tree/
/*
    Using Recursion
    ->just check
        -left child of 1st root(left subtree)=right child of 2nd root(right subtree)
        -right child of 1st root(left subtree)=left child of 2nd root(right subtree)
*/
class Solution {
public:
    
    bool isSymmetricUtil(TreeNode* root1,TreeNode* root2){
        
        if(root1==NULL and root2==NULL){
            return true;
        }
        
        if(root1 and root2 and root1->val==root2->val){
            return isSymmetricUtil(root1->left,root2->right) and isSymmetricUtil(root1->right,root2->left);
        }
        
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        
        return isSymmetricUtil(root,root);
    
    }
};

/*
    Using Iteration
    ->just use two pointer left and right
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *left,*right;
        if(root==NULL){
            return true;
        }
        
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){
            
            left=q.front();
            q.pop();
            
            right=q.front();
            q.pop();
            
            if(left==NULL and right==NULL)
                continue;
            
            if(left==NULL or right==NULL)
                return false;
            
            if(left->val!=right->val)
                return false;
            
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
