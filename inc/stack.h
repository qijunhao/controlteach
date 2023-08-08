#pragma once

#include "myMath.h"

// #define COMMON_STACK_SIZE 20

typedef struct Stack {
	// float elment[COMMON_STACK_SIZE];
	float* data;
	u8	   size;
	u8	   top;
} Stack;

Stack* InitStack(const u8 size);
bool   DeleteStack(Stack* stack);

bool IfStackEmpty(const Stack* stack);
bool IfStackFull(const Stack* stack);

bool Push(Stack* stack, float data);
bool Pop(Stack* stack, float* data);

float GetTop(const Stack* stack);
