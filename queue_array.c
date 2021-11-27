/**
* 배열을 활용하여 구현한 queue 알고리즘
*/
#include <stdio.h>

int queue[101];
int front, rear;

void InitializeQueue();
void put(int);
int get();
void DisplayQueue();

// queue 초기화 함수
void InitializeQueue() {
	front = rear = 0;
}

void put(int num) {
	queue[rear++] = num;

	if (rear >= 101) {
		rear = 0;
	}
}

int get() {
	int ret;
	ret = queue[front++];

	if (front >= 101) {
		front = 0;
	}

	return ret;
}

void DisplayQueue() {
	int i;
	printf("front -> ");

	for (i = front; i < rear; i++) {
		printf("%2d -> ", queue[i]);
	}

	printf("rear");
}

int main() {
	int ret;
	InitializeQueue();

	put(1);
	put(9);
	put(10);
	put(22);
	put(19);

	printf("5번의 put() 함수 호출 후의 결과\n");
	DisplayQueue();

	ret = get();
	ret = get();
	ret = get();

	printf("\n\n3번의 get() 함수 호출 후의 결과\n");
	DisplayQueue();

	printf("\n\n2번의 get() 함수 호출 후의 결과\n");

	ret = get();
	ret = get();
	DisplayQueue();
}