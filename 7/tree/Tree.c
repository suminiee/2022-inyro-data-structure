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
// IteratorFunc를 list의 각 요소에 적용. func()함수에 p를 인자로 전달
void TreIterate(PTreeNode root, IterateFunc func, void* p, TreeTraverseOrder order)//선,중,후위 결정하는거 -> order.
{
	if (root)
	{
		if (order == TTO_PREORDER) //본인 먼저 출력하고 왼쪽 오른쪽 아래로 내려감
		{
			func(&(root->data), p);
			TreIterate(root->left, func, p, TTO_PREORDER);
			TreIterate(root->right, func, p, TTO_PREORDER);
		}
		else if (order == TTO_INORDER)
		{
			
			TreIterate(root->left, func, p, TTO_INORDER); 
			func(&(root->data), p); //왼쪽 먼저 내려가고 본인 출력하고 오른쪽으로 내려감
			TreIterate(root->right, func, p, TTO_INORDER);
		}
		else if (order == TTO_POSTORDER)
		{
			
			TreIterate(root->left, func, p, TTO_POSTORDER);
			TreIterate(root->right, func, p, TTO_POSTORDER);
			func(&(root->data), p); //왼쪽 먼저 내려가고 오른쪽 내려가고 마지막으로 본인 출력함.
		}
	}
}
