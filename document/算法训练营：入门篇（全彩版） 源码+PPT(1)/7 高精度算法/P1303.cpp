#include<iostream>
using namespace std;
const int maxn=4050; //注意，每个数2000位，乘积位数最大为2000*2+1 
int a[maxn],b[maxn],c[maxn]; 

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.length();
	int m=s2.length();
	int len=n+m;
	for(int i=0;i<n;i++) //存储第1个字符串到数组中，逆向存储 
		a[n-i]=s1[i]-'0';
	for(int i=0;i<m;i++) //存储第2个字符串到数组中，逆向存储
		b[m-i]=s2[i]-'0';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			c[i+j-1]+=a[i]*b[j]; //累加乘积 
	for(int i=1;i<len;i++){ //处理进位 
		if(c[i]>9){
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	}
	while(c[len]==0&&len>1) len--; //删除前导0 
	for(int i=len;i>0;i--) //输出结果，从高位到低位 
		cout<<c[i];
	return 0;
}
