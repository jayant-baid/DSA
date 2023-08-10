class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        for(int i=1;i<=n;i++)
            ans+=(char)(i+'0');
        
        while(k>1){
            next_permutation(ans.begin(), ans.end());
            k--;
        }
        
        return ans;
        
        
    }
};