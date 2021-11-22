// https://www.geeksforgeeks.org/bottom-view-binary-tree/

/*
    ->just do normal vertical order traversal and store last element in res vector
    
    T.C and S.C= O(n)
*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>res;
        
        if(root==NULL){
            return res;
        }
        
        int hd=0;
        unordered_map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        q.push({root,hd});
        
        int mn=0,mx=0;
        while(!q.empty()){
            
            pair<Node*,int>curr=q.front();
            q.pop();
            
            Node* node=curr.first;
            hd=curr.second;
            
            mp[hd].push_back(node->data);
            
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
          //storing last element of every hd size
            res.push_back(ans[ans.size()-1]);
        }
        return res;
    }
};
