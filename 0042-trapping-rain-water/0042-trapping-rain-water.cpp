class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
//         vector<int> maxl(n, 0);
//         vector<int> maxr(n, 0);
        
//         maxl[0]=height[0];
//         maxr[n-1]=height[n-1];
        
//         for(int i=1;i<n;i++)
//             maxl[i]=max(height[i], maxl[i-1]);
        
//         for(int i=n-2;i>=0;i--)
//             maxr[i]=max(height[i], maxr[i+1]);
        
//         int ans=0;
//         for(int i=0;i<n;i++)
//             ans+=min(maxl[i], maxr[i])-height[i];
        
//         return ans;
        int i=0, j=n-1;
        int maxl=0, maxr=0;
        long long ans=0;
        while(i<=j){
            maxl=max(maxl, height[i]);
            maxr=max(maxr, height[j]);
            if(maxl < maxr){
                ans+=maxl-height[i];
                i++;
            }
            else{
                ans+=maxr-height[j];
                j--;
            }
        }
        return ans;
    }
};