//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int func(vector<int>& piles, int mid){
        int totalhrs=0;
        for(int i=0;i<piles.size();i++){
                totalhrs+=ceil( (double)piles[i]/(double)mid );

        }
        return totalhrs;
    }
    int Solve(int n, vector<int>& piles, int h) {
        int s=1, e=-1;
        int ans=-1;
        for(int i=0;i<piles.size();i++)
            e=max(e, piles[i]);

        while(s<=e){
            int mid=s+(e-s)/2;

            int reqTime=func(piles, mid);
            if(reqTime <= h){
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
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
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends