// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
/*
      Rat is at (0,0) he has to go to (n-1,n-1) and 0-wall, 1-blank
*/
//Time Complexity: O(3^(n^2))=As there are N^2 cells from each cell there are 3 unvisited neighbouring cells. So the time complexity O(3^(N^2).

class Solution{
    public:
    void path(vector<vector<int>>&m,int i,int j,string r,int n,vector<string>&res){
        if(i==n-1 and j==n-1){
            res.push_back(r);
            return;
        }
        if(m[i][j]==0)return;
        
        //choose
        m[i][j]=0;
      
        //exploring
        if(i>0)path(m,i-1,j,r+'U',n,res);
        if(i<n-1)path(m,i+1,j,r+'D',n,res);
        if(j>0)path(m,i,j-1,r+'L',n,res);
        if(j<n-1)path(m,i,j+1,r+'R',n,res);
      
        //backtrack or unchoose
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
       
        vector<string>res;
        //if source or dest cell is not visitable then just return 
        if(m[0][0]==0 or m[n-1][n-1]==0)return res;
        
        path(m,0,0,"",n,res);
        sort(res.begin(),res.end());
        return res;
    }
};
