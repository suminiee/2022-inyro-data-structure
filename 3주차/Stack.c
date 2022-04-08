#include "Stack.h"

Stack* StkCreate()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack) { //stack�� �Ҵ�Ǿ�����
		stack->darr = DACreate();
		if (stack->darr) { //darr�� �Ҵ�Ǿ��ٸ� 
			stack->top = -1;
			return stack;
		}
		free(stack); //stack �Ҵ��, darr�� �Ҵ� �ȵ�.
		
	}
	return NULL; //stack�� �Ҵ���� ����
}

int StkPush(Stack* stack, Element e)
{
	stack->top++;
	if (DAAdd(stack->darr, e)) {
		return 1;
	}
	stack->top--;
	return 0;
}

int StkPop(Stack* stack, Element* pe)
{
	if (stack && stack->darr && stack->top != -1 && DAGet(stack->darr, stack->top, pe)) {
		stack->top--;
		return 1;
	}
	return 0;
}

int StkTop(const Stack* stack, Element* pe) 
{
	return stack && stack->darr && stack->top != -1 && DAGet(stack->darr, stack->top, pe);
}

int StkEmpty(const Stack* stack) // ������ ��� �ִٸ� 1�� ��ȯ. ���ÿ� �����Ͱ� �ִٸ� 0 ��ȯ
{
	if (stack->top != -1) {
		return 1;
	}
	return 0;
}

void StkDestroy(Stack* stack)
{
	DADestroy(stack->darr);
}

void StkPrint(const Stack* stack, PrintFunc func) // ������ ���� ���κп� �ִ� �����ͺ��� ������� ȭ�鿡 ���
{
	if (stack) {
		for (int i = stack->top; i >= 0; i--) {
			Element e;
			if (DAGet(stack->darr, i, &e)) {
				func(e);
			}
		}
	}
}

