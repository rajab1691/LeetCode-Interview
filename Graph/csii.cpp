// https://leetcode.com/problems/course-schedule-ii/

/*
      -> same as course schedule i just store elements in vector and if cycle then return empty array
      T.C- O(V+E)
*/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<int>res;      
        vector<int>adj[n];
        vector<int>indeg(n,0);
        
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0];
            int v=pre[i][1];
            
            adj[v].push_back(u);
            indeg[u]++;
        }
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto x:adj[node]){
                indeg[x]--;
                if(indeg[x]==0){
                    q.push(x);
                }
            }
        }
        if(res.size()!=n)return {};
        return res;
    }
};
