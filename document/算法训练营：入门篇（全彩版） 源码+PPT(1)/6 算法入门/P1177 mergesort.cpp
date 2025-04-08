#include<bits/stdc++.h> //�ϲ�����
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],b[maxn];

void merge(int left,int mid,int right){ //�ϲ�
	int i=left,j=mid+1,k=0;
	while(i<=mid && j<=right){ //����С�����ŵ���������b[]��
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid) b[k++]=a[i++]; //��������ʣ�µ�Ԫ�ط���b[]��
	while(j<=right) b[k++]=a[j++];
	for(i=left,k=0;i<=right;i++)
	    a[i]=b[k++];
}

void mergesort(int left,int right){
	if(left<right){
		int mid=(left+right)/2;  //ȡ�е�
		mergesort(left,mid);    //��a[left:mid]�е�Ԫ�غϲ�����
		mergesort(mid+1,right); //��a[mid+1:right]�е�Ԫ�غϲ�����
		merge(left, mid,right); //�ϲ�
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergesort(0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
