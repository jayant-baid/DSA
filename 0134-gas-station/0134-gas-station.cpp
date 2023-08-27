class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int deficient=0, balance=0;
        
        for(int i=0;i<gas.size();i++){
            balance+=gas[i]-cost[i];
            
            if(balance<0){
                deficient+=balance;
                balance=0;
                start=i+1;
            }
        }
        if(balance+deficient >=0)
            return start;
        return -1;
    }
};