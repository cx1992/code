class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
        int longest=0,index=0;
        for(int i=0;i<n;i++)
        {
        	lengthofPalindrome(s,0,i,&longest,&index);
        	lengthofPalindrome(s,i,n-1,&longest,&index);
        }
        return s.substr(index, longest);
    }
    void lengthofPalindrome(string s,int begin,int end,int *maxLen,int *index){
        int j,k,len=0,index1=begin;
        for(j=(begin+end)/2,k=(begin+end+1)/2;j>=begin&&k<=end;j--,k++){
          if(s[j]==s[k])
            len+=2-(j==k);
          else{
            index1=j+1;break;
          }
        }
        if(len>*maxLen){
        *maxLen=len;
        *index=index1;
      }
    }
};