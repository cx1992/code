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
