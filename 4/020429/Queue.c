#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int Push(int a, int b, int arr[])
{
	arr[a] = b;
	return 0;
}

int Pop(int b)
{
	if (b == '\0')
		return 0;
	else if (b != '\0')
		return 1;
}

int Size(int a, int b)
{
	printf("%d\n", b - a);
}

void Empty(int a, int b)
{
	if (a == b){
		printf("%d", 1);
		return;
	}
	else if (a != b)
	{
		printf("%d", 0);
		return;
	}
	//size�� �ص� �ȴ�
}

int Front(int a, int arr[])
{
	if (arr[a] != '\0') {
		printf("%d\n", arr[a]);
	}
	else if (arr[a] == '\0')
		printf("%d\n", -1);
}

int Back(int a, int arr[])
{
	if (arr[a-1] != '\0')
		printf("%d\n", arr[a-1]);
	else if (arr[a-1] == '\0')
		printf("%d\n", -1);

}


int main(void) {
	//����[�迭]
	int queue[100];
	char order[20]; 

	//����[��ü]
	int i = 0; //numorder
	int numorder;
	int first = 0; //ť�� ù��° �κ��� ����Ű��
	int last = 0; //ť�� ������ �κ��� ����Ű��
	int size = 0;

	//����[push]
	int pushnum;

	//����[Pop]
	int pop;

	char str1[] = "push";
	char str2[] = "pop";
	char str3[] = "size";
	char str4[] = "empty";
	char str5[] = "front";
	char str6[] = "back";

	scanf("%d", &numorder);

	do
	{
		scanf("%s", &order);

		if (strcmp(str1, order) == 0)//push
		{
			scanf("%d", &pushnum);
			Push(last, pushnum, queue);
			last++;
			i++;
			//printf("last = %d\n", last);
		}

		if (strcmp(str2, order) == 0) //pop
		{
			pop = queue[first];

			if (Pop(pop) == 0)
				printf("%d\n", -1);
			if (Pop(pop) == 1)
			{
				printf("%d\n", pop);
				first++;
			}

			i++;
		}

		if (strcmp(str3, order) == 0) //Size
		{
			Size(first,last);
			i++;
		}

		if (strcmp(str4, order) == 0) //Empty
		{
			Empty(first, last);
			i++;
		}

		if (strcmp(str5, order) == 0) //Front
		{
			Front(first, queue);
			i++;
		}

		if (strcmp(str6, order) == 0) //Back
		{
			Back(last, queue);
			i++;
		}
	} while (i <= numorder);

}