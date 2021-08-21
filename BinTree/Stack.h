#pragma once

#include "treeNode.h"
typedef treePtr element;

#define MAX_STACKSIZE 128

typedef struct StackType
{
	element stack[MAX_STACKSIZE];
	int top;
}StackType;

void Init_Stack(StackType* s_);
int Is_StackEmpty(StackType* s_);
int Is_StackFull(StackType* s_);
void Push_Stack(StackType* s_, element item_);
element Pop_Stack(StackType* s_);
element Peek_Stack(StackType* s_);
