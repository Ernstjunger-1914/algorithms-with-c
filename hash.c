#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0
#define overlow 3

typedef struct _NODE {
	int key[3];
	int cnt;
} NODE;

void Initialize();
void MakeRandomNumber();
void DisplayBuffer();
void DisplayHitBuffer();
void Counter();
int IsNumberExit(int);

int buf[100];
NODE hit[50];

void Initialize() {
	for (int i = 0; i < MAX; i++) {
		buf[i] = -1;
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 3; j++) {
			hit[i].key[j] = -1;
		}

		hit[i].cnt = 0;
	}
}

void MakeRandomNumber() {
	int i = 0, num, index;

	srand((unsigned)time(NULL));

	while (i < 50) {
		num = rand() % 100;

		if (!IsNumberExit(num)) {
			buf[num] = num;
			index = num % 50;

			if (hit[index].cnt > 2) {
				printf("\nOverFlow\n");
			} else {
				hit[index].key[hit[index].cnt++] = num;
			}

			i++;
		}
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

void DisplayHitBuffer() {
	printf("\n----- Hit Key Data -----\n");

	for (int i = 0; i < 50; i++) {
		if ((i % 5) == 0) {
			printf("\n");
		}

		switch (hit[i].cnt) {
		case 0:

		case 1:
			printf("%2d", hit[i].key[0]);

			break;

		case 2:
			printf("%2d / %2d", hit[i].key[0], hit[i].key[1]);

			break;
		
		case 3:
			printf("%2d / %2d / %2d", hit[i].key[0], hit[i].key[1], hit[i].key[2]);

			break;
		default:
			printf("**");
		}

		printf("\t");
	}

	printf("\n\n");
}

void Counter() {
	printf("\n----- Hit Counter Data -----\n");

	for (int i = 0; i < 50; i++) {
		if ((i % 5) == 0) {
			printf("\n");
		}

		printf("%4d", hit[i].cnt);
	}

	printf("\n");
}

int IsNumberExit(int num) {
	for (int i = 0; i < MAX; i++) {
		if (buf[i] == num) {
			return TRUE;
		}
	}
	return FALSE;
}

int main() {
	Initialize();
	MakeRandomNumber();
	printf("키-매핑으로 생성된 데이터\n");

	DisplayBuffer();
	printf("\n");

	DisplayHitBuffer();
	Counter();
}