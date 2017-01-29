//
//  main.c
//  一个正整数的划分数
//
//  Created by mac on 16/6/1.
//  Copyright © 2016年 mac. All rights reserved.
//问题描述，每个正整数都可以被划分成为n个数相加的形式，例如：4=1+3;4=1+1+2;4=1+1+1+1;4=2+2;4=4;.则称4 的划分数为5.可以划分为5种正整数想加的形式，设计算法实现，求任意数的划分数。
#include <stdio.h>
int DivideCounter(int n,int m){
    if(m==1) return 1;
    if(m>n) return DivideCounter(n, n);
    if(m==n) return 1+DivideCounter(n, n-1);
    return DivideCounter(n, m-1)+DivideCounter(n-m, m);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n",DivideCounter(8, 8));
    return 0;
}
