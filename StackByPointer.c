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
int IsEmpty(Stack S);
int Push(Stack S, int X);
int Push(Stack S, int X);
int Pop(Stack S);

int main(int argc, const char * argv[]) {
    Stack S;
    S = CreateStack(5);
    
    printf("弹出的元素是：%d \n", Pop(S));
    
    Push(S, 3);
    Push(S, 6);
    printf("弹出的元素是：%d \n", Pop(S));
    
    Push(S, 1);
    
    printf("弹出的元素是：%d\n", Pop(S));
    
    
    printf("Hello, World!\n");
    return 0;
}

Stack CreateStack()
{
    Stack S;
    S = malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

int Push(Stack S, int X)
{
    Stack newCell;
    newCell = CreateStack();
    newCell->Data = X;
    newCell->Next = S->Next;
    S->Next = newCell;
    return X;
}

int Pop(Stack S)
{
    PtrToSNode FirstCell;
    int Data;
    
    if(IsEmpty(S)) {
        printf("堆栈空 \n");
        return -1;
    }
    FirstCell = S->Next;
    Data = FirstCell->Data;
    S->Next = FirstCell->Next;
    free(FirstCell);
    return Data;
}
