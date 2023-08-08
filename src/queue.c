#include "../inc/queue.h"

Queue* InitQueue(u8 size)
{
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	if (!queue)
		return NULL;

	queue->data = (float*) malloc(sizeof(float) * size);
	if (!queue->data) {
		free(queue);
		return NULL;
	}

	queue->front = queue->rear = queue->dataCount = 0;
	queue->size									  = size;

	return queue;
}

bool IfQueueEmpty(const Queue* queue) { return (queue->front == queue->rear); };
bool IfQueueFull(const Queue* queue) { return ((queue->rear + 1) % (queue->size)) == queue->front; };

bool DeQueue(Queue* queue, float* data)
{
	if (IfQueueEmpty(queue))
		return false;

	*data = queue->data[queue->front];
	queue->front++;
	queue->front %= queue->size;

	queue->dataCount--;

	return true;
};

bool EnQueue(Queue* queue, float data)
{
	if (IfQueueFull(queue))
		return false;

	queue->data[queue->rear++]	= data;
	queue->rear				   %= queue->size;

	queue->dataCount++;

	return true;
};
