#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10500;
int a[maxn],b[maxn],c[maxn]; 

int main(){
	string s1,s2;
	cin>>s1>>s2;
	//先比较两个数的大小
	if(s1.size()<s2.size()||(s1.size()==s2.size()&&s1<s2)){
		swap(s1,s2);   //交换，例如，8-15 = -(15-8)
		cout<<"-"; //输出负号 
	}
	int n=s1.length();
	int m=s2.length();
	int len=max(n,m);
	for(int i=0;i<n;i++) //存储第1个字符串到数组中，逆向存储 
		a[n-i]=s1[i]-'0';
	for(int i=0;i<m;i++) //存储第2个字符串到数组中，逆向存储
		b[m-i]=s2[i]-'0';
	for(int i=1;i<=len;i++){
		if(a[i]<b[i]){ //向高位借1
			a[i+1]--;      //高位减1 
			a[i]+=10;   //借1当10 
		}
		c[i]=a[i]-b[i]; //减法 
	}
	while(c[len]==0 && len>1) len--; //删除前导0 
	for(int i=len;i>0;i--) //输出结果，从高位到低位 
		cout<<c[i];
	return 0;
}
