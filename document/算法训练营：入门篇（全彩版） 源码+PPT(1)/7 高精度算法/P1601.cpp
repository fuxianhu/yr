#include<iostream>
#include<algorithm>
using namespace std;
int a[520],b[520],c[520];

int main(){
	string s1,s2;
	cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
	int len=max(n,m);
	for(int i=0;i<n;i++) //存储第1个字符串到数组中，逆向存储
		a[n-i]=s1[i]-'0';
	for(int i=0;i<m;i++) //存储第2个字符串到数组中，逆向存储
		b[m-i]=s2[i]-'0';
	for(int i=1;i<=len;i++){ //高精度加法 
		c[i]+=a[i]+b[i];  //累加 
		c[i+1]=c[i]/10;  //进位 
		c[i]%=10;          //当前位 
	}    
	if(c[len+1]) //处理进位 
	    len++;
	for(int i=len;i>=1;i--) //输出结果，从高位到低位 
		cout<<c[i];
	return 0;   
}
