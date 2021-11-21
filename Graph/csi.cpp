// https://leetcode.com/problems/course-schedule/

/*
      ->just use kahn's algo, if cycle present then false,else true
      T.C- O(V+E)
*/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<int>adj[n];
        vector<int>indeg(n,0);
        
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0];
            int v=pre[i][1];
            
            adj[v].push_back(u);
            indeg[u]++;
        }
        
        int cnt=0;
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }    
        }
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();    
            cnt++;
            for(auto x:adj[node]){
                indeg[x]--;
                if(indeg[x]==0){
                    q.push(x);
                }
            }
        }
        
        if(cnt!=n)return false;
        return true;
        
    }
};
