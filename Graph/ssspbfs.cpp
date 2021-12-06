/*
  ->Undirected/Directed Connected Graph
  ->Unweighted
  ->Just do normal bfs maintaining weight:dist[NewNode]=dist[node]+1;
  T.C-O(v+e)
  S.C-O(v)
*/

//dist[]={0,0,...}-initially,visited[]={f,f,...}
//assume src=0;

void ssspBFS(vector<int>adj[],int dist[],bool visited[],int n){

    //dist of source is zero
    dist[src]=0;

    queue<int>q;

    q.push(src);
    visited[src]=true;

    while(!pq.empty()){

        int node=pq.front();
        pq.pop();

        for(auto x:adj[node]){
            if(visited[x]==false){
                visited[x]=true;
                //add 1 everytime it visit a node levelwise
                dist[x]=dist[node]+1;
                q.push(x);
            }
        }
    }
}
