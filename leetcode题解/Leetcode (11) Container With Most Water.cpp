class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1,max=0,area;
        while(i<j){
            if(height[i]<height[j])
                area=height[i]*(j-i),i++;
            else
                area=height[j]*(j-i),j--;
            if(area>max) max=area;
        }
        return max;
    }
};
