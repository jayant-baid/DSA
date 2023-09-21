class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<k;i++){
            while(!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);

        for(int i=k;i<arr.size();i++){
            while(!dq.empty() && i-dq.front()>=k)
                dq.pop_front();
           
            while(!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();
           
            dq.push_back(i);
          
            ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};