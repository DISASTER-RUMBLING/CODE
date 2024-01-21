#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

//快乐数的定义：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和；
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1；
// 如果这个过程 结果为 1，那么这个数就是快乐数。
// 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
//举例：输入 n=19
//1的平方+9的平方=82   8的平方+2的平方=68  6的平方+8的平方=100  1的平方+0的平方+0的平方=1
//输出 true

//定义一个函数用于计算各位数的平方之和并且返回
int Get_Number(int x) {
    int sum = 0;
    while (x) {
        int d = x % 10;
        sum += (d * d);
        x /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    //判断传入的n是否为1
    if (n == 1) {
        return true;
    }
    //定义俩整形用于计算其各位数平方之和
    //使用循环链表的思想，若该数一直计算各位数平方之和，必定会有一时刻重复或者是等于0
    int a = Get_Number(n), b = Get_Number(Get_Number(n));
    //使用while循环判断a和b会不会重复
    while (a != b) {
        //判断是否有一数的结果会等于1
        //若有，则返回true，若没有则继续算下去，直到俩数相等
        if (a == 1 || b == 1) {
            return true;
        }
        a = Get_Number(a);
        b = Get_Number(Get_Number(b));
    }
    //防止a和b同时等于1
    if (a == 1) {
        return true;
    }
    //a和b相等且都不为1，则返回false
    return false;
}