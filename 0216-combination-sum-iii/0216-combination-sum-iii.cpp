class Solution {
public:
    void solve(int num, int k, int n, vector<int> output, vector<vector<int>>& ans){
        if(output.size() == k){
            if(n == 0)
                    ans.push_back(output);
            return;
        }
        
        for(int i=num;i<=9;i++){
            output.push_back(i);
            solve(i+1, k, n-i, output, ans);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(1, k, n, output, ans);
        return ans;
    }
};