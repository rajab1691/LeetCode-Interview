/*
  Weighted Undirected Graph
  
  T.C-O((V+E)logV) because each vertex is inserted in the priority queue only once and insertion in priority queue take logarithmic time.
*/

//n=no of vertex,pair-->dest,weight(in adj),pair-->weight,dest(in pq)
int prims(vector<pair<int,int>>adj[],int n,int src){

    //to find out which active edge has minimum weight
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    //it tells whether node is included in MST or not
    vector<bool>visited(n,false);
    
    //initially push weight=0,and src
    pq.push({0,src});

    while(!pq.empty()){

        //pick the minimum wdge weight
        auto best=pq.top();
        pq.pop();

        int node=best.second;
        int weight=best.first;

        //already visited,then discard that edge
        if(visited[node])
            continue;

        //otherwise take that current edge
        cost+=weight;
        visited[node]=true;

        //add new edge in queue
        for(auto x:adj[node]){
            if(visited[x]==false){
                q.push({x.second,x.first});
            }
        }
    }
    return cost;
}
