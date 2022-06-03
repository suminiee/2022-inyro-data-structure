#define _CRT_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

Element BSTreFindMinValue(PTreeNode root);

PTreeNode BSTreInsert(PTreeNode root, Element e, CompareElement compare) // compare => ������ ũ�� 1�� ��ȯ, �ƴ� ��� -1�� ��ȯ.
{
	if (root)
	{
		if (compare(&(root->data), &(e)))//root->data���� �� Ŭ ���
		{
			root->left = BSTreInsert(root->left, e, compare);
		}
		else //root->data���� �� ���� ���
		{
			root->right = BSTreInsert(root->right, e, compare);
		}
		return root;
	}
	return TreCreateNode(e); //���ο� node�� ���� root���� �־���.
}


PTreeNode BSTreSearch(PTreeNode root, Element e, CompareElement compare)
{
	if (root)
	{
		if (compare(&(root->data), &(e)) == 0) //root->data = e �� ���
		{
			return root;
		}
		
		else if (compare((&root->data), &(e))) //root->data > e => e�� ���� �Ʒ� ��忡 ����
		{
				BSTreSearch(root->left, e, compare);
		}
		else //root->data < e => e�� ������ �Ʒ� ��忡 ����
		{
				BSTreSearch(root->right, e, compare);
		}
		printf("ã�� e���� �������� �ʽ��ϴ�.\n");
	}

}

//�����Ҷ� �������� �� ���� �Ʒ� �ڽ� ��� or ������ �� ������ �Ʒ� �ڽ� ��带 ��� ��������ָ� ��.
//1. ������ ��尡 ���� ���, 2. ������ ��忡�� �ڽ� ��尡 ���� ���, 3. ������ ��忡�� �ڽ� ��尡 1���� ���, 4. ������ ��忡�� �ڽ� ��尡 2���� ���
/*PTreeNode BSTreDelete(PTreeNode root, Element e, CompareElement compare)
{
	TreeNode* node = root; //ã������ ���
	TreeNode* p = NULL; //ã������ ����� �θ���
	TreeNode* c = NULL; //�ڽĳ�� ������ ���
	TreeNode* a = NULL;
	TreeNode* b = NULL;

	if (root) {
		while (node != NULL && node->data != e)
		{
			p = node; //�θ���
			if (e < node->data)
			{
				node = node->left;
			}
			else
				node = node->right;
		}

		if (node == NULL) //������ ��� ���� ���� ���
		{
			printf("ã�� ���� ����Ʈ���� �������� �ʽ��ϴ�.\n");
			return;
		}

		//������ ��忡�� �ڽ� ��尡 ���� ���
		if (node->left == NULL && node->right == NULL)
		{
			if (p != NULL)
			{
				if (p->left == node)
					p->left = NULL;
				else
					p->right = NULL;
			}

			else
				root = NULL; //������ ��尡 root�ΰ��
		}

		//������ ��忡�� �ڽ� ��尡 �Ѱ��� ���
		else if (node->left == NULL || node->right == NULL)
		{
			if (node->left != NULL) //������ ����ְ� ���� ���� ����ִ�
				c = node->left;
			else
				c = node->right;

			if (p != NULL) //�θ��尡 �����Ѵٸ�
			{
				if (p->left == node) //���� �θ����� ������ ������� �����
					p->left = c; //���ص� ��� c�� �θ����� �����̶� ����
				else
					p->right = c;
			}

			else
				root = c;
		}

		//������ ��忡�� �ڽ� ��尡 �ΰ��� ���
		//else if (node->left != NULL && node->right != NULL)
		//ū ���߿� ���� ���� �� -> �ѹ� ���������� ���ٰ� �ٽ� �������� �� ��������
		else
		{
			a = p;
			b = node->right; //ū���߿� ���� ���� ���� ã��������..
			while (b->left != NULL)
			{
				a = b;
				b = b->left;
			} //b�� ������ node���� ū ���� ���� ���� ���� ��Ÿ����, a�� b�� �θ��带 ����Ŵ.

			if (b->left == NULL && b->right == NULL)
			{
				if (p->left == node)
					p->left = b;
				else
					p->right = b;
			}

			else if (b->left == NULL && b->right != NULL)
			{
				if (p->left == node)
					p->left = b;
				else
					p->right = b;
				//b->right�� ���� �������ұ�,,,?
				a->left = b->right;

			}
			else
				root = root->right;
		}

		free(node);
		
	}*/
Element BSTreFindMinValue(PTreeNode root) {
	if (root->left == NULL) {
		return root->data;
	}
	return BSTreFindMinValue(root->left);
}


PTreeNode BSTreDelete(PTreeNode root, Element e, CompareElement compare)
{
	if (root == NULL) return root;

	int n = compare(&e, &(root->data));
	if (n < 0) {
		root->left = BSTreDelete(root->left, e, compare);
	}
	else if (n > 0) {
		root->right = BSTreDelete(root->right, e, compare);
	}
	else
	{
		//���1
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		//���2
		else if (root->left == NULL)
		{
			PTreeNode temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL)
		{
			PTreeNode temp = root;
			root = root->left;
			free(temp);
		}
		//���3
		else {
			int data = BSTreFindMinValue(root->right);
			root->data = data;
			root->right = BSTreDelete(root->right, data, compare);
		}
	}


}


