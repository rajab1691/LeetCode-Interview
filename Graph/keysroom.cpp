/*
  ->do normal dfs
*/

void dfs(int src,vector<vector<int>>& rooms,vector<int>&visit){
        visit[src]=0;
        
        for(auto x:rooms[src]){
            if(visit[x]==-1){
                dfs(x,rooms,visit);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
            
        vector<int>visit(n,-1);
        visit[0]=0;
        
        for(auto x:rooms[0])
            dfs(x,rooms,visit);
        
        for(int i=0;i<n;i++){
            if(visit[i]==-1)
                return false;
        }
        return true;
    }
