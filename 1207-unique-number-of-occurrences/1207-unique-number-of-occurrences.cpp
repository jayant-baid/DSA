class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mpp;
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++)
            mpp[arr[i]]++;
        
        set<int> st;
        for(auto it: mpp){
            st.insert(it.second);
        }
            
        
        return mpp.size() == st.size();
        
    }
};