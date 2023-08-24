class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        
        vector<int> ans(n);
        stack<int>st;
    
        
        for(int i=2*n-1;i>=0;i--){
            int curr=arr[i%n];
            while(!st.empty() && st.top()<=curr)
                st.pop();
            if(st.empty())
                ans[i%n]=-1;
            else
                ans[i%n]=st.top();
            st.push(curr);
        }
        return ans;
    }
};