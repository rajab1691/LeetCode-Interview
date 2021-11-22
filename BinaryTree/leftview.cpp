// 

/*
      Use LOT
      T.C-O(n)
*/

void leftView(Node* root){

    if(root==NULL){
        return;
    }

    queue<Node*>q;
    q.push(root);
   
    while(!q.empty()){

        int size=q.size();
        int count=size;
        while(size--){

            Node* curr=q.front();
            q.pop();

            if(count-1==size){
                cout<<curr->data<<" ";
            }

            if(curr->left){
                q.push(curr->left);
            }

            if(curr->right){
                q.push(curr->right);
            }

        }
    }
}
