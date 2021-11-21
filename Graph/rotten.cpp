// https://leetcode.com/problems/rotting-oranges/

/*
    ->push rotten orange in queue initially and count fresh orange
    ->do bfs
    Time Complexity - O(mn),
    Space Complexity - O(mn) 
*/

class Solution {
public:
    
    bool isValid(int x,int y,int n,int m){
        if(x<0 or x>n-1 or y<0 or y>m-1)
            return false;
        
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
            
        int minutes=0;
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        queue<pair<int,int>>q;
        int fresh=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        while(!q.empty()){
            
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(isValid(nx,ny,n,m) and grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        fresh--;
                    }
                }
            }
             minutes++;
        }
        if(fresh>0){
            return -1;
        }
        if(minutes<=0)
            return 0;
        
        return  minutes-1;
    }
};
