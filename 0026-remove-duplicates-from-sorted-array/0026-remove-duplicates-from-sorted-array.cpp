class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] != nums[i+1])
                nums[index++] = nums[i];
        }
        nums[index++] = nums[nums.size()-1];
        return index;
    }
};