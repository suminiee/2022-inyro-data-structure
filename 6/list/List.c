#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "List.h"


// List�� ������ �� ��ȯ. ���� �Ҵ��� ����� �ȵǸ� NULL��ȯ
List* LstCreate()
{
	List* list = (List*)malloc(sizeof(List));
	if (list){
		list->head = NULL;
		list->tail = NULL;
		return list;
	}
	return NULL;
}

// ����Ʈ�� ��Ұ� ������ 0, ������ 1�� ��ȯ
int LstEmpty(const List* list)
{
	if (list && list->head != NULL && list->tail != NULL)
	{
		return 0;
	}
	else
		return 1;
}

//���ο� node�� �����ϴ� �Լ�
static ListNode* CreateNode(Element e)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node) {
		node->element = e;
		node->next = NULL;
	}
	return node;
}



// list�� ������ ��ҷ� e�� ����. ListNode�� ���� ���� �Ҵ���
// �߰��� �����ϸ� 1 ��ȯ. �ƴϸ� 0 ��ȯ
/*int LstAddToEnd(List* list, Element e)
{
	ListNode* node = CreateNode(e);
	if (node) {
		if (LstEmpty(list)) {
			list->head = node;
			list->tail = node;
			return 1;
		}
		else {
			list->tail->next = node;
			list->tail = node;
			return 1;
		}
	}
	return 0;
}*/

int LstAddToEnd(List* list, Element e)
{
	if (list) {
		ListNode* node = CreateNode(e);
		if (node) {
			if (list->tail) {
				list->tail->next = node;
				list->tail = node;
				return 1;
			}
			else {
				list->tail = node;
				if (list->head == NULL) {
					list->head = node;
				}
				return 1;
			}
		}
		return 0;
	}
}


// list�� ù ��° ��ҷ� e�� ����. ListNode�� ���� ���� �Ҵ���
// �߰��� �����ϸ� 1 ��ȯ. �ƴϸ� 0 ��ȯ
int LstAddToFront(List* list, Element e)
{
	ListNode* node = CreateNode(e);
	if (node) {
		if (list->head) {
			node->next = list->head; // node�� next�� head�� �������� ����Ű�� �ϸ� �ȴ�.
			list->head = node;
			list->tail = node;
			return 1;
		} //list�� ���ٸ� head�� tail�� ���� ���� ��带 ����Ű�� �ϸ� ��
		else {
			list->head = node;
			if (list->tail == NULL) {
				list->tail = node;
			}
			return 1;
		}
	}
	return 0;
}



//list�� node�� ���� ��带 ã�� �Լ�
static ListNode* FindPreviousNode(List* list, ListNode* node)
{
	ListNode* current = list->head; //head�� ����Ű�� current�� �����
	while (current) {
		if (current->next == node) // current�� next�� ����Ű�°� node�� current�� node�� ���� ��尡 �ȴ�.
			return current;
		current = current->next;
	}
	return NULL;
}

//list�� node�� �ִ��� Ȯ���ϴ� �Լ�
static int IsInList(List* list, ListNode* node)
{
	ListNode* current = list->head;
	while (current) {
		if (current == node) return 1; //list�ȿ� node�� �ִٸ� 1 ��ȯ
		current = current->next;
	}
	return 0; //���ٸ� 0 ��ȯ
}

//if (list) Ȯ�����ֱ�!
// list�� next��尡 �ִٸ�, next �տ� e�� ����. �����ϸ� 1, �����ϸ� 0�� ��ȯ
// list�� next�� ������ 0 
/*int LstInsertBefore(List* list, ListNode* next, Element e)
{
	if (IsInList(list, next)) {
		ListNode* p_node = FindPreviousNode(list, next);
		ListNode* node = CreateNode(e);

		if (p_node) {
			if (node) {
				node->next = list->head->next;
				list->head->next = node;
				node->element = e;
				return 1;
			}
			return 0;
		}
		return 0;
	}
	return 0;
}*/

int LstInsertBefore(List* list, ListNode* next, Element e)
{
	if (list && next && IsInList(list, next)) {
		ListNode* node = CreateNode(e);
		if (node) {
			node->next = next;
			ListNode* previous = FindPreviousNode(list, next);
			if (previous) {
				previous->next = node;
			}
			else {
				if (next == list->head) {
					list->head = node;
				}
			}
			return 1;
		}
	}
	return 0;
}


// list�� next��尡 �ִٸ�, previous �ڿ� e�� ����. �����ϸ� 1, �����ϸ� 0�� ��ȯ
// list�� previous�� ������ 0 ��ȯ
/*int LstInsertAfter(List* list, ListNode* previous, Element e)
{
	ListNode* node = CreateNode(e);
	if (node) {
		if (list->head == NULL) //����Ʈ�� ������ ���
		{
			node->next = NULL;
			list->head = node;
		}
		else if (previous == NULL) //������ previous�� ������ ��� ù��° ���� ������ �Ǵ°ǰ�?
		{
			node->next = list->head;
			list->head = node;
			//return 0; <-?
		}
		else
		{
			node->next = previous->next;
			previous->next = node;
		}
		return 1;
	}
	return 0;
}*/

int LstInsertAfter(List* list, ListNode* previous, Element e)
{
	if (list && IsInList(list, previous)) {
		ListNode* node = CreateNode(e);
		if (node) {
			node->next = previous->next;
			previous->next = node;
			return 1;
		}
	}
	return 0;
}

// func�� �̿��ؼ� list�� ��� ��Ҹ� ���
void LstPrint(List* list, PrintFunc func) //->?
{
	ListNode* p;
	p = list->head;
	while (p)
	{
		func(p->element);
		p = p->next;
	}
	return;
}


// list���� node�� ����. �����ϸ� 1�� ��ȯ. �����ϸ� 0�� ��ȯ
/*int LstDelete(List* list, ListNode* node)
{
	ListNode* previous;
	if (list->head == NULL) // ���� ����Ʈ
		return 0;
	if (list->head->next = NULL) // ����Ʈ�� ��尡 �ϳ��� ���� ��
	{
		free(list->head); //ù��° ��� �޸𸮿��� ����
		list->head = NULL;//����Ʈ ���� �����͸� NULL����
		list->tail = NULL;
		return 1; //���������� 1 ��ȯ
	}
	else if (node == NULL) //������ ��尡 ���ٸ�
		return 0;
	else
	{
		previous = list->head; //������ ����� ���� ��� 
		while (previous->next != node)
		{
			previous = previous->next;
		}
		previous->next = node->next; //������ ����� ���� ����, ������ ����� ���� ��带 ����
		free(node); //������ ����� �޸� ����
		return 1;
	}
	
	return 0;
}*/

int LstDelete(List* list, ListNode* node)
{
	if (list)
	{
		if (node == list->head) {
			if (list->head->next) {
				list->head = list->head->next;
			}
			else {
				list->tail = NULL;
				list->head = NULL;
			}
			free(node);
			return 1;
		}
		else {
			ListNode* n = FindPreviousNode(list, node);
			if (n) {
				n->next = node->next;
				if (node == list->tail)
				{
					list->tail = n;

				}
			}
			free(node);
			return 1;
		}
	}
	return 0;
}
// list���� e�� �˻��ؼ� ������ e�� �ش� ��带 ��ȯ. Element�� ���ϴ� ���� CompareFunc�� �̿�
// ���� �ش� ��尡 ������ NULL ��ȯ
/*ListNode* LstFindNode(List* list, Element e, CompareFunc func)
{
	ListNode* p;
	p = list->head;
	while (p != NULL)
	{
		if (func(&(p->element), &e)) //strcmp..?
		{
			return p;
		}
		else
			p = p->next;
	}
	return NULL;
}*/

ListNode* LstFindNode(List* list, Element e, CompareFunc func)
{
	if (list) {
		ListNode* current = list->head;
		while (current) {
			if (func(&(current->element), &e)){
				return current;
			}
			current = current->next;
		}
	}
	return NULL;
}

// IteratorFunc�� list�� �� ��ҿ� ����. func()�Լ��� p�� ���ڷ� ����
void LstIterate(List* list, IterateFunc func, void* p) //�ݺ�?
{
	if (list) {
		ListNode* current = list->head;
		while (current)
		{
			func(&(current->element), p);
			current = current->next;
		}
	}
}

// list�� �ִ� ��� ��Ҹ� �����ϰ� ���� �Ҵ�� �޸� ����
/*void LstDestroy(List* list)
{
	ListNode* p;
	
	if (list->head == NULL) //�� ����Ʈ���
		free(list);
	else if (list->head->next == NULL) //����Ʈ�� �ϳ����
	{
		free(list);
		list->head = NULL;
	}
	else
	{
		p = list->head;
		while (list->head != NULL)
		{
			
			p = p->next;
			list->head = NULL;
			free(list->head);
			list->head = p;
		}
	}
}*/

void LstDestroy(List* list)
{
	if (list)
	{
		ListNode* temp = list->head;
		while (temp) {
			ListNode* next = temp->next;
			free(temp);
			temp = next;
		}
		free(list);
	}
}