#pragma once

typedef struct treeNode* treePtr;
typedef struct treeNode
{
	int				data;
	treePtr			left, right;
}treeNode;

treePtr MakeNode(int data_, treePtr leftNode_, treePtr rightNode_);
void Dealloc_Tree(treePtr root_);
int Get_Data(treePtr node_);

void In_Order(treePtr root_);
void In_Order_iter(treePtr root_);
void Pre_Order(treePtr root_);
void Pre_Order_iter(treePtr root_);
void Post_Order(treePtr root_);
void Post_Order_iter(treePtr root_);
void Level_Order(treePtr root_);
treePtr Copy_Tree(treePtr in_);

int Get_Max(treePtr root_);
int Get_Sum(treePtr root_);