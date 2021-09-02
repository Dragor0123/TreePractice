/**
 * @file		main.c
 * @author		blader137 (https://github.com/Dragor0123)
 * @brief		main.c of BinTree project
 * @version		0.1
 * @date		2021-08-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include "treeNode.h"
int main()
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
//#ifdef _DEBUG
//	_CrtSetBreakAlloc(56419);
//#endif //DEBUG

	/*
							10
					20		         30
				44	   60		 95       100
			 70   83					22   111
												27
	*/

	treePtr node12 = MakeNode(27, NULL, NULL);
	treePtr node11 = MakeNode(111, NULL, node12);
	treePtr node10 = MakeNode(22, NULL, NULL);
	treePtr node9 = MakeNode(83, NULL, NULL);
	treePtr node8 = MakeNode(70, NULL, NULL);
	treePtr node7 = MakeNode(100, node10, node11);
	treePtr node6 = MakeNode(95, NULL, NULL);
	treePtr node5 = MakeNode(60, NULL, NULL);
	treePtr node4 = MakeNode(44, node8, node9);
	treePtr node3 = MakeNode(30, node6, node7);
	treePtr node2 = MakeNode(20, node4, node5);
	treePtr node1 = MakeNode(10, node2, node3);
	treePtr forcopy = MakeNode(0, NULL, NULL);

	forcopy = Copy_Tree(node1);
	printf("----------preorder----------\n");
	Pre_Order(forcopy);
	printf("\n");
	Pre_Order_iter(node1);
	printf("\n\n");

	printf("----------inorder----------\n");
	In_Order(forcopy);
	printf("\n");
	In_Order_iter(node1);
	printf("\n\n");

	printf("----------postorder----------\n");
	Post_Order(forcopy);
	printf("\n");
	Post_Order_iter(node1);
	printf("\n\n");

	printf("----------levelorder----------\n");
	Level_Order(node1);
	printf("\n\n");

	printf("\n");
	printf("The Max node value of this tree is ... %d\n", Get_Max(node1));
	printf("The Sum of this tree's node value is ... %d\n", Get_Sum(node1));
	
	Dealloc_Tree(node1);
	Dealloc_Tree(forcopy);
	return 0;
}