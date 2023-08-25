class Solution {
public:
    vector<int> nextsmaller(vector<int>& arr, int n){
        vector<int> next(n);
        stack<int>st;
        st.push(-1);
        
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            
            while(st.top()!=-1 && arr[st.top()]>=curr )
                st.pop();
            
            next[i]=st.top();
            st.push(i);
        }
        return next;
    }
    vector<int> prevsmaller(vector<int>& arr, int n){
        vector<int> prev(n);
        stack<int>st;
        st.push(-1);
        
        for(int i=0;i<n;i++){
            int curr=arr[i];
            
            while(st.top()!=-1 && arr[st.top()]>=curr )
                st.pop();
            
            prev[i]=st.top();
            st.push(i);
        }
        return prev;
    }
    int histogramArea(vector<int>& arr, int n){
        vector<int> prev=prevsmaller(arr, n);
        vector<int> next=nextsmaller(arr, n);
        
        int area=0;
        for(int i=0;i<n;i++){
            int l=arr[i];
            
            if(next[i] == -1)
                next[i]=n;
            int b=next[i]-prev[i]-1;
            
            area=max(area, l*b);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int> histo(m, 0);
        int area=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] != '0')
                    histo[j]++;
                else
                    histo[j]=0;
            }
            area=max(area, histogramArea(histo, m));
        }
        return area;
    }
};