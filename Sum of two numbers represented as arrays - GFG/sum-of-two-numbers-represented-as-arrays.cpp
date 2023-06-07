//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    int i=a.size()-1, j=b.size()-1;
	    int carry=0;
	    
	    vector<int> ans;
	    while(i>=0 && j>=0){
	        int sum=a[i]+b[j]+carry;
	        carry=sum/10;
	        ans.push_back(sum%10);
	        i--, j--;
	    }
	    while(i>=0 ){
	        int sum=a[i]+carry;
	        carry=sum/10;
	        ans.push_back(sum%10);
	        i--;
	    }
	    while( j>=0){
	        int sum=b[j]+carry;
	        carry=sum/10;
	        ans.push_back(sum%10);
	        j--;
	    }
	    while(carry!=0){
	        int sum=carry;
	        carry=sum/10;
	        ans.push_back(sum%10);
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends