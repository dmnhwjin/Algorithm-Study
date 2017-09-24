#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) exit(ERROR);
	L.listsize=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
}

void Create_SqList(SqList &L)
{
	int c,i=0;
	int *newBase;
	printf("Please enter element of sequencer,press Ctrl+z end");
	while((scanf("%d",&c))!=EOF)
	{
		if(i>=L.listsize)
		{
			newBase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
			if(!newBase) exit(OVERFLOW);
			L.elem=newBase;
			L.listsize+=LISTINCREMENT;
		}

		L.elem[i++]=c;
	}
	L.length=i;
	printf("Entered elements are:\n");
	for(i=0;i<L.length;i++)
	{
		printf("%d",L.elem[i]);
		printf("\n");
	}
}

Status ListInsert(SqList &L,int i,ElemType e)
{
	ElemType *p,*q,*newbase;
	if(i<1 || i>L.length+1)
	{
		printf("Location insert error\n");
			return(ERROR);

	}
	if(L.length>=L.listsize)
	{
		newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
	}
	if(i==L.length) L.elem[i+1]=e;
	q=&(L.elem[i-1]);
	for (p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++L.length;
	return OK;
}

ElemType GetElem(SqList &L,int i）
{
ElemType *e;
if(!L.elem || i>L.length || i<1)
{
exit(ERROR);
}
e=L.elem+i-1;
return *e;
}

int LocateElem(SqList &L,ElemType e)
{
int i;
if(!L.elem) exit(ERROR);
for(i=0;i<L.length-1;i++)
{
	if(e=L.elem(i) return i+1;
}
return 0;
}

int main()
{
	SqList L;
	int location,element;
	if(!InitList_Sq(L))
	{
		printf("Initialize  sequencer fail！\n");
		exit(ERROR);
	}
	Create_SqList(L);
	printf("Enter insert Location");
	scanf("%d",&location);
	while(location>L.length+1||location<1)
	{
		printf("Location enter wrong,please enter again\n");
		scanf("%d",&location);
	}
	printf("please enter element:\n");
	scanf("%d",&element);
	if(!ListInsert(L,location,element))
	{
		printf("Failed to insert sequencer\n");
		exit(ERROR);
	}
	printf("updated sequencer is:");
	for(int i=0;i<L.length-1;i++)
		printf("%d",L.elem[i]);

	printf("\nupdated list has total %d pcs elements.\n",L.length);

}


