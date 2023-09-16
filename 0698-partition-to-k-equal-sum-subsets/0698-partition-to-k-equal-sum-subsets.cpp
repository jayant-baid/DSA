class Solution {
public:
    bool solve(vector<int> nums,vector<bool>& visited,int sum,int index,int target,int k){
        if(k==1)return true;
        if(sum>target)return false;
        if(index >= nums.size())
            return false;
        if(sum==target)
            return solve(nums,visited,0,0,target,k-1);
        
        for(int i=index;i<nums.size();i++){
            if(!visited[i] && sum+nums[i] <=target){
                visited[i] = true;

                if(solve(nums,visited,sum+nums[i],i+1,target,k))
                    return true;

                visited[i] = false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n)return false;
        int sum=0;
        for(auto it : nums)
            sum += it;
       if (sum < k || sum % k) return false;
        int target = sum/k;
        vector<bool> v(n,false);
        sort(nums.begin(), nums.end(), greater<int>());
        if(nums[0]>target)
            return false;

        return solve(nums,v,0,0,target,k);
    }
    
};