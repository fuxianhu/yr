#include<iostream>
using namespace std;
#define ENDFLAG -1

typedef struct BSTNode{ //�����������ڵ�
	int data;	         //������
	BSTNode *lchild,*rchild; //���Һ���ָ��
}BSTNode,*BSTree;

BSTree SearchBST(BSTree T,int x){ //��������������
    if(!T||x==T->data)//�����ҳɹ����򷵻�ָ���Ԫ�ص�ָ�룬���򷵻ؿ�ָ��
        return T;
    if(x<T->data)
        SearchBST(T->lchild,x);//���������м�������
    else
        SearchBST(T->rchild,x); //���������м�������
}

void InsertBST(BSTree &T,int x){ //��������������
    //������������T�в����ڵ���x��Ԫ��ʱ�������x
	if(!T){  //���Ϊ����
		BSTree s=new BSTNode;  //�����½ڵ�
		s->data=x;             //�½ڵ�s��������Ϊx
		s->lchild=s->rchild=NULL;//�½ڵ�s��ΪҶ�ӽڵ�
		T=s;            		//���½ڵ�s���ӵ����ҵ��Ĳ���λ��
		return; 
	}
	if(x==T->data) return;  //�����ҳɹ���ʲôҲ����
	if(x<T->data)
		InsertBST(T->lchild,x); //���뵽�������� 
	else if(x>T->data)
		InsertBST(T->rchild,x); //���뵽�������� 
}

void CreateBST(BSTree &T){ //��������������
	T=NULL;
	int x;
	cin>>x;
	while(x!=ENDFLAG){ //ENDFLAGΪ�Զ��峣������Ϊ���������־
	    InsertBST(T,x);  //�������������T��
	    cin>>x;
	}
}

void DeleteBST(BSTree &T,int x){ //����������ɾ��
	BSTree p=T,f=NULL,q,s;
	if(!T) return; //��Ϊ���򷵻�
	while(p){//����
		if(x==p->data) break;  //�ҵ��ؼ��ֵ���x�Ľڵ�p������ѭ��
		f=p;                //fΪp�ĸ��ڵ� 
		if(x<p->data)
			p=p->lchild; //��p���������м�������
		else
			p=p->rchild; //��p���������м�������
	}
	if(!p) return; //�Ҳ�����ɾ�ڵ��򷵻�
	//���������p�������������ա�������������������
	if((p->lchild)&&(p->rchild)){ //��ɾ�ڵ�p��������������
		q=p;
		s=p->lchild;
		while(s->rchild){//������ǰ���ڵ㣬��p�����������ҽڵ�
			q=s;
			s=s->rchild;
		}
		p->data=s->data;  //s��ֵ��ֵ����ɾ�ڵ�p,Ȼ��ɾ��s�ڵ�
		if(q!=p)
			q->rchild=s->lchild; //�ؽ�q��������
		else
			q->lchild=s->lchild; //�ؽ�q��������
		delete s;
	}
	else{
		if(!p->rchild){//��ɾ�ڵ�p����������ֻ���ؽ���������
			q=p;
			p=p->lchild;
		}
		else if(!p->lchild){//��ɾ�ڵ�p����������ֻ���ؽ���������
			q=p;
			p=p->rchild;
		}
		/*�D�D�D��p��ָ�������ҽӵ��丸�ڵ�f��Ӧ��λ�èD�D�D*/
		if(!f)
			T=p;  //��ɾ�ڵ�Ϊ���ڵ�
		else if(q==f->lchild)
				f->lchild=p; //�ҽӵ�f��������λ��
			else
				f->rchild=p;//�ҽӵ�f��������λ��
		delete q;
	}
}

void InOrderTraverse(BSTree T){//�������
    if(T){
        InOrderTraverse(T->lchild);
        cout<<T->data<<"\t";
        InOrderTraverse(T->rchild);
	}
}

void PreOrderTraverse(BSTree T){//�������
    if(T){
        cout<<T->data<<"\t";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
	}
}

int main(){
	BSTree T;
	CreateBST(T); //����һЩ������-1����
	cout<<"���������������������"<<endl;
	InOrderTraverse(T);
	cout<<endl;
	cout<<"���������������������"<<endl;
	PreOrderTraverse(T);
	cout<<endl;
	int x;  //�����һ��ɾ��Ԫ�� 
	cout<<"����������ҹؼ���"<<endl;
	cin>>x;
	BSTree result=SearchBST(T,x);
	if(result)
        cout<<"�ҵ�"<<x<<endl;
	else
        cout<<"δ�ҵ�"<<x<<endl;
	cout<<"�������ɾ���ؼ���"<<endl;
	cin>>x;
	DeleteBST(T,x);
	cout<<"���������������������"<<endl;
	InOrderTraverse(T);
	cout<<endl;
	cout<<"���������������������"<<endl;
	PreOrderTraverse(T);
	return 0;
}
/*
25 69 18 5 32 45 20 -1
69
25
*/ 
