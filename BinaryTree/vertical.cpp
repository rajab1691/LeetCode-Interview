// https://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/

/*
    Use LOT and Hashing
    
    T.C and S.C: O(n)
*/

vector<vector<int>>printVertical(Node* root){
        
        vector<vector<int>>res;

        if(root==NULL){
            return res;
        }

        unordered_map<int,vector<int>>mp;
        int hd=0;

        queue<pair<TreeNode*,int>>q;
        q.push({root,hd});

        // mn and mx contain the minimum and
        // maximum horizontal distance from root
        int mn=0,mx=0;

        while(!q.empty()){

            pair<TreeNode*,int>curr=q.front();
            q.pop();

            hd=curr.second;
            TreeNode* node=curr.first;

            mp[hd].push_back(node->val);

            if(node->left){
                q.push({node->left,hd-1});
            }
            if(node->right){
                q.push({node->right,hd+1});
            }

            mn=min(mn,hd);
            mx=max(mx,hd);

        }

        for(int i=mn;i<=mx;i++){
          vector<int>ans=mp[i];
          res.push_back(ans);
        }
       return res;
}
