//Inorder Traversal
 vector<int> inorderTraversal(TreeNode* root) {
        if(root!=NULL){
           inorderTraversal(root->left);
           cout<<(root->val)<<" ";
           inorderTraversal(root->right);
        }
 }

//Preorder Traversal
 vector<int> inorderTraversal(TreeNode* root) {
        if(root!=NULL){
           cout<<(root->val)<<" ";
           inorderTraversal(root->left);
           inorderTraversal(root->right);
        }
 }

 //Postorder Traversal
 vector<int> inorderTraversal(TreeNode* root) {
        if(root!=NULL){
           inorderTraversal(root->left);
           inorderTraversal(root->right);
           cout<<(root->val)<<" ";
        }
 }
