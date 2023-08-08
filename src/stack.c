#include "../inc/stack.h"

Stack *InitStack(const size_t size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack)
        return NULL;

    stack->data = (float *)malloc(sizeof(float) * size);
    if (!stack->data)
    {
        free(stack);
        return NULL;
    }
    stack->size = size;
    stack->top = 0;

    return stack;
};

bool IfStackEmpty(const Stack *stack)
{
    return (stack->top == 0);
}

bool IfStackFull(const Stack *stack)
{
    return (stack->top == stack->size);
}

bool Push(Stack *stack, float data)
{
    if (IfStackFull(stack))
        return false;

    stack->data[stack->top++] = data;
    return true;
    // stack->data[stack->top] = data;
    // stack->top += 1;
};

bool Pop(Stack *stack, float *data)
{
    if (IfStackEmpty(stack))
        return false;

    *data = stack->data[--stack->top];
    return true;
};

float GetTop(const Stack *stack)
{
    if (IfStackEmpty(stack))
        return 0;

    return stack->data[stack->top - 1];
};