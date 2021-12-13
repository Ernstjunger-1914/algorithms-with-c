#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX 100


void MakeRandomNumber();
void QuickSort(int data[], int, int);
void DisplayBuffer();
int IsNumberExit(int, int);
int BinarySearch(int);

int buf[MAX];
int CompareCount;

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

int BinarySearch(int num) {
	int left=0, right=MAX, min;

	while (right >= left) {
		CompareCount++;
		min = (left + right) / 2;

		if (num < buf[min]) {
			right = min - 1;
		} else {
			left = min + 1;
		}

		if (num == buf[min]) {
			return min;
		}
	}
	return -1;
}

int main() {
	int n, ret;
	CompareCount = 0;
	scanf_s("%d", &n);

	MakeRandomNumber();
	QuickSort(buf, 0, MAX - 1);
	printf("데이터 정렬\n");

	DisplayBuffer();
	ret = BinarySearch(n);

	if (ret == -1) {
		printf("\n%d라는 데이터가 존재하지 않는다.\n", n);
	} else {
		printf("\n%d이라는 데이터가 %d번째에 존재한다.\n", n, ret);
	}

	printf("총 비교 횟수 : %d\n", CompareCount);
}