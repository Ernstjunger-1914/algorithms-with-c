#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Round function
void MakeRandomNumber();
void BubbleSort();
void DisplayBuffer();
int IsNumberExit(int, int);
int buf[100];

// 정렬할 데이터 초기화
void MakeRandomNumber() {
	int i = 1, num;

	srand((unsigned)time(NULL));
	buf[0] = 100;

	while (i < 100) {
		num = rand() % 100;

		if (!IsNumberExit(num, i)) {
			buf[i] = num;
			i++;
		}
	}
}

void BubbleSort() {
	int dummy;

	for (int i = 100 - 1; i >= 0; i--) {
		for (int j = 1; j <= i; j++) {
			if (buf[j - 1] > buf[j]) {
				dummy = buf[j - 1];
				buf[j - 1] = buf[j];
				buf[j] = dummy;
			}
		}
	}
}

void DisplayBuffer() {
	for (int i = 0; i < 100; i++) {
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

int main() {
	printf("정렬할 데이터 초기화\n");

	MakeRandomNumber();
	DisplayBuffer();
	printf("\n정렬 후 데이터\n");

	BubbleSort();
	DisplayBuffer();
	printf("\n");
}