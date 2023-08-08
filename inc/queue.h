#pragma once

#include "myMath.h"

typedef struct Queue {
	float* data;
	u8	   front, rear, size, dataCount;
} Queue;

Queue* InitQueue(u8 size);
bool   DeleteQueue(Queue* queue);

bool IfQueueEmpty(const Queue* queue);
bool IfQueueFull(const Queue* queue);

bool DeQueue(Queue* queue, float* data);
bool EnQueue(Queue* queue, float data);
