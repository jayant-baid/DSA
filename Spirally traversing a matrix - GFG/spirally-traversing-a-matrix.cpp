//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int n, int m) 
    {
        // code here 
        vector<int> ans;
        int srow=0, scol=0, erow=n-1, ecol=m-1;
        int cnt=0, total=n*m;
        while(cnt<total){
            for(int i=scol;cnt<total && i<=ecol;i++){
                ans.push_back(matrix[srow][i]);
                cnt++;
            }
            srow++;
            
            for(int i=srow;cnt<total && i<=erow;i++){
                ans.push_back(matrix[i][ecol]);
                cnt++;
            }
            ecol--;

            for(int i=ecol;cnt<total && i>=scol;i--){
                ans.push_back(matrix[erow][i]);
                cnt++;
            }
            erow--;
            for(int i=erow;cnt<total && i>=srow;i--){
                ans.push_back(matrix[i][scol]);
                cnt++;
            }
            scol++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends