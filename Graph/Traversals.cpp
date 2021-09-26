/*
    BFS traversal (using queue)
    Time complexity : O(V+E) 
    adj=graph,v=vertex,src=starting point 
*/

void bfs(int src){

    vector<bool>visit(v+1,false);
    queue<int>q;
    q.push(src);
    visit[src]=true;

    while(!q.empty()){

        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto x:adj[node]){
            if(visit[x]==false){
                q.push(x);
                visit[x]=true;
            }
        }
    }
}

/*
   DFS Traversal(Using Recursion)
   Time complexity: O(V+E)
   adj=graph,v=vertex,src=starting point 
   vector visit =false initially 
*/
void dfs(int src, vector<bool>visit){

    visit[src]=true;
    cout<<src<<" ";
  
    for(auto x:adj[src]){
        if(visit[x]==false){
            dfs(x,visit);
        }
    }
}
