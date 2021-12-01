/*
  Graph is a tree:
    ->No cycle
    ->Undirected
    ->Connected Graph
*/

bool isTree(vector<int>adj[],int n){

    vector<bool>visit(n,false);

    int parent=-1;
    //cycle detection
    if(isCycle(0,adj,parent,visit))
        return false;

    //check for connected components
    for(int i=0;i<n;i++){
        if(visit[i]==false)
            return false;
    }
    return true;
}
