// https://www.geeksforgeeks.org/find-whether-path-two-cells-matrix/
/*
    Given N X N matrix filled with 1, 0, 2, 3. Find whether there is a path possible from source to destination, traversing through blank cells only. You can traverse up, down, right, and left. 

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
*/
/*
    ->apply bfs
    T.C and S.C-O(n*m)
*/

 bool isValid(int x,int y,int n,int m){
        
        if(x<0 or x>n-1 or y<0 or y>m-1)
            return false;
            
        return true;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
       queue<pair<int,int>>q;
       int sx,sy,dx,dy;
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++){
               if(grid[i][j]==1){
                   sx=i;
                   sy=j;
                q.push({sx,sy});
                grid[sx][sy]=0;
               }else if(grid[i][j]==2){
                   dx=i;
                   dy=j;
               }
           }
       }
       int changeX[]={-1,1,0,0};
       int changeY[]={0,0,-1,1};
       
        while(!q.empty()){
            
            auto node=q.front();
            q.pop();
            int x=node.first;
            int y=node.second;
            
            if(x==dx and y==dy){
                return true;
            }
            for(int i=0;i<4;i++){
                int nx=x+changeX[i];
                int ny=y+changeY[i];
                if(isValid(nx,ny,n,m) and grid[nx][ny]!=0){
                    q.push({nx,ny});
                    grid[nx][ny]=0;
                }
            }
        }
       return false;
    }
