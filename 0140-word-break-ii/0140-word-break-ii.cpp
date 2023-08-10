class Solution {
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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string output;
        vector<string> ans;
        solve(0, s, wordDict, output, ans);
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};