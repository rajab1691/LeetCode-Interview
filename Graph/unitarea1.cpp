/*
    use dfs,apply dfs from 1
    and while returning make it 0
    
    T.C and S.C-O(n*m)
*/

void dfs(int x,int y,vector<vector<int>>&grid,int &cnt){
        int n=grid.size();
        int m=grid[0].size();
        int dx[8]={1,0,1,0,-1,-1,1,-1};
        int dy[8]={1,1,0,-1,0,-1,-1,1};
        
        if(x<0 or x>n-1 or y<0 or y>m-1)return;
        if(grid[x][y]==0)return;
        
        grid[x][y]=0;
        cnt++;
        
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
                
            dfs(nx,ny,grid,cnt);
        }
        
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int cnt=0;
                    dfs(i,j,grid,cnt);
                    maxi=max(cnt,maxi);
                }
            }
        }
        return maxi;
    }
