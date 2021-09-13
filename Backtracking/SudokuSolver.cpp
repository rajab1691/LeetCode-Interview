// https://leetcode.com/problems/sudoku-solver/submissions/
/*
    Time Complexity — O(9^(n*n))=For every unassigned index there are 9 possible options 
*/

class Solution {
public:
  
    bool isValid(vector<vector<char>>& board,int i,int j,char c){
        
        //checking if row and col already has given num return false
        for(int x=0;x<9;x++){
            if(board[x][j]==c or board[i][x]==c){
                return false;
            }
        }
        
        //for subgrid =to calculate starting index of and i,j
        int sx=(i/3)*3;
        int sy=(j/3)*3;
        
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(board[sx+x][sy+y]==c)
                    return false;
            }
        }
        return true;
    }
    bool helper(int i,int j,vector<vector<char>>& board){
        //if we completed all the row
        if(i==9){
            return true;
        }
        //if we completed all the column then start from next row and 0th column
        if(j==9){
            return helper(i+1,0,board);
        }
        //if already there's number then just check for next column
        if(board[i][j]!='.'){
            return helper(i,j+1,board);
        }
        //if we can fill, check from num=1 to num=9 every num
        for(char c='1';c<='9';c++){
            if(isValid(board,i,j,c)){
                board[i][j]=c;
                bool f=helper(i,j+1,board);
                if(f){
                    return true;
                }
                //backtracking
                board[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(0,0,board);
    }
};
