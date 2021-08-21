#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

inline void Init_Queue(QueueType *q_)
{
	//memset(&q_->queue, 0x00, sizeof(element) * MAX_QUEUESIZE);
	q_->head = q_->tail = 0;
}

inline int Is_QueueEmpty(QueueType *q_)
{
	return (q_->head == q_->tail);
}

inline int Is_QueueFull(QueueType *q_)
{
	return (q_->head == (q_->tail + 1) % MAX_QUEUESIZE);
}

void Push_Queue(QueueType *q_, element item_)
{
	if (!q_)
	{
		fprintf(stderr, "ERROR: nullptr exception.");
	}

	if (Is_QueueFull(q_))
	{
		fprintf(stderr, "ERROR : Queue is full.");
		return;
	}

	q_->tail = (q_->tail + 1) % MAX_QUEUESIZE;
	q_->queue[q_->tail] = item_;
}

element Pop_Queue(QueueType *q_)
{
	if (!q_)
	{
		fprintf(stderr, "ERROR: nullptr exception.");
		exit(1);
	}

	if (Is_QueueEmpty(q_))
	{
		fprintf(stderr, "ERROR: Queue is Empty.");
		exit(1);
	}

	q_->head = (q_->head + 1) % MAX_QUEUESIZE;
	return q_->queue[q_->head];
}

element Peek_Queue(QueueType* q_)
{
	if (!q_)
	{
		fprintf(stderr, "ERROR: nullptr exception.");
		exit(1);
	}

	if (Is_QueueEmpty(q_))
	{
		fprintf(stderr, "ERROR: Queue is Empty.");
		exit(1);
	}

	return q_->queue[q_->head];
}