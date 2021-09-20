#pragma once

#include<iostream>
using std::cout;
using std::cin;

typedef struct ExpTree Tree;
typedef Tree* PTree;

struct ExpTree
{
	char data;
	PTree left;
	PTree right;
};

PTree CreatExpTree();
void InTraver(PTree T);

