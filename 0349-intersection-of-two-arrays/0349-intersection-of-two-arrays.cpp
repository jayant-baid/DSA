class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
        int n=arr1.size();
        int m=arr2.size();
        
        vector<int> ans;
        
        int i=0, j=0;
        while(i<n && j<m){
            if(arr1[i] == arr2[j]){
                ans.push_back(arr1[i]);
                while(i<n && arr1[i] == ans.back())
                    i++;
                while(j<m && arr2[j] == ans.back())
                    j++;
            }
            else if(arr1[i] < arr2[j])
                i++;
            else
                j++;
        }
        return ans;
    }
};