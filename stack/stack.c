#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct stack {
    struct node *top;
    int size;
};

void init(struct stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

void push(struct stack *stack, int item) {
    struct node *node = malloc(sizeof(struct node));

    node->data = item;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

void pop(struct stack *stack) {
    if (stack->size == 0) {
        puts("Cannot pop from an empty stack");
        exit(0);
    }

    int data = stack->top->data;
    stack->top = stack->top->next;
    stack->size--;
}

int peek(struct stack *stack) {
    if (stack->size == 0) {
        puts("Cannot peek from an empty stack");
        exit(0);
    }
    return stack->top->data;
}

void print(struct stack *stack) {
    struct node *temp;
    temp = stack->top;

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

bool is_empty(struct stack *stack) {
    return stack->size == 0;
}

int main(void) {
    struct stack *s = malloc(sizeof(*s));

    for (int item = 1; item < 10; item++)
        push(s, item);

    // print(s);

    while (!is_empty(s)) {
        printf("%d\n", peek(s));
        pop(s);
    }

    printf("\nlen of stack = %d\n\n", s->size);

    return 0;
}
