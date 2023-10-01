#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void push(struct Stack* stack, char ch) {
    stack->array[++stack->top] = ch;
}

char pop(struct Stack* stack) {
    if (stack->top == -1)
        return '\0';
    return stack->array[stack->top--];
}

int getPrecedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

void infixToPostfix(char* infix) {
    int length = strlen(infix);
    struct Stack* stack = createStack(length);
    int outputIndex = 0;
    char output[length];

    for (int i = 0; i < length; i++) {
        char c = infix[i];

        if (isOperand(c)) {
            output[outputIndex++] = c;
        } else if (c == '(') {
            push(stack, c);
        } else if (c == ')') {
            while (stack->top != -1 && stack->array[stack->top] != '(') {
                output[outputIndex++] = pop(stack);
            }
            if (stack->top != -1 && stack->array[stack->top] == '(') {
                pop(stack);
            }
        } else {
            while (stack->top != -1 && getPrecedence(c) <= getPrecedence(stack->array[stack->top])) {
                output[outputIndex++] = pop(stack);
            }
            push(stack, c);
        }
    }

    while (stack->top != -1) {
        output[outputIndex++] = pop(stack);
    }

    output[outputIndex] = '\0';

    printf("Postfix Expression: %s\n", output);
}

int main() {
    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(infix);
    return 0;
}
