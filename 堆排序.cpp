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

void heapadjust(sqlist &L,int s,int t)//����L.r[s]֮�ⶼ����ѵ�����
{
	//L.r[s....t]
	NODE res = L.r[s];
	int j=2*s;
	for(int j=2*s;j<=t;j*=2)
	{
		if(j<t&&L.r[j].key < L.r[j+1].key) j=j+1;//����󶥶�
		if(res.key>=L.r[j].key) break;
		L.r[s] = L.r[j];s=j;//�൱                 
	}
	L.r[s] = res;           //�ڽ���
}

void heapsort(sqlist &L)
{
	for(int i=L.length/2;i>0;i--)//L.length/2��ȡ������㶼��Ҷ�ӣ�ÿ��Ҷ���൱��һ���ѣ����Դ�L.length/2��ʼ 
		heapadjust(L,i,L.length);
	NODE tmp;
	tmp = L.r[1];L.r[1] = L.r[L.length];L.r[L.length] = tmp;
	for(int i=L.length-1;i>1;i--)//���һ�����ù�
	{
		heapadjust(L,1,i);//��1-i��Щ�����¹���һ����
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
