/*
     ->calculate left height and right height and return maximum b/w them
    T.C and S.C= O(n)
*/

int heightOfBt(Node* root){

    if(root==NULL)
        return 0;

    int lheight=heightOfBt(root->left);
    int rheight=heightOfBt(root->right);

    int resultHeight=1+max(lheight,rheight);
    return resultHeight;
}

