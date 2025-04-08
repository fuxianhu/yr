#include<bits/stdc++.h> //合并排序
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],b[maxn];

void merge(int left,int mid,int right){ //合并
	int i=left,j=mid+1,k=0;
	while(i<=mid && j<=right){ //按从小到大存放到辅助数组b[]中
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid) b[k++]=a[i++]; //将数组中剩下的元素放置b[]中
	while(j<=right) b[k++]=a[j++];
	for(i=left,k=0;i<=right;i++)
	    a[i]=b[k++];
}

void mergesort(int left,int right){
	if(left<right){
		int mid=(left+right)/2;  //取中点
		mergesort(left,mid);    //对a[left:mid]中的元素合并排序
		mergesort(mid+1,right); //对a[mid+1:right]中的元素合并排序
		merge(left, mid,right); //合并
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
