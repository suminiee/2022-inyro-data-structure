#include "Stack.h"

Stack* StkCreate()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack) { //stack이 할당되었으면
		stack->darr = DACreate();
		if (stack->darr) { //darr이 할당되었다면 
			stack->top = -1;
			return stack;
		}
		free(stack); //stack 할당됨, darr이 할당 안됨.
		
	}
	return NULL; //stack이 할당되지 않음
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

int StkEmpty(const Stack* stack) // 스택이 비어 있다면 1을 반환. 스택에 데이터가 있다면 0 반환
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

void StkPrint(const Stack* stack, PrintFunc func) // 스택의 가장 윗부분에 있는 데이터부터 순서대로 화면에 출력
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

