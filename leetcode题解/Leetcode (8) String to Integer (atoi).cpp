class Solution {
public:
    int myAtoi(string str) {
        int flag = 0;//·ûºÅ
        int num = 0;
        int n=0;
        while(str[n]==' ') n++;
        if(str[n]=='+') flag=1;
        else if(str[n]=='-') flag=-1;
        int max=INT_MAX;
        for(int i=(flag!=0)+n; i<str.length(); i++){
            if(str[i]<'0'||str[i]>'9')
                break;
            if((max-(str[i]-'0'))/10<num) {
                if(flag==-1) return INT_MIN;
                else return INT_MAX;
            }
            num=num*10+str[i]-'0';
        }
        return (flag==-1)?-1*num:num;
    }
};
