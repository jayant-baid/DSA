//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        // code here
        for(int i=0;i<=2*n-2;i++){
            for(int j=0;j<=2*n-2;j++){
                int val=min( min(i,j), min(2*n-2-i, 2*n-2-j) ) ;
                cout<<n-val<<" ";
            }
            cout<<endl;
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

        Solution ob;
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends