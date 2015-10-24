# Leetcode (3) Longest Substring Without Repeating Characters 解题报告

## 题目：[Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)  
>  Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

* **Tags**:`Hash Table`、`Two Pointers`、`String`

## 题目分析：
1. 题目要求：找到没有重复字符的最长子串。
2. 注意事项：
  * 空字符串
  * 字符串无重复字符

## 方案
### 方案一：
 1. 用数组模拟hash表，记录每个字符最后出现的位置。从左到右遍历字符串，用left记录最后一个重复字符的位置，若当前子字符串长度更大就更新maxLen。  

#### 代码如下：（Runtime: 12 ms）
```c++
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
```
