class Solution {
public:
    bool isPresent(string str, vector<string>& wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(str.compare(wordDict[i]) == 0)
                return true;
        }
        return false;
    }
    
    bool solve(int index, string s, vector<string>& wordDict, vector<int>& dp){
        if(index == s.length())
            return true;
        if(dp[index] !=-1)
            return dp[index];
        
        for(int i=index;i<s.length(); i++){
            string temp=s.substr(index, i - index + 1);
            if(isPresent(temp, wordDict)){
                if(solve(i+1, s, wordDict, dp))
                    return dp[index] = 1;
            }
        }
        return dp[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return solve(0, s, wordDict, dp);
    }
};