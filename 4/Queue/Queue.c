#include "Queue.h"

Queue* QueCreate()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue) { //queue이 할당되었으면
		queue->darr = DACreate();
		if (queue->darr) { //darr이 할당되었다면 
			queue->front = 0;
			queue->rear = 0;
			return queue;
		}
		free(queue); //queue 할당됨, darr이 할당 안됨.

	}
	return NULL; //queue이 할당되지 않음
}

int QueEnqueue(Queue* queue, Element e)
{
	if (DAAdd(queue->darr, e)) {
		queue->rear++;
		return 1;
	}
	return 0;
}

int QueDequeue(Queue* queue, Element* pe)
{
	if (queue && queue->darr && DAGet(queue->darr, queue->front, pe)) {
		queue->front++;
		return 1;
	}
	return 0;
}

int QueFront(const Queue* queue, Element* pe)
{
	if (queue && queue->darr && DAGet(queue->darr, queue->front, pe)) {
		return 1;
	}
	return 0;
}

int QueEmpty(const Queue* queue)
{
	if (queue->front == queue->rear) {
		return 1;
	}
	return 0;
}

void QueDestroy(Queue* queue)
{
	DADestroy(queue->darr);
}

void QuePrint(const Queue* queue, PrintFunc func) {
	if (queue) {
		for (int i = queue->front; i < queue->rear; i++) {
			Element e;
			if (DAGet(queue->darr, i, &e)) {
				func(e);
			}
		}
	}
}