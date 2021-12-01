/*
  Two coloring problem(we have to color whole graph with colors)
  ->no odd cycle then it  is bipartite
   T.C-O(v+e)
*/

//DFS
  bool dfs(int src,vector<vector<int>>adj,vector<int>&visit,int color,int parent){

        visit[src]=color;

        for(auto x:adj[src]){
            if(visit[x]==0){
                bool f=dfs(x,adj,visit,3-color,parent);
                if(!f)return false;
            }
            //for odd cycle detection
            else if(x!=parent and color==visit[x]){
                return false;
            }
        }
        return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        //starting color is=1
        int color=1;
        int parent=-1;


        vector<int>visit(n,0);

        for(int i=0;i<n;i++){
            if(visit[i]==0){
                if(dfs(i,graph,visit,color,parent)==false){
                    return false;
                }
            }
        }
        return true;
    }


