#define _CRT_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

Element BSTreFindMinValue(PTreeNode root);

PTreeNode BSTreInsert(PTreeNode root, Element e, CompareElement compare) // compare => 왼쪽이 크면 1이 반환, 아닐 경우 -1이 반환.
{
	if (root)
	{
		if (compare(&(root->data), &(e)))//root->data값이 더 클 경우
		{
			root->left = BSTreInsert(root->left, e, compare);
		}
		else //root->data값이 더 작을 경우
		{
			root->right = BSTreInsert(root->right, e, compare);
		}
		return root;
	}
	return TreCreateNode(e); //새로운 node를 만들어서 root값을 넣어줌.
}


PTreeNode BSTreSearch(PTreeNode root, Element e, CompareElement compare)
{
	if (root)
	{
		if (compare(&(root->data), &(e)) == 0) //root->data = e 인 경우
		{
			return root;
		}
		
		else if (compare((&root->data), &(e))) //root->data > e => e가 왼쪽 아래 노드에 있음
		{
				BSTreSearch(root->left, e, compare);
		}
		else //root->data < e => e가 오른쪽 아래 노드에 있음
		{
				BSTreSearch(root->right, e, compare);
		}
		printf("찾는 e값이 존재하지 않습니다.\n");
	}

}

//삭제할때 오른쪽의 맨 왼쪽 아래 자식 노드 or 왼쪽의 맨 오른쪽 아래 자식 노드를 대신 연결시켜주면 됨.
//1. 삭제할 노드가 없는 경우, 2. 삭제할 노드에게 자식 노드가 없는 경우, 3. 삭제할 노드에게 자식 노드가 1개인 경우, 4. 삭제할 노드에게 자식 노드가 2개인 경우
/*PTreeNode BSTreDelete(PTreeNode root, Element e, CompareElement compare)
{
	TreeNode* node = root; //찾으려는 노드
	TreeNode* p = NULL; //찾으려는 노드의 부모노드
	TreeNode* c = NULL; //자식노드 저장할 노드
	TreeNode* a = NULL;
	TreeNode* b = NULL;

	if (root) {
		while (node != NULL && node->data != e)
		{
			p = node; //부모노드
			if (e < node->data)
			{
				node = node->left;
			}
			else
				node = node->right;
		}

		if (node == NULL) //삭제할 노드 값이 없을 경우
		{
			printf("찾는 값이 이진트리에 존재하지 않습니다.\n");
			return;
		}

		//삭제할 노드에게 자식 노드가 없는 경우
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
				root = NULL; //삭제할 노드가 root인경우
		}

		//삭제할 노드에게 자식 노드가 한개인 경우
		else if (node->left == NULL || node->right == NULL)
		{
			if (node->left != NULL) //오른쪽 비어있고 왼쪽 노드는 들어있는
				c = node->left;
			else
				c = node->right;

			if (p != NULL) //부모노드가 존재한다면
			{
				if (p->left == node) //만약 부모노드의 왼쪽이 지우려는 노드라면
					p->left = c; //구해둔 노드 c를 부모노드의 왼쪽이랑 연결
				else
					p->right = c;
			}

			else
				root = c;
		}

		//삭제할 노드에게 자식 노드가 두개인 경우
		//else if (node->left != NULL && node->right != NULL)
		//큰 값중에 제일 작은 값 -> 한번 오른쪽으로 갔다가 다시 왼쪽으로 쭉 내려가는
		else
		{
			a = p;
			b = node->right; //큰값중에 제일 작은 값을 찾으러가는..
			while (b->left != NULL)
			{
				a = b;
				b = b->left;
			} //b는 삭제할 node보다 큰 값중 가장 작은 값을 나타내고, a는 b의 부모노드를 가리킴.

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
				//b->right를 어디로 보내야할까,,,?
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
		//경우1
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		//경우2
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
		//경우3
		else {
			int data = BSTreFindMinValue(root->right);
			root->data = data;
			root->right = BSTreDelete(root->right, data, compare);
		}
	}


}


