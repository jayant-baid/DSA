//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        int lim=0;
        for(int i=1;i<=2*n-1;i++){
            lim = (i<=n) ? i : 2*n-i; 
            for(int j=1;j<=lim;j++)
                cout<<"*";
                
            for(int j=1;j<=2*(n-lim);j++)
                cout<<" ";
                
            for(int j=1;j<=lim;j++)
                cout<<"*";
            
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends