#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {
	char str[100];
	cin>>str;
	cout<<str<<endl;
	cout<<strlen(str)<<"\t"<<sizeof(str)<<endl;
//	cin.get();   //ǰ����cin�����������лس� 
//	cin.getline(str,10);//����һ�У�������9���ַ����������з�ֹͣ�����һ��Ĭ��Ϊ'\0'
//	cout<<str<<endl;
//	
//	cin.getline(str,10,':'); //����һ�У�������9���ַ�������ð����ֹͣ
//	cout<<str<<endl;
//	
//	char str1[100], str2[100];
//	cin>>str1>>str2;  //��������һ���ַ��������к�������һ���ַ���
//	cout<<str1<<"\t"<<str2<<endl; 
	
//	string s;
//	cin>>s; 
//	cout<<s<<endl;
//	cout<<s.size()<<"\t"<<s.length()<<endl;
//	cin.get();      //ǰ����cin�����������лس� 
//	getline(cin,s); //����һ�У��������з�ֹͣ
//	cout<<s<<endl;
//	getline(cin,s,':'); //����һ�У��������з�ֹͣ
//	cout<<s<<endl;
	return 0;
}
