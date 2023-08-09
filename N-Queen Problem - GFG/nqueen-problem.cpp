//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int row, int col, vector<vector<int>>& board, int n){
        int duprow=row, dupcol=col;
        // Upper Diagonal
        while(row>=0 && col>=0){
            if(board[row][col] == 1)
                return false;
            row--, col--;
        }
        
        row=duprow;
        col=dupcol;
        // Lower Diagonal
        while(row<n && col>=0){
            if(board[row][col] == 1)
                return false;
            row++, col--;
        }
        
        row=duprow;
        col=dupcol;
        // Same Row
        while(col>=0){
            if(board[row][col] == 1)
                return false;
            col--;
        }
        return true;
    }
    void addans(vector<vector<int>>& board, vector<vector<int>>& ans, int n){
        vector<int> temp;
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(board[i][j] == 1)
                    temp.push_back(i+1);
            }
        }
        ans.push_back(temp);
    }
    void solve(int col, int n, vector<vector<int>>& board, vector<vector<int>>& ans){
        if(col == n){
            addans(board, ans, n);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row, col, board, n)){
                board[row][col]=1;
                solve(col+1, n, board, ans);
                board[row][col]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        
        solve(0, n, board, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends