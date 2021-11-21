// https://leetcode.com/problems/surrounded-regions/

/*
      Use BFS
      -> Traverse all borders of the grid and if you find an 'O', then mark all the connected 'O's with any other temporary character
      -> Now convert all temporary char to O's and O's to X's
*/
class Solution {
public:
    
    bool isValid(int x,int y,int n,int m){
        if(x<0 or x>n-1 or y<0 or y>m-1)
            return false;
        return true;
    }
    bool isBorder(int i,int j,int n,int m){
        
        if(i==0 or j==0 or i==n-1 or j==m-1)
            return true;
        
        return false;
    }
    void solve(vector<vector<char>>& board) {
        
        if(board.size()==0)
            return;
        
        int n=board.size();
        int m=board[0].size();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' and isBorder(i,j,n,m)){
                    board[i][j]='.';
                    q.push({i,j});
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
                if(isValid(nx,ny,n,m) and board[nx][ny]=='O'){
                    board[nx][ny]='.';
                    q.push({nx,ny});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(board[i][j]=='.'){
                    board[i][j]='O';
                }else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
        }
    }
};


