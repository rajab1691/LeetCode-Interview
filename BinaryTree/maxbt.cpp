/*
  T.C and S.C= O(n)
*/

int maxInBt(Node* root){

    if(root==NULL)
        return INT_MIN;

    return max(root->val,max(maxInBt(root->left),maxInBt(root->right)));
}
