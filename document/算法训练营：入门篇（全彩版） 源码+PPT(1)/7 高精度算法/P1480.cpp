#include<iostream>  //�߾��ȳ��Ե;��� 
using namespace std;
const int maxn=10010;
int a[maxn],c[maxn]; 

int main(){
	string s;       //������ 
	long long b,x=0;  //�������ۼ�����ʱҪ����10�����ܶ���Ϊint 
	cin>>s>>b;
	int n=s.length();
	for(int i=0;i<n;i++) //�洢��1���ַ����������У�����洢 
		a[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++){ //�������� 
		x=x*10+a[i];  //�ۼ��ϴ������͵�ǰλ 
		c[i]=x/b;      //��¼�� 
		x%=b;            //�������� 
	}
	int lenc=1; 
	while(c[lenc]==0&&lenc<n) lenc++; //ɾ��ǰ��0 
	for(int i=lenc;i<=n;i++) //���������Ӹ�λ����λ 
		cout<<c[i]; 
	return 0;
}
