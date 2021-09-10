//Follow the backtracking template given in Letter Combinations problem

class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combine(int n, int k) {
          
        vector<int>ans;
        helper(n,k,1,ans);
        return res;
    }
    void helper(int n,int k,int idx,vector<int>ans){
        
        if(ans.size()==k){
            res.push_back(ans);
            return;
        }
        
        for(int i=idx;i<=n;i++){
            ans.push_back(i);
            helper(n,k,i+1,ans);
            ans.pop_back();
        }
    }
};
