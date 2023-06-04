//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& arr) {
        // Code here
        int cnt1=0, cnt2=0;
        int el1=INT_MIN, el2=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(cnt1==0 && arr[i] != el2){
                cnt1++;
                el1=arr[i];
            }
            else if(cnt2==0 && arr[i] != el1){
                cnt2++;
                el2=arr[i];
            }
            else if(arr[i] == el1)
                cnt1++;
            else if(arr[i] == el2)
                cnt2++;
            else 
                cnt1--, cnt2--;
        }
        vector<int> ans;
        cnt1=0, cnt2=0;
        for(int i=0;i<n;i++){
            if(el1==arr[i])
                cnt1++;
            else if(el2==arr[i])
                cnt2++;
        }
        if(cnt1> n/3) 
            ans.push_back(el1);
        if(cnt2> n/3) 
            ans.push_back(el2);
            
        if(ans.size() == 0)
            return {-1};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends