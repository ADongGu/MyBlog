#include "stack.h"

int main()
{
	PTree TREE = CreatExpTree();
	if (TREE == NULL)
	{
		return 0;
	}
	// 后序 前序代码相差不大， 懒得写了.....

	cout << "中序遍历(中缀表达式)：" << " \n";
	InTraver(TREE);

	return 0;
}