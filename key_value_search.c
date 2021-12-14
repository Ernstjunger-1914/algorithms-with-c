#include <stdio.h>

typedef struct _NODE {
	int key;
	char value;
} NODE;

NODE key_value[10];

int main() {
	for (int i = 0; i < 10; i++) {
		key_value[i].key = 1000 + i;
		key_value[i].value = 'A' + i;
	}

	for (int i = 0; i < 10; i++) {
		printf("key : [%d]\n", key_value[i].key);
		printf("value : [%c]\n\n", key_value[i].value);
	}
}