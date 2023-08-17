/**
 * @name SeqStaticListNotHead  数据结构-链表-不带头结点
 * @date 2023/05/13
 * @author oafz 
 * @details
 * 
 * InitList(LinkList& L); 参数：单链表， 功能：初始化
 * ListLength(LinkList L) 参数：单链表，功能：获取单链表长度
 * ListInsert(LinkList& L, int i, ElemType e);参数：单链表L，位置i，元素e；功能：在位置i中进行后插
 * ListDelete(LinkList& L, int i);参数：单链表L，位置i；功能：删除位置i的元素
 * LocateElem(LinkList L,ElemType e);参数：单链表L，元素：e；功能：查找第一个等于e的元素，返回指针
 * 
*/

#include <iostream>

#define Status int
#define ElemType int

using namespace std;


typedef struct LNode//定义单链表结点类型
{
    ElemType data;//数据域，每个结点存放一个数据元素
    struct LNode *next;//指针域，指针指向下一个结点
}LNode, *LinkList;

//初始化一个空的单链表
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}

//求链表的长度
int ListLength(LinkList L)
{
    LinkList p = L; int sum = 0;
    while (p)
    {
        sum++;
        p=p->next;
    }
    return sum;
}

//按位序插入元素e（重要）
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if(i<1) return false;
    if(i==1) //注意：插入第1个结点和其它结点有所不同
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L=s;
        return true;
    }
    LNode *p;//指针p指向当前扫描到的结点
    int j=1;
    p = L;
    while (p != NULL && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL) //i值不合法
    return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;//插入成功
}

//**********************************功能实现函数*******************************
//遍历输出函数
void PrintList(LinkList L)
{
    LinkList p = L;
    if(ListLength(L))
    {
        printf("当前单链表的所有元素：\n");
        while (p)
        {
            printf("%d ",p->data);
            p = p->next;
        }
        printf("\n");
    }
    else
    {
        printf("当前单链表已空。\n");
    }

}

void Insert(LinkList &L)
{
    int place; ElemType e; bool flag;
    printf("请输入要插入的位置（从1开始）及元素：");
    scanf("%d%d",&place, &e);
    flag = ListInsert(L,place,e);
    if(flag)
    {
        printf("插入成功！\n");
        PrintList(L);
    }
}

void Delete(LinkList &L)
{

}


void Select(LinkList L)
{

}

void menu()
{
    printf("*********************1.插入   2.删除********************\n");
    printf("*********************3.查找   4.输出********************\n");
    printf("*********************5.退出        *********************\n");
}

int main()
{
    LinkList L; int choice;
    InitList(L);
    while (1)
    {
        menu();
        printf("请输入菜单序号：\n");
        scanf("%d",&choice);
        if(choice == 5) break;
        switch (choice)
        {
        case 1:Insert(L);break;
        case 2:Delete(L);break;
        case 3:Select(L);break;
        case 4:PrintList(L);break;
        default:printf("输入错误！\n");
            break;
        }
    }
    return 0;
}