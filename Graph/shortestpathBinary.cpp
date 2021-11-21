// https://leetcode.com/problems/shortest-path-in-binary-matrix/

/*
    Use BFS
    ->initially check if index(0,0) and index(n-1,n-1) is zero otherwise return -1
    ->cal shortest path in all 8 direcns
    
    T.C- O(n*n)
*/


class Solution {
public:
    
    bool isValid(int x,int y,int n){
        if(x<0 or x>n-1 or y<0 or y>n-1)
            return false;
        
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0]!=0 or grid[n-1][n-1]!=0)
            return -1;
        
        int dx[8]={1,0,1,0,-1,-1,1,-1};
        int dy[8]={1,1,0,-1,0,-1,-1,1};
        
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        
        while(!q.empty()){
            
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            if(x==n-1 and y==n-1){
                return grid[n-1][n-1];
            }
            
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(isValid(nx,ny,n) and grid[nx][ny]==0){
                    q.push({nx,ny});
                    grid[nx][ny]=grid[x][y]+1;
                }
            }
        }
        return -1;
    }
};

