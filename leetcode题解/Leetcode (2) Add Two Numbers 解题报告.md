# Leetcode (2) Add Two Numbers 解题报告

## 题目：[Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)  
>  You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

>Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

* **Tags**:`Linked List`、`Math`

## 题目分析：
1. 题目要求：链表逆序存储一个正数，将两个链表相加，得到新的链表。
2. 注意事项：
  * 链表逆序存储
  * 两链表长度不定
  * 链表的进位

## 方案
### 方案一：
将两个链表分别转换为整数，比如long后，想加，再把结果转换回链表。   

### 方案二：
链表按顺序直接想加，用一个变量记录和与进位状态，将和依次加入链表中。

#### 代码如下：（Runtime: 40 ms）
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* begin=NULL;
        int value=0;
        do{
            ListNode* end;
            if(l1!=NULL){
                value+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                value+=l2->val;
                l2=l2->next;
            }
            ListNode* temp=new ListNode(value%10);
            if(begin==NULL){
                begin=temp;
                end=begin;
            }else{
                end->next=temp;
                end=end->next;
            }
            value/=10;
        }while(value||(l1!=NULL)||(l2!=NULL));
        return begin;
    }
};
```