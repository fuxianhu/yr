#include<iostream>
#include<cstdio>
#include<algorithm>//��ͷ�ļ�����������sort
using namespace std;
struct node{
	int t,id;//��ˮʱ�䣬���      
}a[1010];

bool cmp(node x,node y){ //��������Ƚ����ȼ� 
	return x.t<y.t; //����ˮʱ��ǵݼ� 
}

int main(){
	int n;
	double time=0;
	cin>>n;    
	for(int i=1;i<=n;i++){
		cin>>a[i].t;
		a[i].id=i;//��Ŵ�����    
	} 
	sort(a+1,a+n+1,cmp);//����
	for(int i=1;i<=n;i++)//������С����ı��
		cout<<a[i].id<<" ";
	cout<<endl;
	for(int i=1;i<n;i++)//�ۼӵȴ�ʱ�� 
		time+=a[i].t*(n-i); 
	printf("%.2f",time/n);//���ƽ��ʱ�䣬������λС�� #include<iomanip> cout<<fixed<<setprecision(2)<<time/n;
	return 0; 
}
