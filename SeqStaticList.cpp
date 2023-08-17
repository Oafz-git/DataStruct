/**
 * @name SeqStaticList  ���ݽṹ-˳���-��̬�洢
 * @date 2023/05/13
 * @author oafz 
 * @details
 * 
 * ListCreate(SqList &L, int n) ������˳���L��˳�����n ���ܣ���������Ϊn��˳���
 * ListInit(SqList &L) ������˳���L ���ܣ���ʼ��
 * ListInsert(SqList &L, int i , ElemType e) ������˳���L��λ��i��Ԫ��e ���ܣ���λ��i����������Ԫ��e
 * ListDelete(Sqlist &L, int i,ElemType &e);������˳���L��λ��i,Ԫ��e ���ܣ�ɾ��λ��i��������Ԫ�أ�������
 * LocateElem(Sqlist &L, ElemType e);������˳���L�� Ԫ��e ���ܣ����ص�һ������e��Ԫ�ص�λ��
 * Reverse(SqList &L) ������˳���L ���ܣ����ú�������ԭ˳���ֱ�ӵ���
 * PrintList(SqList L) ������˳���L ���ܣ�����L�������
 * SplitSort(SqList &L) ������˳���L ���ܣ��ֿ���ż�����ֿ�����
 * ClearList(SqList &L) ������˳���L ���ܣ����˳���
 * 
*/

#include<cstdio>
#include<malloc.h>
#include<algorithm>

#define MaxSize 10
#define ElemType int
#define Status int

using namespace std;

typedef struct
{
    ElemType data[MaxSize]; //�þ�̬�ġ����顱�������Ԫ��
    int length;             //˳���ĵ�ǰ����
}SqList;                    //˳�������Ͷ���

//**************************������������***********************

Status ListInit(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;              //����������Ԫ������ΪĬ�ϳ�ʼֵ��ע�⣺û����������Ԫ�ص�Ĭ��ֵ���ڴ��л������������ݡ�
    }
    L.length = 0;                  //��ʼ������Ϊ0
    return 0;
}

//����˳���������ʼ��ǰn������
bool ListCreate(SqList &L, int n)
{
    if(n<0||n>MaxSize) return false;//n�Ƿ�
    for(int i=0; i<n; i++)//��ʼ��ǰn������
    {
        scanf("%d",&L.data[i]);
        L.length++;
    }
    return true;
}

//���뺯�� λ��i��������  i��֮��Ԫ�غ���  1=<i<=length+1
bool ListInsert(SqList &L, int i, ElemType e)
{
    if(i<0||i>L.length)         //�ж�i�ķ�Χ�Ƿ���Ч
    {
        printf("λ����Ч��\n");
        return false;
    } 

    if(L.length>=MaxSize) 
    {
        printf("��ǰ�洢�ռ��Ѵ�����\n"); //��ǰ�洢�ռ����������ܲ���
        return false;
    }
    for(int j=L.length; j>=i; j--)      //����i��Ԫ�ؼ�֮���Ԫ�غ���
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;                    //��λ��i������e
    L.length++;                         //���ȼ�1
    return true;
}

//ɾ��������ɾ��λ��i��Ԫ�أ�i֮���Ԫ������ǰ��
bool ListDelete(SqList &L,int i, int &e)
{
    if(i<1 || i>L.length)       //�ж�i�ķ�Χ�Ƿ���Ч
    {
        printf("λ����Ч\n");
        return false;
    }
    e = L.data[i-1];            //����ɾ����Ԫ�ظ�ֵ��e
    for(int j=i; j<L.length; j++)//��iλ�ú��Ԫ��ǰ�ƣ�ע�⣺λ��������±�Ĺ�ϵ������ǰ�������Ԫ�������ƶ�
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;//���Ա�ĳ���-1
    return true;
}

//��λ����
ElemType GetElem(SqList &L, int i)
{
    return L.data[i-1];
}

//��ֵ����λ��  ��λ�ô�С������ҵ�һ��ֵ����e��Ԫ�أ�������λ��
int LocateElem(SqList &L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if(L.data[i] == e)  //ע�⣺C�����У��ṹ��ıȽϲ���ֱ���á�==��
        {
            return i+1;     //�����±�Ϊi��Ԫ��ֵ����e��������λ��i+1
        }
    }
    return 0; //�˳�ѭ����˵������ʧ��
}

//���ú��� ��ԭ˳���ֱ�ӵ���
void Reverse(SqList &L)
{
    if(L.length)
    {
        for(int i=0; i<L.length-1; i++)
        {
            int t = L.data[i];
            L.data[i] = L.data[L.length-1-i];
            L.data[L.length-1-i] = t;
        }
    }
}

//��ż�ֿ� ������ǰ��������ż����
void SplitSort(SqList &L)
{
    int Even = 0;
    int Odd = L.length - 1;
    int i = 0;
    int j = L.length-1;
    bool flag = false;
    if(L.length)
    {
        for(; i<j; i++,j--)
        {
            while (L.data[i]%2 != 0 && i<L.length) i++;
            while (L.data[j]%2 == 0 && j>0) j--;
            if(L.data[i]%2==0 && L.data[j]%2!=0 && i<j)//��ǰ���ҵ�ż�����ں���ҵ����������н���
            {
                int temp = L.data[i];
                L.data[i] = L.data[j];
                L.data[j] = temp;
                flag = true;
            }       
            if(!flag)//û�н���
            {
                if(i>j)//ǡ�÷ֿ�
                {
                    Even = j;
                    Odd = i;
                }
                else
                {
                    Even = L.length - 1;//ȫ����
                    Odd = 0;//ȫż��
                }
            }
        }
        if(flag)//�н���
        {
            for(int i = 0; i<L.length; i++)
            {
                if(L.data[i]%2 == 0)
                {
                    Odd = i;
                    Even = i - 1;
                    break;
                }
            }
        }
    }
    sort(L.data,L.data+Even +1);
    sort(L.data+Odd,L.data+L.length);

}

//���˳���
void ClearList(SqList& L)
{
    L.length = 0;
}

//**********************���ܺ���****************************

//��ӡ���
void PrintList(SqList L)
{
    printf("��ǰ˳��������е�Ԫ�أ�");
    for(int i=0; i<L.length; i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}

//����˳���ĺ���
void Create(SqList &L)
{
    int n; bool flag;
    L.length = 0;
    printf("������Ҫ������˳�����(>1):");
    scanf("%d", &n);
    printf("������%d����(�ո����):",n);
    flag = ListCreate(L,n);
    if(flag)
    {
        printf("�����ɹ�\n");
        PrintList(L);
    }
    else printf("���볤�ȷǷ�! \n");
}

//���빦�ܣ�����InsertList���˳���Ԫ�ز��� ����PrintList������ʾ����ɹ���Ľ��
void Insert(SqList& L)
{
    int place;
    ElemType e;
    bool flag;
    printf("������Ҫ�����λ��(��1��ʼ)��Ԫ��:\n");
    scanf("%d,%d",&place,&e);
    flag = ListInsert(L, place, e);
    if(flag)
    {
        printf("����ɹ���\n");
        PrintList(L);
    }
}

//ɾ�����ܣ�����ListDelete�������˳����ɾ�� ����PrintList������ʾ����ɹ���Ľ��
void Delete(SqList& L)
{
    int place; bool flag; ElemType e;
    printf("������Ҫɾ����λ�ã���1��ʼ��:\n");
    scanf("%d", &place);
    flag = ListDelete(L, place,e);
    if(flag)
    {
        printf("ɾ���ɹ���\n");
        printf("ɾ����Ԫ��Ϊ��%d\n",e);
        PrintList(L);
    }
}

//���ҹ��ܣ�����LocateElem����Ԫ��
void Search(SqList& L)
{
    ElemType e; int flag;
    printf("������Ҫ���ҵ�ֵ��\n");
    scanf("%d", &e);
    flag = LocateElem(L, e);
    if (flag)
    {
        printf("��Ԫ��λ��Ϊ��%d��\n", flag);
    }
    else printf("δ�ҵ�Ԫ��! \n");

}


//�˵�
void menu()
{
    printf("********************1.����              2.����**********************\n");
    printf("********************3.ɾ��              4.����**********************\n");
    printf("********************5.����              6.����ż����**********************\n");
    printf("********************7.���              8.���**********************\n");
    printf("********************9.�˳�              **********************\n");
}

int main()
{
    SqList L; int choice;
    ListInit(L);
    while (1)
    {
        menu();
        printf("������˵���ţ�\n");
        scanf("%d", &choice);
        if(9 == choice) break;
        switch (choice)
        {
        case 1:Create(L); break;
        case 2:Insert(L); break;
        case 3:Delete(L); break;
        case 4:Search(L); break;
        case 5:Reverse(L); break;
        case 6:SplitSort(L); break;
        case 7:PrintList(L); break;
        case 8:ClearList(L); break;

        default:printf("�������\n");
        }
    }
    

}