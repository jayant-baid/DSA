class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end])
                return false;
            start++, end--;
        }
        return true;
    }
     void solve(string s, int index, vector<string> output, vector<vector<string>>& ans){
         if(index == s.size()){
             ans.push_back(output);
             return;
         }
         
         for(int i=index;i<s.size();i++){
             if(isPalindrome(s, index, i)){
                 output.push_back(s.substr(index, i-index+1));
                 solve(s, i+1, output, ans);
                 output.pop_back();
             }
         }
     }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(s, 0, output, ans);
        return ans;
    }
};