//
//  main.c
//  LinearListByArr
//
//  线性表的顺序结构
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef int Position;

typedef struct LNode * PtrToLNode;
struct LNode {
    int Data[MAXSIZE];
    Position Last;
};
typedef PtrToLNode List;

List ListMakeEmply(void);
int ElementTypeFindKth(List L, int i);
int PositionFind(List L, int X);
int Insert(List L, int X, Position i);
int Delete(List L, int i);
int Length(List L);
void Ergodic(List L);

int main(int argc, const char * argv[]) {
    // 新建一个变量L
    List L;
    // 初始化变量L
    L = ListMakeEmply();
                          
    // 插入一个2的值放在链表的第1位
    Insert(L, 2, 1);
    // 查找元素第一个位置
    printf("当前查找的地址的结果是：%d \n", ElementTypeFindKth(L, 1));
    // 打印元素的长度
    printf("当前的链表的长度：%d \n", Length(L));
    // 插入一个2的值放在链表的第2位
    Insert(L, 3, 2);
    // 删除链表的第一个元素
    Delete(L, 1);
    // 插入一个2的值放在链表的第2位
    Insert(L, 5, 2);
    // 插入一个2的值放在链表的第2位
    Insert(L, 9, 1);
    // 查询元素为5的链表位置
    printf("搜索元素查询到的结果是:%d \n", PositionFind(L, 5));
                            
    // 循环遍历链表查看数据
    Ergodic(L);
}
                         
List ListMakeEmply(void) {
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}
                         
int ElementTypeFindKth(List L, int i) {
    if(i < 1 || i > L->Last + 1) {
        printf("查找的位置不合法 \n");
        return 0;
    }
                            
    return L->Data[i-1];
}
                         
int Insert(List L, int X, Position i) {
    Position j;
                            
    if(L->Last == MAXSIZE - 1) {
        printf("表满");
        return 0;
    }
                            
    if(i < 1 || i > L->Last + 2) {
        printf("插入的位置不合法 \n");
        return 0;
    }
                            
    for (j = L->Last; j >=i-1; j--) {
        L->Data[j+1] = L->Data[j];
    }
    L->Data[i-1] = X;
    L->Last++;
    return 1;
}
                         
int Delete(List L, int i) {
    Position j;
                            
    if(i < 1 || i > L->Last + 1) {
        printf("删除位置不合法 \n");
        return 0;
    }
                            
    for(j = i; j < L->Last; j++)
        L->Data[j-1] = L->Data[j];
                            
    L->Last--;
    return 1;
}
                         
int PositionFind(List L, int X) {
    int i = 0;
    while (i <= L->Last && L->Data[i] != X) {
        i++;
    }
                            
    return i <= L->Last ? i + 1 : 0;
}

int Length(List L) {
    return L->Last + 1;
}
                         
void Ergodic(List L) {
    int i = -1;
    printf("链表的内容：");
    while(i < L->Last) {
        printf("%d ", L->Data[i+1]);
        i++;
    }
    printf("\n");
}