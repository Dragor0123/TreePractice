#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeNode.h"

treePtr	MakeNode(element data, treePtr leftNode, treePtr rightNode)
{
	treePtr node = (treePtr)malloc(sizeof(treeNode));
	if (!node)
		return NULL;

	node->left = leftNode;
	node->right = rightNode;
	//memcpy(&node->key, &data, sizeof(element));
	node->key = data;
	return node;
}

void Dealloc_Tree(treePtr root)
{
	if (root)
	{
		if (root->left)
			Dealloc_Tree(root->left);
		if (root->right)
			Dealloc_Tree(root->right);
		free(root);
		root = NULL;
	}
}

void display(treePtr p)
{
	if (p)
	{
		printf("(");
		display(p->left);
		printf("%s", p->key.word);
		display(p->right);
		printf(")");
	}
}

treePtr	search(treePtr root, element key)
{
	treePtr p = root;
	while (p) {
		switch (compare(key, p->key))
		{
		case -1:
			p = p->left;
			break;
		case 1:
			p = p->right;
			break;
		case 0:
			return p;
		}
	}
	return NULL;
}

void insertNode(treePtr* root, element key)
{
	treeNode *p, *t;	// p = parent node, t = child node;
	treeNode *n;		// n is new node;
	t = *root;
	p = NULL;
	
	while (t)
	{
		int cmp = compare(key, t->key);
		if (0 == cmp)
			return;
		p = t;
		t = (0 > cmp) ? t->left : t->right;
	}

	n = MakeNode(key, NULL, NULL);

	if (p)
	{
		if (0 > compare(key, p->key))
			p->left = n;
		else
			p->right = n;
	}
	else
	{
		*root = n;
	}
}

void deleteNode(treePtr* root, element key)
{
	// p = parent, succ = successor, succ_p = parent of successor,
	treeNode * p, * child, * succ, * succ_p, * tmp;
	
	p = NULL;
	tmp = *root;
	int cmp;

	while (tmp && 
		0 != (cmp = compare(tmp->key, key)))
	{
		p = tmp;
		tmp = (0 > cmp) ? tmp->left : tmp->right;
	}

	if (NULL == tmp)
	{
		printf("key is not in the tree.");
		return;
	}


	if (!tmp->left && !tmp->right)
	{ 	// case 1: no children node.
		if (p)
		{
			if (p->left == tmp)
				p->left = NULL;
			else
				p->right = NULL;
		}
		else
		{
			*root = NULL;
		}
	}
	else if (!tmp->left || !tmp->right)
	{  	// case 2: only has one child node.
		child = (tmp->left) ? tmp->left : tmp->right;
		if (p)
		{
			if (p->left == tmp)
				p->left = child;
			else
				p->right = child;
		}
		else
		{
			*root = child;
		}
	}
	else
	{	// case 3: has both left and right child.
		// 오른쪽 서브트리에서 후속자를 찾는다.
		succ_p = tmp;
		succ = tmp->right;

		// 후속자를 찾아서 계속 왼쪽으로 이동한다.
		while (succ->left)
		{
			succ_p = succ;
			succ = succ->left;
		}

		// 후속자의 부모와 자식을 연결
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;

		tmp->key = succ->key;
		tmp = succ;
	}

	free(tmp);
}
