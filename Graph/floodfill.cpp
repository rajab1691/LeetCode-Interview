/*
  DFS:Idea is to color with new color where the color is same as source color
  T.C-O(n),n=no of pixels
  S.C-O(n),call stack
*/

void dfs(int x,int y,vector<vector<int>>& image,int nc ,int sc){
        int n=image.size();
        int m=image[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        image[x][y]=nc;
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 and nx<n and ny>=0 and ny<m and image[nx][ny]==sc){
                dfs(nx,ny,image,nc,sc);
            }
        }
    }
 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc) {
        
    int n=image.size();
    int m=image[0].size();
        
    if(image[sr][sc]!=nc)
      int sourceColor=image[sr][sc];
      dfs(sr,sc,image,nc,sourceColor);
     }
  return image;   
 }
