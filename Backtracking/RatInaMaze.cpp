// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
/*
  
      
  Time Complexity: O(3^(n^2))=As there are N^2 cells from each cell there are 3 unvisited neighbouring cells. So the time complexity O(3^(N^2).
  Auxiliary Space: O(3^(n^2))=As there can be atmost 3^(n^2) cells in the answer so the space complexity is O(3^(n^2)).
  
*/
vector<string>res;
vector<vector<int>>vis(5, vector<int> (5,0));
class Solution{
    public:
    void path(vector<vector<int>>&m,int i,int j,string r,int n){
        if(i==n-1 and j==n-1){
            res.push_back(r);
            return;
        }
        if(m[i][j]==0 or vis[i][j]==1)return;
        
        //choose
        vis[i][j]=1;
      
        //exploring
        if(i>0)path(m,i-1,j,r+'U',n);
        if(i<n-1)path(m,i+1,j,r+'D',n);
        if(j>0)path(m,i,j-1,r+'L',n);
        if(j<n-1)path(m,i,j+1,r+'R',n);
      
        //backtrack or unchoose
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=0;
            }
        }
        res.clear();
        //if source or dest cell is not visitable then just return 
        if(m[0][0]==0 or m[n-1][n-1]==0)return res;
        
        path(m,0,0,"",n);
        sort(res.begin(),res.end());
        return res;
    }
};
