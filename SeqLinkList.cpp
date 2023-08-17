/***
 * @name SeqLinkList ������
 * @date 2023/05/17
 * @author oafz
 * @details
 * 
 * (1)������Ķ���
 * ��1.1��������Ľ�����ͷ�巨��β�巨��
 * ��2��InitList(L) ��ʼ��������
 * ��3��ListInsert(L,i,e) L����iλ�ã�eԪ�أ�
 * ��4��InsertNextNode(p,e)p��㣬eԪ�� ָ�����ĺ�����
 * ��5��InsertPriorNode(p,e)p��㣬eԪ�� ָ������ǰ�����
 * ��6��ListDelete(L,i,e) ��λ��ɾ��Ԫ��
 * ��7��GetElem(L,i)��λ����Ԫ��
 * ��8��LocateElem(L,e)��ֵ����Ԫ��
 * ��9�����ĳ��� 
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

//�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩
bool ListInsert(LinkList&L , int i, ElemType e)
{
    if(i<1)
    {
        printf("λ��i���벻�Ϸ�");
        return false;
    }
    LNode *p;   //ָ��pָ��ǰɨ�赽�Ľ��
    int j = 0;  //��ǰpָ����ǵڼ������
    p = L;      //Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
    while (p!=NULL && j<i-1)    //ѭ���ҵ���i-1�����
    {
        p=p->next;
        j++;
    }
    if(p==NULL) //iֵ���Ϸ�
    {
        printf("λ��i���벻�Ϸ�");
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;    //�����s����p֮��
    return true;
}


bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if(i<1)
    {
        printf("λ��i���벻�Ϸ�");
        return false;
    }
    LNode *p;   //ָ��pָ��ǰɨ�赽�Ľ��
    int j = 0;  //��ǰpָ����ǵڼ������
    p = L;      //Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
    while (p != NULL && j<i-1)  //ѭ���ҵ���i-1�����
    {
        p=p->next;
        j++;
    }
    if(p == NULL)   //iֵ���Ϸ�
    {
        printf("λ��i���벻�Ϸ�");
        return false;
    }
    if(p->next == NULL)
    {
        printf("֮�������������");
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
        printf("λ��i���벻�Ϸ���\n");
        return NULL;
    }
    LNode *p;   //ָ��pָ��ǰɨ�赽�Ľ��
    int j = 0;  //��ǰpָ����ǵڼ������
    

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
        printf("�����е�ǰԪ��Ϊ��");
        while (p)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
    else
    {
        printf("��ǰ����Ϊ�գ�\n");
    }
}



void Insert(LinkList &L)
{
    int place; ElemType e; bool flag;
    printf("������Ҫ�����λ�ã���1��ʼ����Ԫ�أ�\n");
    scanf("%d%d",&place,&e);
    flag = ListInsert(L,place,e);
    if(flag)
    {
        printf("����ɹ���\n");
        PrintList(L);
    }
}

void Delete(LinkList &L)
{
    int place; ElemType e; bool flag;
    printf("������Ҫɾ����λ�ã�\n");
    scanf("%d",&place);
    flag = ListDelete(L,place,e);
    if(flag)
    {
        printf("ɾ���ɹ�!\n");
        PrintList(L);
    }
}

void Search(LinkList &L)
{

}

void menu()
{
    printf("************1.����    2.ɾ��***********\n");
    printf("************3.����    4.���***********\n");
    printf("************5.�˳�    ***********\n");
}

int main()
{
    LinkList L;
    InitList(L);
    int choice;
    while (1)
    {
        menu();
        printf("������˵���ţ�\n");
        scanf("%d",&choice);
        if(choice == 5)break;
        switch (choice)
        {
        
        case 1: Insert(L); break;
        case 2: Delete(L); break;
        case 3: Search(L); break;
        case 4: PrintList(L);break;
        default:
            printf("�˵��������");
        }
    }
    return 0;
}




