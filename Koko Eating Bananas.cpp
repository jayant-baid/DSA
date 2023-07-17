class Solution {
public:
    long func(vector<int>& piles, int mid){
        long totalhrs=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] % mid == 0)
                totalhrs+=piles[i]/mid;
            else
                totalhrs+=piles[i]/mid + 1;

        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1, e=-1;
        int ans=-1;
        for(int i=0;i<piles.size();i++)
            e=max(e, piles[i]);

        while(s<=e){
            int mid=s+(e-s)/2;

            long reqTime=func(piles, mid);
            if(reqTime <= h){
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};
