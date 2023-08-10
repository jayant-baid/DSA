//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool isPresent(string str, vector<string>& wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(str.compare(wordDict[i]) == 0)
                return true;
        }
        return false;
    }
    
    bool solve(int index, string s, vector<string>& wordDict){
        if(index == s.length())
            return true;
        
        for(int i=index;i<s.length(); i++){
            string temp=s.substr(index, i - index + 1);
            if(isPresent(temp, wordDict)){
                if(solve(i+1, s, wordDict))
                    return true;
            }
        }
        return false;
    }
    int wordBreak(string s, vector<string> &wordDict) {
        return solve(0, s, wordDict);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends