//
//  main.c
//  Tom的借书方案问题
//
//  Created by mac on 16/6/1.
//  Copyright © 2016年 mac. All rights reserved.
//问题描述，Tom有5本书可以借给A，B，C三位同学。每人只能借1本，则有多少种分配方案

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int cnt=0;
    char Book[5][6]={"book1","book2","book3","book4","book5"};
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(i-j&&j-k&&i-k){
                    printf("A-%s,B-%s,C-%s\n",Book[i],Book[j],Book[k]);
                    cnt++;
                }
            }
        }
    }
    printf("总共有%d种分配方案\n",cnt);
    return 0;
}
