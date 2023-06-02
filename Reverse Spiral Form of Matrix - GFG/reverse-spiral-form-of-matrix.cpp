//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int n, int m, vector<vector<int>>&matrix)  {
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
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends