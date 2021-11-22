/*
    Time complexity= O(n)
*/

bool isFullTree (Node* root)
{
    if(root==NULL)
        return false;
        
    if((root->left==NULL) and (root->right)==NULL){
        return true;
    }
    if((root->left) and (root->right)){
        return (isFullTree(root->left) and isFullTree(root->right));
    }
    return false;
}
