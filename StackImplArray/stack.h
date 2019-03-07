#pragma once
#include <stdlib.h>
struct StackRecord;
typedef struct StackRecord* Stack;
typedef int ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
ElementType Pop(Stack S);


#define EmptyTOS -1
#define MinStackSize 5

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType* Array;
};

int IsEmpty(Stack S) {
	return S->TopOfStack == EmptyTOS;
}
int IsFull(Stack S) {
	return S->TopOfStack == S->Capacity - 1;
}
Stack CreateStack(int MaxElements) {
	Stack S = (Stack)malloc(sizeof(struct StackRecord));
	S->Array = (ElementType*)malloc(sizeof(ElementType) * MaxElements);
	S->Capacity = MaxElements;
	MakeEmpty(S);
	return S;

}
void DisposeStack(Stack S) {
	if (S != NULL) {
		free(S->Array);
		free(S);
	}
}
void MakeEmpty(Stack S) {
	S->TopOfStack = EmptyTOS;
}
void Push(ElementType X, Stack S) {
	if (!IsFull(S)) {
		S->Array[++S->TopOfStack] = X;
	}
	else {
		printf("Stack Is Full!");
	}
}
ElementType Top(Stack S) {
	if (!IsEmpty(S)) {
		return S->Array[S->TopOfStack];
	}
	printf("Stack Is Empty!");
	return 0;
}
ElementType Pop(Stack S) {
	ElementType Item;
	if (!IsEmpty(S)) {
		Item = S->Array[S->TopOfStack];
		S->TopOfStack--;
	}
	else {
		printf("Stack Is Empty!");
	}
	return Item;
}
