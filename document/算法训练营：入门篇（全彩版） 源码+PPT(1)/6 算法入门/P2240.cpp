#include<bits/stdc++.h> //�������⣨���и 
using namespace std;
struct node{//����ṹ�� 
	double w;//���� 
	double v;//��ֵ 
	double p;//��ֵ������v/w 
}a[105];
int n;//������� 
double c,sum=0;//�������������Դ��ߵĽ������

bool cmp(node a,node b){//�������ȼ� 
	return a.p>b.p;//����ֵ�����ȴӴ�С����
}

int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].v;
		a[i].p=a[i].v/a[i].w;//��ֵ������=�۸�/���� 
	}
	sort(a+1,a+n+1,cmp);//����ֵ�����ȴӴ�С����
	for(int i=1;i<=n;++i){
		if(a[i].w<=c){//��ҵ�����<=����ʣ������
			c-=a[i].w;//���±���ʣ������ 
			sum+=a[i].v;//�ۼӽ�ҵļ�ֵ 
		}
		else{
			sum+=c*a[i].p;//���װ���¾ͷָ���װ��ʣ������������װ�� 
			break;
		}
	}
	printf("%.2f",sum);//����С�������λ���
	return 0; 
}
