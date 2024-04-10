#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char* change(char* s) {
    int n = strlen(s), now = 0;
    char* arr = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        if (s[i] != '#') {
            arr[now++] = s[i];
        }
        else if (now > 0) {
            now--;
        }
    }
    arr[now] = '\0';
    return arr;
}

bool backspaceCompare(char* s, char* t) {
    if (strcmp(change(s), change(t)) == 0) {
        return true;
    }
    return false;
}