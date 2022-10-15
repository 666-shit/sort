//
// Created by c1533 on 2022/10/11.
//
/**归并排序
 * 归并：把两个或多个已经有序列的序列合并为一个
 * 新建一个空列表，大小为小列表之和，以两个列表为例：
 * 列表A大小为7(0~6)，B大小为5(0~4)，新建列表C，大小为12
 * A上第一个元素放指针i，B放j，C放k
 * 对比i和j大小，小的元素(比如j)放入k的位置，(比如j)++，k++
 * 重复上述步骤继续对比
 * */
/**“n路”归并：
 * n个序列对比，每选出一个小元素时只需要对比关键字n-1次
 * */
#include <cstdlib>

/**对n个无序元素进行归并排序：
  * 每一个元素可以看作一个有序的序列
  * 对每两个相邻元素进行“2路”归并，单个元素不进行归并
  * 重复上述步骤，直到剩下一个序列
  * */
int *B = (int *) malloc(sizeof(int));        //Auxiliary array B大小为n(两个加起来：int *B = (int *)malloc(n*sizeof(int));)
//A[low] and A[high] are ordered
void Merge(int A[], int low, int mid, int high) {//需要合并的是low~mid，和mid+1~high这两个序列
    int i, j, k;
    for (k = low; k < high; k++)
        B[k] = A[k];      //将A中所有元素复制到B中，归并排序在B中进行，排好的序列放入A
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {       //i指向B中第一个元素，j指向B中第mid+1个元素，k指向原序列的第一个元素
        if (B[i] <= B[j])      //i指的位置元素比较小，或两元素相等时让i位置的优先放入(保证稳定性)
            A[k] = B[i++];    //较小的值复制到A中
        else                   //j指的位置元素比较小
            A[k] = B[j++];
    }       //当有一个指针超出范围，跳出循环
    while (i <= mid)       //检测某一个指针是否超出范围，即某一个序列是否完成放入，剩下一个序列直接全部放入A中
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[j++];
}

void MergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;       //中间划分
        MergeSort(A, low, mid);     //对左半部分归并排序
        MergeSort(A, mid + 1, high);  //对右半部分归并排序
        Merge(A, low, mid, high);       //归并
    }
}
/**效率分析
 * 2路归并的归并树可以看作二叉树
 * 二叉树的h层最多有2^(h-1)个结点，若树高为h则满足n<=2^(h-1)
 * 即：h-1=[log_2n]
 *
 * n个元素进行2路归并排序，次数=[log_2n]
 * 每一次排序的时间复杂度O(n)
 * 算法时间复杂度为O(nlog_2n)
 * 空间复杂度O(n)，来自辅助数组B
 * */
