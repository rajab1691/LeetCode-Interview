/*
    ->just count the nodes in tree
    T.C and S.C= O(n)
*/
int countNodes(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        int leftSubtree=countNodes(root->left);
        int rightSubtree=countNodes(root->right);

        return 1+leftSubtree+rightSubtree;
}

/*
    ->if tree is full binary tree then calculate height of the tree and count=pow(2,height)-1
*/

/*
    ->if tree is complete bt then calculate left height and right height 
    ->whenever both are equal then it will be like full bt so cal count=pow(2,height)-1
    
    T.C- O(log(n)^2)
*/

class Solution {
public:
    
    int lheight(TreeNode* root){
        
        if(root==NULL){
            return 0;
        }
        return lheight(root->left)+1;   
    }
    int rheight(TreeNode* root){
        
        if(root==NULL){
            return 0;
        }
        return rheight(root->right)+1;
        
    }
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int lh=lheight(root);
        int rh=rheight(root);
        
        if(lh==rh){
            return pow(2,lh)-1;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};
