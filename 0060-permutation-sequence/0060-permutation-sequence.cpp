class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        int fact=1;
        vector<int> num;
        for(int i=1;i<=n;i++){
            fact*=i;
            num.push_back(i);
        }
        fact/=n;
        
        k=k-1;
        while(num.size() != 0){
            ans+=to_string(num[k/fact]);
            num.erase(num.begin() + k/fact);
            
            k=k%fact;
            if(num.size() != 0)
                fact=fact/num.size();
        }
        
        return ans;
        
        
    }
};