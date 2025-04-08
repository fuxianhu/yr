#include<iostream>
using namespace std;

void swap(int *x,int *y){ //交换两个数 
	int temp=*x;
	*x=*y;
	*y=temp;
} 

class MyClass{ //定义一个类 
public:
    int val;  //定义个一个公有变量 
};

int main(){
	int x=10;
	int *p=&x; //定义一个指针变量p，p为x变量的地址
	cout<<x<<endl;  //10
	cout<<*p<<endl; //10
	cout<<p<<endl;  //0x6ffe14
	
	char *str="Hello, World!"; 
	cout<<*(str+2)<<endl;  //输出l，即str[2]
	
	int a[5]={1,2,3,4,5};
	int *p1=a;  //定义一个指针，指向数组首地址 
	cout<<*(p1+2)<<endl;  //输出3，即a[2]，因为p1存储数组a的首地址
	int *p2=new int(10);  //分配内存空间并初始化为数组大小为10
	
	int x1=2,x2=3;
	swap(&x1,&x2);
	cout<<x1<<" "<<x2<<endl;
	
	MyClass obj;       //定义一个类对象实例 
    MyClass *ptr=&obj; //定义一个指针指向类对象obj 
    ptr->val=10;
    cout<<ptr->val<<endl;  //输出10

	return 0;
} 
