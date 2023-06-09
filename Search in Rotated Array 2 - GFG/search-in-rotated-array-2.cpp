//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& arr, int target) {
        // Code here
        int s=0, e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid] == target)
                return true;
            
            if(arr[s] == arr[mid] && arr[mid] == arr[e]){
                s++, e--;
                continue;
            }
            
            if(arr[s] <= arr[mid]){
                if(arr[s] <= target && target <= arr[mid])
                    e=mid-1;
                else
                    s=mid+1;
            }
            else{
                if(arr[mid] <= target && target <= arr[e])
                    s=mid+1;
                else
                    e=mid-1;
            }
        }
        return false;
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
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends