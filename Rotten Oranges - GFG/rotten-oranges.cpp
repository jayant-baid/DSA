//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    vis[i][j]=2;
                    q.push({i, j});
                }
         
            }
        }
        
        int time=0;
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, 1, 0, -1};
        
        while(!q.empty()){
            
            int size=q.size();
            
            while(size--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=r+dr[i];
                    int ncol=c+dc[i];

                    if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol] ==1){
                        vis[nrow][ncol]=2;
                        q.push({nrow, ncol});
                    }
                }
            }
            
            if(!q.empty())
                time++;
            
            
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends