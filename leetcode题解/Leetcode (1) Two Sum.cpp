#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstring>
#include <unordered_map>
//#include <stack>
//#include <queue>
using namespace std;
/*
vector<int> twoSum(vector<int>& nums, int target) { //≈≈–Ú∑®
        vector<int> temp(nums);
        sort(temp.begin(),temp.end());
        vector<int> twoNum;
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            int sum=temp[i]+temp[j];
            if(sum==target){
                int index1=find(nums.begin(),nums.end(),temp[i])-nums.begin()+1;
                int index2;
                if(temp[i]!=temp[j])
					index2=find(nums.begin(),nums.end(),temp[j])-nums.begin()+1;
				else
					index2=find(nums.begin()+index1,nums.end(),temp[j])-nums.begin()+1;
                if(index1>index2)
                    index1^=index2^=index1^=index2;
                twoNum.push_back(index1);
                twoNum.push_back(index2);
                break;
            }else if(sum<target)
                i++;
            else
                j--;
        }
        return twoNum;
    }*/

vector<int> twoSum(vector<int>& nums, int target) { // hash table;
        vector<int> twoNum;
        unordered_map<int,int> hmap;
        for(int i=0;i<nums.size();i++){
			unordered_map<int,int>::iterator it = hmap.find(target-nums[i]);
			if(it==hmap.end()){
				hmap.insert(pair<int,int>(nums[i],i+1));
			}
			else{
				twoNum.push_back(it->second);
				twoNum.push_back(i+1);
				break;
			}
        }
        return twoNum;
    }



int main()
{
	int a[]={2,1,9,4,4,56,90,3};
	vector <int> out(a,a+sizeof(a)/sizeof(a[0]));
	vector <int> nums=twoSum(out, 8);
	int i;
	for(i=0;i<nums.size();i++)
		cout <<nums[i]<<endl;
	return 0;
}
