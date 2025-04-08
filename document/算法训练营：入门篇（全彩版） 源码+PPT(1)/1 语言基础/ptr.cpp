#include<iostream>
using namespace std;

void swap(int *x,int *y){ //���������� 
	int temp=*x;
	*x=*y;
	*y=temp;
} 

class MyClass{ //����һ���� 
public:
    int val;  //�����һ�����б��� 
};

int main(){
	int x=10;
	int *p=&x; //����һ��ָ�����p��pΪx�����ĵ�ַ
	cout<<x<<endl;  //10
	cout<<*p<<endl; //10
	cout<<p<<endl;  //0x6ffe14
	
	char *str="Hello, World!"; 
	cout<<*(str+2)<<endl;  //���l����str[2]
	
	int a[5]={1,2,3,4,5};
	int *p1=a;  //����һ��ָ�룬ָ�������׵�ַ 
	cout<<*(p1+2)<<endl;  //���3����a[2]����Ϊp1�洢����a���׵�ַ
	int *p2=new int(10);  //�����ڴ�ռ䲢��ʼ��Ϊ�����СΪ10
	
	int x1=2,x2=3;
	swap(&x1,&x2);
	cout<<x1<<" "<<x2<<endl;
	
	MyClass obj;       //����һ�������ʵ�� 
    MyClass *ptr=&obj; //����һ��ָ��ָ�������obj 
    ptr->val=10;
    cout<<ptr->val<<endl;  //���10

	return 0;
} 
