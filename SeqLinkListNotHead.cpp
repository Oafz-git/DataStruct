/**
 * @name SeqStaticListNotHead  ���ݽṹ-����-����ͷ���
 * @date 2023/05/13
 * @author oafz 
 * @details
 * 
 * InitList(LinkList& L); ������������ ���ܣ���ʼ��
 * ListLength(LinkList L) ���������������ܣ���ȡ��������
 * ListInsert(LinkList& L, int i, ElemType e);������������L��λ��i��Ԫ��e�����ܣ���λ��i�н��к��
 * ListDelete(LinkList& L, int i);������������L��λ��i�����ܣ�ɾ��λ��i��Ԫ��
 * LocateElem(LinkList L,ElemType e);������������L��Ԫ�أ�e�����ܣ����ҵ�һ������e��Ԫ�أ�����ָ��
 * 
*/

#include <iostream>

#define Status int
#define ElemType int

using namespace std;


typedef struct LNode//���嵥����������
{
    ElemType data;//������ÿ�������һ������Ԫ��
    struct LNode *next;//ָ����ָ��ָ����һ�����
}LNode, *LinkList;

//��ʼ��һ���յĵ�����
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}

//������ĳ���
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

//��λ�����Ԫ��e����Ҫ��
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if(i<1) return false;
    if(i==1) //ע�⣺�����1�������������������ͬ
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L=s;
        return true;
    }
    LNode *p;//ָ��pָ��ǰɨ�赽�Ľ��
    int j=1;
    p = L;
    while (p != NULL && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL) //iֵ���Ϸ�
    return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;//����ɹ�
}

//**********************************����ʵ�ֺ���*******************************
//�����������
void PrintList(LinkList L)
{
    LinkList p = L;
    if(ListLength(L))
    {
        printf("��ǰ�����������Ԫ�أ�\n");
        while (p)
        {
            printf("%d ",p->data);
            p = p->next;
        }
        printf("\n");
    }
    else
    {
        printf("��ǰ�������ѿա�\n");
    }

}

void Insert(LinkList &L)
{
    int place; ElemType e; bool flag;
    printf("������Ҫ�����λ�ã���1��ʼ����Ԫ�أ�");
    scanf("%d%d",&place, &e);
    flag = ListInsert(L,place,e);
    if(flag)
    {
        printf("����ɹ���\n");
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
    printf("*********************1.����   2.ɾ��********************\n");
    printf("*********************3.����   4.���********************\n");
    printf("*********************5.�˳�        *********************\n");
}

int main()
{
    LinkList L; int choice;
    InitList(L);
    while (1)
    {
        menu();
        printf("������˵���ţ�\n");
        scanf("%d",&choice);
        if(choice == 5) break;
        switch (choice)
        {
        case 1:Insert(L);break;
        case 2:Delete(L);break;
        case 3:Select(L);break;
        case 4:PrintList(L);break;
        default:printf("�������\n");
            break;
        }
    }
    return 0;
}