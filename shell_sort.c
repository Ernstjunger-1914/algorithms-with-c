#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Round function
void MakeRandomNumber();
void ShellSort();
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

void ShellSort() {
	int i, j, h, v;

	for (h = 0; h < 100; h = 3 * h + 1);

	for (; h > 0; h/=3) {
		for (i = h; i < 100; i++) {
			v = buf[i];
			j = i;

			while (j >= h && buf[j - h] > v) {
				buf[j] = buf[j - h];
				j -= h;
			}
			buf[j] = v;
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

	ShellSort();
	DisplayBuffer();
	printf("\n");
}