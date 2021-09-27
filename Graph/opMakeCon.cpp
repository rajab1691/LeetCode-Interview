/*
  ->Approach:-just count the connected component and return count-1
  Time: O(n+m), m is the length of connections
  Space: O(n)     
  
*/

class Solution {
public:
    
    void dfs(int src,vector<bool>&visit, vector<int>adj[]){
        visit[src]=true;
        
        for(auto x:adj[src]){
            if(visit[x]==false){
                dfs(x,visit,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>&con) {
        int m=con.size();
        // We need at least n - 1 cables to connect all nodes (like a tree).
        if(n-1>m){
            return -1;
        }
        //Creating an adjacency list
        vector<int>adj[n];
        for(int i=0;i<m;i++){
            int u=con[i][0];
            int v=con[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int cnt=0;
        vector<bool>visit(n,false);
        for(int i=0;i<n;i++){
            if(!visit[i]){
                cnt++;
                dfs(i,visit,adj);
            }
        }
        return cnt-1;
    }
};
