class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        int cnt=1;
        sort(arr.begin(), arr.end());
        for(int i=1;i<arr.size();i++){
            if(arr[i] == arr[i-1])
                cnt++;
            else{
                ans.push_back(cnt);
                cnt=1;
            }
        }
        ans.push_back(cnt);
        sort(ans.begin(), ans.end());
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i] == ans[i+1])
                return false;
        }
        return true;
        
    }
};