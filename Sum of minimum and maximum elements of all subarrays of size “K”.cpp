#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	long long ans=0;
    multiset<int> st;
    
    for(int i=0;i<k;i++)
        st.insert(nums[i]);

    int mini=*st.begin();
    int maxi=*st.rbegin();

    ans+=mini+maxi;
    
    int startindex=0;
    
    for(int i=k;i<n;i++){
        st.insert(nums[i]);
        st.erase(st.find(nums[startindex]));
        
        int mini=*st.begin();
        int maxi=*st.rbegin();

        ans+=mini+maxi;
        startindex++;
    }
    return ans;
}
