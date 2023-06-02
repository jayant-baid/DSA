//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &matrix, int n, int m, int k)
    {
        // Your code goes here
        vector<int> ans;
        int srow=0, scol=0, erow=n-1, ecol=m-1;
        int cnt=0, total=k;
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
        return ans[k-1];
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends