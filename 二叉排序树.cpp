//����������
#include <iostream>
using namespace std;

typedef struct BiTree
{
	int data;
	BiTree *lchild,*rchild;
}*pBTNode,BiTree;

void Insert_BST(pBTNode &T,int e)
{
	//����TΪ���ڵ�Ķ����������в����¼e
	pBTNode s = new BiTree;
	s->data = e;
	s->lchild = s->rchild = NULL;
	if(!T) T = s;         //����ڵ�Ϊ���ڵ�
	else
	{
		pBTNode p = new BiTree;
		pBTNode pre = new BiTree;
		p = T;
		while(p)
		{
			if(e < p->data)
			{
				pre = p;
				p = p->lchild;
			}
			else
			{
				pre = p;
				p = p->rchild;
			}
		}
		if(e < pre->data) pre->lchild = s;
		else pre->rchild = s;
	}
}

void InOrder(pBTNode T)
{
	if(T)
	{
		InOrder(T->lchild); 
		cout<<T->data<<" ";
		InOrder(T->rchild);
	}
}

void BSTsort(int a[],int n)//�����˳����ɣ�nΪ���鳤��
{
	pBTNode T = NULL;//��ʼ��һ������
	//�������������������������֪�������˳��������������Ϊ����
	for(int i=0;i<n;i++)
		Insert_BST(T,a[i]);
	InOrder(T);//�������
}

int main()
{
	int a[10] = {49,38,65,76,49,13,27,52};
	BSTsort(a,8);
	return 0;
}
