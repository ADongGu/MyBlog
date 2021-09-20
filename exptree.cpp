#include "exptree.h"
#include "stack.h"

PTree CreatExpTree()
{
	char data;
	Pstack S = CreatStack();  // �����ջ ����� ��ַ
	if (S == NULL)
	{
		return NULL;
	}

	cout << "�����룺 ��Ctrl ^z �������룩\n";

	while (cin >> data)
	{
		PTree temp = (PTree)malloc(sizeof(Tree));
		if (temp == NULL)
		{
			cout << "�ڴ泬��\n";
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

			// ��Ϊ�㹹����Ǳ��ʽ�� �� ����һ�������һ�������������ӡ��� �����ﻹ�Ǹ�����ж�һ��
			if (S->next == NULL)
			{
				cout << "�������󣬹��첻�˱��ʽ\n";
				return NULL;
			}

			temp->left = Pop(S);
			Push(S, temp);
		}
	}

	// ���� a b c + ;
	// ��������˸�a ��ջS��
	PTree ans = Pop(S);
	if (is_empty(S)) return ans;
	else 
	{
		cout << "����������ջ� �������󣬹��첻�˱��ʽ\n";
		return NULL;
	}
}

void InTraver(PTree T)
{
	if (T == NULL) return;

	/*
	* �������ȼ���һ�� ��ֹ�Ӽ��˳������ȼ�˳��
	* ���Լ������ţ�������һ�ԣ� ������һ��
	*/

	if (T->left) cout << "( ";
	InTraver(T->left);

	cout << T->data << " ";

	InTraver(T->right);
	if (T->right) cout << ") ";

}