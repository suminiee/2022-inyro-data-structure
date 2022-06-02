#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

PTreeNode TreCreateNode(Element e) {
	TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));
	if (tree) {
		tree->data = e;
		tree->left = NULL;
		tree->right = NULL;
	}
}

PTreeNode TreCreateNode2(Element e, PTreeNode left, PTreeNode right)
{
	TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));
	if (tree) {
		tree->data = e;
		tree->right = right;
		tree->left = left;
	}
}

void TreDestroy(PTreeNode root)
{
	if (root) {
		if (root->left) {
			TreDestroy(root->left);
			root->left = NULL;
		}
		if (root->right) {
			TreDestroy(root->right);
			root->right = NULL;
		}
		free(root);
		return;
	}
	
}
//typedef void(*IterateFunc)(Element* e, void* p);
// IteratorFunc�� list�� �� ��ҿ� ����. func()�Լ��� p�� ���ڷ� ����
void TreIterate(PTreeNode root, IterateFunc func, void* p, TreeTraverseOrder order)//��,��,���� �����ϴ°� -> order.
{
	if (root)
	{
		if (order == TTO_PREORDER) //���� ���� ����ϰ� ���� ������ �Ʒ��� ������
		{
			func(&(root->data), p);
			TreIterate(root->left, func, p, TTO_PREORDER);
			TreIterate(root->right, func, p, TTO_PREORDER);
		}
		else if (order == TTO_INORDER)
		{
			
			TreIterate(root->left, func, p, TTO_INORDER); 
			func(&(root->data), p); //���� ���� �������� ���� ����ϰ� ���������� ������
			TreIterate(root->right, func, p, TTO_INORDER);
		}
		else if (order == TTO_POSTORDER)
		{
			
			TreIterate(root->left, func, p, TTO_POSTORDER);
			TreIterate(root->right, func, p, TTO_POSTORDER);
			func(&(root->data), p); //���� ���� �������� ������ �������� ���������� ���� �����.
		}
	}
}
