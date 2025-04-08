#include<iostream>
using namespace std;
const int maxn=1e6+5;
int a[maxn],n,m;

int BinarySearch(int x){ //二分查找
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(x<=a[mid]) //找左边界 
			r=mid;
		else
			l=mid+1;
	}
	if(a[l]==x) return l;
	return -1;
}

int main(){
	int x;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
       cin>>a[i];
    for(int i=1;i<=m;i++){
    	cin>>x;
    	int k=BinarySearch(x);
    	cout<<k<<" ";
	}
    return 0;
}
