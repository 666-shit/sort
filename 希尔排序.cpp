//
// Created by c1533 on 2022/10/4.
//
/**希尔排序
 * 先将待排序表分割成若干特殊子表，对各个子表分别进行直接插入排序，缩小增量d，重复上述步骤，直到d=1
 * 第一轮：d1=n/2，n为表中总元素个数，从1开始，相距d个长度的元素分到同一子表
 * 第二轮：d2=d1/2
 * 第n轮：dn=d(n-1)/2=1，此时表已经是一个大体有序的表，再次插入排序会降低时间
 * */
//希尔排序
void ShellSort(int A[], int n) {
    int d, i, j;
    //A[0]是暂存单源，不是哨兵，当j<=0时，插入位置已到
    for (d = n / 2; d >= 1; d /= 2) {       //步长变化
        for (i = d + 1; i <= n; i++) {
            if (A[i] < A[i - d]) {      //需要将A[i]插入有序增量子表，当前指向元素比上一个元素小
                A[0] = A[i];            //暂存在A[0]
                for (j = i - d; j > 0 && A[0] < A[j]; j -= d) {     //检查当前元素前边的元素是否更大，如果更大，j所指的元素后移，移到j+d
                    A[j + d] = A[j];        //记录后移，寻找插入位置
                }
                A[j + d] = A[0];        //插入
            }
        }
    }
}
/**复杂度分析
 * 空间：O(1)
 * 时间：最坏：O(n^2)，最好O(n^1.3)，无法确切证明与表述
 * 如果使d=1，则希尔排序退化为插入排序
 * */
