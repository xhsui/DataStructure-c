//
//  main.c
//  LinearList2
//
//  Created by xhsui on 2018/3/12.
//  Copyright © 2018年 xhsui. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode *PtrToLNode;
struct LNode {
   int Data;
   PtrToLNode Next;
};
typedef PtrToLNode List;

List ListMakeEmply(void);
int ElementTypeFindKth(List L, int i);
int PositionFind(List L, int X);
int Insert(List L, int X, int i);
List InsertByHeader(List L, int X, int i);
int Delete(List L, int i);
int Length(List L);
void Ergodic(List L);
 
int main(int argc, const char * argv[]) {
   List L = ListMakeEmply();
   Insert(L, 2, 1);
   Insert(L, 5, 2);
   Insert(L, 6, 2);
   Insert(L, 7, 1);
   Ergodic(L);
   
   printf("链表的长度为：%d \n", Length(L));
   Delete(L, 2);
   Ergodic(L);
   
   printf("寻找到的元素是: %d \n", ElementTypeFindKth(L, 2));
   
   printf("寻找到元素的位置是：%d \n", PositionFind(L, 7));
   
   return 0;
}
 
List ListMakeEmply(void) {
   List L;
   L = (List)malloc(sizeof(struct LNode));
   L->Next = NULL;
   return L;
}
 
int ElementTypeFindKth(List L, int i) {
   List pre = L;
   int cnt = 0;
   
   while (pre->Next && cnt != i-1) {
       pre = pre->Next;
       cnt++;
   }
   
   
   if(cnt == i - 1) {
       return pre->Next->Data;
   } else {
       printf("%d - %d \n", cnt, i);
       return 0;
   }
}
 
int PositionFind(List L, int X) {
   List pre = L;
   int cnt = 1;
   
   while (pre->Next) {
       if(pre->Next->Data == X) {
           return cnt;
       } else {
           pre = pre->Next;
           cnt ++;
       }
   }
   
   return 0;
}
 
int Length(List L) {
   List pre = L;
   int cnt = 0;
   
   while (pre->Next) {
       pre = pre->Next;
       cnt ++;
   }
   
   return cnt;
}
 
// 尾插法
int Insert(List L, int X, int i) {
   List tmp, pre;
   
   int cnt = 0;
   
   // 定义一个pre移动到L的第i个元素
   pre = L;
   while (pre && cnt < i-1) {
       pre = pre->Next;
       cnt++;
   }
   
   if(pre==NULL || cnt!=i-1) {
       printf("插入的位置错误 \n");
       return 0;
   } else {
       tmp = ListMakeEmply();
       tmp->Data = X;
       tmp->Next = pre->Next;
       pre->Next = tmp;
       return 1;
   }
}
 
// 头插法的链表插入，预定义不符合返回一个int型
List InsertByHeader(List L, int X, int i) {
   List tmp, pre;
   tmp = ListMakeEmply();
   L->Data = X;
   
   if (i == 1) {
       tmp->Next = L;
       return L;
   } else {
       int cnt = 1;
       pre = L;
       while (pre && cnt < i -1) {
           pre = pre->Next;
           cnt++;
       }
       
       if(pre == NULL || cnt != i-1) {
           printf("插入的节点参数错误");
           free(tmp);
           return L;
       } else {
           tmp->Next = pre->Next;
           pre->Next = tmp;
       
           return L;
       }
   }
   return L;
}
 
int Delete(List L, int i) {
   List pre,tmp;
   int cnt = 0;
   
   // 定义一个pre移动到L的第i个元素
   pre = L;
   while (pre && cnt < i-1) {
       pre = pre->Next;
       cnt++;
   }
   
   if(pre==NULL || cnt!=i-1 || pre->Next == NULL) {
       printf("插入的位置错误 \n");
       return 0;
   } else {
       tmp = pre->Next;
       pre->Next = tmp->Next;
       free(tmp);
       return 1;
   }
};
 
void Ergodic(List L) {
   printf("链表的内容：");
   List pre;
   pre = L;
   while(pre->Next) {
       printf("%d ", pre->Next->Data);
       pre = pre->Next;
       
   }
   printf("\n");
}