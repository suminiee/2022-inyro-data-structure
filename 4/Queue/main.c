#include <stdio.h>

#include "Queue.h"

void PrintInt(Element e)
{
    printf("%d\n", e);
}

int main(void)
{
    const int NUMS = 6;

    Queue* s = QueCreate();
    if (s) {
        for (int i = 0; i < NUMS; i++) {
            if (QueEnqueue(s, i) == 0) {
                printf("Failed to push an element into the given queue\n");
            }
        }
        printf("��ü ť ���\n");
        QuePrint(s, PrintInt);
        printf("ť ��Ҹ� ���� front, dequeue�� �� ���\n");
        for (int i = 0; i < NUMS; i++) {
            Element e;
            if (QueFront(s, &e) == 0) {
                printf("Failed to look at the top element of the given stack\n");
            }
            else {
                printf("Front = %d\n", e);
            }
            if (QueDequeue(s, &e) == 0) {
                printf("Failed to pop an element from the given queue\n");
            }
            else {
                printf("Dequeued = %d\n", e);
            }
        }
        QueDestroy(s);
    }
    return 0;
}