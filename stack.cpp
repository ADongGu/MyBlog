#include "stack.h"

Pstack CreatStack()
{
	Pstack S = (Pstack)malloc(sizeof(stack));
	if (S == NULL) return NULL;

	S->next = NULL;
	return S;
}

int is_empty(Pstack P)
{
	if (P->next == NULL) return 1;
	else return 0;
}

void Push(Pstack P, PTree T)
{
	Pstack temp = (Pstack)malloc(sizeof(stack));
	temp->data = T;
	temp->next = P->next;
	P->next = temp;
}

PTree Pop(Pstack P)
{
	PTree T = (PTree)malloc(sizeof(Tree));
	Pstack temp = (Pstack)malloc(sizeof(stack));

	// �����ǿ�ָ�룬 Ҳ���Ը���������ַ�� ��Ϊ������ָ�����
	// ���ԾͲ���ȡ�ж����Ƿ�Ϊ��

	temp = P->next;

	T->data = temp->data->data;
	T->left = temp->data->left; 
	T->right = temp->data->right;

	P->next = temp->next;

	free(temp);

	return T;
}