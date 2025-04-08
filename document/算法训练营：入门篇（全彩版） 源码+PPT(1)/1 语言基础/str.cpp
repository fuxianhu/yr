#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {
	char str[100];
	cin>>str;
	cout<<str<<endl;
	cout<<strlen(str)<<"\t"<<sizeof(str)<<endl;
//	cin.get();   //前面有cin，输入流中有回车 
//	cin.getline(str,10);//读入一行，最多读入9个字符，遇到换行符停止，最后一个默认为'\0'
//	cout<<str<<endl;
//	
//	cin.getline(str,10,':'); //读入一行，最多读入9个字符，读到冒号则停止
//	cout<<str<<endl;
//	
//	char str1[100], str2[100];
//	cin>>str1>>str2;  //可以输入一个字符串，换行后，再输入一个字符串
//	cout<<str1<<"\t"<<str2<<endl; 
	
//	string s;
//	cin>>s; 
//	cout<<s<<endl;
//	cout<<s.size()<<"\t"<<s.length()<<endl;
//	cin.get();      //前面有cin，输入流中有回车 
//	getline(cin,s); //读入一行，遇到换行符停止
//	cout<<s<<endl;
//	getline(cin,s,':'); //读入一行，遇到换行符停止
//	cout<<s<<endl;
	return 0;
}
