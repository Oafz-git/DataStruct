/**
 * @name SeqStaticList  数据结构-顺序表-静态存储
 * @date 2023/05/13
 * @author oafz 
 * @details
 * 
 * ListCreate(SqList &L, int n) 参数：顺序表L，顺序表长度n 功能：创建长度为n的顺序表
 * ListInit(SqList &L) 参数：顺序表L 功能：初始化
 * ListInsert(SqList &L, int i , ElemType e) 参数：顺序表L，位置i，元素e 功能：在位置i处插入数据元素e
 * ListDelete(Sqlist &L, int i,ElemType &e);参数：顺序表L，位置i,元素e 功能：删除位置i处的数据元素，并返回
 * LocateElem(Sqlist &L, ElemType e);参数：顺序表L， 元素e 功能：返回第一个等于e的元素的位置
 * Reverse(SqList &L) 参数：顺序表L 功能：倒置函数，将原顺序表直接倒置
 * PrintList(SqList L) 参数：顺序表L 功能：遍历L，并输出
 * SplitSort(SqList &L) 参数：顺序表L 功能：分开奇偶，并分开排序
 * ClearList(SqList &L) 参数：顺序表L 功能：清空顺序表
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
    ElemType data[MaxSize]; //用静态的“数组”存放数据元素
    int length;             //顺序表的当前长度
}SqList;                    //顺序表的类型定义

//**************************基本操作函数***********************

Status ListInit(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;              //将所有数据元素设置为默认初始值，注意：没有设置数据元素的默认值，内存中会遗留“脏数据”
    }
    L.length = 0;                  //初始化长度为0
    return 0;
}

//创建顺序表函数，初始化前n个数据
bool ListCreate(SqList &L, int n)
{
    if(n<0||n>MaxSize) return false;//n非法
    for(int i=0; i<n; i++)//初始化前n个数据
    {
        scanf("%d",&L.data[i]);
        L.length++;
    }
    return true;
}

//插入函数 位置i插入数据  i及之后元素后移  1=<i<=length+1
bool ListInsert(SqList &L, int i, ElemType e)
{
    if(i<0||i>L.length)         //判断i的范围是否有效
    {
        printf("位置无效！\n");
        return false;
    } 

    if(L.length>=MaxSize) 
    {
        printf("当前存储空间已存满！\n"); //当前存储空间已满，不能插入
        return false;
    }
    for(int j=L.length; j>=i; j--)      //将第i个元素及之后的元素后移
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;                    //在位置i处放入e
    L.length++;                         //长度加1
    return true;
}

//删除函数：删除位置i的元素，i之后的元素依次前移
bool ListDelete(SqList &L,int i, int &e)
{
    if(i<1 || i>L.length)       //判断i的范围是否有效
    {
        printf("位置无效\n");
        return false;
    }
    e = L.data[i-1];            //将被删除的元素赋值给e
    for(int j=i; j<L.length; j++)//将i位置后的元素前移，注意：位序和数组下标的关系，并从前面的数据元素依次移动
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;//线性表的长度-1
    return true;
}

//按位查找
ElemType GetElem(SqList &L, int i)
{
    return L.data[i-1];
}

//按值查找位置  按位置从小到大查找第一个值等于e的元素，并返回位置
int LocateElem(SqList &L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if(L.data[i] == e)  //注意：C语言中，结构体的比较不能直接用“==”
        {
            return i+1;     //数组下标为i的元素值等于e，返回其位序i+1
        }
    }
    return 0; //退出循环，说明查找失败
}

//倒置函数 将原顺序表直接倒置
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

//奇偶分开 并排序（前奇数，后偶数）
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
            if(L.data[i]%2==0 && L.data[j]%2!=0 && i<j)//在前边找到偶数，在后边找到奇数，进行交换
            {
                int temp = L.data[i];
                L.data[i] = L.data[j];
                L.data[j] = temp;
                flag = true;
            }       
            if(!flag)//没有交换
            {
                if(i>j)//恰好分开
                {
                    Even = j;
                    Odd = i;
                }
                else
                {
                    Even = L.length - 1;//全奇数
                    Odd = 0;//全偶数
                }
            }
        }
        if(flag)//有交换
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

//清空顺序表
void ClearList(SqList& L)
{
    L.length = 0;
}

//**********************功能函数****************************

//打印输出
void PrintList(SqList L)
{
    printf("当前顺序表中所有的元素：");
    for(int i=0; i<L.length; i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}

//创建顺序表的函数
void Create(SqList &L)
{
    int n; bool flag;
    L.length = 0;
    printf("请输入要创建的顺序表长度(>1):");
    scanf("%d", &n);
    printf("请输入%d个数(空格隔开):",n);
    flag = ListCreate(L,n);
    if(flag)
    {
        printf("创建成功\n");
        PrintList(L);
    }
    else printf("输入长度非法! \n");
}

//插入功能：调用InsertList完成顺序表元素插入 调用PrintList函数显示插入成功后的结果
void Insert(SqList& L)
{
    int place;
    ElemType e;
    bool flag;
    printf("请输入要插入的位置(从1开始)及元素:\n");
    scanf("%d,%d",&place,&e);
    flag = ListInsert(L, place, e);
    if(flag)
    {
        printf("插入成功！\n");
        PrintList(L);
    }
}

//删除功能：调用ListDelete函数完成顺序表的删除 调用PrintList函数显示插入成功后的结果
void Delete(SqList& L)
{
    int place; bool flag; ElemType e;
    printf("请输入要删除的位置（从1开始）:\n");
    scanf("%d", &place);
    flag = ListDelete(L, place,e);
    if(flag)
    {
        printf("删除成功！\n");
        printf("删除的元素为：%d\n",e);
        PrintList(L);
    }
}

//查找功能：调用LocateElem查找元素
void Search(SqList& L)
{
    ElemType e; int flag;
    printf("请输入要查找的值：\n");
    scanf("%d", &e);
    flag = LocateElem(L, e);
    if (flag)
    {
        printf("该元素位置为：%d的\n", flag);
    }
    else printf("未找到元素! \n");

}


//菜单
void menu()
{
    printf("********************1.创建              2.插入**********************\n");
    printf("********************3.删除              4.查找**********************\n");
    printf("********************5.倒置              6.分奇偶排序**********************\n");
    printf("********************7.输出              8.清空**********************\n");
    printf("********************9.退出              **********************\n");
}

int main()
{
    SqList L; int choice;
    ListInit(L);
    while (1)
    {
        menu();
        printf("请输入菜单序号：\n");
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

        default:printf("输入错误！\n");
        }
    }
    

}