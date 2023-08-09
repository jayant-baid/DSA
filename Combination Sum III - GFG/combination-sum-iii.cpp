//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(int num, int k, int n, vector<int> output, vector<vector<int>>& ans){
        if(output.size() == k){
            if(n == 0)
                    ans.push_back(output);
            return;
        }
        
        for(int i=num;i<=9;i++){
            output.push_back(i);
            solve(i+1, k, n-i, output, ans);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(1, k, n, output, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends