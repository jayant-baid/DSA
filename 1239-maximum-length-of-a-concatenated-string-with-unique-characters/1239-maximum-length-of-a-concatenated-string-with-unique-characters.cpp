class Solution {
public:
    bool isPossible(string ch, vector<int>& numbers){
        vector<int> selfCheck(26, 0);
        
        for(int i=0;i<ch.size();i++){
            if(selfCheck[ch[i] - 'a'] == 1)
                return false;
            
            if(numbers[ch[i] - 'a'] == 1)
                return false;
            
            selfCheck[ch[i] - 'a'] = 1;
        }
        return true;
    }
    int solve(vector<string>& arr, vector<int>& numbers, int index, int len){
        if(index == arr.size())
            return len;
        
        string ch=arr[index];
        if(isPossible(ch, numbers)){
            
            for(int i=0;i<ch.size();i++)    
                numbers[ch[i]-'a']=1;
            len+=ch.size();
            
            int ans1=solve(arr, numbers, index+1, len);
            
            len-=ch.size();
            for(int i=0;i<ch.size();i++)    
                numbers[ch[i]-'a']=0;
            
            int ans2=solve(arr, numbers, index+1, len);
            
            return max(ans1, ans2);
        }
        else
            return solve(arr, numbers, index+1, len);
    }
    int maxLength(vector<string>& arr) {
        vector<int> numbers(26, 0);
        return solve(arr, numbers, 0, 0);
    }
};