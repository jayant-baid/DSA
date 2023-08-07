class Solution{
    public:
    bool solve(vector<int>& arr, int k, int index, int sum){
        if(sum > k)
            return false;
        if(index == arr.size()){
            if(sum == k)
                return true;
                
            return false;
        }
        
        if(solve(arr, k, index+1, sum))
            return true;
            
        if(solve(arr, k, index+1, sum+arr[index]))
            return true;
            
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return solve(arr, k, 0, 0);
    }
};
