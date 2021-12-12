#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct _NODE {
	int data;
	struct _NODE* Next;
} NODE;

void MakeRandomNumber();
void MergeSort(int [], int , int);
void DisplayBuffer();
int IsNumberExit(int, int);
int buf[100];
int tmp[100];

void MakeRandomNumber() {
	int i = 1, num;

	srand((unsigned)time(NULL));

	while (i < 100) {
		num = rand() % 100;

		if (!IsNumberExit(num, i)) {
			buf[i] = num;
			i++;
		}
	}
}

void MergeSort(int data[], int left, int right) {
	int i, j, k, middle;

	if (left < right) {
		middle = (left + right) / 2;

		MergeSort(data, left, middle);
		MergeSort(data, middle + 1, right);

		for ( i = middle + 1; i > left; i--) {
			tmp[i - 1] = data[i - 1];
		}

		for (j = middle; j < right; j++) {
			tmp[right + middle - j] = data[j + 1];
		}

		for (k = left; k <= right; k++) {
			data[k] = (tmp[i] < tmp[j]) ? tmp[i++] : tmp[j--];
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

	MergeSort(buf, 0, 100 - 1);
	DisplayBuffer();
	printf("\n");
}