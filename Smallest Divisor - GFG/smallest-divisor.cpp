//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool possible(vector<int>& arr,int num, int limit){
    	int sum=0;
    	for(int i=0;i<arr.size();i++)
    		sum+=ceil( (double)arr[i]/ (double)num );
    	
    	return (sum<=limit);
    		
    }
    int smallestDivisor(vector<int>& arr, int limit) {

        // Write your code here.
        int n=arr.size();

    	int maxi=INT_MIN;
    	for(int i=0;i<n;i++)
    		maxi=max(maxi, arr[i]);
    
    	// for(int i=1;i<=maxi;i++){
    	// 	if(possible(arr, i, limit) == true)
    	// 		return i;
    	// }
    	// return -1;
    
    	int s=1, e=maxi;
    	int ans=-1;
    	while(s<=e){
    		int mid=s+(e-s)/2;
    
    		if(possible(arr, mid, limit)==true){
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
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends