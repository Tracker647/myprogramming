package com.zhang.chapter60;

/**
 * 总结
 * 1.事件驱动模拟：对碰撞先后顺序用优先队列，实现基于事件驱动模拟
 * 2.B树：一种对2-3树的扩展，一个结点可以包含多个键，插入删除类似于2-3树，每个结点包含了值的信息（可以对应文件信息）
 *   B+树：对B树的变形，值的信息仅存在于叶子结点（对于文件系统可以有效减少IO操作）
 *   参考博客：https://www.cnblogs.com/guohai-stronger/p/9225057.html
 * 3.后缀数组：将一个字符串的所有后缀数组排序，查找最长重复子字符串（排序后最长公共字串存在于两个相邻字符串中）
 * 4.最大st-流量：给定一个st-流量网络，找到一种st-流量配置，使得从s到t的流量最大化
 * 5.Ford-Fulkerson算法（增广路径）：依次填充所有边中未使用的流量的最小值，直到所有起点到终点至少有一条边是饱和的
 * 6.剩余网络：
 * 7.最短增广路径的Ford-Fulkerson最大流量算法：增广路径的查找等价于剩余网络中的广度优先搜索
 */
public class AnswerList {
}
