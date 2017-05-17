/* 定义线性表的动态分配顺序存储结构 */

#define LIST_INIT_SIZE 10	// 存储空间的初始分配量
#define LIST_INCREMENT 2	// 存储空间的分配增量

typedef struct {
	ElemType *data;	// 储存空间基址
	int maxSize;	// 可容纳元素的总个数
	int len;	// 有效元素的个数
}List, *pList;
