//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     bool possible(vector<int> arr,int day, int k, int m){
    	int cnt=0, noOfB=0;
    	for(int i=0;i<arr.size();i++){
    		if(arr[i] <= day)
    			cnt++;
    		else{
    			noOfB+=cnt/k;
    			cnt=0;
    		}
    	}
    	noOfB+=cnt/k;
    	return (noOfB>=m);
    }
    
    int solve(int m, int k, vector<int> &arr){
        int n=arr.size();
    	if(n<m*k)
    		return -1;
    	int mini=INT_MAX, maxi=INT_MIN;
    	int ans=-1;
    
    	for(int i=0;i<n;i++){
    		mini=min(mini, arr[i]);
    		maxi=max(maxi, arr[i]);
    	}
    
    	int s=mini, e=maxi;
    	while(s<=e){
    		int mid=s+(e-s)/2;
    
    		if(possible(arr, mid, k, m) == true){
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
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends