class Solution {
public:
    void solve(vector<int>& arr, int index, vector<vector<int>>& ans){
        if(index == arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=index;i<arr.size();i++){
            swap(arr[i], arr[index]);
            solve(arr, index+1, ans);
            swap(arr[i], arr[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(nums, 0, ans);
        return ans;
    }
};