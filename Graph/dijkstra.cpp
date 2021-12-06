/*
  ->Weighted Graph (No negative weight)
  ->SSSP
  ->Greedy
  T.C-O(v+elogv)
*/
#define INF LLONG_MAX

void dijkstra(int src,vector<pair<int,int>>adj[],vector<int>&dist){


    //mark all as infinity initially 
    dist.assign(INF);
    //mark src=0
    dist[src]=0;

    //take min heap,it helps us in popping out minimum weight
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    //push source
    pq.push({0,src});

    while(!pq.empty()){

        auto best=pq.top();
        pq.pop();

        int node=best.second;
        int weight=best.first;

        //if curr weight is greater than node's weight then no need to go down
        if(weight>dist[node]){
            continue;
        }

        for(auto x:adj[node]){
            int dest=x.first;
            int weight=x.second;

            //if distance greater then update it
            if(dist[dest]>dist[node]+weight){
                dist[dest]=dist[node]+weight;
                pq.push({dist[dest],dest});
            }
        }
    }
}
