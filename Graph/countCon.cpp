/*
    Use DFS to count the connected component
    Time complexity =O(V+E)
    
*/

 void dfs(int src, vector<bool>&visit) {
        visit[src] = true;
        for (auto x : adj[src]) {
            if (visit[x] == false) {
                dfs(x, visit);
            }
        }
}
