#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10500;
int a[maxn],b[maxn],c[maxn]; 

int main(){
	string s1,s2;
	cin>>s1>>s2;
	//�ȱȽ��������Ĵ�С
	if(s1.size()<s2.size()||(s1.size()==s2.size()&&s1<s2)){
		swap(s1,s2);   //���������磬8-15 = -(15-8)
		cout<<"-"; //������� 
	}
	int n=s1.length();
	int m=s2.length();
	int len=max(n,m);
	for(int i=0;i<n;i++) //�洢��1���ַ����������У�����洢 
		a[n-i]=s1[i]-'0';
	for(int i=0;i<m;i++) //�洢��2���ַ����������У�����洢
		b[m-i]=s2[i]-'0';
	for(int i=1;i<=len;i++){
		if(a[i]<b[i]){ //���λ��1
			a[i+1]--;      //��λ��1 
			a[i]+=10;   //��1��10 
		}
		c[i]=a[i]-b[i]; //���� 
	}
	while(c[len]==0 && len>1) len--; //ɾ��ǰ��0 
	for(int i=len;i>0;i--) //���������Ӹ�λ����λ 
		cout<<c[i];
	return 0;
}
