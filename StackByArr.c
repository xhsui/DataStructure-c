//
//  main.c
//  Stack1
//
//  Created by xhsui on 2018/3/23.
//  Copyright © 2018年 xhsui. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct SNode *PtrToSNode;
struct SNode {
    int Data;
    PtrToSNode Next;
    
};
typedef PtrToSNode Stack;

Stack CreateStack();
int IsFull(Stack S);
int IsEmpty(Stack S);
int Push(Stack S, int X);
int Pop(Stack S);

int main(int argc, const char * argv[]) {
    Stack S;
    S = CreateStack();
    
    printf("弹出的元素是：%d \n", Pop(S));
    
    Push(S, 3);
    Push(S, 6);
    printf("弹出的元素是：%d \n", Pop(S));
    
    Push(S, 1);
    
    printf("弹出的元素是：%d\n", Pop(S));
    
    
    printf("Hello, World!\n");
    return 0;
}
