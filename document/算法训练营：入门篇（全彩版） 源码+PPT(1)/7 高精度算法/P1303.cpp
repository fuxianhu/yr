#include<iostream>
using namespace std;
const int maxn=4050; //ע�⣬ÿ����2000λ���˻�λ�����Ϊ2000*2+1 
int a[maxn],b[maxn],c[maxn]; 

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.length();
	int m=s2.length();
	int len=n+m;
	for(int i=0;i<n;i++) //�洢��1���ַ����������У�����洢 
		a[n-i]=s1[i]-'0';
	for(int i=0;i<m;i++) //�洢��2���ַ����������У�����洢
		b[m-i]=s2[i]-'0';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			c[i+j-1]+=a[i]*b[j]; //�ۼӳ˻� 
	for(int i=1;i<len;i++){ //�����λ 
		if(c[i]>9){
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	}
	while(c[len]==0&&len>1) len--; //ɾ��ǰ��0 
	for(int i=len;i>0;i--) //���������Ӹ�λ����λ 
		cout<<c[i];
	return 0;
}
