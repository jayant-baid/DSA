//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    int NthRoot(int n, int m) {
      int s=1, e=m;
    
      while(s<=e){
        long long mid=s+(e-s)/2;
    
        if(mid == m/pow(mid,n-1))
          return mid;
        
        else if(mid < m/pow(mid,n-1))
          s=mid+1;
    
        else 
          e=mid-1;
      }
      return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends