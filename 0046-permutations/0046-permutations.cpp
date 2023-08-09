class Solution {
public:
    void solve(vector<int>& arr, vector<int> ds, vector<vector<int>>& ans, int freq[]){
        if(ds.size() == arr.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<arr.size();i++){
            if(!freq[i]){
                freq[i]=1;
                ds.push_back(arr[i]);
                solve(arr, ds, ans, freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        fill_n(freq, nums.size(), 0);
        solve(nums, ds, ans, freq);
        return ans;
    }
};