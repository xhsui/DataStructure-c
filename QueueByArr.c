//
//  main.c
//  Stack1
//
//  Created by xhsui on 2018/3/23.
//  Copyright © 2018年 xhsui. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node * PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode * PtrToQNode;
struct QNode {
    Position Front, Rear;
    int MaxSize;
}
typedef PtrToQNode Queue;

Queue CreateQueue();
int isFull(Queue Q);
int AddQ(Queue Q, ElementType X);
int IsEmpty(Queue Q);
ElementType DeleteQ(Queue Q);

int main()
{
    Queue Q;
    Q = CreateQueue(10);
    printf("弹出一个元素：%d \n", DeleteQ(Q));
    printf("添加一个元素：%d \n", AddQ(Q, 5));
    printf("弹出一个元素：%d \n", DeleteQ(Q));
    printf("添加一个元素：%d \n", AddQ(Q, 1));
    printf("添加一个元素：%d \n", AddQ(Q, 3));
    
    printf("弹出一个元素：%d \n", DeleteQ(Q));
    
    printf("添加一个元素：%d \n", AddQ(Q, 6));
    
    printf("弹出一个元素：%d \n", DeleteQ(Q));
    printf("hello world! \n");
}

Queue CreateQueue(int MaxSize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

int AddQ(Queue Q, ElementType X)
{
    if(isFull(Q)) {
        printf("队列满 \n");
        return -1;
    }
    
    Q->Rear = (Q->Rear + 1) % Q->MaxSize;
    Q->Data[ Q->Rear ] = X;
    return X;
}

ElementType DeleteQ(Queue Q)
{
    if(IsEmpty(Q)) {
        printf("队列空 \n");
        return -1;
    }
    
    Q->Front = (Q->Front + 1) % Q->MaxSize;
    return Q->Data[Q->Front];
}

int isFull(Queue Q)
{
    return (Q->Rear + 1) % Q->MaxSize == Q->Front;
}

int IsEmpty(Queue Q)
{
    return Q->Front == Q->Rear;
}