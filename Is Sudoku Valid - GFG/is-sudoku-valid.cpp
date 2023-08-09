//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(vector<vector<int>>& board, int row, int col, int num){
        for(int i=0;i<9;i++){
            if(board[row][i] == num && col!=i)
                return false;
            if(board[i][col] == num && row!=i)
                return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == num && row!=(3*(row/3) + i/3) && col!=(3*(col/3) + i%3))
                return false;
        }
        return true;
    }
    bool solve(vector<vector<int>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != 0){
                
                    if(isValid(board, i, j, board[i][j]) == false){
                        return false;
                    }
                    
                }
            }
        }
        return true;
    }
    
    int isValid(vector<vector<int>> mat){
        // code here
        return solve(mat);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends