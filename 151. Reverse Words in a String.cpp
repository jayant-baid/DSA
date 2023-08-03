class Solution {
public:
    bool isPalindrome(string s) {
        string temps="";

        for(int i=0;i<s.size();i++){
            if(s[i] >='a' && s[i]<='z')
                temps+=s[i];

            else if(s[i] >='A' && s[i]<='Z')
                temps+=s[i]+32;
                
            else if(s[i] >='0' && s[i]<='9')
                temps+=s[i];

        }
        int i=0, j=temps.size()-1;
        while(i<j){
            if(temps[i++] != temps[j--])
                return false;
        }
        return true;
    }
};
