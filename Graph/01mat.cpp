// https://leetcode.com/problems/01-matrix/

/*
  -> process all 0's and mark their distance as 0
  Time: O(M * N), where M is number of rows, N is number of columns in the matrix.
  Space: O(M * N), space for the queue.

*/

class Solution {
public:
    
    bool isValid(int x,int y,int n,int m){
        
        if(x<0 or x>n-1 or y<0 or y>m-1)
            return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        vector<vector<int>>dis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;   
                }
            }   
        }
        while(!q.empty()){
            
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(isValid(nx,ny,n,m) and dis[nx][ny]==-1){
                    dis[nx][ny]=dis[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return dis;
    }
};
