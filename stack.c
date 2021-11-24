#include <stdio.h>
#include <stdlib.h>

// 스택의 하위 자료구조용 노드 선언
typedef struct _NODE {
	int Data;
	struct _NODE *Next;
} NODE;

NODE *head, *end;
NODE *ptrNode;

void InitializeStack();
void push(int);
int pop();
void DisplayStack();

// Stack 초기화 함수 
void InitializeStack() {
	head=(NODE *)malloc(sizeof(NODE));
	end=(NODE *)malloc(sizeof(NODE));
	head->Next=end;
	end->Next=end;
}

// 데이터 삽입
void push(int num) {
	ptrNode=(NODE *)malloc(sizeof(NODE));
	ptrNode->Data=num;
	ptrNode->Next=head->Next;
	head->Next=ptrNode;
}

// 데이터 삭제
int pop() {
	int ret;
	ptrNode=head->Next;
	head->Next=head->Next->Next;
	ret=ptrNode->Data;
	free(ptrNode);
	
	return ret;
}

// Stack 조회
void DisplayStack() {
	NODE *indexNode;
	printf("head -> ");
	
	for(indexNode=head->Next; indexNode!=end; indexNode=indexNode->Next) {
		printf("%d -> ", indexNode->Data);
	}
	
	printf("end\n");
}

int main() {
	int ret, n, n_;
	InitializeStack();

	push(1);
	push(3);
	push(10);
	push(20);
	push(12);
	printf("5번의 push() 함수 호출 후 실행 결과\n");
	DisplayStack();
	
	ret=pop();
	ret=pop();
	ret=pop();
	printf("\n3번의 pop() 함수 호출 후 실행 결과\n");
	DisplayStack();
}