//
//  main.cpp
//  MaxSubArray
//
//  Created by mac on 16/8/3.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <iostream>
#define INF -2147483647
using namespace std;
double maxl(double a,double b,double c){
    return a>b?(a>c?a:c):(b>c?b:c);
}
double maxl(double a,double b){
    return a>b?a:b;
}
//传统迭代方法，用sum记录当前子数组的和，去sum和currentMax比较的最大值
double MaxItera(double *a,int N){
    double currentMax=INF;
    double sum;
    for (int i=0; i<N; i++) {
        sum=0;
        for (int j=i; j<N; j++) {
            sum+=a[j];
            currentMax=maxl(sum,currentMax);
        }
    }
    return currentMax;
}
//时间复杂度O(N^2)
//联想斐波那契的最大子数组求和方法
//开辟一个数组用来记录a(0...N)的和maxL[i]=a[0]+a[2]+...+a[i];
//从数组a(i...j)的和sum=maxL[j]-maxL[i]
double MaxIteFebi(double *a,int N){
    double max=INF;
    double *maxL=new double[N];
    maxL[0]=a[0];
    for (int i=1; i<N; i++) {
        maxL[i]=a[i]+maxL[i-1];
    }
    double sum;
    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {
            sum=maxL[j]-maxL[i];
            max=maxl(max, sum);
        }
    }
    return max;
}
//采用分治的方法解决最大子数组的问题
double MaxDivQue(double *a,int N,int low,int high){
    if(low>high){return INF;}
    if(low==high){return a[low];}
    int mid=(low+high)/2;
    double maxLeft,maxRight,sum;
    sum=0;
    maxLeft=INF;
    for (int i=mid;i>=low;i-- ) {
        sum+=a[i];
        maxLeft=maxl(maxLeft, sum);
    }
    sum=0;
    maxRight=INF;
    for (int j=mid+1; j<=high; j++) {
        sum+=a[j];
        maxRight=maxl(maxRight, sum);
    }
    return maxl(maxLeft+maxRight, MaxDivQue(a, N, mid+1, high),MaxDivQue(a, N, low, mid) );
}
//采用启发式淘汰算法求解最大子数组的问题
double MaxInspire(double *a,int N){
    double max_end_sum=0;
    double currentMax_so_far=INF;
    for (int i=0; i<N; i++) {
        max_end_sum+=a[i];
        if(max_end_sum<0){max_end_sum=0;}
        currentMax_so_far=maxl(max_end_sum, currentMax_so_far);
    }
    return currentMax_so_far;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<maxl(5,4,5)<<endl;
    double a[]={1,-2,3,4,-5,6,7,8,9,-11};
    cout<<MaxDivQue(a, 10, 0, 9)<<endl;
    cout<<MaxItera(a, 10)<<endl;
    cout<<MaxIteFebi(a, 10)<<endl;
    cout<<MaxInspire(a, 10)<<endl;
    return 0;
}
