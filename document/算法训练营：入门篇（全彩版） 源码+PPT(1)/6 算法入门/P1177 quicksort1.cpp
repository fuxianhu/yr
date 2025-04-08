#include<bits/stdc++.h> //�����������������
using namespace std;
const int maxn=1e5+5;
int n,a[maxn];

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

void quicksort(int left,int right) { //�������� 
	if(left<right){
		int mid=partition(left,right);
		quicksort(left,mid-1);
		quicksort(mid+1,right);
	}
}

int main() {
	srand((unsigned)time(NULL)); //ϵͳʱ����Ϊ��������� 
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	quicksort(0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
