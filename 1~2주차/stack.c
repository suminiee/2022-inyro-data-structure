#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int Push(int a, int b, int arr[]) {
	arr[a] = b;
	return 0;
}

int Pop(int a, int c, int arr) {
	if (c == '/0') {
		printf("%d\n", -1);
		return 0;
	}
	else if (c != '/0') {
		printf("%d\n", c);
		return 1;
	}
}//pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

int Size(int a) {
	printf("%d\n", a + 1);
	return 0;
} //size: 스택에 들어있는 정수의 개수를 출력한다.

int Empty(int c) {
	if (c == '/0') {
		printf("%d\n", 1);
		return 0;
	}
	else
	{
		printf("%d\n", 0);
		return 1;
	}
}//empty: 스택이 비어있으면 1, 아니면 0을 출력한다.

int Top(int c) {
	if (c != '/0') {
		printf("%d\n", c);
		return 0;
	}
	else if (c == '/0') {
		printf("%d\n", -1);
		return 1;
	}

}//스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.



int main(void) {
	int size = 0;
	char order;
	int stack[10000];//stack
	int a = 0; //현재위치?
	int b;
	int c;
	
	char str1[] = "push";
	char str2[] = "pop";
	char str3[] = "size";
	char str4[] = "empty";
	char str5[] = "top";

	scanf("%s", &order);
	

	if (strcmp(str1, order) == 0) {
		scanf("%d", &b);
		Push(a, b, stack);
		a++;
	}
	else {
		return 0;
	}
	
	if (strcmp(str2, order) == 0) {
		c = stack[a];
		Pop(a-1, c, stack);
		if (Pop(a-1, c, stack) == 1) {
			stack[a] = '/0';
			a--;
		}
	}
	else {
		return 0;
	}
	if (strcmp(str3, order) == 0) {
		Size(a);
	}
	else {
		return 0;
	}
	if (strcmp(str4, order) == 0) {
		c = stack[a];
		Empty(c);
	}
	else {
		return 0;
	}
	if (strcmp(str5, order) == 0) {
		c = stack[a];
		Top(c);
	}
	else {
		return 0;
	}
}