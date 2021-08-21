#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

void Init_Stack(StackType* s_)
{
	s_->top = -1;
}

int Is_StackEmpty(StackType* s_)
{
	return (-1 == s_->top);
}

int Is_StackFull(StackType* s_)
{
	return (MAX_STACKSIZE - 1 == s_->top);
}

void Push_Stack(StackType* s_, element item_)
{
	if (!s_)
	{
		fprintf(stderr, "ERROR: nullptr exception.");
		return;
	}

	if (Is_StackFull(s_))
	{
		fprintf(stderr, "ERROR: Stack Overflow.\n");
		return;
	}
	else
		s_->stack[++s_->top] = item_;
}

element Pop_Stack(StackType* s_)
{
	if (!s_)
	{
		fprintf(stderr, "ERROR: nullptr exception.");
		exit(1);
	}

	if (Is_StackEmpty(s_))
	{
		fprintf(stderr, "ERROR: Stack Underflow.\n");
		exit(1);
	}
	else
		return s_->stack[s_->top--];
}

element Peek_Stack(StackType* s_)
{
	if (!s_)
	{
		fprintf(stderr, "ERROR: nullptr exception.");
		exit(1);
	}

	if (Is_StackEmpty(s_))
	{
		fprintf(stderr, "ERROR: Stack Underflow.\n");
		exit(1);
	}
	else
		return s_->stack[s_->top];
}
