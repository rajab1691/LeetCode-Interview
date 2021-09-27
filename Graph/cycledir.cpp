/*
      DFS
      if backedge present, then cycle present
*/
bool isCycle(int src,bool* visited,bool* stack){

    visited[src]=true;
    recStack[src]=true;
    for(auto x:adj[src]){
        if(recStack[x]==true){
            return true;
        }
        if(visited[x]==false){
            bool f=isCycle(x,visited,stack);
            if(f)return f;
        }
    }
    recStack[src]=false;
    return false;
}

/*
    BFS (using kahn's algo)
    kahn's algo=store indegree(=0) in a vector
*/

bool isCycle(vector<int>adj[]){

    vector<int>indegree(v,0);

    for(int i=0;i<v;i++){
        for(auto x:adj[i]){
            indegree[x]++;
        }
    }

    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        for(auto x:adj[node]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }

    return (cnt!=v);
}
