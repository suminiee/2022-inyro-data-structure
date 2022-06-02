#pragma once

#include "DAType.h"

typedef struct _Node {
    Element element;
    struct _Node* next;
} ListNode;

typedef struct {
    ListNode* head; // ���� ù ��° ��带 ����Ŵ
    ListNode* tail; // ���� ������ ��带 ����Ŵ
} List;

typedef void (*PrintFunc)(Element e);

// e1�� e2�� �����ϸ� 1�� ��ȯ�ϰ� �ƴϸ� 0�� ��ȯ
typedef int (*CompareFunc)(const Element* e1, const Element* e2);

typedef void (*IterateFunc)(Element* e, void* p);

// List�� ������ �� ��ȯ. ���� �Ҵ��� ����� �ȵǸ� NULL��ȯ
List* LstCreate();

// ����Ʈ�� ��Ұ� ������ 0, ������ 1�� ��ȯ
int LstEmpty(const List* list);

// list�� ������ ��ҷ� e�� ����. ListNode�� ���� ���� �Ҵ���
// �߰��� �����ϸ� 1 ��ȯ. �ƴϸ� 0 ��ȯ
int LstAddToEnd(List* list, Element e);

// list�� ù ��° ��ҷ� e�� ����. ListNode�� ���� ���� �Ҵ���
// �߰��� �����ϸ� 1 ��ȯ. �ƴϸ� 0 ��ȯ
int LstAddToFront(List* list, Element e);

// list�� next��尡 �ִٸ�, next �տ� e�� ����. �����ϸ� 1, �����ϸ� 0�� ��ȯ
// list�� next�� ������ 0 ��ȯ
int LstInsertBefore(List* list, ListNode* next, Element e);

// list�� next��尡 �ִٸ�, previous �ڿ� e�� ����. �����ϸ� 1, �����ϸ� 0�� ��ȯ
// list�� previous�� ������ 0 ��ȯ
int LstInsertAfter(List* list, ListNode* previous, Element e);

// func�� �̿��ؼ� list�� ��� ��Ҹ� ���
void LstPrint(List* list, PrintFunc func);

// list���� node�� ����. �����ϸ� 1�� ��ȯ. �����ϸ� 0�� ��ȯ
int LstDelete(List* list, ListNode* node);

// list���� e�� �˻��ؼ� ������ e�� �ش� ��带 ��ȯ. Element�� ���ϴ� ���� CompareFunc�� �̿�
// ���� �ش� ��尡 ������ NULL ��ȯ
ListNode* LstFindNode(List* list, Element e, CompareFunc func);

// IteratorFunc�� list�� �� ��ҿ� ����. func()�Լ��� p�� ���ڷ� ����
void LstIterate(List* list, IterateFunc func, void* p);

// list�� �ִ� ��� ��Ҹ� �����ϰ� ���� �Ҵ�� �޸� ����
void LstDestroy(List* list);

