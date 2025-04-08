#include<iostream>
using namespace std;

typedef struct Lnode{
	int data; //节点的数据域
	struct Lnode *next; //节点的指针域
}Lnode,*LinkList; //LinkList为指向结构体LNode的指针类型

bool InitList_L(LinkList &L){//构造一个空的单链表L
    L=new Lnode;     //生成新节点作为头节点，用头指针L指向头节点
	if(!L)
		return false;  //生成节点失败
	L->next=NULL;   //头节点的指针域置空
	return true;
}

void CreateList_H(LinkList &L){//插法创建单链表
	//输入n个元素的值，建立到头节点的单链表L
	int n;
	LinkList s; //定义一个指针变量
	L=new Lnode;
	L->next=NULL; //先建立一个带头节点的空链表
	cout<<"请输入元素个数n："<<endl;
	cin>>n;
	cout<<"请依次输入n个元素："<<endl;
	cout<<"前插法创建单链表..."<<endl;
	while(n--){
		s=new Lnode; //生成新节点s
		cin>>s->data; //输入元素值赋给新节点的数据域
		s->next=L->next;
		L->next=s; //将新节点s插入到头节点之后
	}
}

void CreateList_R(LinkList &L){//尾插法创建单链表
	//输入n个元素的值，建立带表头节点的单链表L
	int n;
	LinkList s, r;
	L=new Lnode;
	L->next=NULL; //先建立一个带头节点的空链表
	r=L; //尾指针r指向头节点
	cout<<"请输入元素个数n："<<endl;
	cin>>n;
	cout<<"请依次输入n个元素："<<endl;
	cout<<"尾插法创建单链表..."<<endl;
	while(n--){
		s=new Lnode;//生成新节点
		cin>>s->data; //输入元素值赋给新节点的数据域
		s->next=NULL;
		r->next=s;//将新节点s插入尾节点*r之后
		r=s;//r指向新的尾节点s
	}
}

bool GetElem_L(LinkList L, int i, int &e){//单链表的取值
	//在带头节点的单链表L中查找第i个元素
	//用e记录L中第i个数据元素的值
	LinkList p;
	p=L->next;//p指向第一个节点，
	int j=1; //j为计数器
	while(j<i&&p){ //顺链域向后扫描，直到p指向第i个元素或p为空
		p=p->next; //p指向下一个节点
		j++; //计数器j相应加1
	}
	if(!p||j>i)
		return false; //i值不合法i＞n或i<=0
	e=p->data; //取第i个节点的数据域
	return true;
}

bool LocateElem_L(LinkList L,int e){ //按值查找
	//在带头节点的单链表L中查找值为e的元素
	LinkList p;
	p=L->next;
	while(p&&p->data!=e)//顺链域向后扫描，直到p为空或p所指节点的数据域等于e
		p=p->next; //p指向下一个节点
	if(!p)
        return false; //查找失败p为NULL
    return true;
}

bool ListInsert_L(LinkList &L,int i,int e){//在带头节点的单链表L中第i个位置插入e
	LinkList p=L,s;
	int j=0;
	while(p&&j<i-1){ //查找第i-1个节点，p指向该节点
		p=p->next;
		j++;
	}
	if(!p||j>i-1) //i＞n+1或者i＜1
		return false;
	s=new Lnode;     //生成新节点
	s->data=e;       //将新节点的数据域置为e
	s->next=p->next; //将新节点的指针域指向节点ai
	p->next=s;       //将节点p的指针域指向节点s
	return true;
}

bool ListDelete_L(LinkList &L, int i){ //在带头节点的单链表L中，删除第i个节点
	LinkList p=L,q;
	int j=0;
	while(p->next&&j<i-1){ //查找第i-1个节点，p指向该节点
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i-1))//当i>n或i<1时，删除位置不合理
		return false;
	q=p->next;        //临时保存被删节点的地址以备释放空间
	p->next=q->next; //改变删除节点前驱节点的指针域
	delete q;        //释放被删除节点的空间
	return true;
}

void Listprint_L(LinkList L){ //单链表的输出
    LinkList p;
    p=L->next;
    while(p){
        cout<<p->data<<"\t";
		p=p->next;
    }
    cout<<endl;
}

int main(){
	int i,x,e,choose;
	LinkList L;
	cout<<"1. 初始化\n";
	cout<<"2. 创建单链表（前插法）\n";
	cout<<"3. 创建单链表（尾插法）\n";
	cout<<"4. 取值\n";
	cout<<"5. 查找\n";
	cout<<"6. 插入\n";
	cout<<"7. 删除\n";
	cout<<"8. 输出\n";
	cout<<"0. 退出\n";
	choose=-1;
	while(choose!=0){
		cout<<"请输入数字选择:";
		cin>>choose;
		switch(choose){
		case 1: //初始化一个空的单链表
			if(InitList_L(L))
				cout<<"初始化一个空的单链表!\n";
			break;
		case 2: //创建单链表（前插法）
			CreateList_H(L);
            cout<<"前插法创建单链表输出结果:\n";
            Listprint_L(L);
			break;
        case 3: //创建单链表（尾插法）
			CreateList_R(L);
            cout<<"尾插法创建单链表输出结果:\n";
            Listprint_L(L);
			break;
		case 4: //单链表的按序号取值
			cout<<"请输入一个位置i用来取值:";
			cin>>i;
			if (GetElem_L(L,i,e)){
				cout<<"查找成功\n";
				cout<<"第"<<i<<"个元素是："<<e<<endl;
			}
			else
				cout<<"查找失败\n\n";
			break;
		case 5: //单链表的按值查找
			cout<<"请输入所要查找元素x:";
			cin>>x;
			if(LocateElem_L(L,x))
				cout<<"查找成功\n";
			else
				cout<<"查找失败! "<<endl;
			break;
		case 6: //单链表的插入
			cout<<"请输入插入的位置和元素（用空格隔开）:";
			cin>>i;
			cin>>x;
			if(ListInsert_L(L,i,x))
				cout<<"插入成功.\n\n";
			else
				cout<<"插入失败!\n\n";
			break;
		case 7: //单链表的删除
			cout<<"请输入所要删除的元素位置i:";
			cin>>i;
			if(ListDelete_L(L,i))
				cout<<"删除成功!\n";
			else
				cout<<"删除失败!\n";
			break;
		case 8: //单链表的输出
			cout<<"当前单链表的数据元素分别为:\n";
			Listprint_L(L);
			cout<<endl;
			break;
		}
	}
	return 0;
}

