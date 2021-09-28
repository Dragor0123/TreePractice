#pragma once

#define MAX_WORD_SIZE		(1 << 7)
#define MAX_MEANING_SIZE	(1 << 10)

typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
}element;

int compare(element e1, element e2);