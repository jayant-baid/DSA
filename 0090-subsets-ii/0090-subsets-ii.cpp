class Solution {
public:
    void solve(vector<int>& arr, int index, vector<vector<int>>& ans, vector<int> ds){
        
        ans.push_back(ds);
        
        for(int i=index;i<arr.size();i++){
            if(i!=index && arr[i] == arr[i-1])
                continue;
            
            ds.push_back(arr[i]);
            solve(arr, i+1, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ans, ds);
        return ans;
    }
};