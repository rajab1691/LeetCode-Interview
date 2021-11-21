// https://leetcode.com/problems/number-of-provinces/

/*
    Use DFS
    ->make grph using the condition, then
    ->count component using DFS
    
    T.C- O(n^2)
*/
class Solution {
public:
    
    void dfs(int src,vector<int>adj[], vector<bool>&visit){
            
        visit[src]=true;
        
        for(auto x:adj[src]){
            
            if(visit[x]==false){
                dfs(x,adj,visit);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>&mat) {
        
        int n=mat.size();
        
        vector<int>adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }   
            }
        }
        
        vector<bool>visit(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(visit[i]==false){
                dfs(i,adj,visit);
                cnt++;
            }
        }
        return cnt;
    }
};
