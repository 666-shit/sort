//
// Created by c1533 on 2022/10/7.
//
//代码为重点，手写
/**代码考察频率最高*/

/**快排算法思想：
 * 待排序表中任取一个元素作为基准(通常取首元素)，通过一趟排序将待排序表分为两个部分
 * 一部分(L[1…k-1])所有元素小于基准，另一部分(L[k+1…n])所有元素大于基准，基准在k位置上
 * 第一次划分完成，后续分别递归对两个子表重复以上过程，直到每部分内只有一个元素或空为止
 *
 * low指针和high指针分别指向表头和表尾，取出low指针所指位置的元素作为基准
 * 则low指针左侧元素应当小于基准，high右侧元素应该大于基准
 * 此时low指针空，high指针左移，遇到小于基准，的元素，放到low指针所指位置
 * 此时high指针空，low指针右移，如果小于基准，则继续右移，直到大于基准为止
 * 遇到大于基准的元素，放到high指针为止，重复以上步骤
 * 当两个指针指向同一位置，放入基准元素，第一轮划分完成
 * 然后分别对左，右子表划分，步骤同上，递归完成
 * */

//快排
int Partition(int A[], int low, int high){
    int pivot = A[low];     //取基准元素
    while(low < high){
        while(low < high && A[high]>=pivot)     //当low=high时，会跳出循环
            high--;     //high左移
        A[low] = A[high];       //小于基准的放到low位置
        while(low<high && A[low]<=pivot)
            low++;      //low右移
        A[high] = A[low];       //大于基准的放到high位置
    }
    A[low] = pivot; //基准元素最后放到此位置(low=high)
    return low;
}

void QuickSort(int A[],int low, int high){
    if(low<high){
        int pivotpos=Partition(A, low, high);   //进行划分，Partition返回的值(low)赋值给pivotpos
        QuickSort(A,low,pivotpos-1);    //左子表
        QuickSort(A,pivotpos+1,high);   //右子表
    }
}

/**复杂度分析
 * 空间：好：O(log_2n); 坏：O(n^2); O(递归层数)    最坏情况：本来就是排好序的，但是快排还是要排序
 * 时间：好：O(n*log_2n); 坏：O(n^2); O(n*递归层数)    实际应用中接近最好的实际复杂度
 * 每一次quick sort后，都会进行二分，最后相当于二叉树
 * 二叉树的层数就是递归调用的层数
 *
 * 若每一次选中的基准将待排序序列划分成均匀的两个部分，则时间空间复杂度最优，效率最高
 * 不稳定排序
 * */

/**优化：
 * 1. 选头，中，尾三个位置的元素，取中间值作为基准
 * 2. 随机选一个元素作为基准
 * */
