#pragma once

#include "treeNode.h"
typedef treePtr element;

#define MAX_QUEUESIZE 128
typedef struct QueueType
{
	element queue[MAX_QUEUESIZE];
	int head;
	int tail;
}QueueType;

void Init_Queue(QueueType *q_);
int Is_QueueEmpty(QueueType *q_);
int Is_QueueFull(QueueType *q_);
void Push_Queue(QueueType *q_, element item_);
element Pop_Queue(QueueType *q_);
element Peek_Queue(QueueType* q_);