#pragma once

#include "DynamicArray.h"

// �޸𸮰� ����ϴ��� ũ�� ������ ���� ���� ����
typedef struct {
    DynamicArray* darr;
    int top;
} Stack;

// ���� ����
Stack* StkCreate();

// ������ ��� �ִٸ� 1�� ��ȯ. ���ÿ� �����Ͱ� �ִٸ� 0 ��ȯ
int StkEmpty(const Stack* stack);

// ���ÿ� e �߰�
int StkPush(Stack* stack, Element e);

// ������ ���� ���κп� �ִ� �����͸� pe�� �����ؼ� ��ȯ
// ������ ���� ���κп� �ִ� �����ʹ� ����
int StkPop(Stack* stack, Element* pe);

// ������ ���� ���κп� �ִ� �����͸� pe�� �����ؼ� ��ȯ
// ������ ���� ���κп� �ִ� �����ʹ� ���� ����
int StkTop(const Stack* stack, Element* pe);

// ������ ���� ���κп� �ִ� �����ͺ��� ������� ȭ�鿡 ���
void StkPrint(const Stack* stack, PrintFunc func);

// ���� ����
void StkDestroy(Stack* stack);