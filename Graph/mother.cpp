/*
  ->Apply Normal dfs 
  if found any mother check for that again
  T.C-O(V+E)
*/
void dfs(int src,vector<bool>&visit vi adj[]){

    visit[src]=true;
    for(auto x:adj[src]){
        if(visit[x]==false){
            dfs(x,visit,adj);
        }
    }
}
int motherVertex(vector<int>adj[],int n){

    vector<bool>visit(n,false);

    int mother=0;

    for(int i=0;i<n;i++){
        if(visit[i]==false){
            dfs(i,visit,adj);
            mother=i;
        }
    }

    fill(visit.begin(),visit.end(),false);

    dfs(mother,visit,adj);

    for(int i=0;i<n;i++){
        if(visit[i]==false)
            return -1;
    }
    return mother;
}
