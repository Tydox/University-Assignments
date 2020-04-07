#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
	int* Items;
	int stackSize;
	int top;
} Stack;

void display(Stack* S);
int pop(Stack* S);
void push(Stack* S, int x);


void push(Stack* S, int x)
{

	if (S->top == S->stackSize)
	{
		printf("Stack is full!");
		return;
	}
	S->Items[++(S->top)] = x;

}
int pop(Stack* S)
{
	int x;
	if (S->top == -1)
	{
		printf("Stack is empty!");
		return 0;
	}
	
	x = S->Items[S->top];
	S->top--;
	return x;
}

void display(Stack* S) {
	int i;
	printf(" top = %d\n", S->top);
	for (i = S->top; i >= 0; i--)
		printf("value: %6d location %3d\n", S->Items[i], i);
}

char menu() {
	printf("\n\t MAIN MENU:\
			\n 1. Add element to stack \
			\n 2. Delete element from the stack\
			\n 3. Display stack \
			\n 4. sum stack Odds and oppiset evens locations \
			\n 0. Exit \n\
			\n Your choice: ");
	fseek(stdin, SEEK_END, 0);
	char c = getchar();
	return(c);
}
void retainOddAndOppisetEven(Stack* S) {

	//empty stack
	if (S->top == -1)
	{
		printf("Nothing to do, empty stack\n");
		return;
	}

	//init stacks
	Stack even_stack = { NULL, 0, -1 };
	Stack noteven_stack = { NULL,0 , -1 };
	Stack new_even_stack = { NULL,0 , -1 };
	int evenstack;
	int unevenstack;

	//check if given stack top is even or odd
	if (((S->top)+1) % 2 == 0)
	{
		evenstack = (S->top) / 2;
		unevenstack = (S->top) / 2;
		even_stack.stackSize = evenstack;
		noteven_stack.stackSize = unevenstack;
		new_even_stack.stackSize = unevenstack;
		even_stack.Items = (int*)malloc(evenstack * sizeof(int));
		noteven_stack.Items = (int*)malloc(unevenstack * sizeof(int));
		new_even_stack.Items = (int*)malloc((unevenstack) * sizeof(int));
	}
	else
	{
		evenstack = (S->top) / 2;
		unevenstack = (S->top) / 2 + 1;
		even_stack.stackSize = evenstack;
		noteven_stack.stackSize = unevenstack;
		new_even_stack.stackSize = unevenstack + evenstack;
		even_stack.Items = (int*)malloc(evenstack * sizeof(int));
		noteven_stack.Items = (int*)malloc(unevenstack * sizeof(int));
		new_even_stack.Items = (int*)malloc((unevenstack) * sizeof(int));
	}

	
	//check if malloc succeeded
	if (even_stack.Items == NULL || noteven_stack.Items == NULL)
	{
		printf("Mem Error, Exit");
		return;
	}

	//IF ODD - pop bullet & push into new mag
	if (new_even_stack.stackSize != evenstack) {
		push(&new_even_stack, pop(S));
	}

	
	//now either way we have an equal stack
	//pop even & odd and push into seperate mags
	while (S->top > 0) 
	{
		push(&even_stack, pop(S));
		push(&noteven_stack, pop(S));
	}

	
	//reverse our copied even 
	int i = 0;
	if (even_stack.top > -1) {
		while (even_stack.top > -1)
		{
			int temp = even_stack.Items[even_stack.top];
			even_stack.Items[even_stack.top--] = even_stack.Items[i];
			even_stack.Items[i++] = temp;
			
		}
	}
	even_stack.top = even_stack.stackSize;
	//push into new stack
	
	while (even_stack.top > -1 || noteven_stack.top >-1 )
	{
		push(&new_even_stack,(pop(&even_stack) + pop(&noteven_stack)));
	}

	//copy into old stack
	while (new_even_stack.top>-1)
	{
		push(S, pop(&new_even_stack));
	}


	//free items from stacks
	free(new_even_stack.Items);
	free(even_stack.Items);
	free(noteven_stack.Items);
}

//
//	Stack even_stack = { NULL,S->top / 2,0 };
//	even_stack.Items = (int*)malloc(sizeof(int) * S->top / 2);
//	double xx = (S->top / 2) + 1;
//	Stack odd_stack = { NULL,(S->top / 2) + 1,0 };
//	odd_stack.Items = (int*)malloc(sizeof(int) * ((S->top / 2) + 1));
//
//	Stack reverse_even_stack = { NULL,S->top / 2,0 };
//	reverse_even_stack.Items = (int*)malloc(sizeof(int) * (S->top / 2));
//
//	int i, x, even;
//	if (S->top % 2 == 0)
//		even = 1;
//	else
//		even = 0;
//	for (i = 0; i < S->top; i++) {
//		x = pop(S);
//		if (even)
//			push(&even_stack, x);
//		else
//			push(&odd_stack, x);
//		even = !even;
//	}
//
//	while (even_stack.top) {
//		push(&reverse_even_stack, pop(&even_stack));
//	}
//
//
//	while (odd_stack.top || reverse_even_stack.top) {
//		//x = pop(&odd_stack);
//		//y = pop(&reverse_even_stack);
//		//if (odd_stack.top && reverse_even_stack.top) push(S, x+y);
//		if (odd_stack.top && reverse_even_stack.top)
//			push(S, pop(&odd_stack) + pop(&reverse_even_stack));
//		else
//			push(S, pop(&odd_stack));
//	}
//
//	free(even_stack.Items);
//	free(odd_stack.Items);
//	free(reverse_even_stack.Items);
//}

void main() {

	int size = 8, num;
	Stack Stack = { NULL,size,-1 };
	Stack.Items = (int*)malloc(sizeof(int) * size);

	while (1) {
		switch (menu()) {
		case '1': printf("Enter the data: ");
			scanf_s("%d", &num);
			push(&Stack, num);
			break;
		case '2': printf("\n Pop %d", pop(&Stack));
			break;
		case '3': display(&Stack);
			break;
		case '4': retainOddAndOppisetEven(&Stack);
			break;
		case '0': printf("\n Exit ");
			system("pause");
			return;
		default: printf("\n Wrong. Pls try again");
		}// switch
	} // while
}// main



