#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "List.h"


// List를 생성한 후 반환. 동적 할당이 제대로 안되면 NULL반환
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

// 리스트에 요소가 있으면 0, 없으면 1을 반환
int LstEmpty(const List* list)
{
	if (list && list->head != NULL && list->tail != NULL)
	{
		return 0;
	}
	else
		return 1;
}

//새로운 node를 생성하는 함수
static ListNode* CreateNode(Element e)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node) {
		node->element = e;
		node->next = NULL;
	}
	return node;
}



// list의 마지막 요소로 e를 삽입. ListNode를 새로 동적 할당함
// 추가에 성공하면 1 반환. 아니면 0 반환
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


// list의 첫 번째 요소로 e를 삽입. ListNode를 새로 동적 할당함
// 추가에 성공하면 1 반환. 아니면 0 반환
int LstAddToFront(List* list, Element e)
{
	ListNode* node = CreateNode(e);
	if (node) {
		if (list->head) {
			node->next = list->head; // node의 next가 head와 같은것을 가리키게 하면 된다.
			list->head = node;
			list->tail = node;
			return 1;
		} //list가 없다면 head와 tail이 새로 만든 노드를 가리키게 하면 됨
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



//list의 node의 이전 노드를 찾는 함수
static ListNode* FindPreviousNode(List* list, ListNode* node)
{
	ListNode* current = list->head; //head를 가리키는 current를 만들고
	while (current) {
		if (current->next == node) // current의 next가 가리키는게 node면 current는 node의 이전 노드가 된다.
			return current;
		current = current->next;
	}
	return NULL;
}

//list에 node가 있는지 확인하는 함수
static int IsInList(List* list, ListNode* node)
{
	ListNode* current = list->head;
	while (current) {
		if (current == node) return 1; //list안에 node가 있다면 1 반환
		current = current->next;
	}
	return 0; //없다면 0 반환
}

//if (list) 확인해주기!
// list에 next노드가 있다면, next 앞에 e를 삽입. 성공하면 1, 실패하면 0을 반환
// list에 next가 없으면 0 
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


// list에 next노드가 있다면, previous 뒤에 e를 삽입. 성공하면 1, 실패하면 0을 반환
// list에 previous가 없으면 0 반환
/*int LstInsertAfter(List* list, ListNode* previous, Element e)
{
	ListNode* node = CreateNode(e);
	if (node) {
		if (list->head == NULL) //리스트가 공백일 경우
		{
			node->next = NULL;
			list->head = node;
		}
		else if (previous == NULL) //포인터 previous가 공백일 경우 첫번째 노드로 넣으면 되는건가?
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

// func를 이용해서 list의 모든 요소를 출력
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


// list에서 node를 삭제. 성공하면 1을 반환. 실패하면 0을 반환
/*int LstDelete(List* list, ListNode* node)
{
	ListNode* previous;
	if (list->head == NULL) // 공백 리스트
		return 0;
	if (list->head->next = NULL) // 리스트에 노드가 하나만 있을 때
	{
		free(list->head); //첫번째 노드 메모리에서 해제
		list->head = NULL;//리스트 시작 포인터를 NULL으로
		list->tail = NULL;
		return 1; //성공했으니 1 반환
	}
	else if (node == NULL) //삭제할 노드가 없다면
		return 0;
	else
	{
		previous = list->head; //삭제할 노드의 이전 노드 
		while (previous->next != node)
		{
			previous = previous->next;
		}
		previous->next = node->next; //삭제할 노드의 이전 노드와, 삭제할 노드의 다음 노드를 연결
		free(node); //삭제할 노드의 메모리 해제
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
// list에서 e를 검색해서 있으면 e를 해당 노드를 반환. Element를 비교하는 것은 CompareFunc를 이용
// 만약 해당 노드가 없으면 NULL 반환
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

// IteratorFunc를 list의 각 요소에 적용. func()함수에 p를 인자로 전달
void LstIterate(List* list, IterateFunc func, void* p) //반복?
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

// list에 있는 모든 요소를 삭제하고 동적 할당된 메모리 해제
/*void LstDestroy(List* list)
{
	ListNode* p;
	
	if (list->head == NULL) //빈 리스트라면
		free(list);
	else if (list->head->next == NULL) //리스트가 하나라면
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