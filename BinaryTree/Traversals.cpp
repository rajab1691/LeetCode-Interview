//Inorder Traversal
 vector<int> inorderTraversal(TreeNode* root) {
        if(root!=NULL){
           inorderTraversal(root->left);
           cout<<(root->val)<<" ";
           inorderTraversal(root->right);
        }
 }

//Preorder Traversal
 vector<int> preorderTraversal(TreeNode* root) {
        if(root!=NULL){
           cout<<(root->val)<<" ";
           preorderTraversal(root->left);
           preorderTraversal(root->right);
        }
 }

 //Postorder Traversal
 vector<int> postorderTraversal(TreeNode* root) {
        if(root!=NULL){
           postorderTraversal(root->left);
           postorderTraversal(root->right);
           cout<<(root->val)<<" ";
        }
 }
