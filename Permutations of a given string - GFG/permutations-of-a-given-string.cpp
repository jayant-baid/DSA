//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(string s, int index, set<string>& ans){
	        if(index == s.length()-1){
	            ans.insert(s);
	            return;
	        }
	        for(int i=index;i<s.length();i++){
	            swap(s[index], s[i]);
	            if(ans.find(s) != ans.end())
	                continue;
	            solve(s, index+1, ans);
	            swap(s[index], s[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    set<string> st;
		    solve(S, 0, st);
		    vector<string> ans(st.begin(), st.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends