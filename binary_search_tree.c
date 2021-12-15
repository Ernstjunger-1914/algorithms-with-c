#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

typedef struct _NODE {
	int key;
	struct _NODE* left;
	struct _NODE* right;
} NODE;

NODE* ptrNode;
NODE* head;
NODE* end;

void MakeRandomNumber();
void QuickSort(int [], int, int);
void DisplayBuffer();
int IsNumberExit(int, int);
void BSTInitialize();
void BSTInsert(int);
void BSTDisplay(NODE*);

int buf[MAX];
int CompareCount = 0;

void MakeRandomNumber() {
	int i = 1, num;

	srand((unsigned)time(NULL));
	buf[0] = 100;

	while (i < MAX) {
		num = rand() % 200;

		if (!IsNumberExit(num, i)) {
			buf[i] = num;
			i++;
		}
	}
}

void QuickSort(int data[], int left, int right) {
	int i, j, num, temp;

	if (left < right) {
		num = data[right];
		i = left - 1;
		j = right;

		for (;;) {
			while (data[++i] < num);
			while (data[--j] > num);

			if (i >= j) {
				break;
			}

			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}

		temp = data[i];
		data[i] = data[right];
		data[right] = temp;

		QuickSort(data, left, i - 1);
		QuickSort(data, i + 1, right);
	}
}

void DisplayBuffer() {
	for (int i = 0; i < MAX; i++) {
		if ((i % 10) == 0) {
			printf("\n");
		}

		printf("%4d", buf[i]);
	}

	printf("\n");
}

int IsNumberExit(int num, int index) {
	for (int i = 0; i < index; i++) {
		if (buf[i] == num || num == 0) {
			return TRUE;
		}
	}
	return FALSE;
}

void BSTInitialize() {
	end = (NODE*)malloc(sizeof * end);
	end->left = end;
	end->right = end;
	end->key = -1;

	head = (NODE*)malloc(sizeof * head);
	head->right = end;
	head->key = 0;
}

void BSTInsert(int num) {
	NODE* p, * x;
	p = head;
	x = head->right;

	while (x != end) {
		p = x;
		x = (num < x->key) ? x->left : x->right;
	}

	x = (NODE*)malloc(sizeof * x);
	x->key = num;
	x->left = end;
	x->right = end;

	if (num < p->key) {
		p->left = x;
	} else {
		p->right = x;
	}
}

void BSTDisplay(NODE* ptr) {
	if (ptr != end) {
		BSTDisplay(ptr->left);
		printf("%5d", ptr->key);
		BSTDisplay(ptr->right);
	}
}

int main() {
	int n, ret;

	MakeRandomNumber();
	QuickSort(buf, 0, MAX - 1);
	printf("데이터 정렬\n");

	DisplayBuffer();
	BSTInitialize();

	for (int i = 0; i < MAX; i++) {
		BSTInsert(buf[i]);
	}

	printf("\nroot node : %d\n", head->right->key);

	BSTDisplay(head->right);
}