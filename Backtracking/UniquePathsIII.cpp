/*
  why do you think we need to do backtracking, recursion here?
      ->we need to count all paths from src to dest by visiting evry single block where there is no obstacle.
     
  **here if we have to check for min/max ..path/res etc then we have to use DP.

*/

class Solution {
public:
    //empty=1 because our src cell will also becomes negative and counted as empty that's why
    int res=0,sx,sy,empty=1;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }else if(grid[i][j]==0){
                    empty++;
                }
            }
        }
        dfs(grid,sx,sy);
        return res;
    }
    void dfs(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        //invalid cell
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]<0)return;
      
        //given that destination have value 2 in cell
        if(grid[i][j]==2){
            if(empty==0){
                res++;
            }
            return;
        }
        //choose
        grid[i][j]=-2;
        empty--;
        
        //explore
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            dfs(grid,nx,ny);
        }
        //backtracking 
        grid[i][j]=0;
        empty++;
    }
};
