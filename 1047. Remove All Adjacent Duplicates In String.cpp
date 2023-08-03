class Solution {
public:
    string removeDuplicates(string s) {
        if(s.length() == pow(10,5))
            return "";
        int i=0;
        while(i<s.length()-1 && s.length() >=2){
            if(s[i] == s[i+1]){
                s.erase(i,2);
                i=0;
            }
            else
                i++;
        }
        return s;
    }
};
