#define min(a,b) ((a)<(b)?(a):(b))

int find_kth(int *A, int m, int *B, int n, int k){//���ҵ�kС��ֵ
    if(m>n) return find_kth(B,n,A,m,k); //��֤m<=n
    if(m==0) return B[k-1];     //��ֹ����1������һ������Ϊ0��
    if(k==1) return min(A[0],B[0]);//��ֹ����2��������Сֵ��
    
    int ia=min(k/2,m),ib=k-ia;
    if(A[ia-1]<B[ib-1])         //��A��ia��Ԫ��С���������Ԫ��
        return find_kth(A+ia,m-ia,B,n,k-ia);
    else if(A[ia-1]>B[ib-1])    //��B��ib��Ԫ��С���������Ԫ��
        return find_kth(A,m,B+ib,n-ib,k-ib);
    else
        return A[ia-1];         //��ֹ����3���ҵ���Ŀ��ֵ��
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    if(total & 0x1)
        return find_kth(nums1,nums1Size,nums2,nums2Size,total/2+1);
    else
        return (find_kth(nums1,nums1Size,nums2,nums2Size,total/2)+find_kth(nums1,nums1Size,nums2,nums2Size,total/2+1))/2.0;
}
