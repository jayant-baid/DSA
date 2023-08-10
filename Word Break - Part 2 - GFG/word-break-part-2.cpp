//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPresent(string str, vector<string>& wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(str.compare(wordDict[i]) == 0)
                return true;
        }
        return false;
    }
    void solve(int index, string s, vector<string>& wordDict, string& output, vector<string>& ans){
        if(index == s.length()){
            output.pop_back();
            ans.push_back(output);
            return;
        }
        
        for(int i=index;i<s.length();i++){
            string temp=s.substr(index, i - index + 1);
            if(isPresent(temp, wordDict)){
                string dupOutput=output;
                output += temp + ' ';
                solve(i+1, s, wordDict, output, ans);
                output=dupOutput;
            }
        }
        
    }

    vector<string> wordBreak(int n, vector<string>& wordDict, string s)
    {
        string output;
        vector<string> ans;
        solve(0, s, wordDict, output, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends