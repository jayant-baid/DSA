class Solution {
public:
    bool checkEqual(int a[], int b[]){
        for(int i=0;i<26;i++){
            if(a[i] != b[i])
                return 0;
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};

        for(int i=0;i<s1.length();i++)
            count1[s1[i] - 'a']++;

        int windowSize=s1.length();
        int i=0;
        int count2[26]={0};
        while(i<windowSize && i< s2.length()){
            count2[s2[i] - 'a']++;
            i++;
        }
        if(checkEqual(count1, count2))
            return 1;

        while(i<s2.length()){
            count2[s2[i] - 'a']++;
            count2[s2[i-windowSize] - 'a']--;

            if(checkEqual(count1, count2))
                return 1;

            i++;
        }
        return 0;
    }
};
