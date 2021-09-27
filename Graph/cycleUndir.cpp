/*
      Time Complexity: O(V+E)
      Space Complexity: O(V)
*/
bool dfs(int src,vector<int>adj[],vector<bool>&visit,int parent){

        visit[src]=true;

        for(auto x:adj[src]){
            if(!visit[x]){
                dfs(x,adj,visit,src);
            }else if(x!=parent){
                return true;
            }
        }
        return false;
}
bool isCycle(vector<int>adj[]){

    int parent=-1;
    int src;cin>>src;
    vector<bool>visit(v+1,false);

    return dfs(src,adj,visit,parent);
}
