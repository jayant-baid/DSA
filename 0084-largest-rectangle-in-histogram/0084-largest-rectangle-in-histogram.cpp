class Solution {
public:
    vector<int> prevsmaller(vector<int>& arr, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        
        for(int i=0;i<n;i++){
            int curr=arr[i];
            
            while(st.top()!=-1 && arr[st.top()] >= curr)
                st.pop();
            
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextsmaller(vector<int>& arr, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            
            while(st.top()!=-1 && arr[st.top()] >= curr)
                st.pop();
            
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prev=prevsmaller(heights, n);
        vector<int> next=nextsmaller(heights, n);
        
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i] == -1)
                next[i]=n;
            
            int b=next[i] - prev[i] - 1;
            
            int temparea=l*b;
            area=max(area, temparea);
        }
        return area;
    }
};