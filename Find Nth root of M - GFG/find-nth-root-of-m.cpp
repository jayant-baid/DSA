//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	// return 1 if == m
    // return 0 if < m
    // return 2 if > m
    
    int func(int mid, int n, int m){
      long long ans=1;
      for(int i=1;i<=n;i++){
        ans*=mid;
        if(ans>m)
          return 2;
      }
      if(ans==m)
        return 1;
      return 0;
    }
    
    int NthRoot(int n, int m) {
      int s=1, e=m;
    
      while(s<=e){
        int mid=s+(e-s)/2;
        int midN=func(mid, n, m);
    
        if(midN == 1)
          return mid;
        
        else if(midN == 0)
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