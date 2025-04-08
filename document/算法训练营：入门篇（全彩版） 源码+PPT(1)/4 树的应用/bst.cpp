#include<iostream>
using namespace std;
#define ENDFLAG -1

typedef struct BSTNode{ //二叉搜索树节点
	int data;	         //数据域
	BSTNode *lchild,*rchild; //左右孩子指针
}BSTNode,*BSTree;

BSTree SearchBST(BSTree T,int x){ //二叉搜索树查找
    if(!T||x==T->data)//若查找成功，则返回指向该元素的指针，否则返回空指针
        return T;
    if(x<T->data)
        SearchBST(T->lchild,x);//在左子树中继续查找
    else
        SearchBST(T->rchild,x); //在右子树中继续查找
}

void InsertBST(BSTree &T,int x){ //二叉搜索树插入
    //当二叉搜索树T中不存在等于x的元素时，则插入x
	if(!T){  //如果为空树
		BSTree s=new BSTNode;  //生成新节点
		s->data=x;             //新节点s的数据域为x
		s->lchild=s->rchild=NULL;//新节点s作为叶子节点
		T=s;            		//把新节点s链接到已找到的插入位置
		return; 
	}
	if(x==T->data) return;  //若查找成功，什么也不做
	if(x<T->data)
		InsertBST(T->lchild,x); //插入到左子树中 
	else if(x>T->data)
		InsertBST(T->rchild,x); //插入到右子树中 
}

void CreateBST(BSTree &T){ //二叉搜索树创建
	T=NULL;
	int x;
	cin>>x;
	while(x!=ENDFLAG){ //ENDFLAG为自定义常量，作为输入结束标志
	    InsertBST(T,x);  //插入二叉搜索树T中
	    cin>>x;
	}
}

void DeleteBST(BSTree &T,int x){ //二叉搜索树删除
	BSTree p=T,f=NULL,q,s;
	if(!T) return; //树为空则返回
	while(p){//查找
		if(x==p->data) break;  //找到关键字等于x的节点p，结束循环
		f=p;                //f为p的父节点 
		if(x<p->data)
			p=p->lchild; //在p的左子树中继续查找
		else
			p=p->rchild; //在p的右子树中继续查找
	}
	if(!p) return; //找不到被删节点则返回
	//三种情况：p左右子树均不空、无右子树、无左子树
	if((p->lchild)&&(p->rchild)){ //被删节点p左右子树均不空
		q=p;
		s=p->lchild;
		while(s->rchild){//查找其前驱节点，即p的左子树最右节点
			q=s;
			s=s->rchild;
		}
		p->data=s->data;  //s的值赋值给被删节点p,然后删除s节点
		if(q!=p)
			q->rchild=s->lchild; //重接q的右子树
		else
			q->lchild=s->lchild; //重接q的左子树
		delete s;
	}
	else{
		if(!p->rchild){//被删节点p无右子树，只需重接其左子树
			q=p;
			p=p->lchild;
		}
		else if(!p->lchild){//被删节点p无左子树，只需重接其右子树
			q=p;
			p=p->rchild;
		}
		/*―――将p所指的子树挂接到其父节点f相应的位置―――*/
		if(!f)
			T=p;  //被删节点为根节点
		else if(q==f->lchild)
				f->lchild=p; //挂接到f的左子树位置
			else
				f->rchild=p;//挂接到f的右子树位置
		delete q;
	}
}

void InOrderTraverse(BSTree T){//中序遍历
    if(T){
        InOrderTraverse(T->lchild);
        cout<<T->data<<"\t";
        InOrderTraverse(T->rchild);
	}
}

void PreOrderTraverse(BSTree T){//先序遍历
    if(T){
        cout<<T->data<<"\t";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
	}
}

int main(){
	BSTree T;
	CreateBST(T); //输入一些整数，-1结束
	cout<<"二叉搜索树的中序遍历："<<endl;
	InOrderTraverse(T);
	cout<<endl;
	cout<<"二叉搜索树的先序遍历："<<endl;
	PreOrderTraverse(T);
	cout<<endl;
	int x;  //待查找或待删除元素 
	cout<<"请输入待查找关键字"<<endl;
	cin>>x;
	BSTree result=SearchBST(T,x);
	if(result)
        cout<<"找到"<<x<<endl;
	else
        cout<<"未找到"<<x<<endl;
	cout<<"请输入待删除关键字"<<endl;
	cin>>x;
	DeleteBST(T,x);
	cout<<"二叉搜索树的中序遍历："<<endl;
	InOrderTraverse(T);
	cout<<endl;
	cout<<"二叉搜索树的先序遍历："<<endl;
	PreOrderTraverse(T);
	return 0;
}
/*
25 69 18 5 32 45 20 -1
69
25
*/ 
