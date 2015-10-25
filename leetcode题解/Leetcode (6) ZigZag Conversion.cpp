class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||numRows>=s.length()) 
            return s;
        int period = 2*(numRows-1);
        string s1;
        for(int i=0;i<numRows;i++){
            int j=i,d=2*i;
            do{
                s1+=s[j];
                d=period-d%period;
                j+=d;
            }while(j<s.length());
           // for(int j=i,d=2*i;j<s.length();d=period-d%period,j+=d)
            //    s1+=s[j];
        }
        return s1;
    }
};