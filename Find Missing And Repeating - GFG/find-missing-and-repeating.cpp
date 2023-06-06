//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
    
        int xr=0;
        for(int i=0;i<n;i++){
            xr=xr^arr[i];
            xr=xr^(i+1);
        }
        
        int number=(xr & ~(xr-1));
        int zero=0, one=0;
        for(int i=0;i<n;i++){
            if((arr[i] & number) != 0)
                one=one^arr[i];
            else
                zero=zero^arr[i];
        }
        
        for(int i=1;i<=n;i++){
            if((i & number) != 0)
                one=one^i;
            else
                zero=zero^i;
        }
        
        for(int i=0;i<n;i++){
            if(arr[i] == zero)
                return {zero, one};
            else if(arr[i] == one)
                return {one, zero};
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends