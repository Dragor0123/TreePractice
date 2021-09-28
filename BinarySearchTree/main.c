/**
 * @file		main.c
 * @author		blader137 (https://github.com/Dragor0123)
 * @brief		main.c of BinarySearchTree Project
 * @version		0.1
 * @date		2021-09-02
 *
 * @copyright Copyright (c) 2021
 *
 */
#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
//#include <crtdbg.h>
//#define _CRTDBG_MAP_ALLOC
#include "treeNode.h"

void help();
void lower(char* c);

int main()
{
	char cmd;
	element e;

	treeNode* root = NULL;
	treeNode* tmp = NULL;

	do
	{
		char c = 0;
		help();
		cmd = getchar();
		lower(&cmd);
		while ((c = getchar()) != '\n' && c != EOF);
		switch (cmd)
		{
		case 'i':
			printf("단어: ");
			fgets(e.word, MAX_WORD_SIZE, stdin);
			printf("의미: ");
			fgets(e.meaning, MAX_MEANING_SIZE, stdin);
			insertNode(&root, e);
			break;
		case 'd':
			printf("단어: ");
			fgets(e.word, MAX_WORD_SIZE, stdin);
			deleteNode(&root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("단어: ");
			fgets(e.word, MAX_WORD_SIZE, stdin);
			tmp = search(root, e);
			if (tmp)
				printf("의미: %s\n", e.meaning);
			break;
		case 'q':
			break;
		default:
			printf("\'i\', \'d\', \'p\', \'s\', \'q\' 중 하나를 입력하시오.\n");
			break;
		}
	} while (cmd != 'q');

	return 0;
}

void help()
{
	printf("***************\n");
	printf("i: 입력\n");
	printf("d: 삭제\n");
	printf("s: 탐색\n");
	printf("p: 출력\n");
	printf("q: 종료\n");
	printf("***************\n");
}

void lower(char* c)
{
	if ('A' <= *c && *c <= 'Z')
		*c += 'a' - 'A';
}
