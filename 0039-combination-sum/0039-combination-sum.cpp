class Solution {
public:
    void solve(vector<int>& arr, int target, int index, vector<vector<int>>& ans, vector<int> output){
        if(index == arr.size()){
            if(target==0)
                ans.push_back(output);
            return;
        }
        if(target < 0)
                return;
        
        solve(arr, target, index+1, ans, output);
        output.push_back(arr[index]);
        solve(arr, target-arr[index], index, ans, output);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        
        solve(candidates, target, 0, ans, output);
        return ans;
    }
};