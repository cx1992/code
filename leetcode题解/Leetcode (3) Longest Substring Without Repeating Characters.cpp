class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int index[256];
        memset(index,-1,sizeof(index));
        int left=-1,maxLen=0;
        for(int i=0;i<s.length();i++){
            if(index[s[i]]>left)
                left=index[s[i]];
            if(i-left>maxLen)
                maxLen=i-left;
            index[s[i]]=i;
        }
        return maxLen;
    }
};