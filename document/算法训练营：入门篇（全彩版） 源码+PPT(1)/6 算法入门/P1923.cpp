#include<bits/stdc++.h> //���ÿ�������Ļ��֣����kС 
using namespace std;
const int maxn=5e6+5;
int n,k,a[maxn];

int partition(int left,int right) { //���� 
	int k=left+rand()%(right-left+1); //����[left,right]֮�������� 
	swap(a[k],a[left]);
	int i=left,j=right,pivot=a[left];
	while(i<j) {
		while(a[j]>pivot && i<j) j--;  //���Ҳ�С�ڵ���pivot����
		if(i<j)
			a[i++]=a[j]; //����
		while(a[i]<pivot && i<j) i++; //�������ڵ���pivot���� 
		if(i<j)
			a[j--]=a[i]; //����
	}
	a[i]=pivot; //�ŵ��м� 
	return i;
}

void findk(int left,int right,int k) { //���ҵ�k���� 
	int mid=partition(left,right);
	if(k==mid)
		cout<<a[k];
	else if(k<mid)
		findk(left,mid-1,k);
	else
		findk(mid+1,right,k);
}

int main() {
	srand((unsigned)time(NULL)); //ϵͳʱ����Ϊ��������� 
	scanf("%d%d",&n,&k);  
	for(int i=0;i<n;i++) //����������scanf��cin�ٶȿ�
		scanf("%d",&a[i]);
	findk(0,n-1,k);
	return 0;
}
