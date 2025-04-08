#include<iostream>  //高精度除以低精度 
using namespace std;
const int maxn=10010;
int a[maxn],c[maxn]; 

int main(){
	string s;       //被除数 
	long long b,x=0;  //除数，累加余数时要乘以10，不能定义为int 
	cin>>s>>b;
	int n=s.length();
	for(int i=0;i<n;i++) //存储第1个字符串到数组中，正向存储 
		a[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++){ //除法运算 
		x=x*10+a[i];  //累加上次余数和当前位 
		c[i]=x/b;      //记录商 
		x%=b;            //更新余数 
	}
	int lenc=1; 
	while(c[lenc]==0&&lenc<n) lenc++; //删除前导0 
	for(int i=lenc;i<=n;i++) //输出结果，从高位到低位 
		cout<<c[i]; 
	return 0;
}
