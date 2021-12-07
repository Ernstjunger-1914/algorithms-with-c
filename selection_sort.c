#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

// Round function
void MakeRandomNumber();
void SelectionSort();
void DisplayBuffer();
int IsNumberExit(int, int);
int buf[100];

// 정렬할 데이터 초기화
void MakeRandomNumber() {
	int i = 1, num;

	srand((unsigned)time_t(NULL));
	buf[0] = 100;

	while (i < 100) {
		num = rand() % 100;

		if (!IsNumberExit(num, i)) {
			buf[i] = num;
			i++;
		}
	}
}

void SelectionSort() {
	int min, dummy;

	for (int i = 0; i < 100; i++) {
		min = i;

		for (int j = i + 1; j < 100; j++) {
			if (buf[j] < buf[min]) {
				min = j;
			}
		}
		dummy = buf[min];
		buf[min] = buf[i];
		buf[i] = dummy;
	}
}

// buf 배열에 저장된 데이터를 출력
void DisplayBuffer() {
	for (int i = 0; i < 100; i++) {
		if ((i % 10) == 0) {
			printf("\n");
		}
		printf("%4d", buf[i]);
	}
	printf("\n");
}

// 이미 생성된 값이 아닌지 검사
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
	printf("\n정렬 후\n");

	SelectionSort();
	DisplayBuffer();
	printf("\n");
}