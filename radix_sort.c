#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct _NODE {
	int data;
	struct _NODE* Next;
} NODE;

NODE* front[10];
NODE* rear[10];
NODE* ptrNode;
int buf[10];

void MakeRandomNumber();
void RadixSort();
void DisplayBuffer();
int IsNumberExit(int, int);
void InitializeQueue();
void put(int, int);
int get(int);

void MakeRandomNumber() {
	int i = 1, num;

	srand((unsigned)time(NULL));

	while (i < 10) {
		num = rand() % 100;

		if (!IsNumberExit(num, i)) {
			buf[i] = num;
			i++;
		}
	}
}

void RadixSort() {
	int j=0, num, digit;

	for (int i = 0; i < 10; i++) {
		num = buf[i];
		digit = num % 10;
		put(digit, num);
	}

	printf("\n1의 자릿수로 정렬된 숫자 리스트\n");

	for (int i = 0; i < 10; i++) {
		printf("\n%d의 자리 : ", i);

		while (1) {
			num = get(i);

			if (num != -1) {
				printf("%3d", num);
				buf[j++] = num;
			} else {
				break;
			}
		}
	}

	printf("\n\n1차 정렬 후 buf 내의 데이터\n");
	DisplayBuffer();

	j = 0;

	for (int i = 0; i < 10; i++) {
		num = buf[i];
		digit = num / 10;
		put(digit, num);
	}

	printf("\n10의 자릿수로 정렬된 숫자 리스트\n");

	for (int i = 0; i < 10; i++) {
		printf("\n%d의 자리 : ", i);

		while (1) {
			num = get(i);

			if (num != -1) {
				printf("%3d", num);
				buf[j++] = num;
			} else {
				break;
			}
		}

		printf("\n\n2차 정렬 후 buf 내의 데이터");
		DisplayBuffer();
	}
}

void DisplayBuffer() {
	for (int i = 0; i < 10; i++) {
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

void InitializeQueue() {
	for (int i = 0; i < 10; i++) {
		front[i] = (NODE*)malloc(sizeof(NODE));
		rear[i] = (NODE*)malloc(sizeof(NODE));
		front[i]->Next = rear[i];
		rear[i]->Next = rear[i];
	}
}

void put(int index, int num) {
	ptrNode = (NODE*)malloc(sizeof(NODE));
	ptrNode->data = num;

	if (front[index]->Next == rear[index]) {
		front[index]->Next = ptrNode;
		ptrNode->Next = rear[index];
		rear[index]->Next = ptrNode;
	} else {
		rear[index]->Next->Next = ptrNode;
		ptrNode->Next = rear[index];
		rear[index]->Next = ptrNode;
	}
}

int get(int index) {
	int ret;
	NODE* deleteNode;

	if (front[index]->Next == rear[index]) {
		return -1;
	} else {
		deleteNode = front[index]->Next;
		front[index]->Next = deleteNode->Next;
		ret = deleteNode->data;

		free(deleteNode);
	}
	return ret;
}

int main() {
	InitializeQueue();
	printf("정렬할 데이터 초기화\n");

	MakeRandomNumber();
	DisplayBuffer();
	RadixSort();

	printf("\n\n\n");
}