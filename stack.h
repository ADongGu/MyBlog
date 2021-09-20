#pragma once

#include"exptree.h"

typedef struct StackNode stack;
typedef stack* Pstack;

struct StackNode
{
	PTree data;
	Pstack next;
};

Pstack CreatStack();
PTree Pop(Pstack P);
int is_empty(Pstack P);
void Push(Pstack P, PTree T);


