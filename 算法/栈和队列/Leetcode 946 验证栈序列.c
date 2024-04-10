#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int* num = (int*)malloc(sizeof(int) * pushedSize);
    int top = 0;
    for (int i = 0, j = 0; i < pushedSize; i++) {
        num[top++] = pushed[i];
        while (top != 0 && num[top - 1] == popped[j]) {
            top--;
            j++;
        }
    }
    return top == 0;
}