#include<bits/stdc++.h> //����ͷ�ļ� 
using namespace std;

int main(){
	int a,b,c;  //�����εı�
	cin>>a>>b>>c; 
	if(a+b>c && a+c>b && b+c>a) //����֮�ʹ��ڵ����� 
		cout<<1<<endl;
	else
		cout<<0<<endl;
	return 0;
}
