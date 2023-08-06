class Solution {
public:
    void func(vector<int>&arr, int i, vector<vector<int>>& ans, vector<int> output){
        if(i==arr.size()){
            ans.push_back(output);
            return;
        }
        
        func(arr, i+1, ans, output);
        
        output.push_back(arr[i]);
        func(arr, i+1, ans, output);
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        
        func(nums, 0, ans, output);
        return ans;
    }
};