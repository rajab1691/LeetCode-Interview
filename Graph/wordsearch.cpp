/*
    T.C-O(n^2)
    just dfs
*/
bool dfs(vector<string> &board, string word,int x,int y,int idx){
        int n=board.size();
        int m=board[0].size();
        
        // end condition
        if(idx==word.size())return true;
        if(x<0 or x>=n or y<0 or y>=m)return false;
        if(word[idx]!=board[x][y])return false;
          
        
        //if same letter cell may be used more than once,then comment below line
        board[x][y]='*';//change the content, to avoid duplicated search
        
        bool search=(dfs(board,word,x+1,y,idx+1) or dfs(board,word,x-1,y,idx+1) or dfs(board,word,x,y+1,idx+1) or dfs(board,word,x,y-1,idx+1));
        //modify it back!
        board[x][y]=word[idx];
        return search;
        
    }
int exist(vector<string> &grid, string s) {

    int n=grid.size();
    int m=grid[0].size();
    int idx=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool f=dfs(grid,s,i,j,idx);
            if(f)return true;
        }
    }
    return false;
}
