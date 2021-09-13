/*
  **A queen travels in straight line (vertically,horizontally,diagonally)**
  Algo Steps:
      i)for evry row check can we put a queen here?
            ->if yes then put the queen and recursively call for the next row
            ->else return false and backtrack;
*/
/*Using backtracking
  The worst-case time complexity is O(N!)
*/
class Solution {
public:
    vector<vector<string>>res;
    vector<vector<string>>solveNQueens(int n) {
        
        vector<string>board(n,string(n,'.'));
        helper(0,board);
        return res;
    }
    
    void helper(int row,vector<string>&board){
        
        if(row==board.size()){
            res.push_back(board);
            return;
        }
        
        for(int j=0;j<board.size();j++){
            if(isValid(row,j,board)){
                board[row][j]='Q';
                helper(row+1,board);
                board[row][j]='.';
            }
        }
    }
    bool isValid(int row,int col,vector<string>&board){
        int n=board.size();
        //check column
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q')
                return false;
        }
        //check left diagonal
        for(int i=row,j=col;i>=0 and j>=0;i--,j--){
            if(board[i][j]=='Q')
                return false;
        }
        for(int i=row,j=col;i>=0 and j<n ;i--,j++){
            if(board[i][j]=='Q')
                return false;   
        }
        return true;
    }
};
