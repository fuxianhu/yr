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
	for(int i=0;i<n;i++) //�洢��1���ַ����������У�����洢
		a[n-i]=s1[i]-'0';
	for(int i=0;i<m;i++) //�洢��2���ַ����������У�����洢
		b[m-i]=s2[i]-'0';
	for(int i=1;i<=len;i++){ //�߾��ȼӷ� 
		c[i]+=a[i]+b[i];  //�ۼ� 
		c[i+1]=c[i]/10;  //��λ 
		c[i]%=10;          //��ǰλ 
	}    
	if(c[len+1]) //�����λ 
	    len++;
	for(int i=len;i>=1;i--) //���������Ӹ�λ����λ 
		cout<<c[i];
	return 0;   
}
