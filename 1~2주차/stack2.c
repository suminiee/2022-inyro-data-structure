#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int Push(int a, int b, int arr[]) {
	arr[a] = b;
	return 0;
}

int Pop(int a, int c, int arr) {
	if (c == '/0') {
		return 0;
	}
	else if (c != '/0') {
		return 1;
	}
}

int Size(int a) {
	printf("%d\n", a + 1);
	return 0;
}

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
}

int Top(int c) {
	if (c != '/0') {
		printf("%d\n", c);
		return 0;
	}
	else if (c == '/0') {
		printf("%d\n", -1);
		return 1;
	}

}


int main(void) {
	int num_order = 0;
	int i = 0;
	int stack[1000];
	int size = 0;
	char order[1000];
	int a = 0; //현재위치?
	int b = 0;
	int c;
	int top_num = 0;

	char str1[] = "push";
	char str2[] = "pop";
	char str3[] = "size";
	char str4[] = "empty";
	char str5[] = "top";

	scanf("%d", &num_order);



	do{
		scanf("%s", &order);

		if (strcmp(str1, order) == 0) {
			scanf("%d", &b);
			Push(a, b, stack);
			a++;
		}
		
		else if (strcmp(str2, order) == 0) {
			c = stack[a-1];
			if (Pop(a - 1, c, stack) == 1) {
				if (a > 0) {
					printf("%d\n", c);
					a--;
				}
				else
					printf("%d\n", -1);
			}
			else if (Pop(a - 1, c, stack) == 0) {
				printf("%d\n", -1);
			}
		} //pop부분 size로 바꾸기
		
		else if (strcmp(str3, order) == 0) {
			Size(a-1);
		}

		else if(strcmp(str4, order) == 0) {
			if (a > 0) {
				c = stack[a - 1];
				Empty(c);
			}
			else {
				printf("%d\n", 1);
			}
		}

		if (strcmp(str5, order) == 0) {
			if (a > 0) {
				c = stack[a - 1];
				Top(c);
			}
			else {
				printf("%d\n", -1);
			}
		}

		
		i++;
	} while (i<=num_order);
}