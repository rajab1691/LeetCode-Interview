/*
      DFS
      Time Complexity: O(V+E)
      Space Complexity: O(V)
      v=nodes
*/
bool dfs(int src,vector<int>adj[],vector<bool>&visit,int parent){

        visit[src]=true;

        for(auto x:adj[src]){
            if(!visit[x]){
                dfs(x,adj,visit,src);
            }else if(x!=parent){ //cycle detected
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

/*
      Time Complexity: O(V+E)
      BFS
*/
bool isCycle(int src,bool*visit,vector<int>adj[]){

    vector<int>parent(v,-1);
        
    queue<int>q;
    q.push(src);
    visit[src]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto x:adj[node]){
            if(visit[x]==false){
                visit[x]=true;
                parent[x]=node;
                q.push(x);
            }else if(parent[x]!=node){ //cycle detected
                return true;
            }
        }
    }   
    return false;
}
