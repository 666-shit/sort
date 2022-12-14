//
// Created by c1533 on 2022/10/13.
//
/**外部排序
 * 外存和内存交换数据
 * 构造初始归并段：归并排序要求各个子序列有序，每次读入两个块的内容，进行内部排序后写回磁盘
 * 磁盘有16块，需要16次读和写，也就是32次读写操作
 * 第一次归并：(缓冲区大小和磁盘每一块的大小一样)
 * 把归并段1和2的第一个子段放入缓冲区中进行排序，如果某一个归并段的子段空了，立即用下一个子段填补
 * 得到4个大的归并段(每一个段有4个子段)
 * 第二次归并：
 * 4个大段进行两两归并同上
 * 第三次归并：
 * 过程同上
 * */

/**外部排序时间开销
 * 读写外存时间+内部排序时间+内部归并所需时间
 * 归并次数下降，时间会节省
 * */

/**优化：
 * 2路归并->4路归并(多路归并)
 * 初始归并段小
 * 结论：采用多路归并可以减少归并次数，从而减少I/O次数
 *
 * 对r个初始归并段，做k路归并，则归并树可以用k叉树表示
 * 若树高为h，则归并次数=h-1=[log_kr]     k越大，r越小，归并次数越少，I/O次数越少
 *
 * 多路归并负面影响：
 * 1. 内存开销增加
 * 2. 内部归并所需时间增加
 * */
