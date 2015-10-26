class Solution {
public:
    int reverse(int x) {
        if(x==0)
            return 0;
        while(x%10==0) 
            x/=10;
        int y=0;
        while(x){
            if((x>0&&(INT_MAX-x%10)/10<y)||(x<0&&(INT_MIN-x%10)/10>y))
                return 0;
            y=y*10+x%10;
            x/=10;
        }
        return y;
    }
};