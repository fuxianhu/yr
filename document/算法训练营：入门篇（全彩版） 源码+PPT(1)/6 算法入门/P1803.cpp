#include<bits/stdc++.h>
using namespace std;
struct node{//����һ���ṹ�����飬�ֱ𴢴濪ʼʱ��ͽ���ʱ��
	int s; //��ʼʱ��
	int e; //����ʱ��
}a[1000010];

bool cmp(node x,node y){//�������ȼ� 
	if(x.e==y.e) return x.s>y.s;//�������ʱ����ȣ���ʼʱ��Ӵ�С 
	return x.e<y.e;//������ʱ���С���󣨷ǵݼ��� 
}

int main(){
	int n,cnt=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>a[i].s>>a[i].e;
	sort(a+1,a+n+1,cmp);//����
	int last=a[1].e;//��¼����ѡ�б����Ľ���ʱ�� 
	for(int i=2;i<=n;i++){//������б��� 
		if(a[i].s>=last){
			cnt++;       //ѡ��ñ�������������1 
			last=a[i].e; //��¼����ѡ�б����Ľ���ʱ��
		}				
	}
	cout<<cnt<<endl;//���
	return 0;
}
