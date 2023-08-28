// Middle Approach
// #include <bits/stdc++.h> 
// long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
// 	long long ans=0;
//     multiset<int> st;
    
//     for(int i=0;i<k;i++)
//         st.insert(nums[i]);

//     int mini=*st.begin();
//     int maxi=*st.rbegin();

//     ans+=mini+maxi;
    
//     int startindex=0;
    
//     for(int i=k;i<n;i++){
//         st.insert(nums[i]);
//         st.erase(st.find(nums[startindex]));
        
//         int mini=*st.begin();
//         int maxi=*st.rbegin();

//         ans+=mini+maxi;
//         startindex++;
//     }
//     return ans;
// }

// Optimized Approad
#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	long long ans=0;
    deque<int> maxi;
    deque<int> mini;

    for(int i=0;i<k;i++){
        while(!maxi.empty() && nums[maxi.front()] <= nums[i])
            maxi.pop_front();
        while(!mini.empty() && nums[mini.front()] >= nums[i])
            mini.pop_front();

        maxi.push_front(i);
        mini.push_front(i);
    }
    ans+=nums[maxi.back()] + nums[mini.back()];

    for(int i=k;i<n;i++){
        while(!maxi.empty() && i-maxi.back()>=k)
            maxi.pop_back();
        while(!mini.empty() && i-mini.back()>=k)
            mini.pop_back();

        while(!maxi.empty() && nums[maxi.front()] <= nums[i])
            maxi.pop_front();
        while(!mini.empty() && nums[mini.front()] >= nums[i])
            mini.pop_front();

        maxi.push_front(i);
        mini.push_front(i);
        ans+=nums[maxi.back()] + nums[mini.back()];
    }
    return ans;
}
// We can interchange front() and back() and get correct ans
