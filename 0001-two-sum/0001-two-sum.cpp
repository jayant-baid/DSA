class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        unordered_map<int, int> mpp;
    
        for(int i=0;i<n;i++){
            int want=target-arr[i];
            if(mpp.find(want) != mpp.end())
                return {mpp[want], i};
            mpp[arr[i]]=i;
        }
        return {-1,-1};
        
    }
};