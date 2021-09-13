/*
    Time Complexity : O(N!), we have N choices in the first row, N-1 in the second row, N-2 in the next and so on... which brings overall time complexity to O(N!)
    Space Complexity : O(N*N). Required for board and recursive stack.
*/
class Solution {
public:
    
    int totalNQueens(int n) {
      
         vector<string>board(n,string(n,'.'));
         return helper(0,board);
      
    }
    int helper(int row,vector<string>&board){
        
        if(row==board.size()){
            return 1;
        }
        int cnt=0;
        for(int j=0;j<board.size();j++){
            if(isValid(row,j,board)){
                board[row][j]='Q';
                cnt+=helper(row+1,board);
                board[row][j]='.';
            }
        }
        return cnt;
    }
    bool isValid(int row,int col,vector<string>&board){
        int n=board.size();
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q')
                return false;
        }
        for(int i=row,j=col;i>=0 and j>=0;i--,j--){
             if(board[i][j]=='Q')
                return false;
        }
        for(int i=row,j=col;i>=0 and j<n;i--,j++){
             if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    
};
