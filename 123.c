#include<stdio.h>
#include<stdbool.h>
#define MaxSize 50
typedef struct{
	int data[MaxSize];
	int length;
}SqList;
void ListInit(SqList *L){
	L->length = 0;
	for (int i = 0; i < MaxSize; i++)
		L->data[i] = 0;

}
bool ListInsert(SqList *L,int i, int e){
	if (i<1 || i>L->length + 1)
	{

		return false;
	}
	if (L->length >= MaxSize)
		return false;
	for (int j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}
int LocateElem(SqList *L , int e) {
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == e)
			return i + 1;
		else if (i == L->length)
			return 0;
	}
}
bool ListDelete(SqList* L, int i,int *e) {
	if (i<1 || i>L->length)
		return false;
	*e = L->data[i - 1];
	for (int j = i; j < L->length; j++) {
		L->data[j - 1] = L->data[j];
	}
	L->length--;
	return true;
}
int main()
{
	SqList list;
	SqList *L=&list;
	ListInit(L);
	ListInsert(L, 1, 100);
	int c = LocateElem(L, 100);
	printf("输出100的位置为%d",c);
	int a=0;
	int *e=&a;
	ListDelete(L, 1,e);
	printf("输出第一个数字为%d,删除的数字为%d", L->data[0], a);
	return 0;
}
