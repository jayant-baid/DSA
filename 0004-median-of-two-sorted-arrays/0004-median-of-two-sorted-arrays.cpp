class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        vector<int> arr;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] <= nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            arr.push_back(nums2[j]);
            j++;        
        }

        double ans;
        int n=arr.size();
        if(n & 1)
            ans=arr[n/2];
        else
            ans=(double)(arr[n/2]+arr[n/2 - 1])/2;

        return ans;
    }
};