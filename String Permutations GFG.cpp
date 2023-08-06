class Solution{
    public:
    void solve(string s, int index, vector<string>& ans){
	   if(index == s.length()-1){
	       ans.push_back(s);
	       return;
	   }
	   for(int i=index;i<s.length();i++){
	       swap(s[index], s[i]);
	       solve(s, index+1, ans);
	       swap(s[index], s[i]);
        }
	}    
    vector<string> permutation(string S)
    {
        vector<string> ans;
    		solve(S, 0, ans);
    		sort(ans.begin(), ans.end());
	    return ans;
    }
};
