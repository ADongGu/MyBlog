#include "stack.h"

int main()
{
	PTree TREE = CreatExpTree();
	if (TREE == NULL)
	{
		return 0;
	}
	// ���� ǰ��������� ����д��.....

	cout << "�������(��׺���ʽ)��" << " \n";
	InTraver(TREE);

	return 0;
}