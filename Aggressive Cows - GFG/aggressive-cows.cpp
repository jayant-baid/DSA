//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    bool isPossible(vector<int> &arr, int n, int dist, int cows){
        int cowCount=1, lastPos=arr[0];
        
        for(int i=1;i<n;i++){
            if(arr[i] - lastPos >= dist){
                cowCount++;
                lastPos=arr[i];
            }
        }
        if(cowCount >= cows)
            return true;
        
        return false;
    }

    int solve(int n, int cows, vector<int> &arr) {
    
        sort(arr.begin(), arr.end());
        
        int s=1, e=arr[n-1] - arr[0];
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(arr,n,mid,cows)==true)
                s=mid+1;
            else
                e=mid-1;
        }
        return e;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends