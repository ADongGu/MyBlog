#include "exptree.h"
#include "stack.h"

PTree CreatExpTree()
{
	char data;
	Pstack S = CreatStack();  // 这里的栈 存的是 地址
	if (S == NULL)
	{
		return NULL;
	}

	cout << "请输入： （Ctrl ^z 结束读入）\n";

	while (cin >> data)
	{
		PTree temp = (PTree)malloc(sizeof(Tree));
		if (temp == NULL)
		{
			cout << "内存超限\n";
			return NULL;
		}

		if ('a' <= data && data <= 'z') {
			temp->data = data;
			temp->left = temp->right = NULL;
			Push(S, temp);
		}
		else {
			temp->data = data;

			temp->right = Pop(S); // return tree;

			// 因为你构造的是表达式树 ， 所以一个运算符一定有两个“儿子”， 在这里还是给大家判断一下
			if (S->next == NULL)
			{
				cout << "输入有误，构造不了表达式\n";
				return NULL;
			}

			temp->left = Pop(S);
			Push(S, temp);
		}
	}

	// 例如 a b c + ;
	// 它最后还留了个a 在栈S里
	PTree ans = Pop(S);
	if (is_empty(S)) return ans;
	else 
	{
		cout << "还有数据在栈里， 输入有误，构造不了表达式\n";
		return NULL;
	}
}

void InTraver(PTree T)
{
	if (T == NULL) return;

	/*
	* 括号优先级高一点 防止加减乘除的优先级顺序
	* 所以加上括号，左子树一对， 右子树一对
	*/

	if (T->left) cout << "( ";
	InTraver(T->left);

	cout << T->data << " ";

	InTraver(T->right);
	if (T->right) cout << ") ";

}