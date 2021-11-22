// https://www.geeksforgeeks.org/print-leaf-nodes-left-right-binary-tree/

/*
    Time Complexity: O(n) , where n is the number of nodes in the binary tree. 
*/

void printLeaves(Node* root){

    if(root==NULL){
        return;
    }

    if(!root->left and !root->right){
        cout<<root->data<<" ";
        return;
    }

    if(root->left)
        printLeaves(root->left);

    if(root->right)
        printLeaves(root->right);

}
