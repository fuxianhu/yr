#include<bits/stdc++.h> //快速排序，引入随机化
using namespace std;
const int maxn=1e5+5;
int n,a[maxn];

int partition(int left,int right) { //划分 
	int k=left+rand()%(right-left+1); //产生[left,right]之间的随机数 
	swap(a[k],a[left]);
	int i=left,j=right,pivot=a[left];
	while(i<j) {
		while(a[j]>pivot && i<j) j--;  //找右侧小于等于pivot的数
		if(i<j)
			a[i++]=a[j]; //覆盖
		while(a[i]<pivot && i<j) i++; //找左侧大于等于pivot的数 
		if(i<j)
			a[j--]=a[i]; //覆盖
	}
	a[i]=pivot; //放到中间 
	return i;
}

void quicksort(int left,int right) { //快速排序 
	if(left<right){
		int mid=partition(left,right);
		quicksort(left,mid-1);
		quicksort(mid+1,right);
	}
}

int main() {
	srand((unsigned)time(NULL)); //系统时间作为随机数种子 
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	quicksort(0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
