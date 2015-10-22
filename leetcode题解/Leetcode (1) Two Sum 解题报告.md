# Leetcode (1) Two Sum 解题报告

## 题目：[Two Sum](https://leetcode.com/problems/two-sum/)  
> Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2  

* **Tags**:`Array`、`Hash Table`

## 题目分析：
1. 题目要求：在一个数组中找到两个数，使其和为目标值，返回下标。
2. 注意事项：
  * 小坐标在前，大坐标在后；
  * 坐标从1开始；

## 方案
### 方案一：排序
 1. 将原数组拷贝到一个新数组中，对新数组进行排序；定义两个下标i，j，其中i=0，j=size-1，取出新数组数据求和。若sum<target,i++;若sum>target,j--;若相等，则证明找到了。然后在原数组找到对应的下标。
 2. 或者建立一个类，类中包括值与下标，对该类按照值进行排序后按1中进行查找，找到后直接可以得到对应下标。  

#### 代码如下：（Runtime: 12 ms）
```c++
	class Solution {
	public:
    vector<int> twoSum(vector<int>& nums, int target) {
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
    }
};
```
### 方案二：哈希表
建立一个哈希表,将value映射到index上。对原数组遍历，对于num[i]，查找target-num[i]在哈希表中是否存在，若不存在，则将num[i]加入哈希表中；若存在，则输出index。

#### 代码如下：（Runtime: 24 ms）
```c++
class Solution {
public:
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
};
```