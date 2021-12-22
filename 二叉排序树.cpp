//二叉排序树
#include <iostream>
using namespace std;

typedef struct BiTree
{
	int data;
	BiTree *lchild,*rchild;
}*pBTNode,BiTree;

void Insert_BST(pBTNode &T,int e)
{
	//在以T为根节点的二叉排序树中插入记录e
	pBTNode s = new BiTree;
	s->data = e;
	s->lchild = s->rchild = NULL;
	if(!T) T = s;         //插入节点为根节点
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

void BSTsort(int a[],int n)//数组和顺序表都可，n为数组长度
{
	pBTNode T = NULL;//初始化一个空树
	//利用中序遍历二叉排序树对已知数组进行顺序输出（可以理解为排序）
	for(int i=0;i<n;i++)
		Insert_BST(T,a[i]);
	InOrder(T);//中序遍历
}

int main()
{
	int a[10] = {49,38,65,76,49,13,27,52};
	BSTsort(a,8);
	return 0;
}
