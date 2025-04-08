#include<bits/stdc++.h> //�����������������
using namespace std;
const int maxn=1e5+5;
int n,a[maxn];

int partition(int left,int right) { //����2 
	int k=left+rand()%(right-left+1); //����[left,right]֮�������� 
	swap(a[k],a[left]);
	int i=left+1,j=right,pivot=a[left];
	while(i<j) {
		while(a[j]>pivot && i<j) j--;  //���Ҳ�С�ڵ���pivot����
        while(a[i]<pivot && i<j) i++; //�������ڵ���pivot���� 
		if(i<j)
			swap(a[i++],a[j--]); //���� 
	}
	if(a[i]>pivot) //�ϴν�����i++,j--������i=j���������pivot,��ǰһ������ 
		i--;
	swap(a[i],a[left]);
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
