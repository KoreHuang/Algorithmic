//
//  main.c
//  movetoend
//
//  Created by mac on 16/9/28.
//  Copyright © 2016年 mac. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
//rename the element data type

typedef struct node{
    ElemType data;
    struct node *next;
}LinkNode,*LinkList;
//Define the linklist node data area and the pointer point to the next node

//create list data copy from array #Array#
LinkList CreateList(ElemType * Array,int n){
    LinkList Head=NULL;
    LinkNode *p=NULL,*q=NULL;
    for (int i=0; i<n; i++) {
        p=(LinkNode*)malloc(sizeof(LinkNode));
        p->data=Array[i];
        p->next=NULL;
        if(!Head) q=Head=p;
        else q=q->next=p;
    }
    return Head;
}
//show the linked list head
void showLinkList(LinkList Head){
    LinkNode *p=Head;
    int cnt=1;
    while (p) {
        printf("%02d ",p->data);
        if(!(cnt%10)){
            printf("\n");
        }
        p=p->next; cnt++;
    }
}

void freeMem(LinkList head){
    LinkNode *p=head;
    while (p&&head) {
        p=head;
        head=head->next;
        free(p);
    }
}

int movetoend(LinkList La,int i){
    LinkNode *p=La,*q=NULL;
    int j;
    if(!i) return -1;
    for( j=0;p&&j<i-1;j++,p=p->next);
    if(j<i) return -1;
    if(p->next){
        q=p->next;
        p->next=q->next;
    }
    if(q){
        while (p->next) p=p->next;
        p->next=q;
        q->next=NULL;
        return 0;
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    int data[21]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    LinkList head=CreateList(data, 21);
    showLinkList(head);
    printf("\n");
    int i=movetoend(head, 21);
    showLinkList(head);
    printf("\n%d\n",i);
    freeMem(head);
    return 0;
}
