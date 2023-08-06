class Solution {
public:
    void solve(string digits, int index, vector<string>& ans, string output, string map[]){
        if(index == digits.size()){
            ans.push_back(output);
            return;
        }
        string value=map[digits[index]-'0'];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits, index+1, ans, output, map);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output="";
        
        if(digits.length() == 0)
            return {};
        
        string map[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(digits, 0, ans, output, map);
        
        return ans;
    }
};