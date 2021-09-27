/*
    DFS
    ->just do dfs store elements and reverse it at the end
*/
void dfs(int src,vector<int>adj[],vector<bool>&visit,list<int>&order){

    visit[src]=true;
    for(auto x:adj[src]){
        if(visit[x]==false){
            dfs(x,adj,visit,order);
        }
    }   
    order.push_front(src);
}
void topo(vector<int>adj[]){

    vector<bool>visit(v,false);
    list<int>order;

    for(int i=0;i<v;i++){
        if(visit[i]==false){
            dfs(i,adj,visit,order);

        }
    }
    for(auto x:order){
        cout<<x<<" ";
    }
}

/*
    BFS
    ->use Kahn's algo 
*/
void topo(vector<int>adj[]){

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
    while(!q.empty()){

        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto x:adj[node]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
}

