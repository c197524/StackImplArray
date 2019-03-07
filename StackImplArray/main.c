#include <stdio.h>
#include "stack.h"


int main() {
	Stack S = CreateStack(10);
	for (int i = 0; i < 10; i++) {
		Push(i, S);
	}
	printf("Stack IsEmpty? %d Stack IsFull? %d Size:%d\n", IsEmpty(S), IsFull(S),S->TopOfStack+1);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", Pop(S));
	}
	printf("Stack IsEmpty? %d Stack IsFull? %d Stack Size:%d\n", IsEmpty(S), IsFull(S),S->TopOfStack+1);
	return 0;
}