#include<iostream>
using namespace std;

const int maxsize = 100;

typedef struct
{
	int key;
}NODE;

typedef struct
{
	NODE r[maxsize + 1];
	int length;
}sqlist;

void heapadjust(sqlist &L,int s,int t)//除了L.r[s]之外都满足堆的条件
{
	//L.r[s....t]
	NODE res = L.r[s];
	int j=2*s;
	for(int j=2*s;j<=t;j*=2)
	{
		if(j<t&&L.r[j].key < L.r[j+1].key) j=j+1;//建造大顶堆
		if(res.key>=L.r[j].key) break;
		L.r[s] = L.r[j];s=j;//相当                 
	}
	L.r[s] = res;           //于交换
}

void heapsort(sqlist &L)
{
	for(int i=L.length/2;i>0;i--)//L.length/2下取整个结点都是叶子，每个叶子相当于一个堆，所以从L.length/2开始 
		heapadjust(L,i,L.length);
	NODE tmp;
	tmp = L.r[1];L.r[1] = L.r[L.length];L.r[L.length] = tmp;
	for(int i=L.length-1;i>1;i--)//最后一个不用管
	{
		heapadjust(L,1,i);//将1-i这些再重新构成一个堆
		tmp = L.r[1];L.r[1] = L.r[i];L.r[i] = tmp;
	}
}

int main()
{
	sqlist L;
	L.length = 0;
	int pos,i=1;
	while(cin>>pos)
	{
		L.r[i++].key = pos;
		L.length++;
	}
	heapsort(L);

	for(int i=1;i<=L.length;i++)
	{
		cout<<" "<<L.r[i].key;
	}
	cout<<endl;

	return 0;
}
