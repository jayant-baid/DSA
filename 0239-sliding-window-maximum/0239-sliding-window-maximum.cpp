class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<k;i++){
            while(!dq.empty() && arr[dq.front()] <= arr[i])
                dq.pop_front();
            
            dq.push_front(i);
        }
        ans.push_back(arr[dq.back()]);

        for(int i=k;i<arr.size();i++){
            while(!dq.empty() && i-dq.back()>=k)
                dq.pop_back();
           
            while(!dq.empty() && arr[dq.front()] <= arr[i])
                dq.pop_front();
           
            dq.push_front(i);
          
            ans.push_back(arr[dq.back()]);
        }
        return ans;
    }
};