/***
 * @name SeqLinkList 单链表
 * @date 2023/05/17
 * @author oafz
 * @details
 * 
 * (1)单链表的定义
 * （1.1）单链表的建立（头插法，尾插法）
 * （2）InitList(L) 初始化单链表
 * （3）ListInsert(L,i,e) L链表，i位置，e元素；
 * （4）InsertNextNode(p,e)p结点，e元素 指定结点的后插操作
 * （5）InsertPriorNode(p,e)p结点，e元素 指定结点的前插操作
 * （6）ListDelete(L,i,e) 按位序删除元素
 * （7）GetElem(L,i)按位查找元素
 * （8）LocateElem(L,e)按值查找元素
 * （9）求表的长度 
 * 
*/

#include <iostream>
#define ElemType int
#define Status int


typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

bool InitList(LinkList &L)
{
    LNode* p = (LNode*)malloc(sizeof(LNode));
    if(p==NULL) return false;
    L = p;
    L->next = NULL;
    return true;
}

//在第i个位置插入元素e（带头结点）
bool ListInsert(LinkList&L , int i, ElemType e)
{
    if(i<1)
    {
        printf("位序i输入不合法");
        return false;
    }
    LNode *p;   //指针p指向当前扫描到的结点
    int j = 0;  //当前p指向的是第几个结点
    p = L;      //L指向头结点，头结点是第0个结点（不存数据）
    while (p!=NULL && j<i-1)    //循环找到第i-1个结点
    {
        p=p->next;
        j++;
    }
    if(p==NULL) //i值不合法
    {
        printf("位序i输入不合法");
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;    //将结点s连到p之后
    return true;
}


bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if(i<1)
    {
        printf("位序i输入不合法");
        return false;
    }
    LNode *p;   //指针p指向当前扫描到的结点
    int j = 0;  //当前p指向的是第几个结点
    p = L;      //L指向头结点，头结点是第0个结点（不存数据）
    while (p != NULL && j<i-1)  //循环找到第i-1个结点
    {
        p=p->next;
        j++;
    }
    if(p == NULL)   //i值不合法
    {
        printf("位序i输入不合法");
        return false;
    }
    if(p->next == NULL)
    {
        printf("之后已无其它结点");
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

LNode* GetElem(LinkList &L, int i)
{
    if(i<1)
    {
        printf("位序i输入不合法！\n");
        return NULL;
    }
    LNode *p;   //指针p指向当前扫描到的结点
    int j = 0;  //当前p指向的是第几个结点
    

}

int ListLength(LinkList &L)
{
    LNode *p = L->next; int sum = 0;
    while(p)
    {
        sum++;
        p=p->next;
    }
    return sum;
}

void PrintList(LinkList& L)
{
    LNode *p = L->next;
    if(ListLength(L))
    {
        printf("链表中当前元素为：");
        while (p)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
    else
    {
        printf("当前链表为空！\n");
    }
}



void Insert(LinkList &L)
{
    int place; ElemType e; bool flag;
    printf("请输入要插入的位置（从1开始）及元素：\n");
    scanf("%d%d",&place,&e);
    flag = ListInsert(L,place,e);
    if(flag)
    {
        printf("插入成功！\n");
        PrintList(L);
    }
}

void Delete(LinkList &L)
{
    int place; ElemType e; bool flag;
    printf("请输入要删除的位置：\n");
    scanf("%d",&place);
    flag = ListDelete(L,place,e);
    if(flag)
    {
        printf("删除成功!\n");
        PrintList(L);
    }
}

void Search(LinkList &L)
{

}

void menu()
{
    printf("************1.插入    2.删除***********\n");
    printf("************3.查找    4.输出***********\n");
    printf("************5.退出    ***********\n");
}

int main()
{
    LinkList L;
    InitList(L);
    int choice;
    while (1)
    {
        menu();
        printf("请输入菜单序号：\n");
        scanf("%d",&choice);
        if(choice == 5)break;
        switch (choice)
        {
        
        case 1: Insert(L); break;
        case 2: Delete(L); break;
        case 3: Search(L); break;
        case 4: PrintList(L);break;
        default:
            printf("菜单输入错误！");
        }
    }
    return 0;
}




