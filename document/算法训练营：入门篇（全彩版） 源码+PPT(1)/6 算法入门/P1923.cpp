#include<bits/stdc++.h> //利用快速排序的划分，求第k小 
using namespace std;
const int maxn=5e6+5;
int n,k,a[maxn];

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

void findk(int left,int right,int k) { //查找第k个数 
	int mid=partition(left,right);
	if(k==mid)
		cout<<a[k];
	else if(k<mid)
		findk(left,mid-1,k);
	else
		findk(mid+1,right,k);
}

int main() {
	srand((unsigned)time(NULL)); //系统时间作为随机数种子 
	scanf("%d%d",&n,&k);  
	for(int i=0;i<n;i++) //数据量大，用scanf比cin速度快
		scanf("%d",&a[i]);
	findk(0,n-1,k);
	return 0;
}
