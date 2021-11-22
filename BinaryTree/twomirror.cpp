// https://www.geeksforgeeks.org/check-if-two-trees-are-mirror/

/*
     Using Recursion
        ->just check
            -left child of 1st root(left subtree)=right child of 2nd root(right subtree)
            -right child of 1st root(left subtree)=left child of 2nd root(right subtree)
*/

class Solution {
public:
    
    bool isMirror(TreeNode* root1,TreeNode* root2){
        
        if(root1==NULL and root2==NULL){
            return true;
        }
        if(root1==NULL or root2==NULL){
            return false;
        }
        return ((root1->val==root2->val) and isMirror(root1->left,root2->right) 
                and isMirror(root1->right,root2->left));
    }
    
};
