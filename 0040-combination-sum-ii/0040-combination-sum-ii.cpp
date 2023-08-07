class Solution {
public:
    void solve(vector<int>& arr, int target, int index, vector<vector<int>>& ans, vector<int> output){
        if(target == 0){
            ans.push_back(output);
            return;
        }
    
        
        for(int i=index;i<arr.size();i++){
            if(i!=index && arr[i] == arr[i-1])
                continue;
            if(arr[i] > target)
                break;
            
            output.push_back(arr[i]);
            solve(arr, target-arr[i], i+1, ans, output);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates, target, 0, ans, output);
        return ans;
    }
};