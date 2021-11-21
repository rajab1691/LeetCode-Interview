// https://leetcode.com/problems/number-of-islands/

/*
    -> use dfs on grid
    T.C- O(n*m)
*/
class Solution {
public:
    
    void dfs(int x,int y,vector<vector<char>>& grid){
        
        int n=grid.size();
        int m=grid[0].size();
        
        if(x<0 or x>n-1 or y<0 or y>m-1 or grid[x][y]=='0')
            return;
        
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        
        grid[x][y]='0';
        
        for(int i=0;i<4;i++){
            dfs(x+dx[i],y+dy[i],grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
            
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
