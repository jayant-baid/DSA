class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    vis[i][j]=2;
                    q.push({{i, j}, 0});
                }
         
            }
        }
        
        int time=0;
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, 1, 0, -1};
        
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            
            time=max(time, t);
            
            for(int i=0;i<4;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                
                if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol] ==1){
                    vis[nrow][ncol]=2;
                    q.push({{nrow, ncol}, t+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    return -1;
            }
        }
        return time;
    }
};