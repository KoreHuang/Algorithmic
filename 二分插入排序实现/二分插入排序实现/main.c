//
//  main.c
//  二分插入排序实现
//
//  Created by mac on 16/6/6.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#define Swap(a,b){int tmp=a;a=b;b=tmp;}
void reverse(int *data,int start,int end){
    while(start<end){
        Swap(data[start],data[end])
        start++;end--;
    }
}
int find_index(int *data,int i){
    int low=0,pivot=i/2,high=i;
    while(low<=high){
        if(data[pivot]<data[i]){
            low=pivot+1;
            pivot=(high+low)/2;
        }else{
            high=pivot-1;
            pivot=(high+low)/2;
        }
    }
    return low;
}
void binary_sort(int *data,int n){
    int i=1,t;
    while(i<n){
        t=find_index(data, i);
        reverse(data, t, i);
        reverse(data, t+1, i);
        i++;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
//    int data[10]={3,2,5,4,1,7,6,5,8,0};
//    binary_sort(data, 10);
//    for(int i=0;i<10;i++){
//        printf("%d ",data[i]);
//    }
//    printf("\n");
    clock_t start_t, end_t;
    start_t = clock();
    printf("Starting of the program, start_t = %ld\n", start_t);
    
    int a[200000];
    for(int i=0;i<200000;i++)
    {
        a[i]=100-i;
    }
    
    int n=200000;
    
    //Print(a, n);
    binary_sort(a, n);
    //Print(a, n);
    
    end_t = clock();
    printf("End of the function, end_t = %ld\n", end_t);
    double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total seconds time taken by CPU: %f\n", total_t  );
    return 0;
}
