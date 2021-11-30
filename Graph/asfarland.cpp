/*
  ->use BFS insert grid with val=1 in queue
  T.C-O(v+e)
*/
   bool isValid(int x,int y,int n){
        if(x<0 or x>n-1 or y<0 or y>n-1)
            return false;
        return true;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
       
        queue<pair<int,int>>q;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        if(q.size()==n*n)
            return -1;
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto node=q.front();
                q.pop();
                int x=node.first;
                int y=node.second;
                cout<<x<<" "<<y<<endl;
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(isValid(nx,ny,n) and grid[nx][ny]==0){
                        q.push({nx,ny});
                        grid[nx][ny]=1;
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }
