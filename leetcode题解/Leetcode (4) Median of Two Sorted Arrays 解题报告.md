# Leetcode (4) Median of Two Sorted Arrays 解题报告

## 题目：[Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)  
>  There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

* **Tags**:`分治`、`数组`、`二分查找`

## 题目分析：
1. 题目要求：找到两排序数组的全部元素的中位数。
2. 注意事项：
  * 中位数：奇数个则为中间数，偶数个为中间两数平均。
  * 两数组为排序数组
  * 时间复杂度为O(log (m+n))。

## 方案
### 方案一：  
　　这题更通用的形式是，给定两个已经排序好的数组，找到两者所有元素中第k大的元素。
　　假设A和B 的元素个数都大于k/2，我们将A的第k/2个元素（即A[k/2-1]）和B的第k/2个元素（即B[k/2-1]）进行比较，有以下三种情况（为了简化这里先假设k为偶数，所得到的结论对于k 是奇数也是成立的）：
* A[k/2-1] == B[k/2-1]
* A[k/2-1] > B[k/2-1]
* A[k/2-1] < B[k/2-1]  

　　如果A[k/2-1] < B[k/2-1]，意味着A[0]到A[k/2-1]的肯定在A和B的最小k个元素的范围内，换句话说，A[k/2-1］不可能大于A和B的第k元素。
　　因此，我们可以放心的删除A数组的这k/2个元素。同理，当A[k/2-1] > B[k/2-1] 时，可以删除B 数组的k/2个元素。
　　当A[k/2-1] == B[k/2-1] 时，说明找到了第k 元素，直接返回A[k/2-1] 或B[k/2-1]即可。
　　递归的终止条件：
* 当A或B是空时，直接返回B[k-1]或A[k-1]；
* 当k=1时，返回min(A[0], B[0])；
* 当A[k/2-1] == B[k/2-1]时，返回A[k/2-1]或B[k/2-1]。

#### 代码如下：（Runtime: 24 ms）
```c
#define min(a,b) ((a)<(b)?(a):(b))

int find_kth(int *A, int m, int *B, int n, int k){//查找第k小的值
    if(m>n) return find_kth(B,n,A,m,k); //保证m<=n
    if(m==0) return B[k-1];     //终止条件1：其中一个长度为0；
    if(k==1) return min(A[0],B[0]);//终止条件2：查找最小值；
    
    int ia=min(k/2,m),ib=k-ia;
    if(A[ia-1]<B[ib-1])         //若A第ia个元素小，抛弃左侧元素
        return find_kth(A+ia,m-ia,B,n,k-ia);
    else if(A[ia-1]>B[ib-1])    //若B第ib个元素小，抛弃左侧元素
        return find_kth(A,m,B+ib,n-ib,k-ib);
    else
        return A[ia-1];         //终止条件3：找到了目标值；
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    if(total & 0x1)
        return find_kth(nums1,nums1Size,nums2,nums2Size,total/2+1);
    else
        return (find_kth(nums1,nums1Size,nums2,nums2Size,total/2)+find_kth(nums1,nums1Size,nums2,nums2Size,total/2+1))/2.0;
}

```