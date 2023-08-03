class Solution {
public:
    int countPrimes(int n) {
        
        int cnt=0;
        
        if(n==0 || n== 1)
            return cnt;
        
        vector<bool> prime(n, true);
        prime[0]=prime[1]=false;
        
        for(int i=2;i<n;i++){
            if(prime[i] == true){
                cnt++;
                for(int j=2*i;j<n;j+=i)
                    prime[j]=false;
            }
        }
        return cnt;
    }
};