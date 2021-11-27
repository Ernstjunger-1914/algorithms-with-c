#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	int data;
	struct _NODE* Next;
} NODE;

NODE* front, * rear;
NODE* ptrNode;

void InitializeQueue();
void put(int);
int get();
void DisplayQueue();

void InitializeQueue() {
	front = (NODE*)malloc(sizeof(NODE));
	rear = (NODE*)malloc(sizeof(NODE));
	front->Next = rear;
	rear->Next = front;
}

void put(int n) {
	ptrNode = (NODE*)malloc(sizeof(NODE));
	ptrNode->data = n;

	if (front->Next == rear) {
		front->Next = ptrNode;
		ptrNode->Next = rear;
		rear->Next = ptrNode;
	} else {
		rear->Next->Next = ptrNode;
		ptrNode->Next = rear;
		rear->Next = ptrNode;
	}
}

int get() {
	int ret;
	NODE* deleteNode;
	printf("\n");

	if (front->Next == rear) {
		printf("Queue Empty\n");
	} else {
		deleteNode = front->Next;
		front->Next = deleteNode->Next;
		ret = deleteNode->data;

		printf("get() : %d", ret);

		free(deleteNode);
	}
	return ret;
}

void DisplayQueue() {
	NODE* ptrtemp;

	if (front->Next != rear) {
		for (ptrtemp = front->Next; ptrtemp->Next != rear; ptrtemp = ptrtemp->Next) {
			printf("%d -> ", ptrtemp->data);
		}
		printf("%d\n", ptrtemp->data);
	} else if (front->Next == rear) {
		printf("Queue Empty");
	}
}

int main() {
	int ret;
	InitializeQueue();
	printf("put() 함수 호출\n");

	put(4);
	put(6);
	put(11);
	put(32);
	put(17);

	printf("5번의 put() 함수 호출 후의 결과 : ");
	DisplayQueue();

	ret = get();
	ret = get();
	ret = get();

	printf("\n3번의 get() 함수 호출 후의 결과 : ");
	DisplayQueue();

	ret = get();
	ret = get();

	printf("\n2번의 get() 함수 호출 후의 결과 : ");
	DisplayQueue();
}