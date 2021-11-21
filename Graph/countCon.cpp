/*
    Use DFS to count the connected component
    Time complexity =O(V+E)
    
*/

 void dfs(int src, vector<bool>&visit,vector<int>adj[]) {
        visit[src] = true;
        for (auto x : adj[src]) {
            if (visit[x] == false) {
                dfs(x, visit);
            }
        }
}

int countComp(vector<int>adj[],int v){

    int count=0;
    vector<bool>visit(v,false);

    for(int i=0;i<v;i++){   

        if(visit[i]==false){
            dfs(i,visit,adj);
            count++;
        }
    }
    return count;
}
